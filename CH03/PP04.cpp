#include <iostream>
using namespace std;

const float G {6.673e-8};

float calc_gravity(){
    float m1{}, m2{}, r{};
    cout << "Please enter the mass of the first object m1: ";
    cin >> m1;
    cout << "Please enter the mass of the second object m2: ";
    cin >> m2;
    cout << "Please enter the distance between the two objects r: ";
    cin >> r;

    float grav = G*m1*m2/r/r ;
    cout << "The grativational force will be " << grav << " g cm/sec" << endl;
    return grav;
}

int main()
{
    calc_gravity();


    return 0;
}