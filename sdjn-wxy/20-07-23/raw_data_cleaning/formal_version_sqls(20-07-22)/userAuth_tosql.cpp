#include "tosql.h"

using namespace std;

int main(){
    ofstream out;
    out.open("userauth.sql", ios::out);
    int value_size;
    string table_name, filed, value, *values, insert;

    value_size = 3;
    values =new string[value_size];
    filed = " ( userName, password, type ) ";
    table_name = " userauth ";
    for (int i = 0; i < 231; ++i)
    {
        values[0] = "\"teacher" + to_string(i) + "\"";
        values[1] = "\"123456\"";
        values[2] = "\"teacher\"";
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
    
    value_size = 3;
    values =new string[value_size];
    filed = " ( userName, password, type ) ";
    table_name = " userauth ";
    for (int i = 0; i < 10000; ++i)
    {
        values[0] = "\"student" + to_string(i) + "\"";
        values[1] = "\"123456\"";
        values[2] = "\"student\"";
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