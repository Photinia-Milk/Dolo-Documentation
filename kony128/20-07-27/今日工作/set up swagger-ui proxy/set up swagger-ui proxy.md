# set up swagger-ui proxy

## 时间

## 内容

### Swagger在远程库访问不到

swagger ui 因为反向代理proxy_pass的原因给了提示

![image-20200727165856147](set%20up%20swagger-ui%20proxy.assets/image-20200727165856147.png)

嗯。。怎么办好呢

---

![image-20200727170240440](set%20up%20swagger-ui%20proxy.assets/image-20200727170240440.png)

首先，本地跑是没问题的

------

找一下google

https://github.com/springfox/springfox/issues/1996

这个帖子比较helpful

![image-20200727170303133](set%20up%20swagger-ui%20proxy.assets/image-20200727170303133.png)

应该是nginx反向代理的原因

-----

### 啥是X-FORWARDED-FOR

https://www.jianshu.com/p/15f3498a7fad

是代理的时候层层的IP套娃

https://blog.csdn.net/u010900754/article/details/81160268

配置看看这个

![image-20200727170753351](set%20up%20swagger-ui%20proxy.assets/image-20200727170753351.png)

改成了这个样子

![image-20200727170854589](set%20up%20swagger-ui%20proxy.assets/image-20200727170854589.png)

重启nginx

![image-20200727170903721](set%20up%20swagger-ui%20proxy.assets/image-20200727170903721.png)

这次怎么直接报错了。。

![image-20200727171030827](set%20up%20swagger-ui%20proxy.assets/image-20200727171030827.png)

嗯，出了问题，curl访问本地localhost也没东西了

![image-20200727171304698](set%20up%20swagger-ui%20proxy.assets/image-20200727171304698.png)

刚才输错了

把nginx配置给还原了，还是连不上

看来nginx崩掉了

得想想办法



![image-20200727171712055](set%20up%20swagger-ui%20proxy.assets/image-20200727171712055.png)



![image-20200727171823641](set%20up%20swagger-ui%20proxy.assets/image-20200727171823641.png)

等等，好像是因为少了个斜杠

加上

![image-20200727172010405](set%20up%20swagger-ui%20proxy.assets/image-20200727172010405.png)



![image-20200727171938345](set%20up%20swagger-ui%20proxy.assets/image-20200727171938345.png)给爷恢复了

但还是不得行

很烦，看来不是X-Forwarded-For的原因

---------

### 换一种Google方式

![image-20200727172119063](set%20up%20swagger-ui%20proxy.assets/image-20200727172119063.png)

https://stackoverflow.com/questions/58696358/spring-boot-swagger2-behind-nginx-proxy-swagger-resources-not-found

还真被我找到了

没有人回答。。

https://github.com/springfox/springfox/issues/2240

这个好像也是reverse proxy

还是没有解决

https://serverfault.com/questions/804298/nginx-reverse-proxy-without-base-url

这个呢！？

![image-20200727172903467](set%20up%20swagger-ui%20proxy.assets/image-20200727172903467.png)

信你的邪，试一下

![image-20200727172935955](set%20up%20swagger-ui%20proxy.assets/image-20200727172935955.png)

还是不得行

------------

![image-20200727173106986](set%20up%20swagger-ui%20proxy.assets/image-20200727173106986.png)

如果使用localhost:8081，就会报这种错

应该是安全组策略的问题

我服了

---------

试试看二楼的邪

![image-20200727173537767](set%20up%20swagger-ui%20proxy.assets/image-20200727173537767.png)

![image-20200727173620777](set%20up%20swagger-ui%20proxy.assets/image-20200727173620777.png)

还是不行

-----

https://gitter.im/springfox/springfox?at=5a9193a4a2194eb80da9e627

又一个nginx相关的帖子

没有啥相关建议

[timelog]17点39分

一个小时了，终止这个探索

