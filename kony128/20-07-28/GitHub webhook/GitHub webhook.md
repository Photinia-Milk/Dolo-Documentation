# GitHub webhook

## 内容

![image-20200729050920293](GitHub%20webhook.assets/image-20200729050920293.png)

ok，let's try this out



faild

![image-20200729051154476](GitHub%20webhook.assets/image-20200729051154476.png)

the location is changed







![image-20200729051253054](GitHub%20webhook.assets/image-20200729051253054.png)

change into this





![image-20200729051348556](GitHub%20webhook.assets/image-20200729051348556.png)

果然失效了

重新配置一个



![image-20200729051604755](GitHub%20webhook.assets/image-20200729051604755.png)

前端项目也整一个



再试试看（v2

还是没效果

嗯。。检查了一下，配置都没问题

https://dzone.com/articles/adding-a-github-webhook-in-your-jenkins-pipeline

按照国外的教程走一遍，基本是一样的

看了一下也没有问题

怎么回事呢

![image-20200729052500922](GitHub%20webhook.assets/image-20200729052500922.png)

这个webhook的确是发送了，而且返回了200





构建没有启动？！

嗯。。会不会是credentials的原因



https://www.jianshu.com/p/5879816dea49

我的凭据是直接用的用户名密码



仔细上网查了一下，好像也可以的



嗯。。。



maven job的webhook是正确的啊

奇怪了



试试看配置向maven的项目靠齐

![image-20200729053010012](GitHub%20webhook.assets/image-20200729053010012.png)

先是把这个develop

改成*/develop



![image-20200729053042031](GitHub%20webhook.assets/image-20200729053042031.png)

二是在repo的末尾加上

.git



再试试看（v3

![image-20200729053250988](GitHub%20webhook.assets/image-20200729053250988.png)

这次webhook也发送成功了

![image-20200729053312260](GitHub%20webhook.assets/image-20200729053312260.png)

流水线还是没有任何变化

哇



![image-20200729053412972](GitHub%20webhook.assets/image-20200729053412972.png)

等等，发现一个问题

这里显示polling has not run yet

嗯。。



https://stackoverflow.com/questions/29346076/not-been-able-to-make-jenkins-trigger-a-build-when-changes-are-pushed-to-github

我看看这个

这个是因为localhost没有ngork



https://issues.jenkins-ci.org/browse/JENKINS-41377

这个比较符合我的问题



![image-20200729053747372](GitHub%20webhook.assets/image-20200729053747372.png)

哦，这哥们和我问题一样



![image-20200729053810936](GitHub%20webhook.assets/image-20200729053810936.png)

这哥们解决问题的方式真特别

看来只是pipeline 出问题，那么我们搞一个freestyle project吧！





![image-20200729054150906](GitHub%20webhook.assets/image-20200729054150906.png)

![image-20200729054156248](GitHub%20webhook.assets/image-20200729054156248.png)

![image-20200729054202583](GitHub%20webhook.assets/image-20200729054202583.png)

![image-20200729054209606](GitHub%20webhook.assets/image-20200729054209606.png)

啊哈，和maven项目保持一致

试试看（v4



![image-20200729054313929](GitHub%20webhook.assets/image-20200729054313929.png)

收到了！！！



![image-20200729054408357](GitHub%20webhook.assets/image-20200729054408357.png)

哈哈哈

这个项目被启动了



这下开心了



同样配置给后端

![image-20200729054538887](GitHub%20webhook.assets/image-20200729054538887.png)

试试看后端的（v1



![image-20200729054648258](GitHub%20webhook.assets/image-20200729054648258.png)

后端的webhook也解决了



![image-20200729054715717](GitHub%20webhook.assets/image-20200729054715717.png)

等等，后端是收得到webhook的





![image-20200729054942806](GitHub%20webhook.assets/image-20200729054942806.png)

两个就只有这个不一样



前端向后端配置对其，取消掉

再试试前端（v4 v5

![image-20200729055328431](GitHub%20webhook.assets/image-20200729055328431.png)

好吧，前端job无论怎么改，它就是8得行

那就不管它了







