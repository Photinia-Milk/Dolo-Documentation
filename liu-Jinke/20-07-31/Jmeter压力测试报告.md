# Jmeter压力测试报告

## 内容

### 100并发/s，重复5秒

#### 并发配置

![image-20200731182850732](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95%E6%8A%A5%E5%91%8A.assets/image-20200731182850732.png)

#### student/course_valid

![image-20200731183112245](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95%E6%8A%A5%E5%91%8A.assets/image-20200731183112245.png)

参数设定：

pageSize固定10

startIdx从0到250随机

（条数最多260，发高了返回空请求，影响测试）

![image-20200731183136055](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95%E6%8A%A5%E5%91%8A.assets/image-20200731183136055.png)

平均：0.845

最高：1.989

无错误

#### student/section_valid

![image-20200731183414663](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95%E6%8A%A5%E5%91%8A.assets/image-20200731183414663.png)

参数设定：

courseId固定SE125

![image-20200731184821679](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95%E6%8A%A5%E5%91%8A.assets/image-20200731184821679.png)

平均：1.085

最高：2.973

无错误

#### student/course_search

![image-20200731185131591](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95%E6%8A%A5%E5%91%8A.assets/image-20200731185131591.png)

参数设定：

startIndex：1~3

pageSize：10

key：素、艺、开、工、数其中一个字

（可以检索到素描、艺术、开发、工程、数学等等词汇）

![image-20200731185359245](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95%E6%8A%A5%E5%91%8A.assets/image-20200731185359245.png)

平均：0.875

最高：2.030

无错误

#### student/course_list

![image-20200731185617504](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95%E6%8A%A5%E5%91%8A.assets/image-20200731185617504.png)

参数：

user_name：student0

![image-20200731185956856](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95%E6%8A%A5%E5%91%8A.assets/image-20200731185956856.png)

平均：0.908

最高：2.174

无错误



#### student/course_select

![image-20200731190311429](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95%E6%8A%A5%E5%91%8A.assets/image-20200731190311429.png)

参数设定：

userName：student0 ~ student100

courseId： AD001

year：2020-2021

courseId：AD001

teacherUserName：teacher130

![image-20200731190737666](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95%E6%8A%A5%E5%91%8A.assets/image-20200731190737666.png)

平均：0.841

最高：2.428

无错误

#### student/course_drop

![image-20200731190900487](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95%E6%8A%A5%E5%91%8A.assets/image-20200731190900487.png)

参数：

userName：student0 ~ student100

courseId： AD001

year：2020-2021

courseId：AD001

teacherUserName：teacher130

![image-20200731191238277](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95%E6%8A%A5%E5%91%8A.assets/image-20200731191238277.png)

平均：0.740

最高：1.715

无错误

#### student/gpa

![image-20200731191407498](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95%E6%8A%A5%E5%91%8A.assets/image-20200731191407498.png)

参数：

userName:student${__Random(0,20,)}

from:1998-1999-1

to:2020-2021-2

type:all

![image-20200731191718171](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95%E6%8A%A5%E5%91%8A.assets/image-20200731191718171.png)

平均：0.430

最高：2.250

无错误

#### student/gpa_detail

![image-20200731191812055](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95%E6%8A%A5%E5%91%8A.assets/image-20200731191812055.png)

参数：

userName:student${__Random(0,20,)}

from:1998-1999-1

to:2020-2021-2

![image-20200731192243357](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95%E6%8A%A5%E5%91%8A.assets/image-20200731192243357.png)

平均：0.419

最高：2.124

无错误

#### student/query_info

![image-20200731192446485](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95%E6%8A%A5%E5%91%8A.assets/image-20200731192446485.png)

参数：

userName：student${__Random(0,20,)}

![image-20200731192943038](Jmeter%E5%8E%8B%E5%8A%9B%E6%B5%8B%E8%AF%95%E6%8A%A5%E5%91%8A.assets/image-20200731192943038.png)

平均：440

最高：2488

无错误