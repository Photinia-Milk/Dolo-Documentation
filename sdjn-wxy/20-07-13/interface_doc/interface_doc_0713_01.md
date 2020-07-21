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
**GET** /api/student/course_valid
* 请求参数：
  * startIndex: **Interger**
  * pageSize: **Interger**
* 返回结果：
  * **List\<Map\<String, Object\>\>**

### 按课程名模糊搜索接口
**GET** /api/student/course_search
* 请求参数：
  * searchString **String**
  * startIndex: **Interger**
  * pageSize: **Interger**
* 返回结果：
  * **List\<Map\<String, Object\>\>**

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
       &emsp;credits **double**
       &emsp;weeks **String**
       &emsp;timeslotID  **String**
       &emsp;courseID **String**
       &emsp;maxnum **int**
       &emsp;currentnum **int**
   }
* 返回结果：
  * 类型：**int**
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
       &emsp;credits **double**
       &emsp;weeks **String**
       &emsp;timeslotID  **String**
       &emsp;courseID **String**
       &emsp;maxnum **int**
       &emsp;currentnum **int**
   }
* 返回结果：
  * 类型：**int**
  * 成功：0
  * 失败：(删除takes成功但更新section失败：1；反之为2)

### 
**POST** /api/student/course_list
* 请求参数：
  * user_name **String**
  * startIndex **Interger**
  * pageSize: **Interger**
* 返回结果：
  * **List\<Map\<String, Object\>\>**

<!-- ### 
**POST** /api/student
* 请求参数：
* 返回结果： -->