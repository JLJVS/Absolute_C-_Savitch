#include <iostream>
using namespace std;


int main(){
    int loopid, temp[10];
    for (loopid=0; loopid < 10; loopid++){
        temp[loopid] = 3*loopid;
    }
    for (loopid=9; loopid >= 0; loopid--){
        cout << temp[loopid] << " ";
    }
    cout << endl;
    for (loopid = 0; loopid < 10; loopid = loopid + 2){
        cout << temp[loopid] << " ";
    }


    return 0;
}

