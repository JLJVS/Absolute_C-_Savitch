#include <iostream>
using namespace std;

int main(void)
{
    int age{18}, nationality {91};
    if ((age>=18) && (nationality==91)){
        cout << "Eligible to vote." << endl;
    } else {
        cout << "Not Eligible to Vote." << endl;
    }



    return 0;
}