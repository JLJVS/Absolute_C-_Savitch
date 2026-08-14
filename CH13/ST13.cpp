// rose seems to be the faculty function n: n!
#include <iostream>
using std::cout, std::endl;

int rose(int n);

int main()
{
    cout << rose(4) << endl;
    return 0;
}

int rose(int n)
{
    if (n<=0){
        return 1;
    } else {
        return (rose(n-1)*n);
    }
}