# apache benchmark安装尝试

### 尝试使用yum进行安装

最简单的apache benchmark安装方法是直接使用命令

```
sudo yum install httpd-tools 
```

尝试安装一下yum

![image-20200722093936319](apache%20benchmark%E5%AE%89%E8%A3%85%E5%B0%9D%E8%AF%95.assets/image-20200722093936319.png)





发现yum不支持windows环境，更支持os Linux环境

找一下有没有办法在windows下安装yum

搜索资料后发现windows安装yum需要搭载iso镜像，其实原理类似于安装虚拟机，暂时放弃这种方法改用官网安装apache benchmark

### 官网安装yum

![image-20200722102709782](apache%20benchmark%E5%AE%89%E8%A3%85%E5%B0%9D%E8%AF%95.assets/image-20200722102709782.png)

![image-20200722102751798](apache%20benchmark%E5%AE%89%E8%A3%85%E5%B0%9D%E8%AF%95.assets/image-20200722102751798.png)

选择下载一个稳定版本

![image-20200722103118203](apache%20benchmark%E5%AE%89%E8%A3%85%E5%B0%9D%E8%AF%95.assets/image-20200722103118203.png)

发现该版本也是支持Linux系统，综上Windows系统想使用apache benchmark不太方便，所以暂时更换工具。