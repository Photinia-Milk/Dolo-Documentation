# Docker 安装失败解决实验

## 时间

2020年7月13日 14点46分 

## 负责

龙泓杙

## 具体问题

报错，server连不上

![docker_server_wrong](Docker%20%E5%AE%89%E8%A3%85%E5%A4%B1%E8%B4%A5%E8%A7%A3%E5%86%B3%E5%AE%9E%E9%AA%8C.assets/docker_server_wrong.png)

尝试解决

## 解决链接路径

### [docker][win10]安装的坑

https://www.jianshu.com/p/09d53c822cf8

指向：

### github 无法打开的issue

https://github.com/docker/for-win/issues/1825

### [windows10下安装docker报错：error during connect](https://www.cnblogs.com/valu/p/11731294.html)

https://www.cnblogs.com/valu/p/11731294.html

尝试

```
cd "C:\Program Files\Docker\Docker"
./DockerCli.exe -SwitchDaemon
```

原文:

*Especially on windows machine when you see the above error after a docker update, try the above commands. It appears like the Docker Desktop UI may indicate that you are already using Linux Containers, but the update may have messed up that setting. Running the above commands will set to Linux Containers and there after you can work happily.*

*大概意思就是默认使用的是Linux Containers，使用这个命令后改为Windows Containers就好了。(不知道翻译的对不对，哈哈哈)*

尝试后windows有提示效果，但仍然无法连接

### Docker for windows 本地Docker连接失败

https://blog.csdn.net/jioujiou520/article/details/92385914

尝试

![close_all_connections](Docker%20%E5%AE%89%E8%A3%85%E5%A4%B1%E8%B4%A5%E8%A7%A3%E5%86%B3%E5%AE%9E%E9%AA%8C.assets/close_all_connections.png)

没有效果



### Github同样的报错issue，出问题

https://github.com/docker/for-win/issues/1825

尝试

net start com.docker.service

没有权限

请求权限，发现已经启动了

![already](Docker%20%E5%AE%89%E8%A3%85%E5%A4%B1%E8%B4%A5%E8%A7%A3%E5%86%B3%E5%AE%9E%E9%AA%8C.assets/already.png)

尝试后面的帖子回复，使用这个

```
docker-machine ls
docker-machine env HypervDefault
FOR /f "tokens=*" %i IN ('docker-machine env HypervDefault') DO @%i
```

但是docker-machine没有，去下载

> if [[ ! -d "$HOME/bin" ]]; then mkdir -p "$HOME/bin"; fi && \
>
> > curl -L https://github.com/docker/machine/releases/download/v0.16.2/docker-machine-Windows-x86_64.exe > "$HOME/bin/docker-machine.exe" && \
> >
> > chmod +x "$HOME/bin/docker-machine.exe"

![install_docker_machine](Docker%20%E5%AE%89%E8%A3%85%E5%A4%B1%E8%B4%A5%E8%A7%A3%E5%86%B3%E5%AE%9E%E9%AA%8C.assets/install_docker_machine.png)

再尝试运行，还是失败，没有default

![no_default](Docker%20%E5%AE%89%E8%A3%85%E5%A4%B1%E8%B4%A5%E8%A7%A3%E5%86%B3%E5%AE%9E%E9%AA%8C.assets/no_default.png)

根据网上教程新建一个，却无法新建，需要virtual box，去安装

![no_virtual_box](Docker%20%E5%AE%89%E8%A3%85%E5%A4%B1%E8%B4%A5%E8%A7%A3%E5%86%B3%E5%AE%9E%E9%AA%8C.assets/no_virtual_box.png)

猛然发觉，有VMWare 和Virtual Box会导致Hyper-V安装时出现问题

尝试卸载VMWare和Virtual Box，重新开始进行尝试安装

**[timelog] 15点41分**

​		工作流改变，重装Hyper-V，重装 Docker Desktop

​		检查BIOS和Hyper-V是否启动成功

### 		**联想电脑BIOS开启虚拟化的方法**

​			http://iknow.lenovo.com.cn/detail/dc_125894.html

![image-20200713154328716](Docker%20%E5%AE%89%E8%A3%85%E5%A4%B1%E8%B4%A5%E8%A7%A3%E5%86%B3%E5%AE%9E%E9%AA%8C.assets/image-20200713154328716.png)

​		网上有教程显示，安装时去掉windows 相关feature的安装，可以正常启用

![image-20200713154642708](Docker%20%E5%AE%89%E8%A3%85%E5%A4%B1%E8%B4%A5%E8%A7%A3%E5%86%B3%E5%AE%9E%E9%AA%8C.assets/image-20200713154642708.png)

​		重新安装一遍，看看效果

![image-20200713154809389](Docker%20%E5%AE%89%E8%A3%85%E5%A4%B1%E8%B4%A5%E8%A7%A3%E5%86%B3%E5%AE%9E%E9%AA%8C.assets/image-20200713154809389.png)

![image-20200713154816697](Docker%20%E5%AE%89%E8%A3%85%E5%A4%B1%E8%B4%A5%E8%A7%A3%E5%86%B3%E5%AE%9E%E9%AA%8C.assets/image-20200713154816697.png)

​		还是这两个提示，看看这次有没有问题

![image-20200713154847092](Docker%20%E5%AE%89%E8%A3%85%E5%A4%B1%E8%B4%A5%E8%A7%A3%E5%86%B3%E5%AE%9E%E9%AA%8C.assets/image-20200713154847092.png)

现在docker server可以正常启用了





## 问题到底出在哪?

我同时做了两个更改，才成功完成：

1. 删除VMWare，删除Virtual Box
2. 取消Enable Hyper-V Windows Features

目前而言感觉两个都是比较关键的修改，大家按照这两个作配置

**[timelog] 15点52分**

## 最终效果：跑demo成功



![docker](Docker%20%E5%AE%89%E8%A3%85%E5%A4%B1%E8%B4%A5%E8%A7%A3%E5%86%B3%E5%AE%9E%E9%AA%8C.assets/docker.png)**[timelog] 16点05分**

## 其他工作：教组内成员安装docker

![image-20200713181402610](Docker%20%E5%AE%89%E8%A3%85%E5%A4%B1%E8%B4%A5%E8%A7%A3%E5%86%B3%E5%AE%9E%E9%AA%8C.assets/image-20200713181402610.png)![image-20200713181408947](Docker%20%E5%AE%89%E8%A3%85%E5%A4%B1%E8%B4%A5%E8%A7%A3%E5%86%B3%E5%AE%9E%E9%AA%8C.assets/image-20200713181408947.png)







