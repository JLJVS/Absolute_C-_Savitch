#include <iostream>
using namespace std;

int main()
{
    cout << "Please enter a whole number: ";
    int num {};
    cin >> num;
    cout << "Type of num: " << typeid(num).name() << std::endl;
    cout <<"You entered: " << num << endl;


    return 0;
}