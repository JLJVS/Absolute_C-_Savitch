#include <iostream>
#include <cctype>
#include <string>
using namespace std;

class IceCreamSundae
{
    public:
        void outputDescription();
        double computePrice();
        void set_flavour(char flav);
        void set_size(char s);
        void set_number_toppings(int n);

    private:
        char f;
        char size;
        int num_toppings;

};

// setters
void IceCreamSundae::set_flavour(char flav){
    switch (flav){
        case 'c':
        case 'C':
        case 'v':
        case 'V':
        case 's':
        case 'S':
            f = flav;
            break;
        default:
            f = 'v';
    }
}
void IceCreamSundae::set_size(char s){
    switch (s){
        case 's':
        case 'S':
        case 'm':
        case 'M':
        case 'l':
        case 'L':
            size = tolower(s);
            break;
        default:
            size = 's';
            break;
    }        
}
void IceCreamSundae::set_number_toppings(int n){
    num_toppings = n;
}
double IceCreamSundae::computePrice(){
    double price {};
    switch(size){
        case 's':
            price += 10;
            break;
        case 'm':
            price += 14;
            break;
        case 'l':
            price += 17;
            break;
    }
    price += 2*num_toppings;
    return price;
}
void IceCreamSundae::outputDescription(){
    string flavour {}, s{};
    switch(f){
        case 'c':
            flavour = "Chocolate";
            break;
        case 'v':
            flavour = "Vanilla";
            break;
        case 's':
            flavour = "Strawberry";
            break;
        default:
            flavour = "Vanilla";
            break;
    }
    switch(size){
        case 's':
            s = "Small";
            break;
        case 'm':
            s = "Medium";
            break;
        case 'l':
            s = "Large";
            break;
        default:
            s = "Medium";
            break;
    }

    cout << "You ordered a " << s << " " << flavour << " Sundae with " << num_toppings << " toppings. For a total of " << computePrice() << endl;
}

int main()
{
    // ---------- Test Case 1 ----------
    cout << "=== Test Case 1 ===\n";
    IceCreamSundae s1;

    s1.set_flavour('c');      // Chocolate
    s1.set_size('s');         // Small
    s1.set_number_toppings(2);

    cout << "Inputs: flavour = c, size = s, toppings = 2\n";
    cout << "Expected: Small Chocolate Sundae, price = 10 + 2*2 = 14\n";
    cout << "Actual: ";
    s1.outputDescription();
    cout << "\n";


    // ---------- Test Case 2 ----------
    cout << "=== Test Case 2 ===\n";
    IceCreamSundae s2;

    s2.set_flavour('V');      // Vanilla
    s2.set_size('m');         // Medium
    s2.set_number_toppings(0);

    cout << "Inputs: flavour = V, size = m, toppings = 0\n";
    cout << "Expected: Medium Vanilla Sundae, price = 14\n";
    cout << "Actual: ";
    s2.outputDescription();
    cout << "\n";


    // ---------- Test Case 3 ----------
    cout << "=== Test Case 3 ===\n";
    IceCreamSundae s3;

    s3.set_flavour('x');      // invalid → defaults to Vanilla
    s3.set_size('L');         // Large
    s3.set_number_toppings(5);

    cout << "Inputs: flavour = x (invalid), size = L, toppings = 5\n";
    cout << "Expected: Large Vanilla Sundae, price = 17 + 2*5 = 27\n";
    cout << "Actual: ";
    s3.outputDescription();
    cout << "\n";

    return 0;
}
