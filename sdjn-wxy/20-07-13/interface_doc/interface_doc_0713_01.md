# Interface Doc (unfinished)


## 登录

### 登录接口
**POST** /api/login
* 请求参数：
  1. data **JSONObject**
   [
       &emsp;username **String**
       &emsp;password **String**
   ]
   
* 返回结果：
  1. Msg **JSONObject**
   [
    &emsp;status **int** 
    &emsp;&emsp;(登陆成功：0；失败：1)
    &emsp;extra **String** 
    &emsp;&emsp;(
    &emsp;&emsp;&emsp;登陆成功：(管理员："0"，普通用户："1")
    &emsp;&emsp;&emsp;失败：null
    &emsp;&emsp;)
   ]
 
## 学生

### 获取全部课程接口
**GET** /api/student/course_avilable
* 请求参数：
  * None
* 返回结果：
  * List\<Section\>

### 按课程名模糊搜索接口
**GET** /api/student/course_search
* 请求参数：
  * searchString **String**
  * start: **int** # 分页起始记录
  * end: **int** # 分页结束记录
* 返回结果：

### 
**POST** /api/student/course_select
* 请求参数：
  * data **JSONObject**
   {
       &emsp;secID **String**
       &emsp;user_name **String**
       &emsp;semester **String**
       &emsp;year **String**
       &emsp;building **String**
       &emsp;roomnumber **String**
       &emsp;timeslotID  **String**
       &emsp;timeslot **TimeSlot**{ &emsp;timeslotID **String**,&emsp;day **String**, &emsp;startTime **Time**,&emsp;endTime **Time**}
       &emsp;courseID **String**
       &emsp;course **Course**{&emsp;courseID **String**, &emsp;deptID **String**, &emsp;courseName **String**, &emsp;description **String**}
   }
* 返回结果：
  * 类型：int
  * 成功：0
  * 失败：(插入takes成功但更新section失败：1；反之为2)

### 
**POST** /api/student/course_drop
* 请求参数：
  * data **JSONObject**
   {
       &emsp;secID **String**
       &emsp;user_name **String**
       &emsp;semester **String**
       &emsp;year **String**
       &emsp;building **String**
       &emsp;roomnumber **String**
       &emsp;timeslotID  **String**
       &emsp;timeslot **TimeSlot**{ &emsp;timeslotID **String**,&emsp;day **String**, &emsp;startTime **Time**,&emsp;endTime **Time**}
       &emsp;courseID **String**
       &emsp;course **Course**{&emsp;courseID **String**, &emsp;deptID **String**, &emsp;courseName **String**, &emsp;description **String**}
   }
* 返回结果：
  * 类型：int
  * 成功：0
  * 失败：(删除takes成功但更新section失败：1；反之为2)

### 
**POST** /api/student/course_list
* 请求参数：
  * user_name **String**
* 返回结果：
  * 

### 
**POST** /api/student
* 请求参数：
* 返回结果：