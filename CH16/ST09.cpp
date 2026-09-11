#include <iostream>
using std::cout, std::endl;

template<class T>
class Pair
{
    public:
        Pair();
        Pair(T firstValue, T secondValue);

    private:
        T first;
        T second;
};

template<class T>
Pair<T>::Pair() : {first{}, second{}} {}
