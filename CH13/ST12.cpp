// mystery seems to be sum of 1 to n.

#include <iostream>
using std::cout, std::endl;

int mystery(int n);

int main()
{
    cout << mystery(3) <<endl;
    return 0;
}

int mystery(int n)
{
    if (n <= 0){
        return 1;
    }
    else{
        return(mystery(n-1)+n);

    }
}