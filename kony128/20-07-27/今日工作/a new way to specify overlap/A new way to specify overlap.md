# A new way to specify overlap

## 时间

23点47分

## 内容

七点开始做完了才写的文档

### 挑战

我们选课如果课程重叠没有任何处理

这明显不对劲

但根据后端数据库结构，原打算大改，然后做N层循环遍历

我们突然想到一个好方法

把int的三十二位对应三十二周，这样一个学期最多就有8个月

然后再来两个int，分别对应一周七天和每天上课的时间段

这样子，就可以用与操作，虽然还是有循环，但是循环单次重叠的判断变成了位操作

bit

哈哈，我很聪明吧

主要是从ICS lab和算法 lab来的灵感