#include <iostream>
using namespace std;

char even_or_odd(int n){
    return n%2==0 ? 'E' : 'O';
}



int main(void)
{
    for (int i{-5}; i<5 ; i++){
        cout << "i=  " << i << "\t - \t" <<  even_or_odd(i) << endl;
    }

    return 0;
}