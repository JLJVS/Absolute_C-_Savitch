#include <iostream>
#include <chrono>
#include <iomanip>
using std::cout, std::endl;
using std::setw;

// works upto n=45 otherwise use long/ std::int64_t
int fib(int n){
    if (n==1 || n==0){
        return 1;
    } else if (n < 0 ){
        return 0; // values smaller than 0 not allowed
    } else {
        return fib(n-1) + fib(n-2);
    }
}

int main(){
    // Savitch's indexing: F0 = 1, F1 = 1, F2 = 2, F3 = 3, F4 = 5, ...
    const int expected[] {1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987};
    int failures {0};

    cout << "--- correctness ---\n";
    for (int n {0}; n < 16; ++n){
        int got {fib(n)};
        bool ok {got == expected[n]};
        if (!ok) ++failures;
        cout << (ok ? "  ok   " : "  FAIL ") << "fib(" << setw(2) << n << ") = "
             << setw(4) << got << "   expected " << setw(4) << expected[n] << "\n";
    }
    cout << (failures ? "  SOME FAILURES\n" : "  all correct\n");

    cout << "\n--- cost as n grows ---\n";
    for (int n : {20, 25, 30, 35, 38, 40, 42}){
        auto t0 = std::chrono::steady_clock::now();
        int v {fib(n)};
        std::chrono::duration<double> dt {std::chrono::steady_clock::now() - t0};
        cout << setw(4) << n << setw(14) << v << setw(12) << std::fixed
             << std::setprecision(4) << dt.count() << "\n";
    }
    return failures;
}