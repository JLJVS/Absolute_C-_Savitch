#include <iostream>
using namespace std;

int main()
{
    cout << "Please give a multi digit number: \n";
    long num{};
    cin >> num;
    int total{};
    while (num){
        total += num%10;
        num /= 10;
    }
    cout << "The sum of the digits is " << total << endl;

    return 0;
}