#include <iostream>
using namespace std;

void computeCoin(int coinValue, int number, int& amountLeft){
    if ((coinValue > 0) && (coinValue < 100)){
        while (amountLeft >= coinValue){
            number += amountLeft/coinValue;
            amountLeft %= coinValue;
        }
        cout << number << " x " << coinValue << " ";

    }
}

void changeCompute(int amount){
    cout << amount << " cents can be geven as:" << endl;

    int coinValue {25}, number{}, amountLeft = amount;
    if (amount > 0) {
        computeCoin(coinValue, number, amountLeft);
    }
    
    if (amount > 0){
        coinValue=10;
        computeCoin(coinValue, number, amountLeft);
    }
    
    if (amount > 0){
        coinValue=1;
        computeCoin(coinValue, number, amountLeft);
    }
    
}

int main(void)
{

    changeCompute(86);

    return 0;
}