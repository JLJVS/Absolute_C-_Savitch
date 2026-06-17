#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void Benford(string file_name){
    int nums[10]{0,0,0,0,0,0,0,0,0,0}, num{}, N{};

    ifstream file(file_name);
    if (!file.is_open()){
        cerr << "Error: Could not open file!" << endl;
        return;
    }

    while (file >> num){
        num = abs(num);
        while (num >= 10){
            num/=10;
        }
        nums[num]++;
    }
    

    for (int i{1}; i < 10; i++){
        N += nums[i];
    }
    if (N == 0){
        return;
    }
    float percentages[10] = {0,0,0,0,0,0,0,0,0,0};
    cout << "Digit :\tPercentage"<<endl;
    for (int i{1}; i < 10; i++){
        percentages[i] = float(nums[i])/ (float) N;
        cout << i << "\t: " << percentages[i] << endl;
    }

}


int main()
{
    string f {"nums.txt"};
    Benford(f);

    return 0;
}