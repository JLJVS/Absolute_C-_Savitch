#include <iostream>
using namespace std;

const int N {20};

void addTwoLargeNumbers(char a[], int size_a, char b[], int size_b){
    char result[N] {};
    int reversed_a[N] {}, reversed_b[N] {};

    // Reverse digits and convert ASCII → integer 0–9
    for (int i = 0; i < size_a; i++){
        reversed_a[i] = a[size_a - 1 - i] - '0';
    }
    for (int i = 0; i < size_b; i++){
        reversed_b[i] = b[size_b - 1 - i] - '0';
    }

    int carry = 0;
    for (int i = 0; i < N; i++){
        int sum = carry;

        if (i < size_a) sum += reversed_a[i];
        if (i < size_b) sum += reversed_b[i];

        carry = sum / 10;
        result[i] = (sum % 10) + '0';   // convert back to ASCII digit
    }

    // Print result in correct order
    bool started = false;

    if (carry > 0) cout << carry;

    for (int i = N - 1; i >= 0; i--){
        if (!started && result[i] == '0') continue;
        started = true;
        cout << result[i];
    }

    if (!started) cout << "0"; // handle case 0 + 0
}
int main() {
    // ---------- Test 1 ----------
    char a1[] {"1234"};
    char b1[] {"5678"};
    cout << "Test 1\n";
    cout << "Expected:\t6912\n";
    cout << "Your func:\t";
    addTwoLargeNumbers(a1, 4, b1, 4);
    cout << "\n\n";

    // ---------- Test 2 ----------
    char a2[] {"99999"};
    char b2[] {"1"};
    cout << "Test 2\n";
    cout << "Expected:\t100000\n";
    cout << "Your func:\t";
    addTwoLargeNumbers(a2, 5, b2, 1);
    cout << "\n\n";

    // ---------- Test 3 ----------
    char a3[] {"123456789012345678"};
    char b3[] {"987654321098765432"};
    cout << "Test 3\n";
    cout << "Expected:\t1111111110111111110\n";
    cout << "Your func:\t";
    addTwoLargeNumbers(a3, 18, b3, 18);
    cout << "\n\n";

    // ---------- Test 4 ----------
    char a4[] {"0"};
    char b4[] {"0"};
    cout << "Test 4\n";
    cout << "Expected:\t0\n";
    cout << "Your func:\t";
    addTwoLargeNumbers(a4, 1, b4, 1);
    cout << "\n\n";

    // ---------- Test 5 ----------
    char a5[] {"100000000000000000"};
    char b5[] {"999"};
    cout << "Test 5\n";
    cout << "Expected:\t100000000000000999\n";
    cout << "Your func:\t";
    addTwoLargeNumbers(a5, 18, b5, 3);
    cout << "\n\n";

    return 0;
}