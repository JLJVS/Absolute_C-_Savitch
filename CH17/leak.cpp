#include <iostream>
int main()
{
    int* p = new int[100];      // deliberately never deleted
    std::cout << "allocated 400 bytes, not freeing them\n";
    return 0;
}