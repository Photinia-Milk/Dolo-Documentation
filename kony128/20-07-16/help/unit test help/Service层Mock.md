# Service层Mock

## 时间

00点35分

## 负责

kony

## 内容

兴宇从下午一点的service层测试逻辑弄到了晚上十一点，整整十个小时，我裂开了

他没有用到mock，是自己手动插的数据

还老是持久化到数据库里，Transanctional不成功

然后就失败，很烦

我整个Mock吧

### Spring boot, mockito and junit – 单元测试service层

https://blog.csdn.net/chuiju1776/article/details/100671805

### [Mockito when(...).thenReturn(...)和doReturn(...).when(...)的区别](https://www.cnblogs.com/lanqi/p/7865163.html)

https://www.cnblogs.com/lanqi/p/7865163.html![image-20200717005038765](Service%E5%B1%82Mock.assets/image-20200717005038765.png)

我大概知道bug在哪了

改下代码

[timelog]00点50分

还是不行，语法报错

[timelog]00点57分

试试看另一个，应该是依赖注入没有mock的原因

### Spring依赖注入与mock

https://www.jianshu.com/p/c68ee5d08fdd

还是不行，总是报错，因为mapper总是执行了实现类，mock失败

![image-20200717011217342](Service%E5%B1%82Mock.assets/image-20200717011217342.png)

可能mockito和mybatis八字犯冲，放弃

[timelog]01点12分