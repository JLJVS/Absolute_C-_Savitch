#include <iostream>
#include <string>
using std::cout, std::endl;
using std::string;

struct Box
{
    string name;
    int number;
    Box *next;
};

typedef Box* BoxPtr;

int main()
{
    
    BoxPtr head;
    head = new Box;
    head->name = "Sally";
    head->number=18;

    cout << (*head).name <<endl;
    cout << head->name <<endl;
    cout << (*head).number <<endl;
    cout << head->number << endl;
    return 0;
}
