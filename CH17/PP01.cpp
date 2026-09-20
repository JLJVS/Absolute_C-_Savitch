#include <iostream>
#include <vector>
#include <string>

using std::cout, std::vector, std::string, std::endl;

class Node
{
public:
    Node(int theData, Node* theLink) : data(theData), next(theLink) {}

    Node* getLink() const        { return next; }
    int   getData() const        { return data; }
    void  setData(int newData)   { data = newData; }
    void  setLink(Node* pointer) { next = pointer; }

private:
    int   data;
    Node* next;
};


// =========================================================== YOUR FUNCTION ==z

void reverse(Node*& head)
{
    // TODO
    Node* prev = nullptr;
    Node* current = head;
    while (current != nullptr){
        Node* nextOne = current->getLink();
        current->setLink(prev);
        prev = current;
        current = nextOne;
    }
    head = prev;
    
}

// ============================================================================


// ------------------------------------------------------------- helpers -----

// Builds values[0] -> values[1] -> ... Returns the head (nullptr if empty).
Node* buildList(const vector<int>& values)
{
    Node* head = nullptr;
    for (int i = static_cast<int>(values.size()) - 1; i >= 0; --i)
        head = new Node(values[i], head);
    return head;
}

void freeList(Node*& head)
{
    while (head != nullptr){
        Node* nextOne = head->getLink();    // save BEFORE deleting
        delete head;
        head = nextOne;
    }
}

vector<int> toVector(const Node* head)
{
    vector<int> out;
    for (const Node* p = head; p != nullptr; p = p->getLink())
        out.push_back(p->getData());
    return out;
}

// The node ADDRESSES, in list order. Used to prove that reverse() rearranged
// the existing nodes rather than rebuilding the list.
vector<const Node*> addresses(const Node* head)
{
    vector<const Node*> out;
    for (const Node* p = head; p != nullptr; p = p->getLink())
        out.push_back(p);
    return out;
}

string show(const vector<int>& v)
{
    if (v.empty()) return "(empty)";
    string s;
    for (size_t i = 0; i < v.size(); ++i){
        if (i) s += " -> ";
        s += std::to_string(v[i]);
    }
    return s;
}


// --------------------------------------------------------------- tests -----

static int failures = 0;

void check(const char* label, const vector<int>& got, const vector<int>& want)
{
    const bool ok = (got == want);
    if (!ok) ++failures;
    cout << (ok ? "  ok   " : "  FAIL ") << label << "  " << show(got) << "\n";
    if (!ok) cout << "         expected  " << show(want) << "\n";
}

void checkReverse(const char* label, const vector<int>& values)
{
    Node* head = buildList(values);
    const vector<const Node*> before = addresses(head);

    reverse(head);

    const vector<int> want(values.rbegin(), values.rend());
    check(label, toVector(head), want);

    // The spec's other half: same nodes, no allocation, no deletion.
    const vector<const Node*> after = addresses(head);
    const vector<const Node*> beforeReversed(before.rbegin(), before.rend());
    const bool sameNodes = (after == beforeReversed);
    if (!sameNodes) ++failures;
    cout << (sameNodes ? "  ok     " : "  FAIL   ")
         << "same nodes, reversed order (nothing created or destroyed)\n";

    freeList(head);
}

int main()
{
    checkReverse("empty      ", {});
    checkReverse("one node   ", {7});
    checkReverse("two nodes  ", {1, 2});         // where off-by-one shows up
    checkReverse("five nodes ", {1, 2, 3, 4, 5});
    checkReverse("duplicates ", {4, 4, 9, 4});   // order matters, not values

    cout << (failures ? "\nSOME CHECKS FAILED\n" : "\nall checks passed\n");
    return failures;
}