#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    cout << "Please enter a number for the random seed: ";
    int seed{};
    cin >> seed;
    srand(seed);

    for (int i{1}; i<=10; i++){
        cout << (float) (rand()%1001)/1000 << " ";
        if (i%5==0){
            cout << endl;
        } 
    }
    
    return 0;
}