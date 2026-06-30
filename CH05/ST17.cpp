#include <iostream>
using namespace std;

void readNumberArray(){
    int numberArray[10] {};
    cout << "Please enter 10 non negative numbers: " << endl;
    for (int i{}; i < 10; i++){
        cin >> numberArray[i];
        cout << numberArray[i] << " ";
    }
    cout << endl;

}

int main()
{
    readNumberArray();

    return 0;
}