# Jenkins deploy

## 时间

10点24分

## 负责

kony

## 内容

### 如何在Ubuntu 16.04上安装Jenkins

https://www.jianshu.com/p/845f267aec52

#### 第1步 - 安装Jenkins

```shell
# - kony - 安装前先升级的好
sudo apt-get update

sudo apt-get install openjdk-8-jdk -y
#sudo apt-get install openjdk-7-jdk  早些系统可以安装
#首先，我们将存储库密钥添加到系统。
wget -q -O - https://pkg.jenkins.io/debian/jenkins-ci.org.key | sudo apt-key add -
#添加密钥后，系统将返回OK 。 接下来，我们将Debian包存储库地址附加到服务器的sources.list ：
echo deb http://pkg.jenkins.io/debian-stable binary/ | sudo tee /etc/apt/sources.list.d/jenkins.list
#当这两个都到位时，我们将运行update ，以便apt-get将使用新的存储库：
sudo apt-get update -y
#最后，我们将安装Jenkins及其依赖项，包括Java：
sudo apt-get install jenkins -y
#以上安装不成功的朋友，是由于Jenkins官网的校验码出现了问题。
#指定早期版本可以安装。
#sudo apt-get install jenkins=2.138.1
```

#### 第2步 - 开始Jenkins

```shell
# - kony -注意Jenkins默认占领8080端口！
#在这一步之前最好看看下边的修改端口号！
#修改端口号前，最好用一下指令重新载入一下配置文件
#sudo systemctl daemon-reload
#使用systemctl我们将启动Jenkins：
sudo systemctl start jenkins
#-kony-中止指令
#sudo systemctl stop jenkins
#由于systemctl不显示输出，我们将使用其status命令来验证它是否成功启动：
sudo systemctl status jenkins
#如果一切顺利，输出的开始应显示服务处于活动状态，并配置为启动时启动：
● jenkins.service - LSB: Start Jenkins at boot time
  Loaded: loaded (/etc/init.d/jenkins; bad; vendor preset: enabled)
  Active:active (exited) since Thu 2017-04-20 16:51:13 UTC; 2min 7s ago
    Docs: man:systemd-sysv-generator(8)
#现在Jenkins正在运行，我们将调整防火墙规则，以便我们可以从网络浏览器到达Jenkins以完成初始设置。
```

#### 第3步 - 打开防火墙

```shell
#kony - 有的时候的ufw并没有启动，比如ufw status看见的是inactive，使用指令
#sudo ufw enable
#等等，会不会是防火墙导致现在的系统连不上？？？
#那我们给22端口也开放访问吧
#sudo ufw allow 22
#kony - 默认情况下，Jenkins在端口8080上运行，因此我们将使用ufw打开该端口：
#如果你搞成了8090，那这里也要改
sudo ufw allow 8080
#sudo ufw allow 8090
#检查UFW的状态可以看到新的规则。
sudo ufw status
#我们应该看到，从任何地方都可以访问8080端口：
Status: active

To                         Action      From
--                         ------      ----
OpenSSH                    ALLOW       Anywhere
8080                       ALLOW       Anywhere
OpenSSH (v6)               ALLOW       Anywhere (v6)
8080 (v6)                  ALLOW       Anywhere (v6)
#现在，Jenkins已安装，防火墙允许我们访问它，我们可以完成初始设置。
```

#### 第4步 - 设置Jenkins

-kony-

在EC2上，我们可以访问public DNS:端口号 来看看Jenkins的页面

![image-20200715145603750](Jenkins%20deploy.assets/image-20200715145603750.png)



要设置我们的安装，我们将使用服务器域名或IP地址访问Jenkins的默认端口`8080` ： `http:// ip_address_or_domain_name :8080`

我们应该看到“解锁Jenkins”屏幕，显示初始密码的位置

在终端窗口中，我们将使用`cat`命令显示密码：

```shell
sudo cat /var/lib/jenkins/secrets/initialAdminPassword
```

选择相应的plugin安装即可

#### 额外：修改端口号

默认端口是8080，有时候由于端口占用需要修改如下：

1，检查 /etc/init.d/jenkins 脚本，修改 do_start 函数的 check_tcp_port 命令，端口号从 8080 换成 8090：

2，修改 /etc/default/jenkins 文件，将端口 8080 改成 8090

3，重启jenkins

```shell
#-kony 方便你们使用的指令
sudo vim /etc/init.d/jenkins
sudo vim /etc/default/jenkins
#vim 界面可以用/8080查8080字符串在的位置
#kony - 重启前，可能需要先reload配置，但配置又需要密码，我们先改掉密码
#改密码的命令如下
#kony - 最好不要输入密码！不然启动实例弄不了！
#sudo passwd ubuntu
#我改成了最高级+新部署
#reload配置，好吧，我发现不加sudo会需要输入密码，无所谓了
sudo systemctl daemon-reload
#重启服务
sudo systemctl restart jenkins
#记得在防火墙那里启动8090端口
```

## All Finished！ 但是！

![image-20200715141306503](Jenkins%20deploy.assets/image-20200715141306503.png)

在这里又出问题了

尝试解决

### [Unable to Connect to Jenkins Server (Amazon Linux AMI)](https://stackoverflow.com/questions/41055669/unable-to-connect-to-jenkins-server-amazon-linux-ami)

https://stackoverflow.com/questions/41055669/unable-to-connect-to-jenkins-server-amazon-linux-ami![image-20200715141452254](Jenkins%20deploy.assets/image-20200715141452254.png)

![image-20200715141503947](Jenkins%20deploy.assets/image-20200715141503947.png)

好像可以尝试，但是我的服务器又连不上了

![image-20200715141528221](Jenkins%20deploy.assets/image-20200715141528221.png)

无奈重启。。

[timelog]14点18分

![image-20200715142028113](Jenkins%20deploy.assets/image-20200715142028113.png)

重启以后还是无法连接

多种方法尝试后，发现重启了过后public IP会更改，我裂开了

3.235.66.8

![image-20200715142159953](Jenkins%20deploy.assets/image-20200715142159953.png)

再次连接

![image-20200715142301294](Jenkins%20deploy.assets/image-20200715142301294.png)

[timelog]14点23分

还是连不上

但是IP确定是正确的

![image-20200715142252876](Jenkins%20deploy.assets/image-20200715142252876.png)

解决失败，尝试重新部署一遍

[timelog]14点31分

建立的新的实例

[timelog]14点37分

之前链接不上的原因预测

![image-20200715143715160](Jenkins%20deploy.assets/image-20200715143715160.png)

之前重启后的实例不像新的实例，在screenshot界面发现要输入密码

可能是我给用户ubuntu设立密码的原因，

不要设立密码了！

![image-20200715143903706](Jenkins%20deploy.assets/image-20200715143903706.png)

结果新实例发现用户密钥未注册，裂开了

那重新弄个密钥吧

换密钥还需要换实例，只好重新弄一个

![image-20200715144457496](Jenkins%20deploy.assets/image-20200715144457496.png)

登陆上了

[timelog]14点45分

重新配置

已经重新配置完，并更新了本文档

[timelog]14点57分

![image-20200715145720111](Jenkins%20deploy.assets/image-20200715145720111.png)

发现还是有问题

开始尝试StackOverflow上的解法

![image-20200715145930893](Jenkins%20deploy.assets/image-20200715145930893.png)



https://stackoverflow.com/questions/41055669/unable-to-connect-to-jenkins-server-amazon-linux-ami

curl http://127.0.0.1:8090

![image-20200715145909786](Jenkins%20deploy.assets/image-20200715145909786.png)

果然如其所言

`sudo usermod -a -G root jenkins`

这样改完还是报错

那试试

`sudo usermod -a -G ubuntu jenkins`

还是报错

执行第二部

`sudo vim /etc/sysconfig/jenkins`

设置：JENKINS_LISTEN_ADDRESS="0.0.0.0"

无法写入，因为文件不存在

`cd /etc`

`sudo mkdir sysconfig`

`cd sysconfig`

配置文件成功

试试看重启jenkins

还是不行

[timelog]15点06分

![image-20200715150701189](Jenkins%20deploy.assets/image-20200715150701189.png)

应该是文件转移了

重试

sudo vim /etc/default/jenkins

![image-20200715151216125](Jenkins%20deploy.assets/image-20200715151216125.png)

还是报错

[timelog]15点12分

![image-20200715151304563](Jenkins%20deploy.assets/image-20200715151304563.png)

尝试这个方法

`sudo vim /var/lib/jenkins/secrets/initialAdminPassword`

还是不行

那试试这个

#### [JENKINS Authentication Fails](https://stackoverflow.com/questions/25394445/jenkins-authentication-fails)

https://stackoverflow.com/questions/25394445/jenkins-authentication-fails

```
curl -X POST http://jenkins.rtcamp.com/job/Snapbox/buildWithParameters --user "username:password"
```

但这样要密码，username是ubuntu。。密码好像没有，如果设置密码

那试试看这个：

`curl -X POST http://jenkins.rtcamp.com/job/Snapbox/buildWithParameters --user "ubuntu"`

还是不行

![image-20200715160303575](Jenkins%20deploy.assets/image-20200715160303575.png)

不知不觉，已经变成了这个页面，尝试输入自己的用户名密码，提示错误

![image-20200715160330147](Jenkins%20deploy.assets/image-20200715160330147.png)

尝试去取回或修改自己的用户名密码，结果要用临时密码登录

结果失败

[timelog]15点40分

继续上网寻找解决方案

失败

再次尝试找回密码

![image-20200715160437092](Jenkins%20deploy.assets/image-20200715160437092.png)

居然登录进去了

![image-20200715160521509](Jenkins%20deploy.assets/image-20200715160521509.png)

修改密码为最高级

ok

![image-20200715160542181](Jenkins%20deploy.assets/image-20200715160542181.png)

结果还是在ECS登录失败

我裂开了

[timelog]16点04分

![image-20200715160707079](Jenkins%20deploy.assets/image-20200715160707079.png)

修改密码后，登录在localhost里是没问题的

但是在EC2上就不行

貌似是Jenkins用户名密码保存在本地

### Jenkins登录Invalid username or password

https://blog.csdn.net/zhangli0910/article/details/83860775

![image-20200715160814013](Jenkins%20deploy.assets/image-20200715160814013.png)

![image-20200715160936163](Jenkins%20deploy.assets/image-20200715160936163.png)

尝试一下，结果拒绝了

进入su要密码

EC2给的是public key做登录，哪有什么密码！我裂开了

没办法，再次重装实例

我找到了一篇官网教程，再来一次

https://d1.awsstatic.com/Projects/P5505030/aws-project_Jenkins-build-server.pdf

![image-20200715161524662](Jenkins%20deploy.assets/image-20200715161524662.png)

发现安全组策略需要有一个这个东西

我裂开了，再来一次

这一次使用AWS Linux系统，按照这个来做开发

又出现密码不对的情况了，那只能重来，新生成一个key value

麻烦死了

[timelog] 16点21分

sudo yum update –y

sudo wget -O /etc/yum.repos.d/jenkins.repo http://pkg.jenkins-ci.org/redhat/jenkins.repo

sudo rpm --import https://pkg.jenkins.io/redhat/jenkins.io.key

sudo yum install jenkins -y

sudo service jenkins start

**还是连接不上，原来用户名应该改成ec2-user，而非ubuntu，坑死我了**

![image-20200715163113174](Jenkins%20deploy.assets/image-20200715163113174.png)

连接上了，按照教程里给的方法，出错了

![image-20200715163158347](Jenkins%20deploy.assets/image-20200715163158347.png)

原来教程里压根就没提要装java

坑死了

### [yum方式安装java](https://www.cnblogs.com/kevingrace/p/5870814.html)

https://www.cnblogs.com/kevingrace/p/5870814.html

yum安装java8

#检查是否安装

yum list installed |grep java

#若有自带安装的JDK，应如下操作进行卸载CentOS系统自带Java环境

![image-20200715163423779](Jenkins%20deploy.assets/image-20200715163423779.png)

![image-20200715163437386](Jenkins%20deploy.assets/image-20200715163437386.png)

sudo yum -y install java-1.8.0-openjdk*

应该可以了

sudo systemctl start jenkins.service

sudo systemctl status jenkins.service

看看

![image-20200715163834754](Jenkins%20deploy.assets/image-20200715163834754.png)

OK

[timelog]16点38分

ec52f4e35cea4935bfe306bef3918b86



![image-20200715163959874](Jenkins%20deploy.assets/image-20200715163959874.png)

还是老问题

裂开了

[timelog]16点41分

![image-20200715164638027](Jenkins%20deploy.assets/image-20200715164638027.png)

再按照这个配置试试看

![image-20200715165044677](Jenkins%20deploy.assets/image-20200715165044677.png)

重启服务后居然直接进来了

赶紧改一下密码为最高级。。

[timelog] 16点51分