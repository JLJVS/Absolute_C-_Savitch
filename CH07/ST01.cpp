#include <iostream>
using namespace std;

class UGClass
{
    public:
        UGClass( int r, char s){
            RegNo = r; 
            Section = s;
        };
        UGClass(){};
        void EnrollExam();
    private:
        int RegNo;
        char Section;
};

int main()
{
    UGClass student1(14565, 'E');   // allowed
    UGClass student2;               // allowed
    // UGClass student3();          // not allowed if you want to initialize like this you should use braces {}
    student1 = UGClass(10789, 'D'); // allowed
    student1 = UGClass( );          // allowed
    // student1 = UGClass;          // not allowed
    return 0;
}