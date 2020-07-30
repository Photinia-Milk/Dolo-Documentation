# AWS instance broken

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

sudo docker run -p 8080:8080 -p 50000:50000 --name jenkins -u 0 -v /data/jenkins:/var/jenkins_home jenkins 

c5d0fa222590473c900e29b84b599e2d

https://stackoverflow.com/questions/44065827/jenkins-wrong-volume-permissions