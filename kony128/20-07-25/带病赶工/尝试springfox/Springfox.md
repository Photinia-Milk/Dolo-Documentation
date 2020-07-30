# Springfox

## 时间

18点26分

## 内容

### 3.0.0

官网

https://springfox.github.io/springfox/

官方docs：

https://springfox.github.io/springfox/docs/current/#getting-started

官方demo项目：

https://github.com/springfox/springfox-demos



UI是为了展示Springfox成果的

装一下，

既然都出到3.0了，咋个还叫这名hhh

![image-20200726182730353](Springfox.assets/image-20200726182730353.png)

好吧，官网说要用这个玩意

![image-20200726183540903](Springfox.assets/image-20200726183540903.png)



![image-20200726183854846](Springfox.assets/image-20200726183854846.png)

无论如何都解决不了这个问题，看来是依赖不完整，气死我了

尝试搜索google与bing，未果

使用IDEA自带的Find JAR on Web，未果

emmmmmm

去demo项目里看看

![image-20200726184551193](Springfox.assets/image-20200726184551193.png)

项目里明明没有嘛

照抄代码好了

![image-20200726184717345](Springfox.assets/image-20200726184717345.png)

好吧，我还是太天真了

![image-20200726184736883](Springfox.assets/image-20200726184736883.png)

它还是引入了这个不存在的依赖

我去查查看

查不到，未果

3.0.0流产

[timelog]18点49分

### 2.0.0

https://www.jianshu.com/p/ce7e247515f5

尝试照着这个做做看

回滚git

尝试导入新依赖

![image-20200726185343013](Springfox.assets/image-20200726185343013.png)

在这里弄一个配置类



![image-20200726185635509](Springfox.assets/image-20200726185635509.png)

用swagger托管一下

![image-20200726190030681](Springfox.assets/image-20200726190030681.png)

成功了

![image-20200726190038273](Springfox.assets/image-20200726190038273.png)

能够看到返回类型，请求类型等等，可以在这里填，然后做功能测试

![image-20200726190101390](Springfox.assets/image-20200726190101390.png)

这个是有返回类型的，那为什么上面的没有？因为做的不好

### 程序问题

有些controller返回了Map，这是怎么设计的！太不合理了，至少得返回一个封装好的JAVA类才是

佛了

跟他们通知一下

[timelog] 19点01分