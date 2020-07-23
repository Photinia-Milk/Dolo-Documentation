#include "tosql.h"

using namespace std;

// class Student {
// public:
//     string name;
//     string user_name;
//     string dept_name;
//     string grade;
//     bool gender;
//     string admisson_date;
//     string country;
//     string document_type;
//     string birthday;
//     string phone;

//     Student(){}
// };

int main(){
    srand((unsigned)time(NULL));
    ofstream out;
    out.open("student.sql", ios::out);
    int value_size;
    string table_name, filed, value, *values, insert;

    string *departments = new string[13];
    departments[0] = "农业与生物学院";
    departments[1] = "电子信息与电气工程学院";
    departments[2] = "机械与动力工程学院";
    departments[3] = "马克思主义学院";
    departments[4] = "设计学院";
    departments[5] = "船舶海洋与建筑工程学院";
    departments[6] = "航空航天学院";
    departments[7] = "环境科学与工程学院";
    departments[8] = "材料科学与工程学院";
    departments[9] = "物理与天文学院";
    departments[10] = "化学化工学院";
    departments[11] = "安泰经济与管理学院";
    departments[12] = "凯原法学院";

    string *grade = new string[7];
    grade[0] = "大一";
    grade[1] = "大二";
    grade[2] = "大三";
    grade[3] = "大四";
    grade[4] = "研一";
    grade[5] = "研二";
    grade[6] = "研三";

    /* 生成学生表 */
    value_size = 10;
    values =new string[value_size];
    filed = " ( userName, name, deptName, grade, gender, admissonDate, country, documentType, phone, address) ";
    table_name = " student ";
    for (int i = 0; i < PATIENT_SIZE; ++i)
    {
        int academic_year_bar = rand()%6;
        values[0] = "\"student" + to_string(i) + "\"";
        values[1] = "\"学生" + to_string(i) + "\"";
        values[2] = "\"" + departments[rand()%12] + "\"";
        values[3] = "\"" + grade[academic_year_bar] + "\"";
        values[4] = to_string(rand() % 2);
        values[5] = "\"" + to_string(2020 - academic_year_bar) + "-09-01\"";
        values[6] = "\"\"";
        values[7] = "\"\"";
        values[8] = "\"\"";
        values[9] = "\"\"";
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
        out << insert;
        cout << insert;
    }
    delete[] values;
    out.close();
}