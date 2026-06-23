#include <iostream>
using namespace std;

void deductDiscount(float discountRate,float &cost){
    cost *= (1-discountRate/100);
}

int main()
{
    float discountRate{15};
    float costs[3] {66, 100, 150};

    for (int i{0}; i < 3; i++){
        cout << "Price: " << costs[i] << ", discount: " << discountRate << "%" << endl;
        deductDiscount(discountRate, costs[i]);
        cout << "After discount:  " << costs[i] << endl;
    }
    
    return 0;
}