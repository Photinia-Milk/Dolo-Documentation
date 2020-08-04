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

