#include <iostream>
using namespace std;

class Weight
{
    public:
        void setWeightPounds(float p);
        void setWeightKilograms(float kg);
        float getWeightPounds();
        float getWeightKilograms();
    private:
        float weight;
};
// setters
void Weight::setWeightKilograms(float kg){
    weight = kg;
}
void Weight::setWeightPounds(float p){
    weight = p*0.453595237;
}
float Weight::getWeightPounds(){
    return weight/0.453595237;
}
float Weight::getWeightKilograms(){
    return weight;
}

int main()
{
    // ---------- Test Case 1 ----------
    cout << "=== Test Case 1: Set in Kilograms ===\n";
    Weight w1;

    w1.setWeightKilograms(10);   // 10 kg

    cout << "Input: 10 kg\n";
    cout << "Expected pounds: " << 10 / 0.453595237 << "\n";
    cout << "Expected kilograms: 10\n";

    cout << "Actual pounds: " << w1.getWeightPounds() << "\n";
    cout << "Actual kilograms: " << w1.getWeightKilograms() << "\n\n";


    // ---------- Test Case 2 ----------
    cout << "=== Test Case 2: Set in Pounds ===\n";
    Weight w2;

    w2.setWeightPounds(100);   // 100 lbs

    cout << "Input: 100 lbs\n";
    cout << "Expected kilograms: " << 100 * 0.453595237 << "\n";
    cout << "Expected pounds: 100\n";

    cout << "Actual kilograms: " << w2.getWeightKilograms() << "\n";
    cout << "Actual pounds: " << w2.getWeightPounds() << "\n\n";


    // ---------- Test Case 3 ----------
    cout << "=== Test Case 3: Mixed Conversions ===\n";
    Weight w3;

    w3.setWeightKilograms(5);   // 5 kg
    cout << "Input: 5 kg\n";
    cout << "Expected pounds: " << 5 / 0.453595237 << "\n";
    cout << "Actual pounds: " << w3.getWeightPounds() << "\n";

    w3.setWeightPounds(50);     // overwrite with 50 lbs
    cout << "Now input: 50 lbs\n";
    cout << "Expected kilograms: " << 50 * 0.453595237 << "\n";
    cout << "Actual kilograms: " << w3.getWeightKilograms() << "\n\n";

    return 0;
}
