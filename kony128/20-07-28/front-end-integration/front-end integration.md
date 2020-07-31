# front-end integration

## 过程

![image-20200729005948401](front-end%20integration.assets/image-20200729005948401.png)





![image-20200729010011433](front-end%20integration.assets/image-20200729010011433.png)



因为外部ssh证书拿不进去，不好做隔离，就采用内部nginx挂载外部的策略吧

![image-20200729020349450](front-end%20integration.assets/image-20200729020349450.png)





嗯？服务器装的nodejs和npm好像被我搞掉了

因为默认的是旧版的

现在重装一下

```
wget https://nodejs.org/dist/v12.18.3/node-v12.18.3-linux-x64.tar.xz

tar -xvf node-v12.18.3-linux-x64.tar.xz

mv node-v12.18.3-linux-x64 node

sudo vim /etc/profile

source /etc/profile
```





![image-20200729021828916](front-end%20integration.assets/image-20200729021828916.png)



![image-20200729022111071](front-end%20integration.assets/image-20200729022111071.png)





![image-20200729022247304](front-end%20integration.assets/image-20200729022247304.png)

jenkins 没有环境变量，找不到npm

https://blog.csdn.net/u011296165/article/details/96110294

照这个试试看

![image-20200729022418560](front-end%20integration.assets/image-20200729022418560.png)

![image-20200729022422778](front-end%20integration.assets/image-20200729022422778.png)

嗯，不行

查了好几个方法，都说这样改

仔细看看，似乎这个里面没有刚才提到的npm包安装地址

我稍微改一下

![image-20200729023155962](front-end%20integration.assets/image-20200729023155962.png)

在尾巴上加上这个东西

还是不行，加上个/bin试试看

还是不行

我裂开了，应该是node

![image-20200729023627784](front-end%20integration.assets/image-20200729023627784.png)

再次检查，应该没问题了

还是不行

https://stackoverflow.com/questions/45914038/jenkins-unable-to-find-npm

这个上面说可以装插件

![image-20200729024213299](front-end%20integration.assets/image-20200729024213299.png)

还是不行

![image-20200729024441506](front-end%20integration.assets/image-20200729024441506.png)



![image-20200729024520318](front-end%20integration.assets/image-20200729024520318.png)

试试看这种方法

不得行。。

很烦，我想想怎么办

突然想到，用插件



![image-20200729025007529](front-end%20integration.assets/image-20200729025007529.png)

等等，有报错

我看看咋回事

https://wiki.jenkins.io/display/JENKINS/Jenkins+says+my+reverse+proxy+setup+is+broken

原来是X-forward没设置好

![image-20200729025138225](front-end%20integration.assets/image-20200729025138225.png)

![image-20200729025146035](front-end%20integration.assets/image-20200729025146035.png)

试试看

还是不行

https://wiki.jenkins.io/display/JENKINS/Running+Jenkins+behind+Nginx

再加上这个试试看

![image-20200729025442689](front-end%20integration.assets/image-20200729025442689.png)

![image-20200729025649672](front-end%20integration.assets/image-20200729025649672.png)

好像ok了



![image-20200729025938270](front-end%20integration.assets/image-20200729025938270.png)

这样配置一下试试



![image-20200729030023052](front-end%20integration.assets/image-20200729030023052.png)

还是不行，好象这样配置只能认识nodejs项目



还是不行

服了

https://blog.csdn.net/huodoubi/article/details/56845306

看了不少文章，这个比较靠谱

试试看

![image-20200729030615822](front-end%20integration.assets/image-20200729030615822.png)



![image-20200729030740532](front-end%20integration.assets/image-20200729030740532.png)

语法不对，还不能这样写



https://blog.csdn.net/yule09/article/details/86537652

![image-20200729030918559](front-end%20integration.assets/image-20200729030918559.png)

好像可以这样写

![image-20200729031002354](front-end%20integration.assets/image-20200729031002354.png)



![image-20200729031312861](front-end%20integration.assets/image-20200729031312861.png)

source 成功了，还是不认识npm

![image-20200729031446331](front-end%20integration.assets/image-20200729031446331.png)

到底是为什么我这里都正常啊。。

​	

![image-20200729031534568](front-end%20integration.assets/image-20200729031534568.png)

气死我了，用绝对路径试试看



![image-20200729031724515](front-end%20integration.assets/image-20200729031724515.png)

我终于知道为什么了，一切的元凶都在这

https://blog.csdn.net/wuyepiaoxue789/article/details/106908128



![image-20200729031942811](front-end%20integration.assets/image-20200729031942811.png)

改一下



不行

我再试试把/home/ec2-user/node的权限改一下



![image-20200729032149565](front-end%20integration.assets/image-20200729032149565.png)

https://blog.csdn.net/daxiang12092205/article/details/52125558



![image-20200729032333374](front-end%20integration.assets/image-20200729032333374.png)



https://blog.csdn.net/zhiaicq_r/article/details/79228981

sudo chmod -R 777 node/



![image-20200729032615810](front-end%20integration.assets/image-20200729032615810.png)

我服了，还是permission denied



我尝试把npm转移到usr/local里

![image-20200729035421425](front-end%20integration.assets/image-20200729035421425.png)

奇怪了，明明是能识别的

然而就是不认识npm install

那试试这个呢

![image-20200729035455772](front-end%20integration.assets/image-20200729035455772.png)



![image-20200729035707460](front-end%20integration.assets/image-20200729035707460.png)

看来jenkins的path有一点问题

嗯。。尝试一下改一改



![image-20200729035839299](front-end%20integration.assets/image-20200729035839299.png)

![image-20200729035852113](front-end%20integration.assets/image-20200729035852113.png)

helm是安装在/usr/local/bin里的，看来jenkins 也没识别出来，

而docker在/usr/bin里，怪不得jenkins识别出来了

![image-20200729040032919](front-end%20integration.assets/image-20200729040032919.png)

source后echo path是正常的

但再执行一次sh脚本，path就又不正常了

在npm install之前source /etc/profile试试

这回却成功了



## 总结

1. 权限问题，jenkins没有ec2-user用户的权限
2. PATH变量问题，导致读不到