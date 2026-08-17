#include <iostream>
using std::cout, std::endl;

void hanoi(int n, char from, char to, char spare)
{
    if (n <= 0) return;

    hanoi(n - 1, from, spare, to);                      // clear the small ones off
    cout << "  disk " << n << ":  " << from << " -> " << to << "\n";
    hanoi(n - 1, spare, to, from);                      // put them back on top
}

// Same recursion, counting instead of printing.
long long hanoi_moves(int n)
{
    if (n <= 0) return 0;
    return hanoi_moves(n - 1) + 1 + hanoi_moves(n - 1);
}