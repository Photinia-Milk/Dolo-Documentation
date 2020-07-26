#include "tosql.h"

using namespace std;

class timeslot {
public:
    int id;
    int starttime;
    int endtime;
    string day;
    timeslot(int t_id, int t_st, int t_et, string t_d);
    bool operator == (timeslot &rec) const;
};

timeslot::timeslot(int t_id, int t_st, int t_et, string t_d)
{
    id = t_id;
    starttime = t_st;
    endtime = t_et;
    day = t_d;
}

// 重载类相等函数
// 相同的class对象互为友元，所以可以访问private对象。== 是二元操作符，class内隐藏了this
bool timeslot::operator==(timeslot & rec) const
{
    return this->day == rec.day
        && this->starttime == rec.starttime
        && this->endtime == rec.endtime;
}