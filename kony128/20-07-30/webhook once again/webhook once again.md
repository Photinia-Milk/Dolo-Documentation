# webhook once again

## 时间

14点22分

## 内容

用域名而非ip

让webhook鲁棒性高起来

我先试试看

![image-20200730135016790](webhook%20once%20again.assets/image-20200730135016790.png)



![image-20200730140049067](webhook%20once%20again.assets/image-20200730140049067.png)





尝试性push以下，结果看到webhook成功了！



![image-20200730141059899](webhook%20once%20again.assets/image-20200730141059899.png)





![image-20200730141139814](webhook%20once%20again.assets/image-20200730141139814.png)

然而，在jenkins上却没有任何反应



是不是上一次的原因

写一个free-style trigger试试看

![image-20200730141953883](webhook%20once%20again.assets/image-20200730141953883.png)

trigger正常

可以了

![image-20200730142211612](webhook%20once%20again.assets/image-20200730142211612.png)