#include <iostream>
using namespace std;


class CellPhone 
{
    public:
        void setPrice(double newPrice);
        void setProfit(double newProfit);
        double getPrice();
    private:
        double price;
        double profit;
        double getProfit();
};

int main()
{
    CellPhone nokia, samsung;
    // nokia.price = 1299.99; price is private
    samsung.setPrice(2000.97);
    // allowed since setprice is a public function
    double aPrice, aProfit;
    aPrice = samsung.getPrice(); 
    // allowed since getPrice is a public function
    // aProfit = samsung.getProfit();
    // not allowed since getprofit is a private function
    // aProfit = nokia.getProfit();
    // not allowed since getprofit is a private function
    nokia = samsung; // allowed but not sure how the behaviour is defined

    return 0;
}