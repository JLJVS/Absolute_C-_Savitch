#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
using namespace std;

void getHighScore(string &highScoreName, int &highScore)
{
    ifstream file("scores.txt");
    if (!file) {
        std::cerr << "Could not open file\n";
        return;
    }

    string name {};
    int score {};
    while (file >> name >> score){
        if (score > highScore){
            highScore = score;
            highScoreName = name;
        }
    }
}

int main()
{
    string name {};
    int score {};

    getHighScore(name, score);
    cout << "The highest scoring player was: " << name << " with a score of: " << score << endl;


    return 0;
}