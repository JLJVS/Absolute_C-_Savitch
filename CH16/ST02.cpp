#include <iostream>
using std::cout, std::endl;

template<class T>
T absolute(T val){
    return val < 0 ? -val : val;
}

int main()
{
    int a {1}, b{-2}, c {};
    float d {- 3}, e {1.5}, f{};
    double g{}, h { -6.5};

    cout << absolute(a) << endl;
    cout << absolute(b) << endl;
    cout << absolute(c) << endl;
    cout << absolute(d) << endl;
    cout << absolute(e) << endl;
    cout << absolute(f) << endl;
    cout << absolute(g) << endl;
    cout << absolute(h) << endl;
    
    return 0;
}