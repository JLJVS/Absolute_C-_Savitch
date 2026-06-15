#include <iostream>
using namespace std;


int main(void)
{
    int n {150};
    if (n < 0){
        cout << "n is smaller than zero" << endl;
    } else if (n<=100){
        cout << "0<=n<=100" << endl;
    } else
        cout << "n = 100" << endl;



    return 0;
}