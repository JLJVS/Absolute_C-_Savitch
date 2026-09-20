// Absolute C++ (Savitch, 5th ed) - Chapter 17, Programming Project 2
// mergeLists - splice two sorted linked lists into one.
//
//   g++ -std=c++20 -Wall -Wextra -g -fsanitize=address,undefined PP17_02_merge_lists.cpp -o merge
//   ./merge
//
// SPEC
//   Two call-by-reference pointer arguments, each the head of a list of int
//   sorted smallest first. Returns a pointer to the head of a list containing
//   all the nodes from both, also sorted smallest to largest. The function
//   neither creates nor destroys any nodes. When the call ends, both argument
//   pointers should be NULL.
//
// WHAT IS NEW HERE, COMPARED WITH 12.6 AND 17.1
//
//   The algorithm is the one from 12.6 - look at both heads, take the smaller,
//   advance that side - but you are SPLICING rather than copying. In 12.6 you
//   read ints out of two streams and wrote them to a third; here you unlink
//   existing nodes and relink them into the result. Nothing is allocated.
//
//   And both inputs must end up NULL. That is the spec's way of saying the
//   nodes now belong to the merged list: after the call, naming them through
//   the old pointers would be meaningless. It is ownership transfer done by
//   hand, and it is the idea std::move later makes the compiler enforce.
//
// TWO IMPLEMENTATION NOTES
//
//   Keep a TAIL pointer. Walking to the end of the result on every append
//   would make the whole thing O(n^2).
//
//   The first node is a special case, because there is no tail yet. Handle it
//   with an if, or look up the "dummy head" trick which removes the special
//   case at the cost of one throwaway node.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::cout, std::vector, std::string;


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


// =========================================================== YOUR FUNCTION ==

Node* mergeLists(Node*& list1, Node*& list2)
{
    // TODO
    Node* merged = nullptr;
    if (list1 && list2){
        if (list1->getData() < list2->getData())
        {
            merged = list1;
            list1 = list1->getLink();
        } else {
            merged = list2;
            list2 = list2->getLink();
        }
    } else if (list1){
        merged = list1;
        list1 = list1 -> getLink();
    } else if (list2){
        merged = list2;
        list2 = list2 -> getLink();
    }
    Node* start = merged;
    while (list1 || list2)
    {
        if (list1 && list2){
            if (list1->getData() < list2->getData()){
                merged->setLink(list1);
                list1 = list1->getLink();
            } else {
                merged->setLink(list2);
                list2 =list2->getLink();
            }
        } else if (list1){
            merged->setLink(list1);
            list1 = list1->getLink();
        } else if (list2){
            merged->setLink(list2);
            list2 = list2->getLink();
        }
        merged = merged->getLink();
    }
    
    return start;
}

// ============================================================================


// ------------------------------------------------------------- helpers -----

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
        Node* nextOne = head->getLink();
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
        if (i) s += " ";
        s += std::to_string(v[i]);
    }
    return s;
}


// --------------------------------------------------------------- tests -----

static int failures = 0;

void report(const char* what, bool ok)
{
    if (!ok) ++failures;
    cout << (ok ? "    ok    " : "    FAIL  ") << what << "\n";
}

void checkMerge(const char* label, const vector<int>& a, const vector<int>& b)
{
    cout << "  " << label << ":  [" << show(a) << "]  +  [" << show(b) << "]\n";

    Node* list1 = buildList(a);
    Node* list2 = buildList(b);

    const vector<const Node*> before1 = addresses(list1);
    const vector<const Node*> before2 = addresses(list2);

    Node* merged = mergeLists(list1, list2);

    // 1. the values come out sorted and complete
    vector<int> want(a);
    want.insert(want.end(), b.begin(), b.end());
    std::sort(want.begin(), want.end());
    const vector<int> got = toVector(merged);
    const bool values_ok = (got == want);
    if (!values_ok) ++failures;
    cout << (values_ok ? "    ok    " : "    FAIL  ") << "result  [" << show(got) << "]";
    if (!values_ok) cout << "   expected  [" << show(want) << "]";
    cout << "\n";

    // 2. both inputs were nulled
    report("both argument pointers are null", list1 == nullptr && list2 == nullptr);

    // 3. the same nodes, spliced rather than rebuilt
    vector<const Node*> union_before = before1;
    union_before.insert(union_before.end(), before2.begin(), before2.end());
    vector<const Node*> after = addresses(merged);
    std::sort(union_before.begin(), union_before.end());
    std::sort(after.begin(), after.end());
    report("same nodes as the two inputs (nothing created or destroyed)",
           union_before == after);

    freeList(merged);
}

int main()
{
    checkMerge("interleaved  ", {1, 3, 5, 7}, {2, 4, 6});
    checkMerge("disjoint     ", {1, 2, 3},    {10, 20, 30});
    checkMerge("reverse order", {10, 20, 30}, {1, 2, 3});
    checkMerge("duplicates   ", {1, 3, 3, 5}, {3, 3, 4});
    checkMerge("one empty    ", {1, 2, 3},    {});
    checkMerge("other empty  ", {},           {4, 5});
    checkMerge("both empty   ", {},           {});
    checkMerge("singles      ", {2},          {1});
    checkMerge("equal heads  ", {5, 9},       {5, 6});

    cout << (failures ? "\nSOME CHECKS FAILED\n" : "\nall checks passed\n");
    return failures;
}