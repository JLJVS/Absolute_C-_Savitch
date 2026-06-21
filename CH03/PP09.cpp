#include <iostream>
#include <cstdlib>
using namespace std;

int roll_game(){
    int d1 {rand()%6 +1}, d2 {rand()%6 +1}, total {d1+d2};
    if ((total==7) | (total==11)){
        return 1;
    } else if ((total==2)|(total==3)|(total==12)){
        return 0;
    } else {
        int point{total};
        while (true){
            d1 = rand()%6 + 1;
            d2 = rand()%6 +1;
            total = d1 + d2;
            if (point == total){
                return 1;
            } else if (total == 7);
                return 0;
        }
    }


    
}


int main(){

    int N {10000};
    float wins{};
    for (int i{}; i<N; i++){
        wins += roll_game();
    }
    cout << "Total wins after 10000 games: " << wins << endl;
    cout << "Win percentage: " << wins/N << endl;

    return 0;
}