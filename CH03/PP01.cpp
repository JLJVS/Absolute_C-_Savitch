#include <iostream>
using namespace std;

/*
Employees are paid out 12% of the total sales done in a month. Write a program that calculates the total sales based on the incentive received.

*/

float total_sales(float incentive){

    return incentive/0.12;
}

int main()
{
    cout << "total sales was 10000 and we calculated: " << total_sales(10000*.12) << endl;



    return 0;
}