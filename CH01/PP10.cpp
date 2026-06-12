#include <iostream>
using namespace std;

int main(void)
{
    const float acceleration{32};
    float time{};

    cout << "Please enter a time for the object to be falling: " << endl;
    cin >> time;

    cout << "The object in freefall will have fallen " << 0.5*acceleration*time*time << " feet" << endl;



    return 0;
}