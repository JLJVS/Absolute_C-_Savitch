#include <iostream>
using namespace std;

void output(const double a[], int size);
void droppOdd(int a[], int size);


/*
output shouldn't change the input array so it should be const
droppOdd wants to change the input aray so should not be const!
*/