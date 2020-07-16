# Jenkins Try

## 时间

08点42分

## 负责

kony

## 内容

### 资料

#### Docker+K8S+Jenkins项目实战视频教程（经典）

https://www.bilibili.com/video/BV1mt411u7An?p=31

![image-20200716085316097](Jenkins%20Try.assets/image-20200716085316097.png)

还是和我之前想的一样，打包到docker上再做部署

![image-20200716085346401](Jenkins%20Try.assets/image-20200716085346401.png)

最后应该有这样的效果

![image-20200716085402259](Jenkins%20Try.assets/image-20200716085402259.png)

这是一个项目的例子

#### Jenkins系列(四)----Jenkins+Github持续集成

https://blog.csdn.net/u011781521/article/details/77914344

#### Jenkins+Github+Docker实现自动化构建运行Jar

https://zhuanlan.zhihu.com/p/32871379

#### centos 7 安装maven 详细过程

https://blog.csdn.net/xiaolinlangzi/article/details/83056698

#### Java和Maven在AWS EC2(Linux)上的安装

https://blog.csdn.net/baixue11270526/article/details/102563954

#### Error: Could not create the Java Virtual Machine

https://blog.csdn.net/weixin_41558061/article/details/79878890

#### [Centos7配置JAVA_HOME](https://www.cnblogs.com/lenmom/p/9494877.html)

https://www.cnblogs.com/lenmom/p/9494877.html

#### [Centos命令行报bash:.....:command not found的解决办法](https://www.cnblogs.com/therunningfish/p/6106553.html)

https://www.cnblogs.com/therunningfish/p/6106553.html

### 那我到底要做什么？

1. 弄一下GitHub token - 完成 - 09点44分
2. 配置一下自动化拉取
3. 搞一个私有docker仓库
4. 写一些脚本
   1. 预先写好Dockerfile
   2. 自动拉取
   3. 自动配置环境
   4. 自动测试
   5. 自动打包Docker
   6. Push Docker镜像
   7. 替换本机容器 / 新配置本机容器
      1. 问题：这个要自己做还是很麻烦，可不可以自动化抓取Docker Hub变化，实现真正的持续交付（CD）呢

### 具体尝试内容

#### 尝试1：弄git参数化构建-失败

失败，不知道为何没有效果

![image-20200716094527165](Jenkins%20Try.assets/image-20200716094527165.png)

#### 尝试2：自动化获取GitHub仓库内容配置-成功

![image-20200716094417070](Jenkins%20Try.assets/image-20200716094417070.png)

成功

[timelog]09点44分

#### 尝试3：配置Github WebHook - 成功

![image-20200716094711151](Jenkins%20Try.assets/image-20200716094711151.png)

![image-20200716094719363](Jenkins%20Try.assets/image-20200716094719363.png)

![image-20200716094723923](Jenkins%20Try.assets/image-20200716094723923.png)

![image-20200716094727355](Jenkins%20Try.assets/image-20200716094727355.png)

[timelog]09点47分

#### 尝试4：新建一个Maven Build - 成功

![image-20200716095343651](Jenkins%20Try.assets/image-20200716095343651.png)

Git 配置出错，不知为何

![image-20200716095801072](Jenkins%20Try.assets/image-20200716095801072.png)

![image-20200716095923239](Jenkins%20Try.assets/image-20200716095923239.png)

还需要知道Maven工具的位置，好吧

![image-20200716095917099](Jenkins%20Try.assets/image-20200716095917099.png)

#### 尝试5：安装与配置Maven - 成功

/usr/share/apache-maven

![image-20200716101139826](Jenkins%20Try.assets/image-20200716101139826.png)

https://blog.csdn.net/baixue11270526/article/details/102563954

#### 尝试6：配置JAVA - 成功

[timelog]10点11分

![image-20200716101304503](Jenkins%20Try.assets/image-20200716101304503.png)

差点裂开

https://blog.csdn.net/weixin_41558061/article/details/79878890

https://www.cnblogs.com/lenmom/p/9494877.html

https://www.cnblogs.com/therunningfish/p/6106553.html

https://www.cnblogs.com/panzhaohui/p/6306675.html

![image-20200716101924838](Jenkins%20Try.assets/image-20200716101924838.png)

/usr/lib/jvm/java-1.8.0-openjdk-1.8.0.252.b09-2.amzn2.0.1.x86_64/jre/bin/java

[timelog]10点17分

突然之间整个命令行用不了了

还好网上有解决方案

![image-20200716102811513](Jenkins%20Try.assets/image-20200716102811513.png)

是因为这里配错了

[timelog]10点28分

![image-20200716103105571](Jenkins%20Try.assets/image-20200716103105571.png)

怎么配都不对，最后还用这个成功了

[timelog]10点32分

#### 尝试7：配置git工具 - 取消

好像没报错，就不做这个了

#### 尝试8：Maven构建尝试



#### 尝试9：post steps