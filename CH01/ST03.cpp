#include <iostream>
using namespace std;

int main()
{
    char a {'a'};
    int b {1};
    float c {2.5};
    double d {1.000000000001};

    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";
    std::cout << "c: " << c << "\n";
    std::cout << "d: " << d << "\n";

    return 0;
}