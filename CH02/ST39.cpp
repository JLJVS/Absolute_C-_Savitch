#include <iostream>
#include <fstream>
using namespace std;


int main(void){
    string name {};
    int score {}, n{};

    fstream inputStream;
    inputStream.open("scores.txt");

    inputStream >> n;

    for (int i {0}; i < n; i++){
        inputStream >> name;
        inputStream >> score;
        cout << name << ", " << score << endl;
    }
    



    return 0;
}
