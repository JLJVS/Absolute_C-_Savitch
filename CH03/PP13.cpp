#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void select_three_winners(){
    srand(time(0));
    int winner1{}, winner2{}, winner3{};
    while (winner1==winner2 || winner1==winner3 || winner2==winner3){
        winner1 = rand()%5000 + 1;
        winner2 = rand()%5000 + 1;
        winner3 = rand()%5000 + 1;
    }
    cout << "And the three prize winners are: " << winner1 << ", " << winner2 << ", " << winner3 << endl; 
}

int main()
{
    select_three_winners();
    return 0;
}