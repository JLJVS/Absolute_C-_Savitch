#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int calc_weight(int feet, int inches){

    int weight{};
    if (feet < 5){
        return -1;
    }
    weight = 110 + (feet-5)*12*5 + inches*5;
    return weight;
}


int main(void)
{
    string name{}, feetstr{}, inchstr{};
    int feet{}, inches{}, weight{};
    

    ifstream file("heights.txt");

    if (!file.is_open()){
        cerr << "Error: Could not open file!" << endl;
        return 1;
    }

    while (getline(file, name)) {
        getline(file, feetstr);
        getline(file, inchstr);
        feet = stoi(feetstr);
        inches = stoi(inchstr);
        cout << name << endl;
        cout << feet << " " << inches << endl;
        cout << "Ideal boy weight: " << calc_weight(feet, inches) << " lb" << endl << endl;
    }




    return 0;
}