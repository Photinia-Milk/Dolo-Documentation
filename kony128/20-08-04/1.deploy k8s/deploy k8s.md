# deploy k8s

## 时间

08点46分

## 内容

### install kubeadmin

https://kubernetes.io/docs/setup/production-environment/tools/kubeadm/install-kubeadm/

#### 确保每个节点MAC地址不同

![image-20200804084646683](deploy%20k8s.assets/image-20200804084646683.png)

#### iptables流量可被桥接

### ![image-20200804084656383](deploy%20k8s.assets/image-20200804084656383.png)

![image-20200804084729422](deploy%20k8s.assets/image-20200804084729422.png)

无论怎么做，这个总是0

### ![image-20200804084915763](deploy%20k8s.assets/image-20200804084915763.png)

现在可以了

原来是要运行上面那个脚本

#### 添加当前用户到docker用户组

docker默认需要用sudo才能连上，可以把当前用户添加到docker用户组

sudo groupadd docker #添加docker用户组
sudo gpasswd -a $XXX docker #检测当前用户是否已经在docker用户组中，其中XXX为用户名。 # 不管用
sudo gpasswd -a $USER docker #将当前用户添加至docker用户组
newgrp docker #更新docker用户组

#### 安装kubeadm kubelet kubectl

![image-20200804092517184](deploy%20k8s.assets/image-20200804092517184.png)

![image-20200804092510193](deploy%20k8s.assets/image-20200804092510193.png)

#### 配置kubernetes

根据教程，如果使用docker，kubeadm不需要你额外配置cgroupDriver，

否则要重新配置

https://kubernetes.io/docs/reference/setup-tools/kubeadm/kubeadm-init/#config-file

以上是配置细节

![image-20200804092936547](deploy%20k8s.assets/image-20200804092936547.png)

配置完后要重启kubelet

### Creating a single control-plane cluster with kubeadm

https://kubernetes.io/docs/setup/production-environment/tools/kubeadm/create-cluster-kubeadm/

#### 初始化control-plane node

#### ![image-20200804093549123](deploy%20k8s.assets/image-20200804093549123.png)

```bash
kubeadm init <args>
```

#### 让control plane集群高可用的配置

![image-20200804093903356](deploy%20k8s.assets/image-20200804093903356.png)

#### 详细的kubeadm配置

![image-20200804094040904](deploy%20k8s.assets/image-20200804094040904.png)

kubeadm reference guide

https://kubernetes.io/docs/reference/setup-tools/kubeadm/kubeadm/

configuration file documentation

https://kubernetes.io/docs/reference/setup-tools/kubeadm/kubeadm-init/#config-file

##### 一些我认为比较有用的参数

![image-20200804094249789](deploy%20k8s.assets/image-20200804094249789.png)

![image-20200804094305070](deploy%20k8s.assets/image-20200804094305070.png)

![image-20200804094320873](deploy%20k8s.assets/image-20200804094320873.png)

![image-20200804094348512](deploy%20k8s.assets/image-20200804094348512.png)

![image-20200804094423930](deploy%20k8s.assets/image-20200804094423930.png)

#### 按推荐配置 - 失败

sudo kubeadm init --control-plane-endpoint cluster-endpoint

![image-20200804101102091](deploy%20k8s.assets/image-20200804101102091.png)

嗯。。看来有error

![image-20200804101154885](deploy%20k8s.assets/image-20200804101154885.png)

kublet是正常运行的，查看日志

![image-20200804101215454](deploy%20k8s.assets/image-20200804101215454.png)

master IP是错的

好吧

看来得手动配置conf文件了

#### 手动配置 - 失败

sudo kubeadm config print init-defaults --kubeconfig ClusterConfiguration > kubeadm.yml

导不出来

![image-20200804101950014](deploy%20k8s.assets/image-20200804101950014.png)

可能这是1.5版教程原因，现在用了1.8版，Google老是爱大改API

试试这个

```kotlin
sudo cat /etc/kubernetes/kubelet.conf
```

有用

sudo vim /etc/kubernetes/kubelet.conf

好吧，看来是cluster-endpoint不靠谱，应该填公网DNS才对，自己把自己坑了

完全复制粘贴教程不可取hhh

![image-20200804102440567](deploy%20k8s.assets/image-20200804102440567.png)

改一下

sudo kubeadm reset

sudo kubeadm init --control-plane-endpoint 54.91.201.*** : )

正确指令应该是这个才对

![image-20200804103712150](deploy%20k8s.assets/image-20200804103712150.png)

结果还是炸了

看看怎么回事

![image-20200804103740276](deploy%20k8s.assets/image-20200804103740276.png)

还是同样的问题

有四个镜像启动失败了

![image-20200804104650236](deploy%20k8s.assets/image-20200804104650236.png)

查看一下logs，发现有这些报错

![image-20200804105001749](deploy%20k8s.assets/image-20200804105001749.png)

还有一个容器也有这些报错

connection timeout。。等等。。

#### 发现失败原因 - 失败

我懂了!

该死的亚马逊安全组，给爷把6443端口给封了

待我重新搞一遍

![image-20200804105221135](deploy%20k8s.assets/image-20200804105221135.png)

明明这部分文档我看了的

但是当时没反应过来

不禁哭出菜鸡的泪水

sudo kubeadm reset -y

sudo kubeadm init --control-plane-endpoint 54.91.201.*** : )

![image-20200804110253783](deploy%20k8s.assets/image-20200804110253783.png)

不好意思，它还是炸了

![image-20200804110429509](deploy%20k8s.assets/image-20200804110429509.png)

这下的错误变成了connection refused

嗯。。。

![image-20200804110544576](deploy%20k8s.assets/image-20200804110544576.png)

还真是refuse掉了

![image-20200804110658029](deploy%20k8s.assets/image-20200804110658029.png)

在本机上尝试，出现了这些问题

嗯。。

https://github.com/rancher/rancher/issues/18786

看来有人和我遇到同样的问题

但是解决方案没有

![image-20200804112302935](deploy%20k8s.assets/image-20200804112302935.png)

发现运行kubectl version时，server会报authentication required

查了半天，未果

网上有人说关闭swap空间，我的确是关了的

嗯。。

#### 修改docker驱动

https://blog.csdn.net/m82_a1/article/details/97626309

![image-20200804103218310](deploy%20k8s.assets/image-20200804103218310.png)

发现有报warning

按照教程改了配置，重启了docker服务

sudo su root

vim /etc/docker/daemon.json

```
{
 	"exec-opts":["native.cgroupdriver=systemd"]
}
```

#重启docker

systemctl restart docker

systemctl status docker

exit

#### 真正的失败原因 - OTZ

我仔细回味了一下之前的失败

发现我ip配错了!我给配了个slave的ip

好吧

换成master的ip

sudo kubeadm init --control-plane-endpoint 52.23.65.*** : ) --pod-network-cidr=192.168.0.0/16

![image-20200804113104911](deploy%20k8s.assets/image-20200804113104911.png)

配置成功

淦

#### 让kubernetes可以被非root用户使用

mkdir -p $HOME/.kube

sudo cp -i /etc/kubernetes/admin.conf $HOME/.kube/config

sudo chown $(id -u):$(id -g) $HOME/.kube/config

#### 验证安装

![image-20200804113618393](deploy%20k8s.assets/image-20200804113618393.png)

哈，小样

### 把slave join进来

#### 提前配置

从节点也安装好kubectl kubelet kubeadm

做一些配置

sudo systemctl enable docker.service

改docker驱动



接着，从节点直接复制粘贴接入指令就行

注意要root权限

#### 报错

slave2 成功加入

![image-20200804114941483](deploy%20k8s.assets/image-20200804114941483.png)

但slave1不听话

![image-20200804115002173](deploy%20k8s.assets/image-20200804115002173.png)

嗯。。

#### 发现原因 - ORZ

通过cat master和slave2的这个crt，发现是一样的！

嗯？！这说明它们是自动配置的才对啊，难道我slave1配置不对！

果然。。。我输成了control-plane的指令，应该是作为worker节点才对

气死我了

#### 验证安装

![image-20200804115303182](deploy%20k8s.assets/image-20200804115303182.png)

嗯。。现在好了