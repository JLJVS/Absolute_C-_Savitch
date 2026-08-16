#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>
using std::cout, std::endl;
using std::vector;
using std::setw;

int choose(int n, int r)
{
    if (n < 0 || r < 0 || r > n)
    {
        return 0;
    } 
    if (r == 0 || r == n)
    {
        return 1;   
    }
    return choose(n-1, r-1) + choose(n-1, r);
}

int choose_memo_helper(int n, int r, vector<vector<int>>& memo)
{
    if (n < 0 || r < 0 || r > n)
    {
        return 0;
    } 
    if (r == 0 || r == n)
    {
        return 1;
    }        
    if (memo[n][r] != -1)
    {
        return memo[n][r];
    }        

    memo[n][r] = choose_memo_helper(n-1, r-1, memo) + choose_memo_helper(n-1, r, memo);
    return memo[n][r];
}

int choose_memo(int n, int r)
{
    if (n < 0 || r < 0 || r > n)
    {
        return 0;
    } 
    vector<vector<int>> memo(n + 1, vector<int>(r + 1, -1));
    return choose_memo_helper(n, r, memo);
}


void enumerate(int n, int r, int start, vector<int>& current, long long& count)
{
    if (static_cast<int>(current.size()) == r){ ++count; return; }
 
    for (int i {start}; i < n; ++i){
        current.push_back(i);
        enumerate(n, r, i + 1, current, count);
        current.pop_back();
    }
}
 
long long count_bruteforce(int n, int r)
{
    if (r < 0 || n < 0 || r > n) return 0;
    vector<int> current;
    long long count {0};
    enumerate(n, r, 0, current, count);
    return count;
}

int main(){
    int failures {0};

    // --- 1. cross-check both against the brute-force enumerator ---
    cout << "--- choose vs choose_memo vs brute force, n,r = 0..12 ---\n";
    int mismatches {0};
    for (int n {0}; n <= 12; ++n)
        for (int r {0}; r <= 12; ++r){
            const long long b {count_bruteforce(n, r)};
            if (choose(n, r) != b || choose_memo(n, r) != b){
                ++mismatches;
                cout << "  MISMATCH n=" << n << " r=" << r
                     << " brute=" << b << " choose=" << choose(n, r)
                     << " memo=" << choose_memo(n, r) << "\n";
            }
        }
    cout << (mismatches ? "  MISMATCHES FOUND\n" : "  all 169 pairs agree\n");
    failures += mismatches;

    // --- 2. known values ---
    cout << "\n--- known values ---\n";
    struct Case { int n, r, want; };
    const Case cases[] { {0,0,1}, {5,0,1}, {5,5,1}, {5,2,10},
                         {10,5,252}, {12,6,924}, {30,15,155117520},
                         {5,6,0}, {5,-1,0} };
    for (const Case& c : cases){
        const int got {choose_memo(c.n, c.r)};
        const bool ok {got == c.want};
        if (!ok) ++failures;
        cout << (ok ? "  ok   " : "  FAIL ")
             << "C(" << setw(2) << c.n << "," << setw(3) << c.r << ") = "
             << setw(10) << got << "   expected " << setw(10) << c.want << "\n";
    }

    // --- 3. it really is Pascal's triangle ---
    cout << "\n--- Pascal's triangle, rows 0..8 ---\n";
    for (int n {0}; n <= 8; ++n){
        cout << "  " << setw(12 - n) << "";
        for (int r {0}; r <= n; ++r) cout << setw(4) << choose(n, r);
        cout << "\n";
    }

    // --- 4. cost of not memoising ---
    cout << "\n--- seconds per call ---\n";
    cout << "   n   r        naive           memo         ratio\n";
    struct Timing { int n, r; };
    const Timing timings[] { {20,10}, {25,12}, {30,15} };
    for (const Timing& t : timings){
        auto t0 = std::chrono::steady_clock::now();
        volatile int a = choose(t.n, t.r); (void)a;
        const std::chrono::duration<double> dn {std::chrono::steady_clock::now() - t0};

        auto t1 = std::chrono::steady_clock::now();
        volatile int b = 0;
        for (int k {0}; k < 10000; ++k) b = choose_memo(t.n, t.r);
        (void)b;
        const std::chrono::duration<double> dm {std::chrono::steady_clock::now() - t1};

        const double naive {dn.count()}, memo {dm.count() / 10000};
        cout << setw(4) << t.n << setw(4) << t.r
             << setw(14) << std::scientific << std::setprecision(3) << naive
             << setw(15) << memo
             << setw(12) << std::fixed << std::setprecision(0) << naive / memo << "x\n";
    }

    cout << (failures ? "\nSOME CHECKS FAILED\n" : "\nall checks passed\n");
    return failures;
}