#include <iostream>
#include <string>
using  std::cout, std::endl;
using std::string;

static int failures = 0;

bool matches_here(const char* h, const char* n)
{
    if (*n == '\0') return true;      // if we hit a '\0'in n that means we have exhausted n
    if (*h != *n)   return false;     // characters at the start mismatch
    return matches_here(h + 1, n + 1);// both characters at the start match so we increment both
}

bool contains(const char* haystack, const char* needle)
{
    return matches_here(haystack, needle)
        || (*haystack != '\0' && contains(haystack + 1, needle));
}

// std::string::find is banned in the implementation, but it's perfectly
// legitimate as a TEST ORACLE - a known-correct reference to compare against.
void chk(const char* h, const char* n)
{
    const bool got  {contains(h, n)};
    const bool want {string(h).find(n) != string::npos};
    if (got != want) ++failures;
    cout << (got == want ? "  ok   " : "  FAIL ")
         << "contains(\"" << h << "\", \"" << n << "\") = "
         << (got ? "true" : "false") << "\n";
}

int main()
{
    chk("C++ programming", "ogra");     // Savitch's example: true
    chk("C++ programming", "grammy");   // Savitch's example: false
    chk("hello", "hello");              // needle is the whole haystack
    chk("hello", "h");                  // first character
    chk("hello", "o");                  // last character
    chk("hello", "");                   // empty needle
    chk("", "");                        // both empty
    chk("", "a");                       // empty haystack
    chk("hello", "hello!");             // needle longer than haystack
    chk("aaab", "aab");                 // partial match must restart
    chk("abababc", "ababc");            // repeated prefix
    chk("mississippi", "issip");
    chk("mississippi", "issipi");

    // --- 20000 random cases against the same oracle ---
    unsigned seed = 7;
    auto rnd = [&seed](int n){ seed = seed*1103515245u + 12345u; return (int)((seed>>16) % n); };
    int bad = 0;
    for (int t = 0; t < 20000; ++t){
        string h, n;
        for (int i = 0, L = rnd(12); i < L; ++i) h += char('a' + rnd(3));
        for (int i = 0, L = rnd(4);  i < L; ++i) n += char('a' + rnd(3));
        if (contains(h.c_str(), n.c_str()) != (h.find(n) != string::npos)) ++bad;
    }
    cout << (bad ? "\n  RANDOM MISMATCHES\n"
                 : "\n  20000 random cases agree with std::string::find\n");
    failures += bad;

    cout << (failures ? "\nSOME CHECKS FAILED\n" : "all checks passed\n");
    return failures;
}