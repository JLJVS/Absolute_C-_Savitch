#include <iostream>
using namespace std;

void friendly();
void shy(int audienceCount);


int main(void)
{
    friendly();
    shy(6);
    cout << "one more time\n";
    shy(2);
    friendly();
    cout << "End of the program\n";
    
    return 0;
}

void friendly(){
    cout << "Hello\n";
}

void shy(int n){
    if (n < 5){
        return ;
    } 
    cout << "Goodbye\n";
}