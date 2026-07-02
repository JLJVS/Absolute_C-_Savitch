#include <iostream>
using namespace std;

struct Student
{
    int rollno;
    char name[80];
    long totalmarks;
    float weight;
    float height;
    int semester;
    char hometown[90];
};

int main()
{
    Student student1, st2;

    // a
    // student1.totalmarks -> not a member of the struct student
    // b student1.weight -> float;
    // c Student.semester -> adresses the struct instead of the instances
    // d st2.hometown -> returns a char array
    // e st2 -> type student
    return 0;
}