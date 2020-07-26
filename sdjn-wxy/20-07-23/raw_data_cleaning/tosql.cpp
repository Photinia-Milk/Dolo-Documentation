#include "tosql.h"

using namespace std;

class Timeslot {
public:
    int id;
    int starttime;
    int endtime;
    string day;

    Timeslot();
    Timeslot(int t_id, int t_st, int t_et, string t_d);
    bool operator == (Timeslot &rec) const;
};

Timeslot::Timeslot(){}

Timeslot::Timeslot(int t_id, int t_st, int t_et, string t_d)
{
    id = t_id;
    starttime = t_st;
    endtime = t_et;
    day = t_d;
}

// 重载类相等函数
// 相同的class对象互为友元，所以可以访问private对象。== 是二元操作符，class内隐藏了this
bool Timeslot::operator==(Timeslot & rec) const
{
    return this->day == rec.day
        && this->starttime == rec.starttime
        && this->endtime == rec.endtime;
}

class Section {
public:
    // int secID;
    string semester;
    string year;
    string timeslotID;
    string courseID;
    string location;
    double credits;
    string reamarks;
    string weeks;
    string model;
    string teacher_username;
    int maxnum;
    int currentnum;

    Section();
    Section(string timeslotID, string courseID, string location, 
            double credits, string reamarks, string weeks, string model, string teacher_username, int maxnum);
};

Section::Section(){}

Section::Section(string t_timeslotID, string t_courseID, string t_location, 
            double t_credits, string t_reamarks, string t_weeks, string t_model, string t_teacher_username, int t_maxnum)
{
    // secID = t_sec_id;
    semester = "1";
    year = "2020-2021";
    timeslotID = t_timeslotID;
    courseID = t_courseID;
    location = t_location;
    credits = t_credits;
    reamarks = t_reamarks;
    teacher_username = t_teacher_username;
    weeks = t_weeks;
    model = t_model;
    maxnum = t_maxnum;
    currentnum = 0;
}

class Course {
public:
    string courseID;
    string coursename;
    string course_type;
    string elective_type;

    Course();
    Course(string courseID, string coursename, string course_type, string elective_type);
};

Course::Course(){}

Course::Course(string t_courseID, string t_coursename, string t_course_type, string t_elective_type){
    courseID = t_courseID;
    coursename = t_coursename;
    course_type = t_course_type;
    elective_type = t_elective_type;
}

class Teacher {
public:
    string user_name;
    string dept_name;
    string name;
    string rank;

    Teacher();
    Teacher(string username, string name, string rank);
    bool operator == (Teacher &rec) const;
};

Teacher::Teacher(){}

Teacher::Teacher(string t_username, string t_name, string t_rank)
{
    user_name = t_username;
    name = t_name;
    rank = t_rank;
}

bool Teacher::operator==(Teacher &rec) const
{
    return this->user_name == rec.user_name &&
        this->name == rec.name && 
        this->rank == rec.rank &&
        this->dept_name == rec.dept_name;
}

// class Teach {
// public: 
//     // string secID;
//     string semester;
//     string year;
//     string timeslotID;
//     string courseID;
//     string user_name;

//     Teach();
//     // Teach(string secID, string timeslotID, string courseID, string user_name);
// };

// Teach::Teach(){}

// Teach::Teach(string t_secID, string t_timeslotID, string t_courseID, string t_user_name)
// {
//     // // secID = t_secID;
//     semester = "1";
//     year = "2020-2021";
//     timeslotID = t_timeslotID;
//     courseID = t_courseID;
//     user_name = t_user_name;
// }

int main()
{

    ifstream infile("course.txt", ios::in);
    int course_num = 0;
    int teacher_num = 0;
    int time_slot_num = 0;
    int section_size = 0; 
    string raw_data1, raw_data2, raw_data3, table_name, filed, value, *values, insert;
    string courseID, coursename, name, rank, day, weeks, location, remarks, course_type, elective_type, model;
    int starttime, endtime, value_size;
    char a, b, c;
    double credit;

    /* 获取课程section */
    Section section[231];
    Timeslot timeslot[231];
    Course course[231];
    Teacher teacher[231];
    // Teach teach[231];

    srand((unsigned)time(NULL));

    while(section_size < 231){
        infile >> raw_data1 >> a >> credit >> raw_data2 >> raw_data3;
        string::size_type nPos1 = string::npos;
        string::size_type nPos2 = string::npos;
        string::size_type nPos3 = string::npos;
        string::size_type nPos4 = string::npos;
        string::size_type nPos5 = string::npos;
        string::size_type nPos6 = string::npos;
        string::size_type nPos7 = string::npos;
        string::size_type nPos8 = string::npos;
        string::size_type nPos9 = string::npos;
        string::size_type nPos10 = string::npos;
        string::size_type nPos11 = string::npos;
        string::size_type nPos12 = string::npos;
        string::size_type nPos13 = string::npos;
        string::size_type nPos14 = string::npos;
        string::size_type nPos15 = string::npos;
        string::size_type nPos16 = string::npos;
        string::size_type nPos = string::npos;
        /*  find(string strSub, npos);
                strSub是需要寻找的子字符串，npos为查找起始位置
                找到返回子字符串首次出现的位置，否则返回-1；
            find_last_of的npos为从末尾开始寻找的位置 */
        nPos1 = raw_data1.find_first_of("(");
        nPos2 = raw_data1.find_first_of(")", nPos1+1);
        nPos3 = raw_data2.find("】");
        nPos4 = raw_data2.find("【");
        nPos5 = raw_data3.find("上课时间:");
        nPos6 = raw_data3.find("第");
        nPos7 = raw_data3.find("-");
        nPos8 = raw_data3.find("节");
        nPos9 = raw_data3.find_first_of("{");
        nPos10 = raw_data3.find_first_of("}", nPos9+1);
        nPos11 = raw_data3.find("教学地点:", nPos10+1);
        nPos12 = raw_data3.find("选课备注:", nPos11+1);
        nPos13 = raw_data3.find("课程归属:");
        nPos14 = raw_data3.find("课程性质:");
        nPos15 = raw_data3.find("教学模式:");
        nPos16 = raw_data3.find("已选/容量:");
        nPos = raw_data2.find("学分");
        /*  strsub(npos，size)
            其中npos为开始位置，size为截取大小 */
        if(nPos1 !=-1 && nPos2 != -1)
        {
            /* 获取课号 */
            courseID = raw_data1.substr(nPos1+1, nPos2-nPos1-1);
            /* 获取课程名称 */
            coursename = raw_data1.substr(nPos2+1, raw_data1.size()-nPos1);
        }
        if(nPos3 !=-1 && nPos4 != -1)
        {
            /* 获取教师名称 */
            name = raw_data2.substr(nPos4+3, nPos3-nPos4-3);
        }
        if(nPos5 !=-1)
        {
            /* 获取教师职称 */
            rank = raw_data3.substr(0, nPos5);
        }
        if(nPos5 !=-1 && nPos6 != -1)
        {
            /* 获取上课日 */
            day = raw_data3.substr(nPos5+13, nPos6-nPos5-13);
        }
        if(nPos6 !=-1 && nPos7 != -1)
        {
            /* 获取开始时间（节） */           
            // starttime = raw_data3.substr(nPos6+3, nPos7-nPos6-3);
            std::stringstream stime;
            stime << raw_data3.substr(nPos6+3, nPos7-nPos6-3);
            stime >> starttime;
        }
        if(nPos7 !=-1 && nPos8 != -1)
        {
            /* 获取结束时间（节） */
            // endtime = raw_data3.substr(nPos7+1, nPos8-nPos7-1);
            std::stringstream etime;
            etime << raw_data3.substr(nPos7+1, nPos8-nPos7-1);
            etime >> endtime;
        }
        if(nPos10 !=-1 && nPos9 != -1)
        {
            /* 获取上课周数 */
            weeks = raw_data3.substr(nPos9+1, nPos10-nPos9-1);
        }
        if(nPos11 !=-1 && nPos12 != -1)
        {
            /* 获取教学地点 */
            location = raw_data3.substr(nPos11+13, nPos12-nPos11-13);
        }
    
        if(nPos12 !=-1 && nPos13 != -1)
        {
            /* 获取选课备注 */
            remarks = raw_data3.substr(nPos12+13, nPos13-nPos12-13);
        }else if (nPos12 !=-1 && nPos13 == -1)
        {
            remarks = raw_data3.substr(nPos12+13, nPos14-nPos12-13);
        }
        
        if(nPos13 !=-1 && nPos14 != -1)
        {
            /* 获取课程归属 */
            elective_type = raw_data3.substr(nPos13+13, nPos14-nPos13-13);
        }else
        {
            elective_type = "";
        }
        if(nPos14 != -1 && nPos15 != -1)
        {
            /* 获取课程性质 */
            course_type = raw_data3.substr(nPos14+13, nPos15-nPos14-13);
        }
        if(nPos15 != -1 && nPos16 == -1)
        {
            /* 获取课程教学模式 */
            model = raw_data3.substr(nPos15+13, raw_data3.size()-nPos15-13);
        }else if (nPos15 != -1 && nPos16 != -1)
        {
            model = raw_data3.substr(nPos15+13, nPos16-nPos15-13);
        }
        
        /* 向数据对象中填充数据 timeslot & course & teacher -> section -> teach */
        
        /* Course对象 */
        course[section_size].courseID = courseID;
        course[section_size].coursename = coursename;
        course[section_size].course_type = course_type;
        course[section_size].elective_type = elective_type;
        
        /* Timeslot对象 */
        Timeslot newslot;
        newslot.day = day;
        newslot.starttime = starttime;
        newslot.endtime = endtime;
        if(time_slot_num == 0){
            time_slot_num++;
            timeslot[0].day = newslot.day;
            timeslot[0].endtime = newslot.endtime;
            timeslot[0].starttime = newslot.starttime;
            timeslot[0].id = 1;
            newslot.id = 1;
            // cout << "[" << timeslot[0].id << "]" 
            //     << timeslot[0].day
            //     << timeslot[0].starttime
            //     << timeslot[0].endtime
            //     << endl;
        }else{
            bool isSame = false;
            for(int i = 0; i < time_slot_num; i++){
                if(newslot==timeslot[i]){
                    isSame = true;
                    newslot.id = timeslot[i].id;
                }
            }if(!isSame){
                time_slot_num++;
                timeslot[time_slot_num-1].day = newslot.day;
                timeslot[time_slot_num-1].endtime = newslot.endtime;
                timeslot[time_slot_num-1].starttime = newslot.starttime;
                timeslot[time_slot_num-1].id = time_slot_num;
                newslot.id = time_slot_num;
                // cout << "[" << timeslot[time_slot_num-1].id << "]" 
                //     << timeslot[time_slot_num-1].day
                //     << timeslot[time_slot_num-1].starttime
                //     << timeslot[time_slot_num-1].endtime
                //     << endl;
            }
        }

        /* Teacer对象 */
        // 此处暂不考虑重名情况
        teacher[section_size].name = name;
        teacher[section_size].rank = rank;
        teacher[section_size].user_name = "teacher" + std::to_string(section_size);
        
        /* Section对象 */
        // section[section_size].secID = section_size;
        section[section_size].courseID = courseID;
        section[section_size].timeslotID = to_string(newslot.id);
        cout << newslot.id << endl;
        section[section_size].semester = "1";
        section[section_size].year = "2020-2021";
        section[section_size].credits = credit;
        section[section_size].currentnum = 0;
        section[section_size].teacher_username = teacher[section_size].user_name;
        section[section_size].location = location;
        section[section_size].model= model;
        section[section_size].reamarks = remarks;
        section[section_size].weeks = weeks;

        section[section_size].maxnum = rand() % 140 + 30;
        
        // /* Teach对象 */
        // teach[section_size].courseID = courseID;
        // teach[section_size].secID = section[section_size].secID;
        // teach[section_size].semester = "2";
        // teach[section_size].timeslotID = newslot.id;
        // teach[section_size].user_name = teacher[section_size].username;
        // teach[section_size].year = "2020-2021";
        section_size++;
        // cout << "[" <<section_size << "]" << courseID << " " << coursename  << " " << course_type<< " " << elective_type << endl;
    }

    /* 生成section表 */
    ofstream outSections;
    outSections.open("section.sql");
    value_size = 9;
    values = new string[value_size];
    table_name = " section ";
    filed = " ( semester, year, courseId, teacherUserName, location, remarks, model, maxNum, currentNum ) ";
    for (int i = 0; i < section_size; ++i){
        // values[0] = "\"" + to_string(section[i].secID) + "\"";
        values[0] = "\"" + section[i].semester +"\"";
        values[1] = "\"" + section[i].year +"\"";
        // values[3] = "\"" + section[i].timeslotID + "\"";
        values[2] = "\"" + section[i].courseID + "\"";
        values[3] = "\"" + section[i].teacher_username + "\"";
        values[4] = "\"" + section[i].location + "\"";
        // values[7] = to_string(section[i].credits);
        // values[5] = "\"" + section[i].weeks +"\"";
        values[5] = "\"" + section[i].reamarks +"\"";
        values[6] = "\"" + section[i].model +"\"";
        values[7] = to_string(section[i].maxnum);
        values[8] = to_string(section[i].currentnum);

        value = "";
        value += " (";
        for(int j = 0; j < value_size; ++j){
            value += values[j];
            if(j != value_size - 1){
                value += ", ";
            }
        }
        value += ") ";
        insert = "INSERT INTO" + table_name + filed +
                 "VALUES" + value + "; \n";
        outSections << insert;
        cout << insert;
    }
    delete[] values;
    outSections.close();

    /* 生成sectime表 */
    ofstream outSecTime;
    outSecTime.open("sectime.sql");
    value_size = 6;
    values = new string[value_size];
    table_name = " sectime ";
    filed = " ( timeslotId, semester, year, courseId, weeks, teacherUserName ) ";
    for(int i = 0; i < section_size; ++i){
        values[0] = "\"" + section[i].timeslotID + "\"";
        values[1] = "\"" + section[i].semester +"\"";
        values[2] = "\"" + section[i].year + "\"";
        values[3] = "\"" + section[i].courseID + "\"";
        values[4] = "\"" + section[i].weeks +"\"";
        values[5] = "\"" + section[i].teacher_username +"\"";
        value = "";
        value += " (";
        for( int j = 0; j < value_size; ++j)
        {
            value += values[j];
            if (j != value_size - 1)
            {
                value += ", ";
            }
        }
        value += ") ";
        insert = "INSERT INTO" + table_name + filed +
                 "VALUES" + value + "; \n";
        outSecTime << insert;
        cout << insert;
    }
    delete[] values;
    outSecTime.close();


    /* 生成course表(已实现) */
    ofstream outCourses;
    outCourses.open("course.sql");
    value_size = 5;
    values = new string[value_size];
    table_name = " course ";
    filed = " ( courseId, courseName, courseType, electiveType, credits ) ";
    for(int i = 0; i < section_size; ++i){
        values[0] = "\"" + course[i].courseID + "\"";
        values[1] = "\"" + course[i].coursename +"\"";
        values[2] = "\"" + course[i].course_type + "\"";
        values[3] = "\"" + course[i].elective_type + "\"";
        values[4] = to_string(section[i].credits);
        value = "";
        value += " (";
        for( int j = 0; j < value_size; ++j)
        {
            value += values[j];
            if (j != value_size - 1)
            {
                value += ", ";
            }
        }
        value += ") ";
        insert = "INSERT INTO" + table_name + filed +
                 "VALUES" + value + "; \n";
        outCourses << insert;
        cout << insert;
    }
    delete[] values;
    outCourses.close();

    /* 生成teacher表 */
    ofstream outTeachers;
    outTeachers.open("teacher.sql");
    value_size = 4;
    values = new string[value_size];
    table_name = " teacher ";
    filed = " ( userName, deptName, `rank`, name ) ";
    for(int i = 0; i < section_size; ++i){
        values[0] = "\"" + teacher[i].user_name + "\"";
        values[1] = "\"" + teacher[i].dept_name +"\"";
        values[2] = "\"" + teacher[i].rank + "\"";
        values[3] = "\"" + teacher[i].name + "\"";
        value = "";
        value += " (";
        for( int j = 0; j < value_size; ++j)
        {
            value += values[j];
            if (j != value_size - 1)
            {
                value += ", ";
            }
        }
        value += ") ";
        insert = "INSERT INTO" + table_name + filed +
                 "VALUES" + value + "; \n";
        outTeachers << insert;
        // cout << insert;
    }
    delete[] values;
    outTeachers.close();

    /* 生成timeslot表 */
    ofstream outTimeslots;
    outTimeslots.open("timeslot.sql");
    value_size = 4;
    values = new string[value_size];
    table_name = " timeslot ";
    filed = " ( timeslotId, day, startTime, endTime ) ";
    for(int i = 0; i < time_slot_num; ++i){
        values[0] = "\"" + to_string(timeslot[i].id) + "\"";
        values[1] = "\"" + timeslot[i].day + "\"";
        values[2] = "\"" + to_string(timeslot[i].starttime) + "\"";
        values[3] = "\"" + to_string(timeslot[i].endtime) + "\"";
        value = "";
        value += " (";
        for( int j = 0; j < value_size; ++j)
        {
            value += values[j];
            if (j != value_size - 1)
            {
                value += ", ";
            }
        }
        value += ") ";
        insert = "INSERT INTO" + table_name + filed +
                 "VALUES" + value + "; \n";
        outTimeslots << insert;
    }
    delete[] values;
    outTimeslots.close();

    // /* 生成*/
    // ofstream outTeach;
    // outTeach.open("teach.sql");
    // value_size = 6;
    // values = new string[value_size];
    // table_name = " taech ";
    // filed = " ( secID, , semester, year, timeslotID, courseID, user_name ) ";
    // for(int i = 0; i < section_size; ++i){
        // values[0] = "\"" + teach[i].secID + "\"";
    //     values[1] = "\"" + teach[i].semester +"\"";
    //     values[2] = "\"" + teach[i].year + "\"";
    //     values[3] = "\"" + teach[i].timeslotID + "\"";
    //     values[4] = "\"" + teach[i].courseID + "\"";
    //     values[5] = "\"" + teach[i].user_name + "\"";
    //     value = "";
    //     value += " (";
    //     for( int j = 0; j < value_size; ++j)
    //     {
    //         value += values[j];
    //         if (j != value_size - 1)
    //         {
    //             value += ", ";
    //         }
    //     }
    //     value += ") ";
    //     insert = "INSERT INTO" + table_name + filed +
    //              "VALUES" + value + "; \n";
    //     outTeach << insert;
    //     cout << insert;
    // }
    // delete[] values;
    // outTeach.close();

    // cout << section_size << endl;
    // cout << courseID << endl;
    // cout << coursename << endl;
    // cout << name << endl;
    // cout << rank << endl;
    // cout << day << endl;
    // cout << starttime << endl;
    // cout << endtime << endl;
    // cout << weeks << endl;
    // cout << location << endl;
    // cout << remarks << endl;
    // cout << elective_type << endl;
    // cout << course_type << endl;
    // cout << model << endl;
    // infile.close();

    return 0;
}