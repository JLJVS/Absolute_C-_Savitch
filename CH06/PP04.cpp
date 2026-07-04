#include <iostream>
using namespace std;

class GasPump
{
    public:
        void display_amount();
        void display_total_price();
        void display_price_per_L();
        void increment_by_1L();
        void tank_gas();
        void stop();

        void set_price_per_l(float p);
        void set_total_price(float p);
        void set_current_vol(float v);
        void set_total_vol(float v);
        
    private:
        float price_per_L;
        float total_price {0};
        float current_vol {0};
        float total_vol {0};
};
// setters
void GasPump::set_price_per_l(float p){
    price_per_L = p;
}
void GasPump::set_total_price(float p){
    total_price = p;
}
void GasPump::set_current_vol(float v){
    current_vol = v;
}
void GasPump::set_total_vol(float v){
    total_vol = v;
}

void GasPump::display_amount(){
    cout << "You have currently tanked: " << current_vol << "L" << endl;
}
void GasPump::display_total_price(){
    cout << "Price: " << total_price << endl;
}
void GasPump::display_price_per_L(){
    cout << "Price per L: " << price_per_L << endl;
}
void GasPump::increment_by_1L(){
    current_vol++;
    total_vol++;
    total_price = price_per_L*current_vol;
}
void GasPump::tank_gas(){
    while (true){
        display_total_price();
        display_amount();
        display_price_per_L();
        cout << "Do you want to continue tanking (y/n)?";
        char choice {};
        cin >> choice;
        if (choice=='n'){
            stop();
            break;
        } else{
            increment_by_1L();
        }

    }
}

void GasPump::stop(){
    cout << "You have tanked " << current_vol << "L and have to pay " << total_price << ".\nPlease come again." << endl;
    current_vol = 0;
    total_price = 0;
}

int main()
{
    // ---------- Test Case 1 ----------
    cout << "=== Test Case 1 ===\n";
    GasPump g1;

    g1.set_price_per_l(2.00);
    g1.set_current_vol(0);
    g1.set_total_price(0);
    g1.set_total_vol(0);

    cout << "Inputs: price_per_L = 2.00, start volume = 0\n";
    cout << "Operation: increment_by_1L()\n";
    cout << "Expected: current_vol = 1, total_price = 2.00\n";

    g1.increment_by_1L();

    cout << "Actual:\n";
    g1.display_amount();
    g1.display_total_price();
    cout << "\n";


    // ---------- Test Case 2 ----------
    cout << "=== Test Case 2 ===\n";
    GasPump g2;

    g2.set_price_per_l(1.50);
    g2.set_current_vol(3);
    g2.set_total_price(4.50);
    g2.set_total_vol(3);

    cout << "Inputs: price_per_L = 1.50, start volume = 3\n";
    cout << "Operation: increment_by_1L() twice\n";
    cout << "Expected: current_vol = 5, total_price = 7.50\n";

    g2.increment_by_1L();
    g2.increment_by_1L();

    cout << "Actual:\n";
    g2.display_amount();
    g2.display_total_price();
    cout << "\n";


    // ---------- Test Case 3 ----------
    cout << "=== Test Case 3 ===\n";
    GasPump g3;

    g3.set_price_per_l(1.80);
    g3.set_current_vol(2);
    g3.set_total_price(3.60);
    g3.set_total_vol(2);

    cout << "Inputs: price_per_L = 1.80, start volume = 2\n";
    cout << "Operation: stop()\n";
    cout << "Expected: message printed, current_vol reset to 0, total_price reset to 0\n";

    cout << "Actual:\n";
    g3.stop();
    cout << "After stop(), current_vol should be 0:\n";
    g3.display_amount();
    cout << "After stop(), total_price should be 0:\n";
    g3.display_total_price();
    cout << "\n";

    return 0;
}

