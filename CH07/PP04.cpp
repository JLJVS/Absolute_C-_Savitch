#include <iostream>
using namespace std;

class HotDogStand
{
    public:
        HotDogStand(int ID, int n);
        void JustSold();
        void DogsSold();
        void AllDogsSold();
    private:
        int id;
        int dogs_sold;
        static long total_dogs_sold;
};
long HotDogStand::total_dogs_sold = 0;

HotDogStand::HotDogStand(int ID, int n){
    id = ID;
    dogs_sold = n;
    total_dogs_sold += n;
}
void HotDogStand::JustSold(){
    dogs_sold++;
    total_dogs_sold++;
}
void HotDogStand::DogsSold(){
    cout << "HotDogStand with ID: " << id << ", has sold " << dogs_sold << " hotdogs sold" << endl;
}
void HotDogStand::AllDogsSold(){
    cout << "The total amount of hotdogs sold by all stands is: " << total_dogs_sold << endl;
}


int main() {
    // Create a few stands with different starting sales
    cout << "-- Creating stands --" << endl;
    HotDogStand stand1(1, 50);
    HotDogStand stand2(2, 20);
    HotDogStand stand3(3, 0);

    stand1.DogsSold();   // expect 50
    stand2.DogsSold();   // expect 20
    stand3.DogsSold();   // expect 0
    stand1.AllDogsSold(); // expect 70 (total so far, since it's static/shared)

    // Sell some more dogs from individual stands
    cout << "\n-- Selling more hotdogs --" << endl;
    stand1.JustSold();
    stand1.JustSold();
    stand2.JustSold();
    stand3.JustSold();
    stand3.JustSold();
    stand3.JustSold();

    stand1.DogsSold();   // expect 52
    stand2.DogsSold();   // expect 21
    stand3.DogsSold();   // expect 3

    // Confirm total is shared across all instances
    cout << "\n-- Checking shared total across all stands --" << endl;
    stand1.AllDogsSold();  // expect 70 + 2 + 1 + 3 = 76
    stand2.AllDogsSold();  // should print the same total: 76
    stand3.AllDogsSold();  // should print the same total: 76

    // Add a new stand and confirm total keeps accumulating
    cout << "\n-- Adding a new stand --" << endl;
    HotDogStand stand4(4, 100);
    stand4.DogsSold();      // expect 100
    stand4.AllDogsSold();   // expect 76 + 100 = 176

    return 0;
}