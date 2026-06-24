#include <iostream>
using namespace std;

void timeConverter(int hour, int minutes){
    char timestamp[4] = {'A', '.', 'M', '.'}; 
    if (hour >12){
        hour -= 12;
        timestamp[0] = 'P';
    }

    cout << hour <<":"<< minutes << " ";
    for (int i{0}; i<4; i++){
        cout << timestamp[i];
    }
    cout << endl;
}

void time_question()
{   
    int hour{}, mins{};
    while (true){
        cout << "Please enter a 24h time to be converted to exit enter -1 for either:\nHours:";
        cin >> hour;
        cout << "minutes: ";
        cin >> mins;
        if (hour == -1){
            break;
        }
        if (mins == -1){
            break;
        }
        if ((hour < 0) || (hour > 23) || (mins < 0) || (mins > 59)){
            cout << "invalid time entered" << endl;
            continue;
        }
        timeConverter(hour, mins);
    }
}

int main()
{



    time_question();
    return 0;
}