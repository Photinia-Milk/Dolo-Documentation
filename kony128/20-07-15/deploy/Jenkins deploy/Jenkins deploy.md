# Jenkins deploy

## 时间

10点24分

## 负责

kony

## 内容

### 如何在Ubuntu 16.04上安装Jenkins

https://www.jianshu.com/p/845f267aec52

```shell
sudo apt-get install openjdk-8-jdk
#sudo apt-get install openjdk-7-jdk  早些系统可以安装
#首先，我们将存储库密钥添加到系统。
wget -q -O - https://pkg.jenkins.io/debian/jenkins-ci.org.key | sudo apt-key add -
#添加密钥后，系统将返回OK 。 接下来，我们将Debian包存储库地址附加到服务器的sources.list ：
echo deb http://pkg.jenkins.io/debian-stable binary/ | sudo tee /etc/apt/sources.list.d/jenkins.list
#当这两个都到位时，我们将运行update ，以便apt-get将使用新的存储库：
sudo apt-get update
#最后，我们将安装Jenkins及其依赖项，包括Java：
sudo apt-get install jenkins
#以上安装不成功的朋友，是由于Jenkins官网的校验码出现了问题。
#指定早期版本可以安装。
#sudo apt-get install jenkins=2.138.1

```