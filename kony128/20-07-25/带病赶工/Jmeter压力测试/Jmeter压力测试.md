# Jmeter压力测试

## 时间

20点55分

## 负责

kony

## 内容

### 配置

![image-20200725205606103](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95.assets/image-20200725205606103.png)

安装好了Jmeter，开干吧

https://blog.csdn.net/weixin_39089928/article/details/87369101

稍微看了一下，上面这个博客比较靠谱

来吧

![image-20200725205852696](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95.assets/image-20200725205852696.png)



![image-20200725210407373](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95.assets/image-20200725210407373.png)



![image-20200725210414575](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95.assets/image-20200725210414575.png)

-----

### 报错

![image-20200725210422162](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95.assets/image-20200725210422162.png)

### 解决



https://stackoverflow.com/questions/59862477/jmeter-illegal-character-found-in-host



![image-20200725210438475](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95.assets/image-20200725210438475.png)

垃圾CSDN

### 单次成果

![image-20200725211018525](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95.assets/image-20200725211018525.png)



相应的数据意义：

![image-20200725211422761](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95.assets/image-20200725211422761.png)

![image-20200725211143241](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95.assets/image-20200725211143241.png)

### 多次迭代

![image-20200725211508131](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95.assets/image-20200725211508131.png)

又设置成了5次迭代，

每次500请求/s

跑了两次

总结果如上，一共5500个请求，

平均响应时间是1.615s



### 随机参数

https://blog.csdn.net/u013036792/article/details/79075464

貌似这个博客比较靠谱

单个参数想变化，看看怎么搞



![image-20200725212053475](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95.assets/image-20200725212053475.png)



设置了startIndex的随机数

结果更可靠了

![image-20200725212225350](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95.assets/image-20200725212225350.png)

平均响应时间更低了，看来结果并不是这么可靠，我估计是网络的原因，cloudflare CDN加速不是这么稳定





![image-20200725212415373](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95.assets/image-20200725212415373.png)

![image-20200725212355544](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95.assets/image-20200725212355544.png)

我大概了解是什么原因了，我们数据库里没这么多数据，只有258条



![image-20200725212624429](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95.assets/image-20200725212624429.png)

改了一下随机数，让请求的数据范围合理后，我们的结果如下

![image-20200725212728769](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95.assets/image-20200725212728769.png)



