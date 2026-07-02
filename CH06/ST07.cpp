#include <iostream>
using namespace std;

struct CourseLevel
{
    char level;
    double fee;
};

void readCourseRecord(CourseLevel& newCourse){
    cout << "Enter course level: ";
    cin >> newCourse.level;
    cout << "Enter course fee: ";
    cin >> newCourse.fee;
}