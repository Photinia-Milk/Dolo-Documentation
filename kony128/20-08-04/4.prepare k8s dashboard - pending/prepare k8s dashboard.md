# prepare k8s dashboard

## 时间

16点10分

## 内容

没有面板的k8s是不舒服的

虽然kubectl很香，但是每一次都要get pods, get services, get deployments, get nodes啥的属实太麻烦了

安装个dashboard一次性搞定

### 直接开冲

最新版本支持1.18版本

yes

https://github.com/kubernetes/dashboard/releases

```
kubectl apply -f https://raw.githubusercontent.com/kubernetes/dashboard/v2.0.3/aio/deploy/recommended.yaml
```

不过有个问题

![image-20200804162229147](prepare%20k8s%20dashboard.assets/image-20200804162229147.png)

这个dashboard默认是配置到443端口的，没有指定type

说明官方希望你在内网访问

那问题来了，我就想试试看嘛！

想起之前改设置的恐怖经历，想死

按理说，要么配置个nodePort，要么搞个Ingress

要不要在targetPort下面加一行：nodePort: 30001 呢

嗯。。

其实要想上线，所有的服务必须正儿八经的配置一个Ingress

好麻烦。。这件事先搁置



### 别人的踩坑总结



#### 小心namespace

![image-20200804162627106](prepare%20k8s%20dashboard.assets/image-20200804162627106.png)

还有一点，这个service所在的命名空间是在

kubernetes-dashboard下面的

正儿八经查应该用kubectl get service -n kubernetes-dashboard

先写着，以后备用



#### 小心直连https的证书问题

![image-20200804162914121](prepare%20k8s%20dashboard.assets/image-20200804162914121.png)

别忘了这个是监听的https

如果直接访问是要配证书的

所以不能用chrome、edge等等浏览器访问

其实你配好证书，它就能访问，但你懒得配，那就要绕道

如果你没配证书，想直接访问，可以尝试firefox，可以“接受风险并继续”

hhh

#### 小心登录需要token认证

注意这是security -> RBAC -> ServiceAccount的知识点

![image-20200804163322002](prepare%20k8s%20dashboard.assets/image-20200804163322002.png)

嗯。。网上有个老哥直接写好了模板，但是是1.5版本的，到时候用来试试看



