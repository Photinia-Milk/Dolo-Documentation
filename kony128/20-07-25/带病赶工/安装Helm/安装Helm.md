# 安装Helm

## 时间

22点17分

## 内容

### Kubernetes

#### kubectl 

https://kubernetes.io/docs/tasks/tools/install-kubectl/

![image-20200725223038980](%E5%AE%89%E8%A3%85Helm.assets/image-20200725223038980.png)

wait！nope！

#### kubeadm + kubelet + kubectl 

https://kubernetes.io/docs/setup/production-environment/tools/kubeadm/install-kubeadm/#letting-iptables-see-bridged-traffic

#### 注意事项：

kubernetes1.8之后弃用了--replicas

### Helm

https://helm.sh/docs/

https://helm.sh/docs/intro/install/

![image-20200725221915994](%E5%AE%89%E8%A3%85Helm.assets/image-20200725221915994.png)

![image-20200725222015178](%E5%AE%89%E8%A3%85Helm.assets/image-20200725222015178.png)

nice！

### Tiller

helm init --upgrade --tiller-image

不识别!

等等。。

https://www.sohu.com/a/317271638_612370

![image-20200725222314077](%E5%AE%89%E8%A3%85Helm.assets/image-20200725222314077.png)

我裂开了

![image-20200725222343419](%E5%AE%89%E8%A3%85Helm.assets/image-20200725222343419.png)

我服了

看来我们可以暂时先不管它

到时候去helm官方文档看看helm2和helm3的区别处理上该怎么做就好了

