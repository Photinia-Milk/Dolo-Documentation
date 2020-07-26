# Report On Mybatis Plus Join

## 时间

16点31分

## 负责

kony

## 内容

### 最简单的 MyBatis Plus 的多表联接、分页查询实现方法

https://blog.csdn.net/larger5/article/details/82082819



#### 写了个VO对象

注意这个VO对象，没有很多Student和Date的属性

![image-20200714163336375](Report%20On%20Mybatis%20Plus%20Join.assets/image-20200714163336375.png)

#### 什么是VO？

##### 浅析VO、DTO、DO、PO的概念、区别和用处

https://blog.csdn.net/zjrbiancheng/article/details/6253232

![image-20200714163446214](Report%20On%20Mybatis%20Plus%20Join.assets/image-20200714163446214.png)

**VO 用于视图层而非持久层（PO）**

![image-20200714163343343](Report%20On%20Mybatis%20Plus%20Join.assets/image-20200714163343343.png)

**作者采用注解版，官方采用配置版**

[timelog]16点35分

#### 作者的配置

![image-20200714163551918](Report%20On%20Mybatis%20Plus%20Join.assets/image-20200714163551918.png)

#### 作者的rest controller

注意两个参数，page和size写在路径里

![image-20200714163645241](Report%20On%20Mybatis%20Plus%20Join.assets/image-20200714163645241.png)

#### Mybatis Plus的基操

https://blog.csdn.net/larger5/article/details/81273287

##### MybatisPlus在单表CRUD上很好用

![image-20200714164002382](Report%20On%20Mybatis%20Plus%20Join.assets/image-20200714164002382.png)

16点40分