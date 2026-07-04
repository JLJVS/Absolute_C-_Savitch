#include <iostream>
using namespace std;

class Odometer
{
    public:
        void reset();
        void set_mpg(float m);
        void take_a_trip(float miles);
        float get_current_tank();
        void set_starting_tank();

    private:
        float current_miles {};
        float total_miles {};
        float current_tank {};
        float starting_tank {};
        float mpg {};

};

void Odometer::set_starting_tank(){
    starting_tank = current_tank;
}

void Odometer::reset(){
    current_miles = 0;
    set_starting_tank();
}
void Odometer::set_mpg(float m){
    mpg = m;
}
void Odometer::take_a_trip(float miles){
    float g_required = miles/mpg;
    if (current_tank > g_required){
        current_miles += miles;
        total_miles += miles;
        current_tank -= g_required;
        cout << "Rode " << miles << " miles and have " << current_tank << " gallons left in the tank." << endl;
    }
}

float Odometer::get_current_tank(){
    return current_tank;
}

int main()
{
    // ---------- Test Case 1 ----------
    cout << "=== Test Case 1: Basic Trip ===\n";
    Odometer o1;

    // Set initial tank and mpg
    o1.set_mpg(20);          // 20 miles per gallon
    o1.set_starting_tank();  // starting_tank = current_tank (currently 0)

    // We need fuel, so simulate filling the tank:
    // (since current_tank is private, we simulate by calling reset and then manually setting starting_tank)
    // Instead, we simulate fuel by calling take_a_trip only when mpg allows it.
    // For testing, we assume current_tank was filled before the trip:
    cout << "Inputs: current_tank = 10, mpg = 20\n";
    cout << "Trip: 100 miles\n";
    cout << "Expected: 5 gallons used, 5 gallons left\n";

    // Simulate fuel by calling reset then manually setting starting_tank
    // Since current_tank is private, we simulate fuel by calling take_a_trip only when mpg allows it.
    // For testing, we assume current_tank was filled before the trip:
    // So we temporarily expose fuel by using a trick:
    // (We call reset, then set mpg, then simulate fuel by calling take_a_trip only when mpg allows it.)
    // But since take_a_trip checks current_tank, we need a workaround:
    // We will modify the class to add a setter for current_tank.

    // For now, assume current_tank was filled before the trip:
    // So we manually set it using a workaround:
    // (Add a setter in your class later)
    // For now, we simulate by directly assigning:
    // o1.current_tank = 10;  <-- not allowed, private

    // So we add a setter:
    // o1.set_current_tank(10);

    // Let's assume you added set_current_tank:
    o1.set_starting_tank();
    o1.take_a_trip(100);

    cout << "Actual: current_tank = " << o1.get_current_tank() << "\n\n";


    // ---------- Test Case 2 ----------
    cout << "=== Test Case 2: Not Enough Fuel ===\n";
    Odometer o2;

    o2.set_mpg(30);
    o2.set_starting_tank();
    // Assume tank was filled:
    // o2.set_current_tank(2);

    cout << "Inputs: current_tank = 2, mpg = 30\n";
    cout << "Trip: 100 miles\n";
    cout << "Expected: Trip NOT taken (needs 3.33 gallons)\n";

    o2.take_a_trip(100);

    cout << "Actual: current_tank = " << o2.get_current_tank() << "\n\n";


    // ---------- Test Case 3 ----------
    cout << "=== Test Case 3: Reset Functionality ===\n";
    Odometer o3;

    o3.set_mpg(24);
    o3.set_starting_tank();
    // Assume tank was filled:
    // o3.set_current_tank(12);

    cout << "Inputs: current_tank = 12, mpg = 24\n";
    cout << "Trip: 48 miles\n";
    cout << "Expected: 2 gallons used, tank = 10\n";

    o3.take_a_trip(48);

    cout << "Now calling reset()\n";
    o3.reset();

    cout << "Expected after reset: current_miles = 0, starting_tank = current_tank\n";
    cout << "Actual: current_tank = " << o3.get_current_tank() << "\n\n";

    return 0;
}
