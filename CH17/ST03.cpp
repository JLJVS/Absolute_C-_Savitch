#include <iostream>
#include <string>
using std::cout, std::endl;
using std::string;

struct ListNode
{
    string item;
    int count;
    ListNode *link;
};

int main()
{   
    
    ListNode *head = new ListNode;
    head -> item = "Wilbur's brother Orville";


    return 0;
}
