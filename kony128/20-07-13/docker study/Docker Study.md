# Docker Study

## 时间

2020年7月13日 16点16分

## 负责

kony

## 流程

### 跑了docker例子，学了下基本部署命令

http://localhost/tutorial/our-application/

![image-20200713161436211](Docker%20Study.assets/image-20200713161436211.png)

-d 后台运行

-p 主机端口80：容器端口80

docker/getting-started 镜像名称

![image-20200713161526308](Docker%20Study.assets/image-20200713161526308.png)

d和p还可以搞融合

### 现在我尝试把一个demo项目打包起来

![image-20200713161827712](Docker%20Study.assets/image-20200713161827712.png)

用Dockerfile作容器部署



FROM node:12-alpine 

WORKDIR /app 

COPY . . 

RUN yarn install --production 

CMD ["node", "src/index.js"]



先创建文件，小心它没有后缀

然后命令：

docker build -t getting-started .

**注意最后要有一个点，代表当前目录**



![image-20200713162129657](Docker%20Study.assets/image-20200713162129657.png)

#### 整个部署流程

1. ​	写Dockerfile
   1. 看看需要什么镜像来做build，比如上面的FROM node:12-alpine，docker会去下
   2. 下好后，复制我们的应用，用yarn来做以来安装，CMD这里是直接指定了默认的命令来跑
2. 写命令行
   1.   -t 标签标志打包后的镜像名称
   2.   .  参数给docker build用，告诉这个程序去哪找Dockerfile
3. 打包完成后在docker上运行
   1. 回到之前的  docker run -dp 3000:3000 getting-started   这种docker run指令



### 打包学会了，如果要更新项目，怎么办

![image-20200713162940785](Docker%20Study.assets/image-20200713162940785.png)

重新docker build再docker run，会出错，要替换老容器

![image-20200713163003616](Docker%20Study.assets/image-20200713163003616.png)



![image-20200713163056508](Docker%20Study.assets/image-20200713163056508.png)

用docker ps看ID

用docker stop [ID]停止容器

用docker rm [ID]删除容器

stop和rm作结合：docker rm -f <the-container-id>

![Docker Dashboard - removing a container](http://localhost/tutorial/updating-our-app/dashboard-removing-container.png)

可以用dashbord直接做



### 基础单机功能我学会了，到底怎么部署？

##### 用Docker Hub，建造Repo

![image-20200713163212035](Docker%20Study.assets/image-20200713163212035.png)

##### 把镜像Push上去

![image-20200713163438042](Docker%20Study.assets/image-20200713163438042.png)



docker push docker/getting-started （会失败

docker image ls （啥没有

docker login -u YOUR-USER-NAME （先登录

docker tag getting-started YOUR-USER-NAME/getting-started （加标签

docker push YOUR-USER-NAME/getting-started （push上去



实践：

![image-20200713164450053](Docker%20Study.assets/image-20200713164450053.png)

登录报错



##### 解决

###### 【已经解决】 | docker的Get https://registry-1.docker.io/v2/: net/http: request canceled 报错

https://blog.csdn.net/qq_40709110/article/details/104740600



**https://hub.daocloud.io**用手动指定仓库的方式就行，比如

docker pull https://hub.daocloud.io/mysql



#### 在新的实例（服务器）上跑你的docker![image-20200713163558293](Docker%20Study.assets/image-20200713163558293.png)

[Play with Docker](http://play-with-docker.com/)



