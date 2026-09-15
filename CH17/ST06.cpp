#include <iostream>
using std::cout, std::endl;
struct Node
{
    double data;
    Node *next;

};

typedef Node * Pointer;

int main(){
    Pointer p1, p2;

    p1 = new Node;
    p1-> data = 1;
    p2 = new Node;
    p2 -> data = 2;
    p1 -> next = p2;
    cout << p1 -> data << endl;
    cout << p1 -> next -> data << endl;
    return 0;
}


