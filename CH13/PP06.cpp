#include <iostream>
#include <chrono>
#include <iomanip>
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
    cout << "   n  fib_rec  fib_iter  expected\n";
    for (int n{0}; n<16; ++n){
        int r{fib_rec(n)}, i{fib_iter(n)};
        bool ok {r==expected[n] && i==expected[n]};
        if (!ok) ++failures;
        cout << (ok?"  ":"! ") << setw(2) << n << setw(9) << r << setw(10) << i
             << setw(10) << expected[n] << "\n";
    }

    cout << "\n--- the two agree for n = 0..30 ---\n";
    int mismatches {0};
    for (int n{0}; n<=30; ++n) if (fib_rec(n) != fib_iter(n)) ++mismatches;
    cout << (mismatches ? "  MISMATCHES FOUND\n" : "  yes\n");
    if (mismatches) ++failures;

    cout << "\n--- edge cases ---\n";
    cout << "  fib_iter(45) = " << fib_iter(45) << "   (largest that fits in int)\n";
    cout << "  fib_rec(-3)  = " << fib_rec(-3)  << "\n";
    cout << "  fib_iter(-3) = " << fib_iter(-3) << "\n";

    cout << "\n--- timing (seconds per call) ---\n";
    cout << "   n      recursive      iterative        ratio\n"; 
    for (int n : {20,25,30,35,40,42}){
        double tr {time_call(fib_rec,  n, 1)};
        double ti {time_call(fib_iter, n, 1000000)};
        cout << setw(4) << n
             << setw(15) << std::scientific << std::setprecision(3) << tr
             << setw(15) << ti
             << setw(13) << std::fixed << std::setprecision(0) << (tr/ti) << "x\n";
    }
    cout << (failures ? "\nSOME CHECKS FAILED\n" : "\nall checks passed\n");
    return failures;
}