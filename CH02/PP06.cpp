#include <iostream>
using namespace std;

int main()
{
    float gamma_water{62.4}, r{}, V{}, pi{3.14}, weight{}, g{9.81};
    float Fb{}, Fz{};

    cout << "Please enter the weight of an orb and the radius in this order: ";
    cin >> weight >> r;
    V = 4/3*pi*r*r*r;
    Fb = V * gamma_water;
    Fz = g * weight;
    
    if (Fb > Fz){
        cout << "The sphere will float" << endl;
    }else {
        cout <<  "The sphere will sink" << endl; 
    }





    return 0;
}