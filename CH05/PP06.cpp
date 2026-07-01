#include <iostream>
using namespace std;

void scoring(float scores[], float difficulty, int size=7){
    float highest {scores[0]}, lowest{scores[0]}, total {};
    int highest_index {}, lowest_index {};
    for (int i {1}; i < size; i++){
        if (scores[i] > highest){
            highest = scores[i];
            highest_index = i;
        }
        if (scores[i] < lowest){
            lowest = scores[i];
            lowest_index = i;
        }
    }
    for (int i{}; i < size; i++){
        if ( (i==highest_index) || (i==lowest_index) ){
            continue;
        }
        total += scores[i];
    }

    total *= difficulty;
    cout << "Total score: " << total/0.6 << endl;
}

int main() {
    // ---------- Test 1: Simple mixed scores ----------
    float s1[] {6.0, 7.5, 8.0, 9.0, 5.5, 7.0, 8.5};
    cout << "Test 1\nScores: 6.0 7.5 8.0 9.0 5.5 7.0 8.5\nDifficulty: 2.0\n";
    scoring(s1, 2.0);
    cout << "\n";

    // ---------- Test 2: All judges similar ----------
    float s2[] {8.0, 8.1, 8.2, 8.3, 8.4, 8.5, 8.6};
    cout << "Test 2\nScores: 8.0 8.1 8.2 8.3 8.4 8.5 8.6\nDifficulty: 3.0\n";
    scoring(s2, 3.0);
    cout << "\n";

    // ---------- Test 3: Very low and very high ----------
    float s3[] {1.0, 9.5, 8.0, 7.5, 9.0, 2.0, 8.5};
    cout << "Test 3\nScores: 1.0 9.5 8.0 7.5 9.0 2.0 8.5\nDifficulty: 1.5\n";
    scoring(s3, 1.5);
    cout << "\n";

    // ---------- Test 4: Repeated highest/lowest ----------
    float s4[] {5.0, 5.0, 9.0, 9.0, 7.0, 7.0, 7.0};
    cout << "Test 4\nScores: 5.0 5.0 9.0 9.0 7.0 7.0 7.0\nDifficulty: 2.5\n";
    scoring(s4, 2.5);
    cout << "\n";

    // ---------- Test 5: Edge case — all equal ----------
    float s5[] {7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.0};
    cout << "Test 5\nScores: 7.0 7.0 7.0 7.0 7.0 7.0 7.0\nDifficulty: 1.0\n";
    scoring(s5, 1.0);
    cout << "\n";

    return 0;
}
