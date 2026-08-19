#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
using std::cout, std::endl;
using std::string;
using std::setw;

void reverse_range(char a[], int first, int last)
{
    if (last <= first)
    {
        return;
    } else 
    {
        char temp = a[first];
        a[first] = a[last];
        a[last] = temp;
        return reverse_range(a, first+1, last-1);
    }
    
}

void reverse_string(char s[]){
    int last = static_cast<int>(std::strlen(s)) -1;
    reverse_range(s, 0, last);
}

static int failures = 0;

void check_range(const char* input, int first, int last, const char* want)
{
    char buf[64];
    std::strcpy(buf, input);
    reverse_range(buf, first, last);
    const bool ok = (std::strcmp(buf, want) == 0);
    if (!ok) ++failures;
    cout << (ok ? "  ok   " : "  FAIL ")
         << "\"" << input << "\" (" << first << "," << last << ") -> \""
         << buf << "\"   want \"" << want << "\"\n";
}

void check_string(const char* input, const char* want)
{
    char buf[64];
    std::strcpy(buf, input);
    reverse_string(buf);
    const bool ok = (std::strcmp(buf, want) == 0);
    if (!ok) ++failures;
    cout << (ok ? "  ok   " : "  FAIL ")
         << "reverse_string(\"" << input << "\") -> \"" << buf
         << "\"   want \"" << want << "\"   (len still " << std::strlen(buf) << ")\n";
}

int main()
{
    cout << "--- Savitch's example: 1-based, index 0 is a spare ---\n";
    check_range("?ABCDE", 2, 5, "?AEDCB");

    cout << "\n--- ranges ---\n";
    struct Case { const char* in; int first, last; const char* want; };
    const Case cases[] {
        {"ABCDEF", 0, 5, "FEDCBA"},   // whole, even length
        {"ABCDE",  0, 4, "EDCBA"},    // whole, odd length
        {"ABCDE",  1, 3, "ADCBE"},    // interior
        {"ABCDE",  1, 2, "ACBDE"},    // adjacent pair
        {"ABCDE",  2, 2, "ABCDE"},    // single element, no change
        {"ABCDE",  3, 2, "ABCDE"},    // empty range, no change
        {"A",      0, 0, "A"},        // one-character array
    };
    for (const Case& c : cases) check_range(c.in, c.first, c.last, c.want);

    cout << "\n--- reversing twice returns the original (500 random cases) ---\n";
    unsigned seed = 12345;
    auto rnd = [&seed](int n){ seed = seed * 1103515245u + 12345u; return (seed >> 16) % n; };
    int bad = 0;
    for (int t = 0; t < 500; ++t){
        char x[21], original[21];
        int n = 1 + static_cast<int>(rnd(20));
        for (int i = 0; i < n; ++i) x[i] = static_cast<char>('a' + rnd(26));
        x[n] = '\0';
        std::strcpy(original, x);
        int f = static_cast<int>(rnd(n)), l = static_cast<int>(rnd(n));
        reverse_range(x, f, l);
        reverse_range(x, f, l);
        if (std::strcmp(x, original) != 0) ++bad;
    }
    cout << (bad ? "  FAILURES\n" : "  all 500 round-trip correctly\n");
    failures += bad;

    cout << "\n--- reverse_string ---\n";
    check_string("hello", "olleh");
    check_string("ab",    "ba");
    check_string("a",     "a");
    check_string("",      "");             // strlen-1 == -1, base case must cope
    check_string("racecar", "racecar");    // palindrome, unchanged
    check_string("hello world", "dlrow olleh");

    cout << (failures ? "\nSOME CHECKS FAILED\n" : "\nall checks passed\n");
    return failures;
}