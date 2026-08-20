 
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
 
using std::cout, std::vector, std::string, std::setw;

 
void hanoi(int n, char from, char to, char spare)
{
    if (n <= 0) return;
 
    hanoi(n - 1, from, spare, to);                       // first we move the smaller disks of
    cout << "  disk " << n << ":  " << from << " -> " << to << "\n"; // move the largest disk
    hanoi(n - 1, spare, to, from);                       // move the smaller disks back on top of the largest disk
}

long long hanoi_moves(int n)
{
    if (n <= 0) return 0;
    return hanoi_moves(n - 1) + 1 + hanoi_moves(n - 1);
}
 
 
// Create a struct to better keep track of the moves 
struct Move { int disk; char from, to; };
 

void hanoi_record(int n, char from, char to, char spare, vector<Move>& out)
{
    if (n <= 0) return;
    hanoi_record(n - 1, from, spare, to, out);
    out.push_back({n, from, to});
    hanoi_record(n - 1, spare, to, from, out);
}
 
 
// Replays a move sequence on three real posts and checks every rule.
// Returns "" if the sequence is valid, otherwise a description of the failure.
string validate(int n, const vector<Move>& moves)
{
    vector<int> post[3];                                  // 0='A', 1='B', 2='C'
    for (int d {n}; d >= 1; --d) post[0].push_back(d);    // largest at the bottom
 
    for (size_t k {0}; k < moves.size(); ++k){
        const Move& m {moves[k]};
        const int f {m.from - 'A'}, t {m.to - 'A'};
        const string where {" at move " + std::to_string(k + 1)};
 
        if (f < 0 || f > 2 || t < 0 || t > 2)   return "bad post letter" + where;
        if (f == t)                             return "source == destination" + where;
        if (post[f].empty())                    return "source post empty" + where;
        if (post[f].back() != m.disk)           return "disk not on top of source" + where;
        if (!post[t].empty() && post[t].back() < m.disk)
            return "larger disk placed on smaller" + where;
 
        post[f].pop_back();
        post[t].push_back(m.disk);
    }
 
    if (!post[0].empty() || !post[2].empty())  return "disks left behind";
    if (static_cast<int>(post[1].size()) != n) return "wrong number on destination";
    for (int i {0}; i < n; ++i)
        if (post[1][i] != n - i)               return "destination out of order";
 
    return "";
}
 
 
// ----------------------------------------------------------------- tests ---
 
int main()
{
    int failures {0};
 
    cout << "--- n = 3, the moves ---\n";
    hanoi(3, 'A', 'B', 'C');
 
    cout << "\n--- every generated sequence is legal and finishes correctly ---\n";
    for (int n {0}; n <= 14; ++n){
        vector<Move> moves;
        hanoi_record(n, 'A', 'B', 'C', moves);
 
        const string err {validate(n, moves)};
        const bool right_length {static_cast<long long>(moves.size()) == (1LL << n) - 1};
 
        if (!err.empty() || !right_length){
            ++failures;
            cout << "  FAIL n=" << n << ": "
                 << (err.empty() ? "wrong move count" : err) << "\n";
        }
    }
    if (!failures)
        cout << "  n = 0..14 all valid, all of length 2^n - 1 (32,752 moves checked)\n";
 
    cout << "\n--- move counts ---\n";
    cout << "   n         moves        2^n - 1\n";
    for (int n : {1, 2, 3, 5, 10, 20, 25}){
        const long long got {hanoi_moves(n)};
        const long long want {(1LL << n) - 1};      // 1LL, not 1: int shifts break past n=31
        if (got != want) ++failures;
        cout << setw(4) << n << setw(14) << got << setw(15) << want
             << (got == want ? "" : "   MISMATCH") << "\n";
    }
 
    cout << "\n--- the monks ---\n";
    const double m64 {18446744073709551615.0};          // 2^64 - 1
    cout << "  64 disks: " << std::scientific << std::setprecision(3) << m64 << " moves\n";
    cout << "  at one move per second: " << m64 / (60.0 * 60 * 24 * 365.25) << " years\n";
 
    cout << (failures ? "\nSOME CHECKS FAILED\n" : "\nall checks passed\n");
    return failures;
}
 