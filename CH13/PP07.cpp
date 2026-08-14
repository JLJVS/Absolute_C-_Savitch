#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>
using std::cout, std::endl;
using std::setw;

// works upto n=45 otherwise use long/ std::int64_t
int fib_rec(int n){
    if (n==1 || n==0){
        return 1;
    } else if (n < 0 ){
        return 0; // values smaller than 0 not allowed
    } else {
        return fib_rec(n-1) + fib_rec(n-2);
    }
}

// works upto n=45 otherwise use long/ std::int64_t
int fib_iter(int n){
    if (n == 1 || n == 0){
        return 1;
    } else if (n < 1){
        return 0;
    } else {
        int vals[2]={1, 1};
        int temp {};
        for (int i=1; i<n; i++){
            temp = vals[1];
            vals[1] = vals[1] + vals[0];
            vals[0] = temp;
            
        }
        return vals[1];
    }
}
    

int fib_memo_helper(int n , std::vector<int>& memo){
    if (n< 0) return 0;
    if (n == 0 || n == 1){
        return 1;
    }
    if (memo[n] != 0 ){
        return memo[n];
    }

    memo[n] = fib_memo_helper(n-1, memo) + fib_memo_helper(n-2, memo);
    return memo[n];
}

int fib_memo(int n){
    if (n < 0 ){
        return 0;
    }
    std::vector<int> memo(n+1, 0);
    return fib_memo_helper(n, memo);
}


double time_call(int (*f)(int), int n, int reps){
    auto t0 = std::chrono::steady_clock::now();
    volatile int sink {0};
    for (int r{0}; r<reps; ++r) sink = f(n);
    (void)sink;
    std::chrono::duration<double> dt {std::chrono::steady_clock::now() - t0};
    return dt.count() / reps;
}

int main(){
    const int expected[] {1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987};
    int failures {0};

    cout << "--- correctness (n = 0..15) ---\n";
    cout << "   n   fib_rec  fib_iter  fib_memo  expected\n";
    for (int n {0}; n < 16; ++n){
        const int r {fib_rec(n)}, i {fib_iter(n)}, m {fib_memo(n)};
        const bool ok {r == expected[n] && i == expected[n] && m == expected[n]};
        if (!ok) ++failures;
        cout << (ok ? "  " : "! ") << setw(2) << n
             << setw(9) << r << setw(10) << i << setw(10) << m
             << setw(10) << expected[n] << "\n";
    }

    cout << "\n--- iter and memo agree all the way to the int limit ---\n";
    int mismatches {0};
    for (int n {0}; n <= 45; ++n) if (fib_iter(n) != fib_memo(n)) ++mismatches;
    cout << (mismatches ? "  MISMATCHES FOUND\n" : "  yes, n = 0..45\n");
    failures += mismatches;

    cout << "\n--- edge cases ---\n";
    cout << "  fib_iter(45) = " << fib_iter(45) << "   (largest fitting in int)\n";
    cout << "  fib_memo(45) = " << fib_memo(45) << "\n";
    cout << "  fib_rec(-3)  = " << fib_rec(-3)
         << "   fib_iter(-3) = " << fib_iter(-3)
         << "   fib_memo(-3) = " << fib_memo(-3) << "\n";
    cout << "  fib_memo(0)  = " << fib_memo(0) << "   (vector of size 1)\n";

    cout << "\n--- seconds per call ---\n";
    cout << "   n     recursive      memoised     iterative\n";
    for (int n : {20, 25, 30, 35, 40, 42}){
        cout << setw(4) << n
             << setw(14) << std::scientific << std::setprecision(3) << time_call(fib_rec,  n, 1)
             << setw(14) << time_call(fib_memo, n, 100000)
             << setw(14) << time_call(fib_iter, n, 1000000) << "\n";
    }

    cout << (failures ? "\nSOME CHECKS FAILED\n" : "\nall checks passed\n");
    return failures;
}