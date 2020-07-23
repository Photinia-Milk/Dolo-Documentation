#include "test.h"

using namespace std;

int main()
{
    srand((unsigned)time(NULL));
    ofstream out;
    out.open("output.txt", ios::out);
    int value_size;
    string table_name, filed, value, *values, insert;

    /* 生成病人 */
    value_size = 5;
    values = new string[value_size];
    filed = " ( p_id, password, name, age, gender ) ";
    table_name = " patient ";
    for (int i = 0; i < PATIENT_SIZE; ++i)
    {
        values[0] = "\"" + to_string(i) + "\"";
        values[1] = "\"" + to_string(rand()) + "\"";
        values[2] = "\"" + to_string(rand()) + "\"";
        values[3] = to_string(rand() % 60 + 15);
        values[4] = to_string(rand() % 2);
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
    }
    delete[] values;

    /* 生成医生 */
    value_size = 5;
    values = new string[value_size];
    table_name = " doctor ";
    filed = " ( d_id, password, name, avg_point, count ) ";
    for (int i = 0; i < DOCTOR_SIZE; ++i)
    {
        values[0] = "\"" + to_string(i) + "\"";
        values[1] = "\"" + to_string(rand()) + "\"";
        values[2] = "\"" + to_string(rand()) + "\"";
        values[3] = "null";
        values[4] = "0";
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
    }
    delete[] values;

    /* 生成部门 */
    value_size = 2;
    values = new string[value_size];
    filed = " ( dept_id, name ) ";
    table_name = " department ";
    for (int i = 0; i < DEPARTMENT_SIZE; ++i)
    {
        values[0] = "\"" + to_string(i) + "\"";
        values[1] = "\"" + to_string(rand()) + "\"";
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
    }
    delete[] values;

    /* 生成门诊 */
    value_size = 8;  
    values = new string[value_size];
    table_name = " outpatient ";
    filed = " ( start_time, end_time, d_id, dept_id, is_open, max_appointment, current_appointment ) ";
    for (int i = 0; i < OUTPATIENT_SIZE; ++i)
    {
        // ID 就让它自增好了，不画蛇添足
        // values[0] = "\"" + to_string(i) + "\"";
        // 每个医生都有早上、中午、下午的门诊
        if (i < DOCTOR_SIZE)
        {
            values[1] = "\"08:30:00\"";
            values[2] = "\"11:30:00\"";
        }
        else if (i < DOCTOR_SIZE * 2)
        {
            values[1] = "\"14:30:00\"";
            values[2] = "\"17:30:00\"";
        }
        else if (i < DOCTOR_SIZE * 3)
        {
            values[1] = "\"18:30:00\"";
            values[2] = "\"23:30:00\"";
        }
        else
        {
            break;
        }
        values[3] = "\"" + to_string(i % DOCTOR_SIZE) + "\"";
        // 该门诊所属部门是随机的
        values[4] = "\"" + to_string(rand() % DEPARTMENT_SIZE) + "\"";
        // 每段门诊有 80 % 机率开门
        if (rand() % 100 < 85)
            values[5] = "1";
        else
            values[5] = "0";
        values[6] = to_string(rand() % 800 + 200);
        values[7] = "0";
        value = "";
        value += " (";
        for (int j = 1; j < value_size; ++j)
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
    }
    delete[] values;

    out.close();
    return 0;
}