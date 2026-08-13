#include <iostream>
using std::cout;
void cheers(int n);

int main() // outputs hip hip hurray
{
    cheers(3);
    return 0;
}
void cheers(int n)
{
   for (int i=n; i>0; i--){
        if (i>1){
            cout << "Hip ";
        }
        else {
            cout << "Hurray.";
        }
   }
}