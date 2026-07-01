#include <iostream>
using namespace std;

double average(const double a[], int size){
    double total {};
    for (int i{}; i < size; i++){
        total += a[i];
    }
    return (double) (total/(double)size);
}

double stdev(const double a[], int size){
    double avg {average(a, size)};
    double std {};

    for (int i{}; i < size; i++){
        std += (a[i] - avg)*(a[i] - avg);
    }
    return (double) (std/(double(size)));
}


int main()
{
    // Test case 1: simple small numbers
    double t1[] {1.0, 2.0, 3.0};
    cout << "Test 1 average: " << average(t1, 3) << endl;
    cout << "Test 1 std: " << stdev(t1, 3) << endl << endl;

    // Test case 2: identical numbers
    double t2[] {5.0, 5.0, 5.0, 5.0};
    cout << "Test 2 average: " << average(t2, 4) << endl;
    cout << "Test 2 std: " << stdev(t2, 4) << endl << endl;

    // Test case 3: mixed positive and negative
    double t3[] {-2.0, 4.0, -1.0, 7.0};
    cout << "Test 3 average: " << average(t3, 4) << endl;
    cout << "Test 3 std: " << stdev(t3, 4) << endl << endl;

    // Test case 4: larger values
    double t4[] {100.0, 200.0, 300.0, 400.0, 500.0};
    cout << "Test 4 average: " << average(t4, 5) << endl;
    cout << "Test 4 std: " << stdev(t4, 5) << endl << endl;

    // Test case 5: decimals
    double t5[] {1.5, 2.5, 3.5, 4.5};
    cout << "Test 5 average: " << average(t5, 4) << endl;
    cout << "Test 5 std: " << stdev(t5, 4) << endl << endl;

    return 0;
}