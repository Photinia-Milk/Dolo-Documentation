# 后端mock再次实验

## 时间

16点57分

## 负责

kony

## 内容

出大事了，后端mock不上导致整个测试耦合度很高

只许成功，不许失败！

### Spring Boot单元测试（Mock）

https://www.cnblogs.com/a8457013/p/7825087.html

![image-20200724165757092](%E5%90%8E%E7%AB%AFmock%E5%86%8D%E6%AC%A1%E5%AE%9E%E9%AA%8C.assets/image-20200724165757092.png)

测试一下新写的service

[timelog]17点32分

service 还是 mock失败了!

以下是对比图，我们写的完全一模一样

（黑框的是我们写的）

![image-20200724173305808](%E5%90%8E%E7%AB%AFmock%E5%86%8D%E6%AC%A1%E5%AE%9E%E9%AA%8C.assets/image-20200724173305808.png)

![image-20200724173458928](%E5%90%8E%E7%AB%AFmock%E5%86%8D%E6%AC%A1%E5%AE%9E%E9%AA%8C.assets/image-20200724173458928.png)

------

![image-20200724173506819](%E5%90%8E%E7%AB%AFmock%E5%86%8D%E6%AC%A1%E5%AE%9E%E9%AA%8C.assets/image-20200724173506819.png)



![image-20200724173538523](%E5%90%8E%E7%AB%AFmock%E5%86%8D%E6%AC%A1%E5%AE%9E%E9%AA%8C.assets/image-20200724173538523.png)

------

![image-20200724173547724](%E5%90%8E%E7%AB%AFmock%E5%86%8D%E6%AC%A1%E5%AE%9E%E9%AA%8C.assets/image-20200724173547724.png)

![image-20200724173555511](%E5%90%8E%E7%AB%AFmock%E5%86%8D%E6%AC%A1%E5%AE%9E%E9%AA%8C.assets/image-20200724173555511.png)

---------

![image-20200724173609848](%E5%90%8E%E7%AB%AFmock%E5%86%8D%E6%AC%A1%E5%AE%9E%E9%AA%8C.assets/image-20200724173609848.png)

![image-20200724173624234](%E5%90%8E%E7%AB%AFmock%E5%86%8D%E6%AC%A1%E5%AE%9E%E9%AA%8C.assets/image-20200724173624234.png)

--------

真的尽力了，这还能怎么办

查了很久很久的google和StackOverflow

[timelog]18点00分

[timelog]18点05分

认真尝试了这一篇，我们mock的就是一个interface，暴毙

https://stackoverflow.com/questions/55257091/mockbean-doesnt-work-in-spring-boot-integration-test

![image-20200724180503555](%E5%90%8E%E7%AB%AFmock%E5%86%8D%E6%AC%A1%E5%AE%9E%E9%AA%8C.assets/image-20200724180503555.png)



[timelog]18点27分

在国内论坛上找了很久很久，

在其中一篇文章中学了

https://www.cnblogs.com/zhangjianbin/p/10083319.html

![image-20200724182819213](%E5%90%8E%E7%AB%AFmock%E5%86%8D%E6%AC%A1%E5%AE%9E%E9%AA%8C.assets/image-20200724182819213.png)

如此的组合

但有啥用？！都试过了，没用，mockBean还是mock不上



按照这个教程重新引入了依赖，

https://springframework.guru/mocking-unit-tests-mockito/

在maven导入依赖后，执行测试

![image-20200724190300838](%E5%90%8E%E7%AB%AFmock%E5%86%8D%E6%AC%A1%E5%AE%9E%E9%AA%8C.assets/image-20200724190300838.png)

结果直接编译报错了



版本回退也不顶用

服了，应该是依赖的问题，

我去把依赖删了

ok，现在可以了



仔细看了一下，这篇教程给的是spring用的，不是spring boot

裂开了



[timelog]19点03分

---------

[timelog]19点06分

看到一篇博客，好像是与MockSpy和MockBean的进一步分析与对比

我发现，MockBean是给代码压根还没写的时候用的

而且，MockBean如果Mock成功了，调用没有when thenReturn规定的方法时，应该是会报错的，我试试看



调用方法，findUserAuthByUserName，这个方法没被定义过

![image-20200724191044773](%E5%90%8E%E7%AB%AFmock%E5%86%8D%E6%AC%A1%E5%AE%9E%E9%AA%8C.assets/image-20200724191044773.png)

![image-20200724191025621](%E5%90%8E%E7%AB%AFmock%E5%86%8D%E6%AC%A1%E5%AE%9E%E9%AA%8C.assets/image-20200724191025621.png)

![image-20200724191010611](%E5%90%8E%E7%AB%AFmock%E5%86%8D%E6%AC%A1%E5%AE%9E%E9%AA%8C.assets/image-20200724191010611.png)

等等！这不是mock上了吗

nope..

不对的，控制变量成Autowired

![image-20200724191252368](%E5%90%8E%E7%AB%AFmock%E5%86%8D%E6%AC%A1%E5%AE%9E%E9%AA%8C.assets/image-20200724191252368.png)

还是报错了

淦，原来是方法没实现吗

![image-20200724191308820](%E5%90%8E%E7%AB%AFmock%E5%86%8D%E6%AC%A1%E5%AE%9E%E9%AA%8C.assets/image-20200724191308820.png)

还真是

哇

![image-20200724191325392](%E5%90%8E%E7%AB%AFmock%E5%86%8D%E6%AC%A1%E5%AE%9E%E9%AA%8C.assets/image-20200724191325392.png)

给稍微实现一下

![image-20200724191344004](%E5%90%8E%E7%AB%AFmock%E5%86%8D%E6%AC%A1%E5%AE%9E%E9%AA%8C.assets/image-20200724191344004.png)

好的，不报错了

试试看mockbean

![image-20200724191429140](%E5%90%8E%E7%AB%AFmock%E5%86%8D%E6%AC%A1%E5%AE%9E%E9%AA%8C.assets/image-20200724191429140.png)

发现MockBean并没有报错，

这意味着findUserAuthByUserName被执行了，

这个UserAuthMapper执行没有被MockBean定义的方法，意味着UserAuthMapper并没有被MockBean挂载上



那试试看SpyBean



![image-20200724191659709](%E5%90%8E%E7%AB%AFmock%E5%86%8D%E6%AC%A1%E5%AE%9E%E9%AA%8C.assets/image-20200724191659709.png)

出问题了，报错了

怎么回事呢

![image-20200724192501925](%E5%90%8E%E7%AB%AFmock%E5%86%8D%E6%AC%A1%E5%AE%9E%E9%AA%8C.assets/image-20200724192501925.png)

看最长的那条红色

UserAuthMapper并没有被实例化

![image-20200724192522895](%E5%90%8E%E7%AB%AFmock%E5%86%8D%E6%AC%A1%E5%AE%9E%E9%AA%8C.assets/image-20200724192522895.png)

上面还有很长的红字

看来这个实例化是在使用时现注入的实际依赖，怪不得Mock不上

等等，他们部署不上，我去看看到底怎么回事

