#include <iostream>
#include <cstdlib>
using namespace std;

void birthdayParadox(int N = 5000) {
    double matches[51] {};

    for (int trial {}; trial < N; trial++) {
        int days[365] {};
        bool found = false;

        for (int people {1}; people <= 50; people++) {
            int day  {rand() % 365};
            days[day]++;

            if (!found && days[day] > 1) {
                matches[people]++;
                found = true;
            }
        }
    }

    double total{};
    for (int i {2}; i <= 50; i++) {
        total += matches[i];
        cout << "For " << i 
             << " people, the probability of two birthdays is about "
             << total / N << endl;
    }
}

int main()
{
    birthdayParadox();
    return 0;
}