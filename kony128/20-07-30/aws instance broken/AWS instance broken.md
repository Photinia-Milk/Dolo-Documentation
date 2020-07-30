# AWS instance broken

## 时间

07点22分

## 内容

一大早起来发现AWS instance崩了

赶紧重新配置一个

https://blog.csdn.net/u014069688/article/details/100532774

https://www.rodolfo.io/2019/05/how-to-install-docker-on-amazon-linux-2/

![image-20200730083256365](AWS%20instance%20broken.assets/image-20200730083256365.png)

无论哪种方法装都会报错

坏了



https://blog.csdn.net/weixin_45489155/article/details/105343062

不管用



![image-20200730083613999](AWS%20instance%20broken.assets/image-20200730083613999.png)

换了一台instance，可以了，但是docker报错

https://www.cnblogs.com/lieweidu/p/12050053.html

还是不行

换上sudo，一切解决



https://www.cnblogs.com/pwc1996/p/5425234.html



用docker装jenkins

https://hub.docker.com/_/jenkins

sudo docker run -d -p 8080:8080 -p 50000:50000 --name jenkins -u 0 -v /data/jenkins:/var/jenkins_home jenkins 

https://stackoverflow.com/questions/44065827/jenkins-wrong-volume-permissions



https://blog.csdn.net/qq_21963133/article/details/88786007



安装java8，maven，git

https://blog.csdn.net/baixue11270526/article/details/102563954



装一下MySQL（本来想用镜像装，但是考虑到单机MySQL镜像挂掉那就全完了，那就先用MySQL，等到变成分布式数据库了再用MySQL）

https://blog.csdn.net/iteye_17336/article/details/82652665

改密码

https://blog.csdn.net/th_num/article/details/71402801

https://blog.csdn.net/Zoctan/article/details/79443030

https://blog.csdn.net/weixin_30919429/article/details/96139103?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-3.edu_weight&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-3.edu_weight

sudo su

mysql -root

use mysql;

update user set password=PASSWORD("root") where User="root";

flush privileges;

exit;



在docker里的jenkins出现了问题，我怎么这么蠢！docker里的jenkins怎么可能用得了宿主机的软件

这样自动更新数据库啥的都干不了

烦死，



https://www.cnblogs.com/stulzq/p/9291237.html

第一种方法rpm + yum安装jenkins，配置权限

f22938b354364caaa5fc278afadc1f99



![image-20200730102511441](AWS%20instance%20broken.assets/image-20200730102511441.png)

为什么这一次就没有出错，比上一次顺利很多

气死我了

行，至少这次没错

先安装npm nodejs

拿到最新版下载地址

https://nodejs.org/en/download/current/

wget https://nodejs.org/dist/v14.7.0/node-v14.7.0-linux-x64.tar.xz

tar xvJf node-v14.7.0-linux-x64.tar.xz

cd node-v14.7.0-linux-x64

sudo cp bin /usr/ -r

sudo cp include /usr/ -r

sudo cp lib /usr/ -r
sudo cp share /usr/ -r

node -v

npm -v

安装方式

https://www.runoob.com/nodejs/nodejs-install-setup.html

之前npm装在了usr/local/bin下，现在装在了usr/bin下，问题解决



https://developer.aliyun.com/article/699966

https://www.jianshu.com/p/d5114a2a2052

https://comtechies.com/how-to-install-and-configure-nginx-on-amazon-ec2-rhel-and-ubuntu-instances.html

👆有用

sudo amazon-linux-extras install epel

sudo yum update -y

sudo yum install nginx -y

![image-20200730121806411](AWS%20instance%20broken.assets/image-20200730121806411.png)

装nginx



配置TLS证书

装certbot

sudo certbot --nginx -d dolo.club -d www.dolo.club -d jenkins.dolo.club -d api.dolo.club

![image-20200730123108959](AWS%20instance%20broken.assets/image-20200730123108959.png)

忘了弄域名解析了



https://wiki.jenkins.io/display/JENKINS/Jenkins+says+my+reverse+proxy+setup+is+broken

https://wiki.jenkins.io/display/JENKINS/Running+Jenkins+behind+Nginx

对于https转http，还要X-Forwarded-Proto



解决reverse_proxy_is_borken

```
  ``# Fix the “It appears that your reverse proxy set up is broken" error.
  ``proxy_redirect   http:``//localhost:8080 $scheme://example.com;
```

没有解决

应该是https转http时出的错



配置nginx



![image-20200730132212225](AWS%20instance%20broken.assets/image-20200730132212225.png)

![image-20200730132221536](AWS%20instance%20broken.assets/image-20200730132221536.png)

![image-20200730132233981](AWS%20instance%20broken.assets/image-20200730132233981.png)

问题不大

[timelog]13点27分

问题全部解决

可见高耦合度的系统可用性有多差，真的得赶紧转k8s