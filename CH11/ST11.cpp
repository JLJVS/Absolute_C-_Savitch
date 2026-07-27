#include <iostream>
using namespace std;

namespace Sun
{
    void message();
}

namespace
{
    void message();
}

int main()
{
    {
        message();
        using Sun::message;
        message();
    }
    message();

        cin.get();
    return 0;
}

namespace Sun
{
    void message(){
        cout << "Hello from Sun.\n";
    }
}

namespace
{
    void message(){
        cout << "Hello from the Moon.\n";
    }
}