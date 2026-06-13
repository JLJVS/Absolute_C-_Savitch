#include <iostream>
using namespace std;


int main(void)
{
    int count {0}, limit{10};
    bool res {};

    // a
    cout << "a: " << (count == 0) && (limit < 20) ;
    cout << endl;

    // b 
    res =  count == 0 && limit < 20;
    cout << "b: " <<  res <<  endl;

    // c
    cout << "c: " << ( (limit > 20) || (count < 5));
    cout << endl;

    // d
    cout << "d: " << !(count == 12);
    cout << endl;

    // e compiler throws erros because x and y are not defined 
    // res = (count == 1) && (x<y)
    // cout << res;
    // cout << endl;

    // f compiler throws erros because x and y are not defined 
    // cout << (count < 10) || (x < y);
    // cout << endl;

    // g compiler throws erros because x and y are not defined 
    // cout << !((count<10)||(x<y)&&(count >= 0));
    // cout << endl;

    // h compiler throws an error because you try to divide by 0
    // res = ((limit / count) > 7) || (limit < 20);
    // cout << "h: " << res;
    // cout << endl;

    // i doesn't throw an error because the first check in the or is 1 
    cout << "i: " << (limit < 20) || ((limit/count)>7);
    cout << endl;

    // j compiler throws an error because you try to divide by 0
    // cout << "j: " << ((limit / count) > 7) && (limit < 0);
    // cout << endl;
   
    // k  compiler throws an error because you try to divide by 0
    // cout << "k: " << (limit < 0 ) && ((limit/count)> 7);
    // cout << endl;

    
    // l 
    cout << "l: " << (5&&7) + (!6);
    cout << endl;

    return 0;
}