# helper

## 时间

10点13分

## 内容

[timelog]记录时已完成

### 帮助金珂解决数据库连接不上的问题：

发现是改密码后navicat连接没改密码，solve!

### 帮助兴宇解决oauth2.0返回错误网页的问题：

发现是请求头少了个prefix，

当时是解决了

但后来兴宇告诉我又有问题，很烦

现在情况是暂时没有解决





嗯。。又有了新进展

下午兴宇告诉我，postman和直接在浏览器里没问题

但是IDEA发请求却出问题了

返回的是一个人的主页

我当时就想，会不会是DNS解析错误了，

或者是请求头没发对

于是让他规范请求头试试

结果折腾了很久，还是不行

让他关VPN试试，结果发现关了VPN就会返回错误信息

开了VPN就会返回正确信息

我一下子悟了

让他看一下windows下的host

果然，api.github.com的host被改掉了

让他删掉，现在恢复正常了

哈。。