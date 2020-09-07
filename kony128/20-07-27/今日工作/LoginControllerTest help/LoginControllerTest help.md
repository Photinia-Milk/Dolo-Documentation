# LoginControllerTest help

## 时间

15点46分

## 内容

帮助兴宇debug

mockMVC返回不是200，而是404

### 问题：

![image-20200727161350000](LoginControllerTest%20help.assets/image-20200727161350000.png)

这个测试类package里面多了个LoginController，里面是个测试类

？！？！？

JAVA bean加载的时候自动找了它，没有实例化，

mockMVC不报404才有鬼

删掉，问题解决