#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool check_for_hit(float hitrate){
    int num {rand()%1000};
    return hitrate*1000 >= num;
}

bool highest_first() {
    float a_hr = 0.33, b_hr = 0.5, c_hr = 1.0;
    bool a_alive = true, b_alive = true, c_alive = true;

    while (a_alive && (b_alive || c_alive)) {

        // A shoots
        if (c_alive) {
            if (check_for_hit(a_hr)) c_alive = false;
        } else if (b_alive) {
            if (check_for_hit(a_hr)) b_alive = false;
        }

        // B shoots
        if (b_alive) {
            if (c_alive) {
                if (check_for_hit(b_hr)) c_alive = false;
            } else if (a_alive) {
                if (check_for_hit(b_hr)) a_alive = false;
            }
        }

        if (!a_alive) return false;

        // C shoots
        if (c_alive) {
            if (b_alive) {
                if (check_for_hit(c_hr)) b_alive = false;
            } else if (a_alive) {
                if (check_for_hit(c_hr)) a_alive = false;
            }
        }

        if (!a_alive) return false;
    }

    return a_alive;
}
    


bool miss_first() {
    float a_hr = 0.33, b_hr = 0.5, c_hr = 1.0;
    bool a_alive = true, b_alive = true, c_alive = true;

    bool a_has_missed_first = false;

    while (a_alive && (b_alive || c_alive)) {

        //  A SHOOTS
        if (!a_has_missed_first) {
            // A intentionally misses the first shot
            a_has_missed_first = true;
        } else {
            // After that, A shoots normally
            if (c_alive) {
                if (check_for_hit(a_hr)) c_alive = false;
            } else if (b_alive) {
                if (check_for_hit(a_hr)) b_alive = false;
            }
        }

        // --- B SHOOTS ---
        if (b_alive) {
            if (c_alive) {
                if (check_for_hit(b_hr)) c_alive = false;
            } else if (a_alive) {
                if (check_for_hit(b_hr)) a_alive = false;
            }
        }

        if (!a_alive) return false;

        // --- C SHOOTS ---
        if (c_alive) {
            if (b_alive) {
                if (check_for_hit(c_hr)) b_alive = false;
            } else if (a_alive) {
                if (check_for_hit(c_hr)) a_alive = false;
            }
        }

        if (!a_alive) return false;
    }

    return a_alive;
}






int main()
{
    srand(time(0));

    int a_highest_first_wins {}, a_miss_first_wins{}, N_rounds {10000};
    for (int i{0}; i < N_rounds; i++){
        a_highest_first_wins += highest_first();
        a_miss_first_wins += miss_first();
    }
    cout << "Highest first: " << a_highest_first_wins << "/10000 wins" << endl;
    cout << "Miss first: " << a_miss_first_wins << "/10000 wins" << endl;



    return 0;
}