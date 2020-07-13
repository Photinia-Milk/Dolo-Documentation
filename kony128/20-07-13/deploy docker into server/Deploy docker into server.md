# Deploy docker into server

## 时间

2020年7月13日17点56分

## 负责

kony

## Ubuntu Docker 安装

https://www.runoob.com/docker/ubuntu-docker-install.html

国内镜像：curl -fsSL https://get.docker.com | bash -s docker --mirror Aliyun

国外：curl -fsSL https://get.docker.com | bash -s docker

## 取消服务器上的Docker用户组权限

![image-20200713180038695](Deploy%20docker%20into%20server.assets/image-20200713180038695.png)![image-20200713180042578](Deploy%20docker%20into%20server.assets/image-20200713180042578.png)

## 服务器上登录Docker，做配置

![image-20200713180137573](Deploy%20docker%20into%20server.assets/image-20200713180137573.png)

docker login配置即可

## 尝试DockerHub下载运行

成功！用ip地址能访问到它

![image-20200713180255692](Deploy%20docker%20into%20server.assets/image-20200713180255692.png)