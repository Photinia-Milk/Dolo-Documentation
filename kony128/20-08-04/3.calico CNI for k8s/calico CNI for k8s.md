# calico CNI for k8s

## 时间

12点13分

## 内容

### 为什么需要CNI

如何解决pod与pod内镜像之间的通信？

实现流量细粒化控制，自动配置部署？

这时候就需要CNI的登场辣



![image-20200804130634522](calico%20CNI%20for%20k8s.assets/image-20200804130634522.png)

目前status都是not ready

配置CNI后，它们就会变成ready了

kubernetes可选CNI插件如下：

Flannel

Calico

Canal

Weave

我们选择Calico，网上说Calico性能比Flannel快1% hhh

### 坑:已经部署了

https://docs.projectcalico.org/getting-started/kubernetes/quickstart

![image-20200804131316775](calico%20CNI%20for%20k8s.assets/image-20200804131316775.png)

我们要在kubeadm init的时候这样弄，但我们已经部署了

嗯。。

问题来了，如何修改已配置的kubeadm文件呢

### 修改已配置文件

https://kubernetes.io/zh/docs/reference/setup-tools/kubeadm/kubeadm-config/

https://kubernetes.io/zh/docs/tasks/administer-cluster/reconfigure-kubelet/

https://stackoverflow.com/questions/49147294/kubelet-dynamic-configuration-doesnt-work

使用kubeadm config view

![image-20200804131921656](calico%20CNI%20for%20k8s.assets/image-20200804131921656.png)

看来可以这样改

在networking那里加一行字

podSubnet: "10.244.0.0/16"

![image-20200804132651354](calico%20CNI%20for%20k8s.assets/image-20200804132651354.png)

根据kubeadm config migrate -h的提示

我们如果不用--kubecinfig指定路径，集群会默认读取

/etc/kubernetes/admin.conf的配置

嗯。。。

![image-20200804134431588](calico%20CNI%20for%20k8s.assets/image-20200804134431588.png)

试试看kubeadm config upload

这个指令被deprecate了

看来要用到kubeadm init phase upload-config了

官网上没有对phase upload-config的说明

![image-20200804134949956](calico%20CNI%20for%20k8s.assets/image-20200804134949956.png)

使用kubectl config view

![image-20200804135415538](calico%20CNI%20for%20k8s.assets/image-20200804135415538.png)

这里甚至没有networking设置

嗯。。

### 也不知道对不对的修改

使用

先写

myconfig.yml

把正确的内容补上

（networking里加上podSubnet: "10.244.0.0/16"）

然后使用

sudo kubeadm init phase upload-config kubeadm --config=./myconfig.yml

试试看配置是否成功

sudo kubeadm config view

![image-20200804142122834](calico%20CNI%20for%20k8s.assets/image-20200804142122834.png)

这里显示配置成功了欸！

以防万一，重启一下kubelet

sudo systemctl restart kubelet

我不确定这样会不会算成功

毕竟只改了kubeadm的配置，没有改kubelet，kubelet是自动生成的，如果依赖于kubeadm，那就炸了

![image-20200804142340224](calico%20CNI%20for%20k8s.assets/image-20200804142340224.png)

但愿不要出现什么隐性bug

老天保佑

### 尝试安装calico - 失败

https://docs.projectcalico.org/getting-started/kubernetes/quickstart

kubectl create -f https://docs.projectcalico.org/manifests/tigera-operator.yaml

kubectl create -f https://docs.projectcalico.org/manifests/custom-resources.yaml

watch kubectl get pods -n calico-system

![image-20200804142848679](calico%20CNI%20for%20k8s.assets/image-20200804142848679.png)

淦

为什么要这样折磨我自己呢

### 重新来过

#### teardown cluster

https://kubernetes.io/docs/setup/production-environment/tools/kubeadm/create-cluster-kubeadm/#tear-down

我先在master上drain所有node

kubectl drain ip-172-31-66-187.ec2.internal --delete-local-data --force --ignore-daemonsets

kubectl drain ip-172-31-67-125.ec2.internal --delete-local-data --force --ignore-daemonsets

kubectl drain ip-172-31-74-166.ec2.internal --delete-local-data --force --ignore-daemonsets

有些node我drain了两次

然后我依次在每个slave上使用了sudo kubeadm reset

最后我尝试在master上使用sudo kubeadm reset

报错了。。

![image-20200804144242391](calico%20CNI%20for%20k8s.assets/image-20200804144242391.png)

etcd 的server就是不肯退出

re-configuration failed due to not enough started members

https://github.com/kubernetes/kubeadm/issues/2144

似乎有人和我遇到同样的问题

楼下有人回了帖

https://github.com/kubernetes/kubernetes/pull/91145

这个phase会不停重复，然后超时50s失败

但是其实下一个phase etcd cluster就会被干掉

所以需要跳过这个phase

嗯。。

等到它超时了，这个phase过去了

好像就行了

![image-20200804153117086](calico%20CNI%20for%20k8s.assets/image-20200804153117086.png)

手动清除cni配置

sudo rm /etc/cni/net.d

手动清除kubeconfig

sudo rm $HOME/.kube/config

手动重置 iptables

```bash
iptables -F && iptables -t nat -F && iptables -t mangle -F && iptables -X
```

手动重置 ipvstables

```bash
ipvsadm -C
```

现在可以删除所有node了

```bash
kubectl delete node <node name>
```

#### init again

sudo kubeadm init --pod-network-cidr=10.244.0.0/16 --control-plane-endpoint 52.23.65.*** : )

![image-20200804153940860](calico%20CNI%20for%20k8s.assets/image-20200804153940860.png)

![image-20200804154008136](calico%20CNI%20for%20k8s.assets/image-20200804154008136.png)

嘿嘿，有了哈哈哈

![image-20200804154113427](calico%20CNI%20for%20k8s.assets/image-20200804154113427.png)

emmm

怎么还是老毛病

![image-20200804154301042](calico%20CNI%20for%20k8s.assets/image-20200804154301042.png)

tigera-operator是装好了的

![image-20200804154323362](calico%20CNI%20for%20k8s.assets/image-20200804154323362.png)

没有calico-system命名空间

![image-20200804154704004](calico%20CNI%20for%20k8s.assets/image-20200804154704004.png)

等下，下面这个note

气死我了

啊啊啊

#### teardown again

哭了

#### init one more time

呵呵，这次我学乖了

wget https://docs.projectcalico.org/manifests/custom-resources.yaml

sudo vim custom-resources.yaml

ip pool给爷改了

```
kubectl create -f custom-resources.yaml
```

![image-20200804160119853](calico%20CNI%20for%20k8s.assets/image-20200804160119853.png)

嘿嘿

开心

### 继续安装

```
kubectl taint nodes --all node-role.kubernetes.io/master-
```

![image-20200804160224011](calico%20CNI%20for%20k8s.assets/image-20200804160224011.png)

![image-20200804160232815](calico%20CNI%20for%20k8s.assets/image-20200804160232815.png)

### 验证安装成功

```
kubectl get nodes -o wide
```

![image-20200804160305048](calico%20CNI%20for%20k8s.assets/image-20200804160305048.png)

![image-20200804160257419](calico%20CNI%20for%20k8s.assets/image-20200804160257419.png)

成了宝贝们

![image-20200804160728208](calico%20CNI%20for%20k8s.assets/image-20200804160728208.png)

太棒啦