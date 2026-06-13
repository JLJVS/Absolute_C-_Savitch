#include <iostream>
using namespace std;


int main(void)
{
    double savings{40e3}, expenses{25e3};

    if (savings > expenses){
        savings -= expenses;
        cout << "solvent" << endl;
    } else {
        cout << "Bankrupt" << endl;
    }


    return 0;
}