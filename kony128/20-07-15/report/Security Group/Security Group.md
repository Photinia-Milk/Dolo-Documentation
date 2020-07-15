# Security Group

## 时间

13点59分

## 负责

kony

## 内容

安全组策略会导致服务器访问不上！

### [AWS EC2中部署Apache服务器（LAMP）](https://www.cnblogs.com/dige1993/p/6395925.html)

https://www.cnblogs.com/dige1993/p/6395925.html

　　在安装apache服务器并启动httpd服务后，接下来需要测试该服务器能否被正常访问。在浏览器中输入前面提到的**Public DNS**，应该就可以看到Apache测试页面了。但一般情况下，只做到这一步的话，还看不到测试页面，因为还需设置下**安全组规则**。在EC2控制面板切到安全组页面

![img](https://images2015.cnblogs.com/blog/649725/201702/649725-20170214215529863-2134694630.png)

然后在右边选中MyFirstInstance实例后，右键单击它，在菜单中选择“编辑入站规则”：

![img](https://images2015.cnblogs.com/blog/649725/201702/649725-20170214215717144-242074204.png)

在“编辑入站规则”中添加下面这样一条规则：

![img](https://images2015.cnblogs.com/blog/649725/201702/649725-20170214215854894-27045378.png)

它的含义是允许任何地方通过HTTP协议80端口访问本实例，也就是通过网页方式访问本实例。这个时候基本上就大功告成了，在浏览器输入Public DNS或者公有IP就能看到Apache测试页了。



### 我们要怎么做？

配置8090端口访问Jenkins！