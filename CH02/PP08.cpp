#include <iostream>
using namespace std;

int main(void)
{
    int celsius {100}, fahrenheit {};
    while (celsius != fahrenheit){
        fahrenheit = 9/5.*celsius + 32;
        cout << "Celsius: " << celsius << ",\t Fahrenheit: " << fahrenheit << endl;
        if (celsius == fahrenheit) break;
        celsius--;
    }
    
    return 0;
}