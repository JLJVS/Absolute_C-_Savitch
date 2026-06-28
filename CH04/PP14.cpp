#include <iostream>
using namespace std;

int timeDiffMins(int startTime, int endTime){
    
    int startHour {startTime/100}, startMin {startTime%100}, endHour {endTime/100}, endMin {endTime%100};
    int totalMins {};
    totalMins += endMin;
    endMin = 0;
    if (startMin != 0){
        totalMins -= (60-startMin);
        startMin = 0;
    }
    
    if (endHour <= startHour){
        totalMins += (24-startHour)*60;
        startHour = 0;
    }
    
    totalMins += (endHour - startHour)*60;
    return totalMins;
}

int main() {
    // Test case 1: Same-day difference
    int t1_start = 930;   // 09:30
    int t1_end   = 1115;  // 11:15
    cout << "[Test 1] 09:30 -> 11:15 = "
         << timeDiffMins(t1_start, t1_end) << " minutes\n";

    // Test case 2: Crossing midnight
    int t2_start = 2330;  // 23:30
    int t2_end   = 45;    // 00:45
    cout << "[Test 2] 23:30 -> 00:45 = "
         << timeDiffMins(t2_start, t2_end) << " minutes\n";

    // Test case 3: Exactly 24 hours apart
    int t3_start = 700;   // 07:00
    int t3_end   = 700;   // 07:00 next day
    cout << "[Test 3] 07:00 => 07:00 next day = "
         << timeDiffMins(t3_start, t3_end) << " minutes\n";

    return 0;
}