#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool check_for_hit(float hitrate){
    int num {rand()%1000};
    return hitrate*1000 >= num;
}

bool highest_first(){
    float a_hr {0.33}, b_hr{0.5}, c_hr {1};
    bool a_alive {true}, b_alive {true}, c_alive {true};
    while (a_alive){
        // first let a shoot
        if (c_alive){
            if (check_for_hit(a_hr)){
                c_alive = false;
            }
        } else if (b_alive){
            if (check_for_hit(a_hr)){
                b_alive = false;
            }
        } else {
            return true;
        }

        // let b shoot if alive
        if (c_alive){
            if (check_for_hit(b_hr)){
                c_alive = false;
            }         
        } else if (a_alive){
            if (check_for_hit(b_hr)){
                return  false;
            }    
        } else {
            return false;
        }

        // let c shoot if alive
        if (b_alive){
            if (check_for_hit(c_hr)){
                b_alive = false;
            }         
        } else if (a_alive){
            if (check_for_hit(c_hr)){
                return false;
            }    
        } else {
            return false;
        }
    return false;
    }
}
    


bool miss_first(){
    float a_hr {0.33}, b_hr{0.5}, c_hr {1}, n {};
    bool a_alive {true}, b_alive {true}, c_alive {true};
    while (a_alive){
        // first let a shoot
        if (n==0){
            n++;
        } else if (c_alive){
            if (check_for_hit(a_hr)){
                c_alive = false;
            }
        } else if (b_alive){
            if (check_for_hit(a_hr)){
                b_alive = false;
            } else {
                return true;
            }
        }

        // let b shoot if alive
        if (c_alive){
            if (check_for_hit(b_hr)){
                c_alive = false;
            }         
        } else if (a_alive){
            if (check_for_hit(b_hr)){
                return false;
            }    
        } else {
            return false;
        }

        // let c shoot if alive
        if (b_alive){
            if (check_for_hit(c_hr)){
                b_alive = false;
            }         
        } else if (a_alive){
            if (check_for_hit(c_hr)){
                return false;
            }    
        } else {
            return false;
        }

    }
    return false;
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