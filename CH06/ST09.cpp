#include <iostream>
using namespace std;

class DayOfYear
{
    public:
        void input();
        void output();
        int month;
        int day;
};

void DayOfYear::input( )
{
    cout  << "Please enter an integer for your desired month: ";
    cin >> month;
    cout << "Please enter an integer for your desired day: ";
    cin >> day;
}


int main()
{
    DayOfYear d {};
    d.input();
    cout << d.month << endl;
    cout << d.day << endl;

    return 0;
}