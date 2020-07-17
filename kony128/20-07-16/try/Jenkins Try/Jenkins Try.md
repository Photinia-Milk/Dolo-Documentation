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

#### 尝试8：Maven构建尝试 - 取消

不用Jenkins Maven了，改用Pipeline

#### 尝试9：post steps - 取消

不用Jenkins Maven了，改用Pipeline

[timelog]21点16分

#### 尝试10：Pipeline 自动拉取 Github代码

##### How to Add Github Webhooks to a Jenkins Pipeline

https://medium.com/better-programming/how-too-add-github-webhook-to-a-jenkins-pipeline-62b0be84e006

刚才去做了一下后端debug，然后按照上文做了部署

![image-20200716220654380](Jenkins%20Try.assets/image-20200716220654380.png)

正好测试一下流水线有没有问题

结果发现push了过后没有触发

是什么原因呢？

排查了一下，是因为我想弄一个参数化配置，本来用tag的，默认版本为latest，结果它只能默认拉取latest，那就很烦

我们把参数化配置取消掉

![image-20200716222050732](Jenkins%20Try.assets/image-20200716222050732.png)

再做一下push

[timelog]22点08分

成功触发流水线

![image-20200716220833756](Jenkins%20Try.assets/image-20200716220833756.png)

但是一直在build，没有停，手动停止

![image-20200716221653619](Jenkins%20Try.assets/image-20200716221653619.png)

不知道为啥，仔细看看执行流程

Start卡了半天

![image-20200716221859110](Jenkins%20Try.assets/image-20200716221859110.png)



![image-20200716221926792](Jenkins%20Try.assets/image-20200716221926792.png)

看一看到底是啥问题

发现用户凭据是空的，赶紧填一下

![image-20200716222127466](Jenkins%20Try.assets/image-20200716222127466.png)

应该是需要用户凭证

![image-20200716221803375](Jenkins%20Try.assets/image-20200716221803375.png)

![image-20200716222158453](Jenkins%20Try.assets/image-20200716222158453.png)

等待运行

还是失败，尝试找原因，没找到，期间给兴宇解决问题，service 单元测试居然写到现在都没写好

[timelog]22点40分

我实在裂开了，为什么我不去看jenkins官方文档呢？

#### 官网：Pipeline

https://www.jenkins.io/doc/book/pipeline/

[timelog]23点39分

![image-20200716233917184](Jenkins%20Try.assets/image-20200716233917184.png)

2  ：  archiveArtifacts捕获与包含模式（** / target / *.jar）匹配而构建的文件，并将其保存到Jenkins主文件中，以供以后检索。

![image-20200716234544116](Jenkins%20Try.assets/image-20200716234544116.png)

Credential的示例，在这里居然用的AWS

![image-20200716234604057](Jenkins%20Try.assets/image-20200716234604057.png)

![image-20200716234612563](Jenkins%20Try.assets/image-20200716234612563.png)

![image-20200716234645854](Jenkins%20Try.assets/image-20200716234645854.png)

blabla看到最后，官网还是啥都没教，或者教的版本不对，裂开了

换一个

#### Continuous Integration with Spring Boot, Maven, GitHub, and Jenkins

https://www.geekyhacker.com/2017/10/12/continuous-integration-with-spring-boot-maven-github-and-jenkins/

