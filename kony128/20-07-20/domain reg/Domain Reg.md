# Domain Reg

## 时间

13点49分

## 负责

kony

## 内容

### dolo.club

去Godaddy注册了一个域名，好弄https和CDN

![image-20200720135124404](Domain%20Reg.assets/image-20200720135124404.png)

域名就叫dolo.club吧

总花费14元，到时候给他们说一声

![image-20200720135357160](Domain%20Reg.assets/image-20200720135357160.png)

目前的解析是这个样子

我们调整一下

#### 最新godaddy配置域名解析(2018.04)

https://www.jianshu.com/p/9aaab848f9e8

解析还是不能换成腾讯云和阿里云，因为不是国内的备案域名会暂停解析，保留这个DNS解析服务器即可

[timelog]13点55分

#### GoDaddy最新域名解析教程（2020年中文版）

https://www.ldhost.cn/jc/do/1242.html

这个就可以了

![image-20200720135754355](Domain%20Reg.assets/image-20200720135754355.png)

哈哈，还好以前有东西可以参照

![image-20200720135914187](Domain%20Reg.assets/image-20200720135914187.png)

我们直接去CloudFlare就可以辣

![image-20200720140034175](Domain%20Reg.assets/image-20200720140034175.png)

这是老域名的代理配置，参照它弄就可以了

### Amazon Route 53

https://aws.amazon.com/cn/getting-started/hands-on/get-a-domain/

才发现用Amazon Route 53可以弄一个域名

好吧，老老实实朝着这个干吧

[timelog]14点48分

![image-20200720144912347](Domain%20Reg.assets/image-20200720144912347.png)

弄了一个Elastic 静态IP地址

![image-20200720145021807](Domain%20Reg.assets/image-20200720145021807.png)

连接一下

![image-20200720145121851](Domain%20Reg.assets/image-20200720145121851.png)

ok，弹性IP是有效的，

接下来去注册域名（Route 53）

![](Domain%20Reg.assets/image-20200720145214808.png)

嗯哼！？！？，AWS EDUCATE账号没有权限做这个操作，不能注册域名！

哈哈哈哈哈，那看来Godaddy注册域名，CloudFlare加速没白做嘛！

呼呼！





https://forums.aws.amazon.com/message.jspa?messageID=852799

![image-20200720145515345](Domain%20Reg.assets/image-20200720145515345.png)

此贴终结

[timelog]14点55分