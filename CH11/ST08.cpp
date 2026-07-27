#include <iostream>
using namespace std;

namespace Hello
{
    void message();
}

namespace GoodBye
{
    void message();
}

void message();

int main()
{
    message();
    using GoodBye::message;
    {
        using Hello::message;
        message;
        GoodBye::message();
    }
    message();
    Hello::message();
    message();
    return 0;
}

void message()
{
    cout << "Global message.\n";
}

namespace Hello
{
    void message(){
        cout << "Hello,\n";
    }    
}

namespace GoodBye
{
    void message(){
        cout << "Good-Bye.\n";
    }
}