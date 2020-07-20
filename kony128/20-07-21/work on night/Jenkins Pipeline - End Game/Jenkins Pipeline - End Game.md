# Jenkins Pipeline - End Game

## 时间

02点07分

## 负责

kony

## 内容

### youtube地址

![image-20200721021747247](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721021747247.png)

我们这次试试用SCM文件来做自动化构建

![image-20200721022000685](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721022000685.png)

先试试写做基础班的Jenkinsfile

push一下

[timelog]02点20分

![image-20200721022418806](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721022418806.png)

的确是有效果了，但是compile报错

![image-20200721022440593](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721022440593.png)

原因是单元测试时出错了，目标服务器上没有安装Mysql

尝试十分钟装上Mysql

### Amazon EC2安装mysql多实例并配置主从复制 - 垃圾

https://yq.aliyun.com/articles/667786



sudo yum install mysql mysql-server mysql-libs -y

sudo service mysqld start

![image-20200721022719329](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721022719329.png)

启动失败

### Failed to start mysqld.service: Unit not found - 可行

https://blog.csdn.net/miaodichiyou/article/details/99289160

![image-20200721022801804](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721022801804.png)

原来是CentOS里Mysql收费，服了

### 数据库:MySQL和MariaDB的JDBC连接

https://blog.csdn.net/yang13563758128/article/details/90575439

以防万一，log一下，好像mysql的连接可以不用变

### 安装mariadb

sudo yum install -y mariadb-server

sudo systemctl start mariadb.service

sudo systemctl enable mariadb.service  # 添加到开机启动

sudo mysql_secure_installation # 安全设置等等

配置好了

![image-20200721023258966](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721023258966.png)

这一段。。。emmmm

应该是在mariadb控制台里的

![image-20200721023403374](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721023403374.png)

很好，使用mysql界面是能登录进来的

### 新建course数据库

![image-20200721023538504](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721023538504.png)

![image-20200721023553953](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721023553953.png)

试试看能不能直接连上

### 尝试直接连接，失败

![image-20200721023848999](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721023848999.png)

BadSqlGrammer，在查询数据库数据时出错了，我裂开了

那把数据库初始化一下，放进几条测试数据

![image-20200721024026294](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721024026294.png)

在本机上尝试构建，是成功的，那可能是没有测试数据的原因

看看是没有什么字段和测试数据

![image-20200721024231089](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721024231089.png)

看来的确是数据库没建起来的原因，不多bb，建库

### 尝试用Jenkins自动化初始化测试数据库

![image-20200721024928682](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721024928682.png)

![image-20200721024920177](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721024920177.png)

我想这样写的，结果不得行，那行⑧

#### MySQL命令执行sql文件的两种方法

https://www.cnblogs.com/qmfsun/p/4838032.html

网上找到一个命令行解决方案

![image-20200721024954041](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721024954041.png)

试试看version 2

![image-20200721025056250](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721025056250.png)

改成了这个样

![image-20200721025225921](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721025225921.png)

没有找到文件！但是好像这个方法可行，我们好像更进一步了

想想看怎么办

![image-20200721025308220](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721025308220.png)

改成这样试试看

还是不行，找不到目录

![image-20200721025603824](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721025603824.png)

那可不可以放在一个stage里呢！？

还是不行

我们深究一下

![image-20200721025935779](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721025935779.png)

结构文件目前应该是放在

/var/lib/jenkins/workspace/Dolo-Dev-Back-End

下面，但具体是哪一个，搞不清楚

![image-20200721030022004](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721030022004.png)

不过可以看到执行sh脚本的时候是在@tmp文件夹下，那git的相应目录呢。。我找找看

![image-20200721030226048](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721030226048.png)

检查一下，不在Dolo-Dev-Back-End与@2中，但tmp中啥也没有

我裂开了

#### Jenkins 系列： （六） Jenkins 构建workspace

https://blog.csdn.net/huaqiangli/article/details/79267422

试试看找不找得到这个pipeline的workspace

![image-20200721030725250](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721030725250.png)

我的确是找到了这个workspace，但是里面只是存的流水线信息和log，具体的github代码应该是放在之前的tmp文件夹里的，一被拉取就被删掉了，这下麻烦了

![image-20200721031833235](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721031833235.png)

尝试了一下ls，发现并没有course.sql

![image-20200721031844254](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721031844254.png)

远程库是有的啊，明明还有Dockerfile，嗯？！

尝试把course.sql放在src里

先等等！

发现一个问题

Jenkins的ls和cd不能持久化，是因为不在一个step里吗

尝试一下

![image-20200721032842690](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721032842690.png)

![image-20200721032938978](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721032938978.png)

这样写呢?

不得行

![image-20200721033114505](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721033114505.png)

那这样呢?

还是不行

![image-20200721033202369](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721033202369.png)

那这样!

![image-20200721033213564](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721033213564.png)

全炸了

我选择死亡，不要用Jenkins自动化配置测试数据库了，我放弃

等等！！！

我发现问题在哪了！

![image-20200721035110194](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721035110194.png)

它pull的是master分支

我就说怎么会有README.md文件，我裂开了

![image-20200721035206203](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721035206203.png)

原来如此

### 发现问题：无法指定特定分支，老是pull master分支，出大问题

![image-20200721035755397](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721035755397.png)

哈哈哈！git插件无论怎么搞都不对，那我就手动配置分支呗！谁怕谁！

![image-20200721040139038](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721040139038.png)

看看今晚的战果，属实舒服

现在有测试schema咯！yeah！	

### 测试数据schema无法导入

由于外键约束无法drop table

我真的想捶死王兴宇

不知道用Navicat自动导出结构和数据吗？！

气死我了

我自己来

![image-20200721040523832](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721040523832.png)





![image-20200721040742040](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721040742040.png)

老子自己导出来的

![image-20200721040931758](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721040931758.png)

Navicat导出来的也会有错，我服了，不认识这个collation

#### mysql导入报错 [Err] 1273 - Unknown collation: 'utf8mb4_0900_ai_ci' - 垃圾

https://blog.csdn.net/westworld2017163com/article/details/83150628

![image-20200721041120351](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721041120351.png)

淦

![image-20200721041135254](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721041135254.png)

行吧，算你狠

#### [ERR] 1273 - Unknown collation: 'utf8mb4_0900_ai_ci'

https://blog.csdn.net/yinzitun7947/article/details/89917611

还是不行

我去你大爷的mysql8.0和5.0区别，还有mariadb和mysql支持字符集不一样的坑

我自己加两句forein key check = 0吧

还是报错

![image-20200721042622568](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721042622568.png)

![image-20200721042632340](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721042632340.png)

mariadb居然大小写敏感！

我服了

把userAuth改成userauth

![image-20200721042712610](Jenkins%20Pipeline%20-%20End%20Game.assets/image-20200721042712610.png)

总算成功了。。。

