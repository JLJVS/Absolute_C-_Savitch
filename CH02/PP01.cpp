#include <iostream>
using namespace std;

int main(void)
{
    int N_items{200}, item_cost{}, years{};
    float inflation_rate{};
    cout << "How much is the item, after how many years and the inflation rate as a percentage: \n";
    cin >> item_cost >> years >> inflation_rate;

    if (inflation_rate > 1){
        inflation_rate/=100;
    }

    float total{item_cost};
    for (int i{}; i < years; i++){
        total *= (1+inflation_rate);
    }
    cout << "The cost to purchase 200 items after " << years << " years is $" << N_items*total << endl;

    return 0;
}