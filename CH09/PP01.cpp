#include <iostream>
#include <cstring>
using namespace std;

const int SIZE {101};


int main()
{
    char line[SIZE];
    cin.getline(line, SIZE);

    char ans_str[SIZE] {};
    int ans_index = {};
    for(int index{}; line[index] != '\0'; index++){
        if (line[index] == ' ' && line[index+1] == ' '){
            continue;
        } else {
            ans_str[ans_index] = line[index];
            ans_index++;
        }
    }
    ans_str[ans_index+1] = '\0';
    cout << ans_str << endl;
    return 0;
}