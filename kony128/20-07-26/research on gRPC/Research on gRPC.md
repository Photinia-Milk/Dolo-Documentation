# Research on gRPC

## 时间

23点13分

## 内容

### roadmap

http://doc.oschina.net/grpc?t=58008

- [x] 中文文档概念



https://developers.google.com/protocol-buffers/docs/overview

- [x] protocol-buffers2



https://developers.google.com/protocol-buffers/docs/proto3

- [x] protocol-buffers3



http://doc.oschina.net/grpc?t=60134

- [x] 中文java gRPC



https://github.com/grpc/grpc-java

- [x] java gRPC repo with examples



https://grpc.io/

- [x] 英文官网



https://grpc.io/docs/languages/java/quickstart/

- [x] 英文java quick start文档

--------------

### what is gRPC and why gRPC

![image-20200726231603621](Research%20on%20gRPC.assets/image-20200726231603621.png)

是一种方法，可以像调用本地对象一样直接调用另一台不同机器上服务端应用

------

为什么使用gRPC？ - java例子中的

一些好处：

1. 在.proto文件中就可以定义服务，客户端和服务端可以用任何语言
2. 通信是十分高效（序列化）且安全（带各种安全验证、授权模板）的
3. 有.proto文件就意味着有接口规范，面向接口编程，容易进行接口更新

![image-20200726234404327](Research%20on%20gRPC.assets/image-20200726234404327.png)



---------------

RPC比http数据传输三次握手等等轻便



![image-20200726231609131](Research%20on%20gRPC.assets/image-20200726231609131.png)

------

RPC内容经过序列化压缩，网络传输更高效

![image-20200726231740967](Research%20on%20gRPC.assets/image-20200726231740967.png)

-----

![image-20200726231814480](Research%20on%20gRPC.assets/image-20200726231814480.png)

protocol buffers有不同版本，3.0目前为alpha，但推荐使用

----

![image-20200726232111313](Research%20on%20gRPC.assets/image-20200726232111313.png)

java语言现在可以很方便的写一个gRPC客户端和服务器

---------------

### what is protocol buffers

![image-20200726232222266](Research%20on%20gRPC.assets/image-20200726232222266.png)注意上一章节教程写得是proto3版本，我们需要去找

-----



![image-20200726232429464](Research%20on%20gRPC.assets/image-20200726232429464.png)

这就是一个.proto 的file里写的proto文件

第一行很好理解，不写编译器默认为proto3

第三行定义了一个message叫SearchRequest

其中有三个fileds，每个field都代表一段data

每个filed由type、name、value组成



-------

![image-20200726232705018](Research%20on%20gRPC.assets/image-20200726232705018.png)

fileds可以声明为conposite的

还可以搞枚举enumerations

下面那个Corpus就是枚举类型type，要加个enum关键词

![image-20200726232729849](Research%20on%20gRPC.assets/image-20200726232729849.png)

-----

![image-20200726232939217](Research%20on%20gRPC.assets/image-20200726232939217.png)

要注意枚举一些坑

必须有0

0必须在第一行

------

![image-20200726233012664](Research%20on%20gRPC.assets/image-20200726233012664.png)

使用option allow_alias = true，

你的alias（其他文件）也就能利用这里定义的枚举类型辣

--------

![image-20200726233120693](Research%20on%20gRPC.assets/image-20200726233120693.png)

file的注释是c/c++风格的

--------

![image-20200726233154816](Research%20on%20gRPC.assets/image-20200726233154816.png)

预留fileds，没细看

---------

![image-20200726233232633](Research%20on%20gRPC.assets/image-20200726233232633.png)

启动protocol buffer compiler，编译.proto文件

编译器会生成你在这个.proto文件里描述的选择的编程语言（包括getting和setting fileds的values）

序列化这些messages到output stream中，

然后从输入stream中parsing这些messages

---------------

以下是一些Scala value types



![image-20200726233453916](Research%20on%20gRPC.assets/image-20200726233453916.png)

![image-20200726233529444](Research%20on%20gRPC.assets/image-20200726233529444.png)

![image-20200726233550784](Research%20on%20gRPC.assets/image-20200726233550784.png)

![image-20200726233557051](Research%20on%20gRPC.assets/image-20200726233557051.png)

---------

没错！我还支持JSON mapping！没想到吧

哈哈

canonical encoding - 正则编码

如果在JSON里，缺省的值会是null，在proto里会被转换为default value，如果这个filed 没有default value，那就会被忽视掉

你还可以写实现，在JSON-encoded output里忽视掉某些带有default values的fields

注意一些转换的编码规则，比如lowerCamelCase啥的

![image-20200726233654085](Research%20on%20gRPC.assets/image-20200726233654085.png)

还有好多blabla………………

此处省略

default values此处也省略，自己查

![image-20200726234019811](Research%20on%20gRPC.assets/image-20200726234019811.png)

-----------

### use gRPC in JAVA / Cn

![image-20200726234241981](Research%20on%20gRPC.assets/image-20200726234241981.png)

最终学习效果，官网blabla

-------

第一步，先学会用.proto文件定义java服务

https://github.com/grpc/grpc-java/blob/master/examples/src/main/proto/route_guide.proto

这是对应的例子





![image-20200726235033633](Research%20on%20gRPC.assets/image-20200726235033633.png)

![image-20200726234748974](Research%20on%20gRPC.assets/image-20200726234748974.png)

service关键字就定义了一个服务

-------

服务中有rpc方法，指定请求request与响应response的类型，

就像写函数接口辣

注意返回的可以是流，可以拿这个流去读取返回的消息队列，客户端会读到里面没值为止

需要加上关键字stream

![image-20200726235023628](Research%20on%20gRPC.assets/image-20200726235023628.png)

![image-20200726235123634](Research%20on%20gRPC.assets/image-20200726235123634.png)

---------

那那些消息类型定义在哪里呢！？

也在.proto文件里

![image-20200726235420958](Research%20on%20gRPC.assets/image-20200726235420958.png)

-------

生成客户端和服务端的代码，就需要用protocol buffer compiler - > protoc

生成代码位于：（应该是，教程给的路径是空的）

https://github.com/grpc/grpc-java/blob/master/examples/src/main/java/io/grpc/examples/routeguide/RouteGuideServer.java

这玩意在引入pom依赖的时候好像有做

会生成哪些代码？

- 各种消息类型的Java类，比如Point.java
- gRPC服务端方法Java类，比如RouteGuideGrpc.java，包括：
  - RouteGuide服务端需要实现的各种接口，比如RouteGuideGrpc.RouteGuide（空的，要自己写）
  - 各种客户端可以RouteGuide服务器交互的**存根**类，包括异步的

![image-20200726235449311](Research%20on%20gRPC.assets/image-20200726235449311.png)

-----------



那么怎么创建一个服务器呢

![image-20200727000318252](Research%20on%20gRPC.assets/image-20200727000318252.png)

看看这个！

它给的地址也是错的，裂开了

正式考虑更换文档为英文

---------

### use gRPC in JAVA / En

![image-20200727000649417](Research%20on%20gRPC.assets/image-20200727000649417.png)

这就舒服多了，符合我们的想法

------

构建后，也是会自动生成GreeterGrpc.java，

里面包含生成的gRPC客户端和服务端类

里面的populating、serializing和retrieving request and response types都给你写好了

该手动写的方法你还是得手动写



![image-20200727000728678](Research%20on%20gRPC.assets/image-20200727000728678.png)

---------

可以自己写一下client，

我 访 问 我 自 己

![image-20200727000946802](Research%20on%20gRPC.assets/image-20200727000946802.png)

---

![image-20200727001028141](Research%20on%20gRPC.assets/image-20200727001028141.png)

接下来跑一下，

把server跑起来，再搞个终端跑client

就能够实现过程调用了！

hia hia