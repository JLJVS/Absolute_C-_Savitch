#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

template<class T>
int search(const T a[], int numberUsed, T target)
{
    int index = 0;
    bool found = false;
    while ((!found) && (index < numberUsed)){
        if (target == a[index]){
            found = true;
        } else {
            index++;
        }
    } 
    return found ? index : -1;

}

int main()
{
    int nums[] {4, 8, 15, 16, 23, 42};
    cout << "int    16 -> " << search(nums, 6, 16) << "   (expect 3)\n";
    cout << "int    99 -> " << search(nums, 6, 99) << "   (expect -1)\n";

    double reals[] {1.5, 2.5, 3.5};
    cout << "double 2.5 -> " << search(reals, 3, 2.5) << "   (expect 1)\n";

    char letters[] {'a', 'b', 'c', 'd'};
    cout << "char   'c' -> " << search(letters, 4, 'c') << "   (expect 2)\n";

    string names[] {"Alice", "Bob", "Carol"};
    cout << "string Bob -> " << search(names, 3, string{"Bob"}) << "   (expect 1)\n";

    cout << "empty range -> " << search(nums, 0, 4) << "   (expect -1)\n";

    // search(names, 3, "Bob");   // deliberately commented out - see below
    return 0;
}