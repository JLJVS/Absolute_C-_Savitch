#include <iostream>
#include <fstream>
using namespace std;


int main(void){
    string name {}, highest_name{};
    int score {}, highest_score{}, n{};

    fstream inputStream;
    inputStream.open("scores.txt");

    inputStream >> n;

    for (int i {0}; i < n; i++){
        inputStream >> name;
        inputStream >> score;
        if (score > highest_score){
            highest_score = score;
            highest_name = name;
        }
    }
    cout << highest_name << ", " << highest_score << endl;



    return 0;
}
