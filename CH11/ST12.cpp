#include <iostream>
using namespace std;

namespace Outer
{
    void message();
    namespace Inner
    {
        void message();
    }
}

int main()
{
    // message(); <- message is not defined in the global scope.
    Outer::message();
    Outer::Inner::message();
    using namespace Outer;
    Inner::message();
    return 0;
}

namespace Outer
{
    void message(){
        cout << "Outer.\n";
    }

    namespace Inner
    {
        void message()
        {
            cout << "Inner.\n";
        }
    }
}