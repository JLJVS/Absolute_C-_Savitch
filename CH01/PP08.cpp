#include <iostream>
using namespace std;

/*
Babylonian algorithm to compute the square root ofa positive number n is as follows:
1. Makes a guess at the answer (you can pick n/2 as your initial guess)
2. compute r = n/guess
3. set guess = (guess+r)/2
4. go back to step 2 for as many itereations as necessary. The more steps 2 and 3 are repeated, the closer guess will become to the square root of n.
*/
int main(void)
{   
    // first set double printing precision to two decimal places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    double num{}, guess{}, r{};
    cout << "Please enter a number to find the square root of: " << endl;
    cin >> num;
    guess = num/2;
    for (int i = 0; i < 5; i++){
        r = num/guess;
        guess = (guess+r)/2;
    }

    cout << "After 5 iterations we have estimated the square root of " << num << " to be " << guess << endl;

    return 0;
}