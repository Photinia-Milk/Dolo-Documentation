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
#使用systemctl我们将启动Jenkins：
sudo systemctl start jenkins
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
#默认情况下，Jenkins在端口8080上运行，因此我们将使用ufw打开该端口：
#如果你搞成了8090，那这里也要改
sudo ufw allow 8080
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
#重启前，可能需要先reload配置，但配置又需要密码，我们先改掉密码
#改密码
sudo passwd ubuntu
#我改成了最高级+新部署
#reload配置，好吧，我发现不加sudo会需要输入密码，无所谓了
sudo systemctl daemon-reload
#重启服务
sudo systemctl restart jenkins
#记得在防火墙那里启动8090端口
```