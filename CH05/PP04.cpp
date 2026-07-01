#include <iostream>
using namespace std;

void countValues(const int a[], int size){
    int values[50][2] = {};

    for (int i {}; i < size; i++){
        int val {a[i]};
        for (int j{}; j <=i; j++){
            if (values[j][0] == val){
                values[j][1]++;
                break;
            } else if ((values[j][0] == 0)&&(values[j][1] == 0)){
                values[j][0] = val;
                values[j][1]++;
                break;
            }
        }
    }
    cout << "N\tCount" << endl;
    for (int i{}; i < size; i++){
        int val {values[i][0]}, count{values[i][1]};
        if ((val == 0)&&(count == 0)){
            break;
        }
        cout << val << "\t" << count << endl; 
    }

}

int main()
{
    // Test case 1: simple repeated values
    int t1[] {1, 2, 1, 3, 2, 1};
    cout << "Test Case 1:" << endl;
    countValues(t1, 6);
    cout << endl;

    // Test case 2: all identical values
    int t2[] {5, 5, 5, 5};
    cout << "Test Case 2:" << endl;
    countValues(t2, 4);
    cout << endl;

    // Test case 3: includes zero and negatives
    int t3[] {0, -1, -1, 2, 0, 2};
    cout << "Test Case 3:" << endl;
    countValues(t3, 6);
    cout << endl;

    // Test case 4: no repeats
    int t4[] {10, 20, 30, 40, 50};
    cout << "Test Case 4:" << endl;
    countValues(t4, 5);
    cout << endl;

    // Test case 5: mixed pattern
    int t5[] {7, 7, 8, 9, 7, 8, 10};
    cout << "Test Case 5:" << endl;
    countValues(t5, 7);
    cout << endl;

    return 0;
}