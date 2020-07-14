# Report on Api and AutoTest Tool

## 时间

2020年7月14日 16点11分

## 负责

kony

## 内容

### - Swagger - 由Controller、Model类自动生成接口文档，做简单测试

#### 芋道 Spring Boot API 接口文档 Swagger 入门

https://mp.weixin.qq.com/s?__biz=MzUzMTA2NTU2Ng==&mid=2247489633&idx=2&sn=1f8264c905f0b586dee4b66c2c738f84&chksm=fa4967d0cd3eeec6ee657dab89d1275ce8b937ebaabb4030ef6c1016533a17039244bdc16f5c&mpshare=1&scene=23&srcid=&sharer_sharetime=1588997202639&sharer_shareid=94d57563d95d90af139479e3745fcada#rd

![image-20200714161431173](Report%20on%20Api%20and%20AutoTest.assets/image-20200714161431173.png)

加几个注解，就可以设定这个接口的数据类型

![image-20200714161537115](Report%20on%20Api%20and%20AutoTest.assets/image-20200714161537115.png)

然后就可以由实际controller生成接口

具体的每个注解的意思：

![image-20200714161618185](Report%20on%20Api%20and%20AutoTest.assets/image-20200714161618185.png)

![image-20200714161629048](Report%20on%20Api%20and%20AutoTest.assets/image-20200714161629048.png)



![image-20200714161640358](Report%20on%20Api%20and%20AutoTest.assets/image-20200714161640358.png)

![image-20200714161646086](Report%20on%20Api%20and%20AutoTest.assets/image-20200714161646086.png)

![image-20200714161658090](Report%20on%20Api%20and%20AutoTest.assets/image-20200714161658090.png)







##### 用于Model类的注解

![image-20200714161817668](Report%20on%20Api%20and%20AutoTest.assets/image-20200714161817668.png)

![image-20200714161834659](Report%20on%20Api%20and%20AutoTest.assets/image-20200714161834659.png)

##### 接口测试：

![image-20200714161854871](Report%20on%20Api%20and%20AutoTest.assets/image-20200714161854871.png)

![image-20200714161909090](Report%20on%20Api%20and%20AutoTest.assets/image-20200714161909090.png)

[timeLog]16点20分

### - YApi - 需要登陆，可以自动化生成测试数据

#### YApi - 简单不清晰实践

https://www.jianshu.com/p/57b9ce6851cd

#### YApi - 官网

https://hellosean1025.github.io/yapi/index.html

![image-20200714162123295](Report%20on%20Api%20and%20AutoTest.assets/image-20200714162123295.png)

要开启服务，要登陆系统

#### 官方文档：自动化测试

[https://hellosean1025.github.io/yapi/documents/case.html#%e7%ac%ac%e4%b8%80%e6%ad%a5%ef%bc%8c%e6%b5%8b%e8%af%95%e9%9b%86%e5%90%88](https://hellosean1025.github.io/yapi/documents/case.html#第一步，测试集合)

![image-20200714162229887](Report%20on%20Api%20and%20AutoTest.assets/image-20200714162229887.png)

![image-20200714162421247](Report%20on%20Api%20and%20AutoTest.assets/image-20200714162421247.png)

![image-20200714162446282](Report%20on%20Api%20and%20AutoTest.assets/image-20200714162446282.png)

![img](https://hellosean1025.github.io/yapi/documents/images/usage/modal-postman.gif)

![image-20200714162506947](Report%20on%20Api%20and%20AutoTest.assets/image-20200714162506947.png)



![img](https://hellosean1025.github.io/yapi/documents/images/usage/case-list.gif)

![img](https://hellosean1025.github.io/yapi/documents/images/usage/modal-postman.gif)

![image-20200714162530747](Report%20on%20Api%20and%20AutoTest.assets/image-20200714162530747.png)

除了用Mock，还可以用json-schema来设定数据格式

#### 什么是Mock？

#### mock测试

[https://baike.baidu.com/item/mock%E6%B5%8B%E8%AF%95](https://baike.baidu.com/item/mock测试)

mock测试就是在[测试过程](https://baike.baidu.com/item/测试过程/10921538)中，对于某些不容易构造或者不容易获取的对象，用一个虚拟的对象来创建以便测试的测试方法。

#### mock.js上的数据模板定义

http://mockjs.com/examples.html

#### 