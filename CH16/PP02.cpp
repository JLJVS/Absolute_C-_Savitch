#include <iostream>
#include <vector>
#include <string>
using std::cout, std::endl, std::vector, std::string;

template <class T>
int bin_search(const T a[], int low, int high, const T& target){
    
    if (low >= high) {return -1;}
    int middle = low + (high-low)/2;
    if (a[middle] < target){
        return bin_search(a, middle+1, high, target);
    } else if (target < a[middle]){
        return bin_search(a, low, middle, target);
    } else {
        return middle;
    }
}

static int failures = 0;

// The harness is itself a template, so it works for every element type.
template<class T>
void check(const char* label, const T a[], int size, const T& target, int want)
{
    const int got = bin_search(a, 0, size, target);
    if (got != want) ++failures;
    cout << (got == want ? "  ok   " : "  FAIL ") << label
         << " -> " << got << "   (expect " << want << ")\n";
}

int main()
{
    const int nums[] {4, 8, 15, 16, 23, 42};          // size 6
    check("int   first  ", nums, 6, 4,  0);
    check("int   middle ", nums, 6, 16, 3);
    check("int   last   ", nums, 6, 42, 5);
    check("int   below  ", nums, 6, 1, -1);
    check("int   above  ", nums, 6, 99, -1);
    check("int   gap    ", nums, 6, 20, -1);
    check("int   empty  ", nums, 0, 4, -1);
    check("int   size 1 ", nums, 1, 4,  0);
    check("int   size 1 ", nums, 1, 8, -1);

    const double reals[] {0.5, 1.5, 2.5, 3.5};        // size 4
    check("double hit   ", reals, 4, 2.5,  2);
    check("double miss  ", reals, 4, 2.0, -1);

    const char letters[] {'a', 'c', 'e', 'g', 'i'};   // size 5
    check("char   hit   ", letters, 5, 'e',  2);
    check("char   miss  ", letters, 5, 'b', -1);

    const string names[] {"alpha", "bravo", "charlie", "delta"};
    check("string hit   ", names, 4, string{"charlie"},  2);
    check("string miss  ", names, 4, string{"zulu"},    -1);

    // check("string lit  ", names, 4, "charlie", 2);
    //   ^ won't compile: T deduces as std::string from the array and as
    //     const char* from the target.

    cout << (failures ? "\nSOME CHECKS FAILED\n" : "\nall checks passed\n");
    return failures;
}