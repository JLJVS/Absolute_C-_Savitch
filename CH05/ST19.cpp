#include <iostream>
using namespace std;

bool search(const int a[], int numberUsed, int target, int& where){

    bool found {false};
    for (int i {}; i < numberUsed; i++){
        if (a[i] == target){
            found = true;
            where = i;
            return found;
        }
    }
    return found;
}

int main() {
    // Test array
    const int SIZE = 5;
    int arr[SIZE] = {10, 20, 30, 20, 40};
    int numberUsed = 5;
    int location;
    // Test 1: Target exists (first occurrence)
    int target1 = 20;
    if (search(arr, numberUsed, target1, location)) {
        cout << target1 << " found at index " << location << endl;
    } else {
        cout << target1 << " not found" << endl;
    }
    // Test 2: Target exists at beginning
    int target2 = 10;
    if (search(arr, numberUsed, target2, location)) {
        cout << target2 << " found at index " << location << endl;
    } else {
        cout << target2 << " not found" << endl;
    }
    // Test 3: Target does not exist
    int target3 = 99;
    if (search(arr, numberUsed, target3, location)) {
        cout << target3 << " found at index " << location << endl;
    } else {
        cout << target3 << " not found" << endl;
    }
    // Test 4: Empty array
    int emptyArr[1] = {0};
    int target4 = 5;
    if (search(emptyArr, 0, target4, location)) {
        cout << target4 << " found at index " << location << endl;
    } else {
        cout << target4 << " not found in empty array" << endl;
    }
    return 0;
}