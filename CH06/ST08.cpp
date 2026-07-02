#include <iostream>
using namespace std;

struct CourseLevel
{
    char level;
    double fee;
};

CourseLevel discount(CourseLevel oldRecord){
    CourseLevel newRecord = oldRecord;
    newRecord.fee *= 0.9;
    return newRecord;
}