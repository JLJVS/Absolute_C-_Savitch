#include <iostream>
using namespace std;


int main(void)
{
    int totalSeconds{}, hours{}, minutes{}, seconds{};
    cout << "Please enter a time in seconds to be converted to hours, minutes and seconds: " << endl;

    cin >>  totalSeconds;
    hours = totalSeconds/3600;
    minutes = (totalSeconds%3600)/60;
    seconds = totalSeconds - hours*3600 - minutes*60;

    cout << totalSeconds <<" seconds converts to " << hours << " hours, " << minutes << " minutes and " << seconds << " seconds." << endl;



    return 0;
}