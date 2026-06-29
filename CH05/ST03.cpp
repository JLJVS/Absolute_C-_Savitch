/*
Identify any erros in the following array declarations
a) int m[4] = {12, 3, 8, 4, 3, 0, -7, 5}
-- size mismatch should be int m[]
b) int m[] = {5, 3, 5226, -54, 0 , 34 , 2, 1, 2, 111, 2, 1};
-- works fine
c)  const int TOTALITEMS = 400;
    int items[TOTALITEMS]; 
-- works fine
*/  


#include <iostream>
using namespace std;

int main()
{
    // a 
    int m[] = {12, 3, 8, 4, 3, 0, -7, 5};
    // b
    int n[] = {5, 3, 5226, -54, 0 , 34 , 2, 1, 2, 111, 2, 1};
    // c
    const int TOTALITEMS = 400;
    int items[TOTALITEMS]; 
    return 0;
}