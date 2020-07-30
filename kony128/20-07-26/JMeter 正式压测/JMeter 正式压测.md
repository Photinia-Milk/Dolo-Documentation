# JMeter 正式压测

## 时间

19点25分

## 内容

### 100并发/s，重复5秒

#### 并发配置

![image-20200726193736552](JMeter%20%E6%AD%A3%E5%BC%8F%E5%8E%8B%E6%B5%8B.assets/image-20200726193736552.png)

注意每次迭代都是不同的用户，模拟真实环境



#### student/course_valid

![image-20200726195145432](JMeter%20%E6%AD%A3%E5%BC%8F%E5%8E%8B%E6%B5%8B.assets/image-20200726195145432.png)

参数设定：

pageSize固定10

startIdx从0到250随机

（条数最多260，发高了返回空请求，影响测试）



![image-20200726192112027](JMeter%20%E6%AD%A3%E5%BC%8F%E5%8E%8B%E6%B5%8B.assets/image-20200726192112027.png)

平均：1.314s

最高：2.719s

无错误



#### student/section_valid

![image-20200726195042931](JMeter%20%E6%AD%A3%E5%BC%8F%E5%8E%8B%E6%B5%8B.assets/image-20200726195042931.png)

参数设定：

courseId固定SE125





![image-20200726203405399](JMeter%20%E6%AD%A3%E5%BC%8F%E5%8E%8B%E6%B5%8B.assets/image-20200726203405399.png)

平均：1.246s

最高：2.612s

无错误



#### student/course_search

![image-20200726194811037](JMeter%20%E6%AD%A3%E5%BC%8F%E5%8E%8B%E6%B5%8B.assets/image-20200726194811037.png)

参数设定：

startIndex：1~3

pageSize：10

key：素、艺、开、工、数其中一个字

（可以检索到素描、艺术、开发、工程、数学等等词汇）



![image-20200726195320307](JMeter%20%E6%AD%A3%E5%BC%8F%E5%8E%8B%E6%B5%8B.assets/image-20200726195320307.png)

平均：1.046s

最高：2.065s

无错误



#### student/course_select

![image-20200726203048890](JMeter%20%E6%AD%A3%E5%BC%8F%E5%8E%8B%E6%B5%8B.assets/image-20200726203048890.png)

参数设定：

userName：student0 ~ student100

courseId： AD001

year：2020-2021

courseId：AD001

teacherUserName：teacher130



![image-20200726203527296](JMeter%20%E6%AD%A3%E5%BC%8F%E5%8E%8B%E6%B5%8B.assets/image-20200726203527296.png)

平均：1.225s

最高：3.041s

无错误



分析：

阻塞明显

这个操作是先查数据库，自己没有选课过才往里写

正常情况下，前端会返回这个用户对该课程的选课情况，如已选课，会出现”退课按钮“

连续多次发送选课请求也不是不可能出现，在选课阻塞的情况下，用户很可能按多次选课请求

这时需要读并发，因此速度明显变慢，

考虑分布式数据库，考虑redis缓存，缓解读写压力



#### student/course_list

![image-20200726202445657](JMeter%20%E6%AD%A3%E5%BC%8F%E5%8E%8B%E6%B5%8B.assets/image-20200726202445657.png)

参数：

user_name：student0



![image-20200726203633451](JMeter%20%E6%AD%A3%E5%BC%8F%E5%8E%8B%E6%B5%8B.assets/image-20200726203633451.png)

平均：1.252s

最高：3.865s

无错误



分析：

阻塞明显

这是多表查询，得到student相关的课程列表

似乎一涉及takes表，查询速度就变得很慢，需要注意



#### student/course_drop

![image-20200726203052441](JMeter%20%E6%AD%A3%E5%BC%8F%E5%8E%8B%E6%B5%8B.assets/image-20200726203052441.png)

参数：

userName：student0 ~ student100

courseId： AD001

year：2020-2021

courseId：AD001

teacherUserName：teacher130



![image-20200726203310831](JMeter%20%E6%AD%A3%E5%BC%8F%E5%8E%8B%E6%B5%8B.assets/image-20200726203310831.png)

平均：1.227s

最高：3.331s

无错误