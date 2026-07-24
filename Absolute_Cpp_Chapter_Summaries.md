# Absolute C++ (Savitch, 5th ed.) — Chapter-by-Chapter Summary

A study reference covering all 20 chapters: the main topics, the key code
patterns, and the functions/syntax you're expected to know. Pitfalls flagged
with ⚠️. Code uses the book's style (`using namespace std;`).

---

## Table of Contents

| Ch | Title | Core idea |
|----|-------|-----------|
| 1  | [C++ Basics](#chapter-1--c-basics) | variables, I/O, operators |
| 2  | [Flow of Control](#chapter-2--flow-of-control) | branching, loops, file input |
| 3  | [Function Basics](#chapter-3--function-basics) | defining functions, scope |
| 4  | [Parameters and Overloading](#chapter-4--parameters-and-overloading) | by-value vs by-reference, overloading |
| 5  | [Arrays](#chapter-5--arrays) | arrays, multidimensional, search/sort |
| 6  | [Structures and Classes](#chapter-6--structures-and-classes) | encapsulation |
| 7  | [Constructors and Other Tools](#chapter-7--constructors-and-other-tools) | ctors, const, static, vectors |
| 8  | [Operator Overloading, Friends, References](#chapter-8--operator-overloading-friends-and-references) | custom operators |
| 9  | [Strings](#chapter-9--strings) | C-strings vs `std::string` |
| 10 | [Pointers and Dynamic Arrays](#chapter-10--pointers-and-dynamic-arrays) | `new`/`delete`, the Big Three |
| 11 | [Separate Compilation and Namespaces](#chapter-11--separate-compilation-and-namespaces) | `.h`/`.cpp`, namespaces |
| 12 | [Streams and File I/O](#chapter-12--streams-and-file-io) | file streams, formatting |
| 13 | [Recursion](#chapter-13--recursion) | recursive design |
| 14 | [Inheritance](#chapter-14--inheritance) | derived classes |
| 15 | [Polymorphism and Virtual Functions](#chapter-15--polymorphism-and-virtual-functions) | late binding |
| 16 | [Templates](#chapter-16--templates) | generic code |
| 17 | [Linked Data Structures](#chapter-17--linked-data-structures) | nodes, lists, trees |
| 18 | [Exception Handling](#chapter-18--exception-handling) | `try`/`throw`/`catch` |
| 19 | [Standard Template Library](#chapter-19--standard-template-library) | containers, iterators, algorithms |
| 20 | [Patterns and UML](#chapter-20--patterns-and-uml) | design patterns |

---

## Chapter 1 — C++ Basics

**About:** The mechanics of a C++ program: variables, arithmetic, and console I/O.

**Key concepts**
- Program skeleton: `#include`, `main`, `return 0`.
- Built-in types: `int`, `double`, `char`, `bool`; the `string` class (intro).
- Assignment, literals, named constants (`const`), type casting.
- Integer vs floating-point division; increment/decrement (`++`/`--`).

**Code**
```cpp
#include <iostream>
using namespace std;

int main() {
    const double PI = 3.14159;   // named constant
    int count = 0;
    double radius;

    cout << "Enter radius: ";
    cin >> radius;                       // console input
    double area = PI * radius * radius;
    cout << "Area = " << area << endl;   // console output

    int a = 7, b = 2;
    cout << a / b << " " << a % b << "\n";        // 3 1  (integer division)
    cout << static_cast<double>(a) / b << "\n";   // 3.5 (type cast)
    return 0;
}
```

**Functions / syntax to know:** `cout <<`, `cin >>`, `cerr <<`, `endl`, `\n`,
`static_cast<T>(x)`, `const`, escape sequences (`\t`, `\"`, `\\`).

- ⚠️ **Uninitialized variables** hold garbage — always initialize.
- ⚠️ **Integer division** truncates (`1/2 == 0`).
- 💡 Format decimals: `cout << fixed << setprecision(2);` (needs `<iomanip>`).

---

## Chapter 2 — Flow of Control

**About:** Making decisions and repeating actions; a first look at reading a file.

**Key concepts**
- Boolean expressions: `&&`, `||`, `!`; short-circuit evaluation; precedence.
- Branching: `if`/`else`, nested/multiway `if`, `switch`, conditional `?:`.
- Loops: `while`, `do-while`, `for`; `break` and `continue`; nested loops.
- Enumeration types.

**Code**
```cpp
// Multiway branch
if (score >= 90)      grade = 'A';
else if (score >= 80) grade = 'B';
else                  grade = 'C';

switch (choice) {                 // switch on an int/char/enum
    case 1: cout << "One";  break;   // ⚠️ don't forget break
    case 2: cout << "Two";  break;
    default: cout << "Other";
}

for (int i = 0; i < n; i++)
    cout << i << " ";

int x = 5;
do { cout << x; x--; } while (x > 0);   // body runs at least once
```

**File input (2.4)**
```cpp
#include <fstream>
ifstream inFile;
inFile.open("data.txt");
int value;
while (inFile >> value)       // loop stops at end-of-file
    cout << value << " ";
inFile.close();
```

**Functions / syntax:** `if/else`, `switch/case/default/break`, `while`,
`do-while`, `for`, `continue`, `ifstream`, `.open()`, `.close()`.

- ⚠️ `=` (assignment) vs `==` (comparison) — `if (x = 5)` is a classic bug.
- ⚠️ Extra semicolon: `for (...);` gives an empty loop body.
- ⚠️ Don't test strings of inequalities like `if (0 < x < 10)` — always true-ish.

---

## Chapter 3 — Function Basics

**About:** Defining and calling functions; how scope works.

**Key concepts**
- Predefined functions: `sqrt`, `pow`, `abs`, `rand`/`srand` (`<cmath>`, `<cstdlib>`).
- Programmer-defined functions: declaration (prototype) vs definition.
- `void` functions and `return`.
- Preconditions / postconditions (as comments).
- Scope: local variables, blocks, global constants, nested scopes.

**Code**
```cpp
#include <iostream>
using namespace std;

double average(double a, double b);   // declaration (prototype)

int main() {
    cout << average(3, 4) << endl;    // call
    return 0;
}

double average(double a, double b) {  // definition
    return (a + b) / 2.0;
}

void printLine(int n) {               // void function
    for (int i = 0; i < n; i++) cout << '*';
    cout << endl;
    return;                           // optional in void
}
```

**Random numbers**
```cpp
#include <cstdlib>
srand(42);                    // seed once
int roll = rand() % 6 + 1;    // 1..6
```

**Functions / syntax:** function prototype, `return`, `void`, `sqrt`, `pow`,
`rand`, `srand`, scope resolution of local vs global names.

- ⚠️ A variable declared inside a block/`for` is only visible inside it.
- 💡 Global **constants** are fine; global **variables** are discouraged.

---

## Chapter 4 — Parameters and Overloading

**About:** How arguments are passed, and defining multiple functions with one name.

**Key concepts**
- **Call-by-value**: function gets a *copy* (changes don't propagate out).
- **Call-by-reference** (`&`): function operates on the *caller's* variable.
- **Constant reference** (`const T&`): efficiency of reference, safety of value.
- **Overloading**: same name, different parameter lists.
- **Default arguments**.
- Testing: `assert`, stubs and drivers.

**Code**
```cpp
void swapValues(int& a, int& b) {   // call-by-reference: & on each parameter
    int tmp = a; a = b; b = tmp;
}

double total(double price, double tax = 0.05);  // default argument

// Overloading: same name, distinct signatures
int  square(int x)    { return x * x; }
double square(double x){ return x * x; }
```

**Functions / syntax:** `&` reference parameters, `const T&`, default args,
`assert(condition)` (`<cassert>`).

- ⚠️ Forgetting `&` means the caller's variable is *not* changed.
- ⚠️ Inconsistent `const`: a `const` parameter can't be passed to a non-`const`
  parameter.
- 💡 Use `const T&` for large objects you only need to read.

---

## Chapter 5 — Arrays

**About:** Fixed-size collections; using them with functions; 2D arrays.

**Key concepts**
- Declaring/indexing: `int a[10];` indices `0..9`.
- Arrays as function arguments (passed as pointers → changes stick); pass the
  size separately.
- Partially filled arrays (track "number used").
- Searching and sorting (linear search, selection sort).
- Multidimensional arrays.

**Code**
```cpp
const int SIZE = 5;
int a[SIZE] = {10, 20, 30};      // rest initialized to 0

void fill(int arr[], int size);  // array parameter (no size in brackets)
double avg(const int arr[], int size);  // const → read-only

// 2D array
int grid[3][4];                  // 3 rows, 4 cols
grid[i][j] = 0;
void process(int m[][4], int rows);  // all dims but the first are required
```

**Selection sort (the book's example)**
```cpp
for (int i = 0; i < n - 1; i++) {
    int minIdx = i;
    for (int j = i + 1; j < n; j++)
        if (a[j] < a[minIdx]) minIdx = j;
    swap(a[i], a[minIdx]);
}
```

**Functions / syntax:** array declaration/initialization, `arr[]` parameters,
`const` array params, `[][COLS]` for 2D.

- ⚠️ **Index out of range** — C++ does *not* check bounds; you get garbage or a crash.
- ⚠️ Array indices start at **0**, so the last valid index is `size - 1`.
- 💡 Use a named constant for the size.

---

## Chapter 6 — Structures and Classes

**About:** Bundling data (`struct`) and bundling data + behavior with access
control (`class`). The start of OOP.

**Key concepts**
- `struct`: aggregate of named members (all public by default).
- `class`: members `private` by default; **encapsulation**.
- Member functions; **accessors** (get) and **mutators** (set).
- Separating interface (declaration) from implementation (`::` definitions).

**Code**
```cpp
struct Date {          // struct: members public
    int day, month, year;
};

class DayOfYear {      // class: members private by default
public:
    void input();
    void output();
    void set(int newMonth, int newDay);   // mutator
    int getMonth() const;                  // accessor (const)
private:
    int month;
    int day;
};

// Implementation, defined with ClassName::
void DayOfYear::set(int newMonth, int newDay) {
    month = newMonth;
    day   = newDay;
}
int DayOfYear::getMonth() const { return month; }
```

**Functions / syntax:** `struct`, `class`, `public:`/`private:`, `ClassName::`,
`const` member functions, dot operator `obj.member`.

- ⚠️ **Forgetting the semicolon** after a `struct`/`class` definition `};`.
- 💡 Keep data `private`; expose behavior through public member functions.

---

## Chapter 7 — Constructors and Other Tools

**About:** Initializing objects automatically, plus assorted class tools and a
first taste of `vector`.

**Key concepts**
- **Constructors**: same name as class, no return type; run at creation.
- Default constructor (no args) — always provide one.
- Initialization lists: `: member(value)`.
- `const` parameter modifier; **inline** functions; **static** members.
- `vector`: a resizable array (STL preview).

**Code**
```cpp
class BankAccount {
public:
    BankAccount();                          // default constructor
    BankAccount(int dollars, double rate);  // parameterized
    double getBalance() const;
private:
    double balance;
    double interestRate;
};

BankAccount::BankAccount() : balance(0), interestRate(0) { }   // init list

BankAccount::BankAccount(int dollars, double rate)
    : balance(dollars), interestRate(rate) { }
```

**Vector preview (7.3)**
```cpp
#include <vector>
vector<int> v;          // empty, size 0
v.push_back(10);        // append → size grows
v.push_back(20);
cout << v[0] << v.size();
```

**Functions / syntax:** constructors, member init list `: x(a)`, `static`
members, `inline`, `vector`, `.push_back()`, `.size()`.

- ⚠️ If you define *any* constructor, the compiler no longer supplies a default —
  add one explicitly if you need `ClassName obj;`.
- ⚠️ `vector v[i] = x` beyond current size is undefined — use `push_back` to grow.

---

## Chapter 8 — Operator Overloading, Friends, and References

**About:** Making your own types work with `+`, `<<`, `[]`, `==`, etc.

**Key concepts**
- Overload operators as **member** functions or **standalone/friend** functions.
- **Friend** functions/classes: granted access to `private` members.
- Overloading `<<` and `>>` (must be friends/standalone — left operand is a stream).
- Returning by reference; overloading `[]`, `++`, `--`.
- Automatic type conversion via constructors.

**Code**
```cpp
class Money {
public:
    Money(double amount);
    friend Money operator+(const Money& a, const Money& b);  // friend
    friend ostream& operator<<(ostream& out, const Money& m);
private:
    long allCents;
};

Money operator+(const Money& a, const Money& b) {
    return Money((a.allCents + b.allCents) / 100.0);
}

ostream& operator<<(ostream& out, const Money& m) {   // return stream by ref
    out << "$" << m.allCents / 100.0;
    return out;                                        // enables chaining
}
```

**Functions / syntax:** `operator+`, `operator==`, `operator<<`, `operator>>`,
`operator[]`, `operator++`, `friend`, returning `ostream&`.

- ⚠️ `<<` / `>>` can't be members (their left operand is the stream) — use friends.
- ⚠️ Don't overload `&&`, `||`, or `,` (you lose short-circuit semantics).
- 💡 Return streams **by reference** so `cout << a << b` chains.

---

## Chapter 9 — Strings

**About:** Two ways to handle text: old C-strings and the modern `string` class.

**Key concepts**
- **C-strings**: `char` arrays ending in `'\0'`; manipulated via `<cstring>`.
- ⚠️ You cannot use `=` or `==` on C-strings — use `strcpy`/`strcmp`.
- Character tools: `<cctype>` (`toupper`, `isdigit`, …); `cin.get`, `cin.getline`.
- **`std::string`**: assignable, comparable, concatenable with `+`.

**Code**
```cpp
// C-string
#include <cstring>
char cstr[10] = "Hi";
strcpy(cstr, "Bye");             // copy (not =)
if (strcmp(cstr, "Bye") == 0)    // compare (not ==)
    cout << "equal";

// std::string
#include <string>
string s = "Hello";
s = s + " world";                // concatenation
if (s == "Hello world") { }      // == works
cout << s.length() << s.substr(0, 5) << s.at(0);

getline(cin, s);                 // read a whole line (spaces included)
```

**Functions / syntax:** `strcpy`, `strcmp`, `strlen`, `strcat`; `toupper`,
`tolower`, `isspace`, `isdigit`; `cin.get`, `cin.getline`, `getline`;
`string`, `.length()`, `.substr()`, `.at()`, `.find()`.

- ⚠️ Mixing `cin >> x;` then `getline` — the leftover `'\n'` gets read; discard it.
- ⚠️ `toupper`/`tolower` return `int` (cast back to `char` for display).

---

## Chapter 10 — Pointers and Dynamic Arrays

**About:** Memory addresses, allocating memory at runtime, and the class rules
that follow ("the Big Three").

**Key concepts**
- Pointers: `int* p; p = &x; *p = 5;` (address-of `&`, dereference `*`).
- `new` / `delete`; `new[]` / `delete[]` for arrays; freestore/heap.
- Dynamic arrays: size decided at runtime.
- The `this` pointer; `->` operator.
- **The Big Three** (needed for any class using `new`):
  destructor, copy constructor, overloaded `operator=`.
- **Deep copy** vs shallow copy.

**Code**
```cpp
typedef double* DoublePtr;
DoublePtr d = new double[n];      // dynamic array
d[0] = 1.5;
delete [] d;                      // must pair new[] with delete[]

// The Big Three for a class with a dynamic-array member `double* a;`
~MyClass() { delete [] a; }                       // destructor

MyClass(const MyClass& other) {                   // copy constructor (deep)
    capacity = other.capacity;
    a = new double[capacity];
    for (int i = 0; i < capacity; i++) a[i] = other.a[i];
}

MyClass& operator=(const MyClass& rhs) {          // assignment (deep + guard)
    if (this == &rhs) return *this;               // self-assignment guard
    delete [] a;
    capacity = rhs.capacity;
    a = new double[capacity];
    for (int i = 0; i < capacity; i++) a[i] = rhs.a[i];
    return *this;
}
```

**Functions / syntax:** `*`, `&`, `new`, `delete`, `new[]`, `delete[]`, `this`,
`->`, destructor `~Class()`, copy constructor, `operator=`.

- ⚠️ **Dangling pointer**: using a pointer after `delete` (memory reclaimed).
- ⚠️ Plain `delete` on an array (needs `delete[]`); double-delete → crash.
- ⚠️ Shallow copy → two objects share one array → double-free / aliasing bugs.
- 💡 In `operator=`, always guard `if (this == &rhs)` before deleting.

---

## Chapter 11 — Separate Compilation and Namespaces

**About:** Splitting a class across files and avoiding name clashes.

**Key concepts**
- **Header file** (`.h`): the interface (class declaration, prototypes).
- **Implementation file** (`.cpp`): the definitions; `#include "class.h"`.
- **Include guards** with `#ifndef`/`#define`/`#endif` (prevent double inclusion).
- **Namespaces**: group names; `using` directives vs `using` declarations.
- Unnamed namespaces (replace file-`static`).

**Code**
```cpp
// digitaltime.h
#ifndef DIGITALTIME_H          // include guard
#define DIGITALTIME_H
namespace timesavitch {
    class DigitalTime {
    public:
        DigitalTime(int h, int m);
        void advance(int minutes);
    private:
        int hour, minute;
    };
}
#endif

// digitaltime.cpp
#include "digitaltime.h"
namespace timesavitch {
    DigitalTime::DigitalTime(int h, int m) : hour(h), minute(m) { }
}

// main.cpp
#include "digitaltime.h"
using namespace timesavitch;         // using directive
using std::cout;                     // using declaration (one name)
```

**Functions / syntax:** `#ifndef`/`#define`/`#endif`, `#include "..."`,
`namespace X { }`, `using namespace X;`, `using X::name;`.

- ⚠️ Without include guards, a header included twice causes redefinition errors.
- 💡 Prefer `using` **declarations** for specific names over blanket directives.

---

## Chapter 12 — Streams and File I/O

**About:** Reading/writing files, formatting output, and stream inheritance.

**Key concepts**
- `ifstream` (input), `ofstream` (output), `fstream`.
- Always check the file opened: `if (inFile.fail())`.
- Detect end-of-file (the read itself returns false / `.eof()`).
- Formatting: `setw`, `setprecision`, `fixed`, `showpoint` (`<iomanip>`).
- Streams form an inheritance hierarchy (preview of Ch 14–15).
- `stringstream`: parse/build strings like a stream.

**Code**
```cpp
#include <fstream>
#include <iomanip>

ofstream outFile("out.txt");
if (outFile.fail()) { cout << "open failed"; exit(1); }
outFile << fixed << setprecision(2) << setw(10) << 3.14159;
outFile.close();

ifstream inFile("in.txt");
double x;
while (inFile >> x)          // false at EOF
    cout << x << " ";

// stringstream
#include <sstream>
stringstream ss;
ss << "42 3.14";
int n; double d;
ss >> n >> d;                // parse out of the string
```

**Functions / syntax:** `ifstream`, `ofstream`, `.open()`, `.close()`,
`.fail()`, `.eof()`, `setw`, `setprecision`, `fixed`, `showpoint`,
manipulators, `stringstream`.

- ⚠️ Stream variables can't be assigned/copied freely — pass by reference.
- 💡 Check `.fail()` right after opening; exit or handle on failure.

---

## Chapter 13 — Recursion

**About:** Functions that call themselves; designing recursively.

**Key concepts**
- Every recursion needs a **base case** and progress toward it.
- The call **stack**; ⚠️ **stack overflow** from missing/incorrect base case.
- Recursive `void` functions and recursive value-returning functions.
- Recursion vs iteration; **binary search** as a recursive design; mutual recursion.

**Code**
```cpp
int factorial(int n) {
    if (n == 0) return 1;             // base case
    return n * factorial(n - 1);      // recursive case
}

// Recursive binary search
int search(const int a[], int first, int last, int key) {
    if (first > last) return -1;      // base case: not found
    int mid = (first + last) / 2;
    if (a[mid] == key)      return mid;
    else if (key < a[mid])  return search(a, first, mid - 1, key);
    else                    return search(a, mid + 1, last, key);
}
```

**Functions / syntax:** base case, recursive call, the run-time stack.

- ⚠️ **Infinite recursion** → stack overflow crash.
- 💡 Any recursion can be rewritten as a loop; choose whichever is clearer.

---

## Chapter 14 — Inheritance

**About:** Deriving new classes from existing ones ("is-a" relationships).

**Key concepts**
- Derived class inherits members: `class Derived : public Base`.
- `protected` members: accessible in derived classes (but not outside).
- Constructors in derived classes call base constructor via init list.
- **Redefining** vs **overloading** inherited member functions.
- Copy constructors, `operator=`, and destructors in derived classes.

**Code**
```cpp
class Employee {
public:
    Employee(string theName, double thePay);
    string getName() const;
protected:                       // accessible to derived classes
    string name;
    double netPay;
};

class HourlyEmployee : public Employee {   // public inheritance
public:
    HourlyEmployee(string theName, double wage, double hrs)
        : Employee(theName, wage * hrs),    // call base constructor
          wageRate(wage), hours(hrs) { }
    void printCheck() const;                // redefined behavior
private:
    double wageRate, hours;
};
```

**Functions / syntax:** `: public Base`, `protected:`, base-constructor call in
init list, `Base::function()` to reach a redefined base version.

- ⚠️ Private base members are **not** directly accessible in the derived class.
- ⚠️ Same object on both sides of `=` in a derived class needs care (Ch 10 guard).
- 💡 "Is-a" → inheritance; "has-a" → member variable (composition).

---

## Chapter 15 — Polymorphism and Virtual Functions

**About:** Choosing the right function at run time based on the actual object type.

**Key concepts**
- **Late (dynamic) binding** via `virtual` functions.
- **Abstract class**: has a **pure virtual** function `= 0`; cannot be instantiated.
- Base-class pointers/references to derived objects.
- ⚠️ **Slicing** when assigning a derived object to a base *variable*.
- 💡 **Make destructors virtual** in any class with virtual functions.
- vtables (how it's implemented, conceptually).

**Code**
```cpp
class Shape {
public:
    virtual double area() const = 0;   // pure virtual → abstract class
    virtual ~Shape() { }               // virtual destructor
};

class Circle : public Shape {
public:
    Circle(double r) : radius(r) { }
    double area() const override { return 3.14159 * radius * radius; }
private:
    double radius;
};

Shape* s = new Circle(2.0);
cout << s->area();     // calls Circle::area() via late binding
delete s;              // virtual dtor → correct destructor runs
```

**Functions / syntax:** `virtual`, pure virtual `= 0`, abstract classes,
`override`, virtual destructors, base pointers to derived objects.

- ⚠️ Without `virtual`, `s->area()` would call the *base* version (early binding).
- ⚠️ Slicing: `Shape x = someCircle;` chops off the derived parts.

---

## Chapter 16 — Templates

**About:** Writing code once that works for many types.

**Key concepts**
- **Function templates**: `template<class T>`.
- **Class templates**: whole classes parameterized by a type.
- Templates + inheritance; `vector`/`basic_string` are templates.

**Code**
```cpp
// Function template
template<class T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}
cout << maximum(3, 7);         // T = int
cout << maximum(2.5, 1.1);     // T = double

// Class template
template<class T>
class Pair {
public:
    Pair(T f, T s) : first(f), second(s) { }
    T getFirst() const { return first; }
private:
    T first, second;
};
Pair<int> p(1, 2);             // instantiate with int
```

**Functions / syntax:** `template<class T>` (or `template<typename T>`),
instantiation `ClassName<Type>`.

- ⚠️ Template definitions usually go in the header (compiler needs them at use site).
- ⚠️ The type must support every operation the template uses (e.g. `>`).

---

## Chapter 17 — Linked Data Structures

**About:** Building your own dynamic structures out of nodes and pointers.

**Key concepts**
- **Node**: struct/class holding data + a pointer to the next node.
- **Linked lists**: insert at head, insert/remove in the middle, search.
- Doubly linked lists.
- Applications: **stack**, **queue**, **hash table** (with chaining), **set**.
- **Iterators** (pointers as iterators; iterator classes).
- **Trees** (binary search tree properties).

**Code**
```cpp
struct Node {
    int data;
    Node* link;
};
typedef Node* NodePtr;

// Insert a new node at the head of the list
void headInsert(NodePtr& head, int value) {
    NodePtr p = new Node;
    p->data = value;
    p->link = head;       // new node points to old head
    head = p;             // head now points to new node
}

// Traverse
for (NodePtr p = head; p != nullptr; p = p->link)
    cout << p->data << " ";
```

**Functions / syntax:** self-referential `struct`, `->`, `new`/`delete` per node,
head/tail pointers, `nullptr`.

- ⚠️ **Losing nodes**: reassign links in the right order or you leak the list.
- ⚠️ Assignment operator on linked structures needs a deep copy (Ch 10 rules).
- 💡 Stacks (LIFO) and queues (FIFO) are classic linked-list applications.

---

## Chapter 18 — Exception Handling

**About:** Separating error detection from error handling.

**Key concepts**
- `try` a block, `throw` a value on error, `catch` it by type.
- Define your own exception **classes**.
- Multiple `catch` blocks — ⚠️ catch the **most specific** type first.
- When (and when not) to use exceptions; rethrowing.

**Code**
```cpp
class DivideByZero { };            // trivial exception class is fine

double safeDivide(double a, double b) {
    if (b == 0) throw DivideByZero();   // throw on error
    return a / b;
}

int main() {
    try {
        cout << safeDivide(10, 0);
    }
    catch (DivideByZero) {              // catch by type
        cout << "Cannot divide by zero!";
    }
    catch (...) {                      // catch-all (last)
        cout << "Some other error";
    }
}
```

**Functions / syntax:** `try { }`, `throw value;`, `catch (Type e) { }`,
`catch (...)`, custom exception classes.

- ⚠️ Uncaught exceptions terminate the program.
- ⚠️ Order `catch` blocks specific → general; a base-class catch first hides derived.
- 💡 Use exceptions for *exceptional* conditions, not ordinary control flow.

---

## Chapter 19 — Standard Template Library

**About:** Ready-made containers, iterators, and algorithms.

**Key concepts**
- **Iterators**: generalize pointers; `begin()`/`end()`; kinds (forward,
  bidirectional, random-access); const/reverse iterators.
- **Sequential containers**: `vector`, `list`, `deque`.
- **Container adapters**: `stack`, `queue` (built on other containers).
- **Associative containers**: `set`, `map` (sorted, key-based).
- **Generic algorithms**: `sort`, `find`, `count`, etc.; **Big-O** running times.

**Code**
```cpp
#include <vector>
#include <algorithm>
vector<int> v = {5, 2, 8, 1};

for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    cout << *it << " ";

sort(v.begin(), v.end());                       // generic algorithm
auto found = find(v.begin(), v.end(), 8);       // returns an iterator
if (found != v.end()) cout << "found";

#include <map>
map<string, int> ages;
ages["Alice"] = 30;                             // key → value
cout << ages["Alice"];
```

**Functions / syntax:** `begin()`/`end()`, iterators, `vector`, `list`, `set`,
`map`, `stack`, `queue`, `sort`, `find`, `count`, `push_back`.

- ⚠️ Modifying a container can **invalidate** its iterators.
- 💡 Know rough Big-O: `vector` random access O(1); `map`/`set` lookup O(log n).

---

## Chapter 20 — Patterns and UML

**About:** Reusable design solutions and diagramming (online chapter).

**Key concepts**
- **Design patterns**: named, reusable solutions to recurring design problems
  (e.g. **Adapter**, **Iterator**, and the model-view idea).
- **UML** (Unified Modeling Language): class diagrams showing classes,
  attributes, methods, and relationships (association, inheritance).
- Patterns are *descriptions*, not code — you implement them per situation.

**Notes**
- Adapter pattern: wrap an existing class to present a different interface
  (the STL `stack`/`queue` adapters are real examples from Ch 19).
- UML class box: `[ ClassName | attributes | methods() ]`, arrows for "is-a".

- 💡 Patterns give you shared vocabulary with other developers.

---

## Appendices (quick reference)

- **A1 — Keywords:** reserved words (`int`, `class`, `virtual`, `template`, …).
- **A2 — Operator precedence:** e.g. `*` binds tighter than `+`; `=` is low.
- **A3 — ASCII table:** `'A'` = 65, `'a'` = 97, `'0'` = 48.
- **A4 — Library functions:** `<cmath>`, `<cstdlib>`, `<cctype>`, `<cstring>`.
- **A5 — Header files:** modern `<iostream>` (+ `using namespace std;`) vs old
  `<iostream.h>`.

---

## The recurring themes (worth memorizing)

1. **The Big Three** (Ch 10): if a class uses `new`, define a destructor, a
   copy constructor, and `operator=` — all doing *deep* copies.
2. **`const` correctness** (Ch 6–8): mark read-only member functions and
   reference parameters `const`.
3. **Pass big objects by `const` reference** (Ch 4), not by value.
4. **Encapsulate** (Ch 6): data `private`, behavior `public`.
5. **`virtual` for polymorphism, virtual destructors** (Ch 15).
6. **Pair allocations**: `new`↔`delete`, `new[]`↔`delete[]` (Ch 10).
