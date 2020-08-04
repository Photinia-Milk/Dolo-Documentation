# k8s not healthy

## 时间

16点45分

## 内容

### 检查组件运行状态

使用命令

 kubectl get cs

![image-20200804164624796](k8s%20not%20healthy.assets/image-20200804164624796.png)

结果除了etcd以外都是not healthy?!

再次附上解释，防止自己忘了：

controller-manager - 自动化修复服务，可以在Node宕机后自动修复Node到之前的状态

scheduler - 调度服务，可以将Pod调度到Node

etcd-[编号] - 用于服务注册与发现，有编号意味着它可以分布式高可用地部署



https://www.cnblogs.com/yuhaohao/p/10197315.html

这老哥也是unhealthy，不过和我问题不太一样



用curl实践一下

![image-20200804164927965](k8s%20not%20healthy.assets/image-20200804164927965.png)

还真连不上



https://github.com/Azure/AKS/issues/311

这位老哥和我遇到了完全一样的问题

这个帖子指向这个解答

https://github.com/Azure/AKS/issues/173

嗯。。这是18年的问题，那时候的版本还是1.14

真的有用吗



![image-20200804165339946](k8s%20not%20healthy.assets/image-20200804165339946.png)

这个用户时不时就会自己恢复正常



![image-20200804165359783](k8s%20not%20healthy.assets/image-20200804165359783.png)

哦，这个用户也遇到了问题



![image-20200804165455627](k8s%20not%20healthy.assets/image-20200804165455627.png)

哈哈哈，跟了个贴



![image-20200804165508361](k8s%20not%20healthy.assets/image-20200804165508361.png)

这老哥给了些自我排查的方案帖子

嗯。。暂时没有找到解决方案

[timelog]16点55分

时间不早了，先吃饭，晚上再弄



### 检查localhost指向

![image-20200804165847486](k8s%20not%20healthy.assets/image-20200804165847486.png)

sudo vim /etc/hosts

在我的系统里，127.0.0.1是localhost没错

奇怪了



### 检查所有deployment、service、pod情况

![image-20200804170009159](k8s%20not%20healthy.assets/image-20200804170009159.png)

这是所有的deployment状态



![image-20200804170031831](k8s%20not%20healthy.assets/image-20200804170031831.png)

所有的service状态



![image-20200804170050920](k8s%20not%20healthy.assets/image-20200804170050920.png)

所有的pods状态



嗯。。怪了

看着没啥问题

### 检查端口号占用

Linux 查看端口占用情况

https://www.runoob.com/w3cnote/linux-check-port-usage.html



![image-20200804175148087](k8s%20not%20healthy.assets/image-20200804175148087.png)



lsof -i:10252

lsof -i:10251

嗯？！这些端口号没人用？！

![image-20200804170333535](k8s%20not%20healthy.assets/image-20200804170333535.png)



lsof -i:10250

10250有人占

![image-20200804175138428](k8s%20not%20healthy.assets/image-20200804175138428.png)



lsof -i:2379

lsof -i:2380

![image-20200804175243575](k8s%20not%20healthy.assets/image-20200804175243575.png)

都有人占

### 检查docker ps

![image-20200804175407887](k8s%20not%20healthy.assets/image-20200804175407887.png)

可见kube-scheduler和kube-controller-manager的容器是有在运行的

### 思考原因

1. 服务没有启动上 - **确定正确**
2. 服务启动上了，配置文件里写得不对（问题出在多次kubeadm reset后又kubeadm init） - 未知
3. etcd里记录的端口不对（之前kubeadm reset时有提示etcd关闭失败） - **不对**
4. 安装calico的姿势不对，导致失效 - 怀疑 - **证据1**
5. 是按照--control-plane-endpoint来启动的master，导致这个不是绑定在主机上 - 怀疑 - **证据2**
6. 我们可以忽略这个问题 - 怀疑 - **证据2** **证据3**

应该**不是**3

![image-20200804174609694](k8s%20not%20healthy.assets/image-20200804174609694.png)

因为kube-scheduler还有kube-controller-manager是默认跑在这两个端口的



![image-20200804174822495](k8s%20not%20healthy.assets/image-20200804174822495.png)

这个老哥提示我们，可以用

sudo systemctl status kube-controller-manager

查看 kube-controller-manager 

不过这是18年的教程，估计是1.15版本，不知道1.18会不会失效

![image-20200804174919485](k8s%20not%20healthy.assets/image-20200804174919485.png)

目前不清楚这是由于版本变化还是服务启动时小



**证据1**

https://github.com/kubernetes/kubernetes/issues/53424

这有帖子，说明是在安装完calico后重启docker服务，结果镜像kube-controller-manager就无法启动

嗯。。是安装calico的原因吗



**证据2**

https://github.com/poseidon/typhoon/issues/239

贴主和我遇到同样的问题

![image-20200804180502420](k8s%20not%20healthy.assets/image-20200804180502420.png)



**证据3**

https://github.com/kubernetes/enhancements/issues/553

component status被deprecate了

在接近1.10以后的版本里，因为安装方式的不同，controller manager 和scheduler可能会和api server安装在不同的pods里

而那段代码就会在这个时候失效

此外，这段代码queries etcd servers是脱出kubernetes的scope的，会返回正常值

我们可以在controller manager和scheduler上增加一个registration，虽然这样意义不大

在1.12-1.13左右，就计划将component status deprecate掉的，不知道为啥到1.18还没有提示

![image-20200804180716858](k8s%20not%20healthy.assets/image-20200804180716858.png)

### 尝试 - 看log

https://kubernetes.io/docs/tasks/debug-application-cluster/debug-cluster/

官网提示可以在这里看log

![image-20200804175933388](k8s%20not%20healthy.assets/image-20200804175933388.png)

![image-20200804180001491](k8s%20not%20healthy.assets/image-20200804180001491.png)

哦豁



![image-20200804180021314](k8s%20not%20healthy.assets/image-20200804180021314.png)

三个log每一个能看

### 总结

Google真的喜欢一个小版本一大改

当年angular就是这样被玩死的

目前不确定这个状态检查是否是真的是fatal faults

我已经放弃这个问题的pending了

先视为解决，若以后的k8s使用中出现问题，再寻求解决方案