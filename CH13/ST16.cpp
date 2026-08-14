#include <iostream>
using std::cout, std::endl;

bool even(int num);
bool odd(int num);


bool even(int num){
    if (num==0){
        return true;
    } else {
        return odd(num-1);
    }
}

bool odd(int num){
    if (num==0){
        return false;
    } else {
        return even(num-1);
    }
}

int main()
{
    cout << even(7) << endl;
    cout << even(8) << endl;
    cout << odd(7) <<endl;
    return 0;
}