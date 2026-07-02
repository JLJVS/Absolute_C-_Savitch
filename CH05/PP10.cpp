#include <iostream>
using namespace std;

void consolidate_scores(int a[], int size_a, int b[], int size_b, int consolidated[]){
    
    int index_a {}, index_b{};
    for (int index{}; index < size_a + size_b; index++){
        int val_a {}, val_b {};
        if (index_a < size_a){
            val_a = a[index_a];
        }
        if (index_b < size_b){
            val_b = b[index_b];
        }
        
        if (val_a > val_b){
            consolidated[index] = val_a;
            index_a++;
        } else{
            consolidated[index] = val_b;
            index_b++;
        }
    }
}

void print_array(int arr[], int size) {
    cout << "[";
    for (int i {}; i < size; i++) {
        cout << arr[i] << (i < size - 1 ? ", " : "");
    }
    cout << "]" << endl;
}


int main() {
    // --- TEST CASE 1: Standard overlapping arrays ---
    int a1[] = {90, 70, 50};
    int b1[] = {85, 80, 40, 30};
    const int size_a1 = 3, size_b1 = 4;
    
    // Pre-allocate the array on the stack
    int res1[size_a1 + size_b1]; 
    consolidate_scores(a1, size_a1, b1, size_b1, res1);
    
    cout << "Test 1 Expected: [90, 85, 80, 70, 50, 40, 30]\nResult:   ";
    print_array(res1, size_a1 + size_b1);
    cout << "-------------------------------------------\n";

    // --- TEST CASE 2: One array entirely greater than the other ---
    int a2[] = {100, 95, 90};
    int b2[] = {20, 10};
    const int size_a2 = 3, size_b2 = 2;
    
    int res2[size_a2 + size_b2];
    consolidate_scores(a2, size_a2, b2, size_b2, res2);
    
    cout << "Test 2 Expected: [100, 95, 90, 20, 10]\nResult:   ";
    print_array(res2, size_a2 + size_b2);
    cout << "-------------------------------------------\n";

    // --- TEST CASE 3: Arrays with equal values ---
    int a3[] = {5, 1, 0};
    int b3[] = {10, 3, 1};
    const int size_a3 = 3, size_b3 = 3;
    
    int res3[size_a3 + size_b3];
    consolidate_scores(a3, size_a3, b3, size_b3, res3);
    
    cout << "Test 3 Expected: [10, 5, 3, 1, 1, 0]\nResult:   ";
    print_array(res3, size_a3 + size_b3);

    return 0;
}