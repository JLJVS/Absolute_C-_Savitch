#include <iostream> 
using namespace std;

void doesnt_change_params(int x){
    x++;
}

void does_change_params(int &x){
    x++;
}

int main()
{
    int x{1};
    
    cout << "initial state x: " << x << endl;
    doesnt_change_params(x);
    cout << "After calling by value: " << x << endl;
    does_change_params(x);
    cout << "After calling by reference: " << x << endl;



    return 0;
}

/*


*/