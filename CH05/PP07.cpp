#include <iostream>
using namespace std;

void generate_hist(const int grades[], int size){
    int counts[6] {0, 0, 0, 0, 0, 0};
    for (int i{}; i < size; i++){
        counts[grades[i]]++;
    }
    for (int i{}; i < 6; i++){
        cout << counts[i] << " grade(s) of " << i << endl;
    }
}

int main() {
    // ---------- Test 1 ----------
    int g1[] {0, 1, 2, 3, 4, 5};
    cout << "Test 1\nGrades: 0 1 2 3 4 5\n";
    generate_hist(g1, 6);
    cout << "\n";

    // ---------- Test 2 ----------
    int g2[] {3, 3, 3, 3, 3, 3, 3};
    cout << "Test 2\nGrades: 3 3 3 3 3 3 3\n";
    generate_hist(g2, 7);
    cout << "\n";

    // ---------- Test 3 ----------
    int g3[] {5, 5, 0, 1, 1, 2};
    cout << "Test 3\nGrades: 5 5 0 1 1 2\n";
    generate_hist(g3, 6);
    cout << "\n";

    // ---------- Test 4 ----------
    int g4[] {0, 0, 0, 0};
    cout << "Test 4\nGrades: 0 0 0 0\n";
    generate_hist(g4, 4);
    cout << "\n";

    // ---------- Test 5 ----------
    int g5[] {1, 4, 2, 5, 3, 2, 1, 0, 5, 4};
    cout << "Test 5\nGrades: 1 4 2 5 3 2 1 0 5 4\n";
    generate_hist(g5, 10);
    cout << "\n";

    return 0;
}
