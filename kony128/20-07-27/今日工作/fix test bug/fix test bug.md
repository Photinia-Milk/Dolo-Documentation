# fix test bug

## 时间

23点29分

## 内容

完成的才来写文档

### debug

![image-20200727233146048](fix%20test%20bug.assets/image-20200727233146048.png)

精度没有达到科学计算，不需要用BigDecimal

两值比较怎么能直接比较相等？！

应该两值相减差小于一个theta啊！

![image-20200727233119598](fix%20test%20bug.assets/image-20200727233119598.png)

这报错，我服了

---

![image-20200727233103868](fix%20test%20bug.assets/image-20200727233103868.png)

mapper层怎么可以带表名，这不就是高耦合了吗？

把表名去掉了

---

![image-20200727233057622](fix%20test%20bug.assets/image-20200727233057622.png)

配置里的用户名密码完全不对，改掉

怎么会连接course3

明明是course2

---

[timelog]22点57分

----

![image-20200727233051438](fix%20test%20bug.assets/image-20200727233051438.png)

怎么会这样写

执行了三次studentService

需要改掉

---

测试用例里写得全是高耦合代码，爷全给改了

只判断返回的个数对不对其实就可以了

![image-20200727233039859](fix%20test%20bug.assets/image-20200727233039859.png)

代码耦合度高了，稍微有一点不对就得全改

时间都浪费在没意义的事情上

只用判断返回的个数对不对就行了

---

List完全不能判断长度，我服了

