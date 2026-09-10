#include <iostream>
using std::cout, std::endl;

template<class T>
T minimum(T t1, T t2){
    return t1 > t2 ? t2 : t1;
}

int main()
{
    int a {0}, b{1};
    cout << minimum(a, b) << endl;

    double c{2.5}, d{0.1};
    cout << minimum(c, d) << endl;

    return 0;
}