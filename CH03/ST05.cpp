#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main(void){

    for (int i{}; i < 51; i++){
        cout << 5 + (rand()%6) << "\t";
        if (i%10==0){
            cout << endl;
        }
    }
    
    return 0;
}