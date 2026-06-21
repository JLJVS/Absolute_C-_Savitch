#include <iostream>
using namespace std;

float height_calculator_child(char sex_child, float height_mother, float height_father){
    if (sex_child == 'M' || sex_child == 'm'){
        return ((height_mother*13/12)+height_father)/2;
    }
    return ((height_father*12/13) + height_mother)/2;
}

int main()
{   
    

    cout << "=== TEST CASES ===\n";

    // Test 1: Male child, normal heights
    cout << "Test 1 (M, 165, 180): "
         << height_calculator_child('M', 165, 180) << endl;

    // Test 2: Female child, normal heights
    cout << "Test 2 (F, 165, 180): "
         << height_calculator_child('F', 165, 180) << endl;

    // Test 3: Lowercase male
    cout << "Test 3 (m, 160, 175): "
         << height_calculator_child('m', 160, 175) << endl;

    // Test 4: Lowercase female
    cout << "Test 4 (f, 160, 175): "
         << height_calculator_child('f', 160, 175) << endl;

    // Test 5: Edge case — very tall parents
    cout << "Test 5 (M, 190, 200): "
         << height_calculator_child('M', 190, 200) << endl;

    // Test 6: Edge case — very short parents
    cout << "Test 6 (F, 150, 160): "
         << height_calculator_child('F', 150, 160) << endl;

    // Test 7: Invalid sex input
    cout << "Test 7 (X, 165, 180) - should use female formula: "
         << height_calculator_child('X', 165, 180) << endl;





    return 0;
}