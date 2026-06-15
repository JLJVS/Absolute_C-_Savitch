#include <iostream>
using namespace std;

int quadratic(int x){
    return x*x;
}

int main()
{
    // a
    float total {0};
    for (float f {1}; abs(f-10)>0.1; f++){
        total += (1/f);
    }
    cout << "a: total = " << total << endl << endl;

    // b
    float grades[5] {6,7,8,9,5};
    total = 0;
    for (int i=0; i < 5; i++){
        total += (grades[i]/5);
    }
    cout << "b: total = " << total << endl << endl;


    // c
    int sick_days[10] {0, 0, 1, 5, 3, 4, 2, 1, 0, 0};
    total = 0;
    for (int i=0; i < 10; i++){
        total += grades[i];
    }
    cout << "c: total = " << total << endl << endl;

    // d
    int x_test_values[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "d: Quadratic test" << endl;
    for (int i = 0; i < 10; i++){
        cout << "x: " << i << " : quadratic(" << i << ") = " << quadratic(i) << endl;
    }

    return 0;
}