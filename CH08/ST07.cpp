/*
const Money operator -(const Money& amount1, const Money& amount2)
{
        int allCents1 = amount1.cents + amount1.dollars*100;
        int allCents2 = amount2.cents + amount2.dollars*100;
        int diffsAllcents = allCents1 - allCents2;
        int absAllCents = abs(diffsAllcents);

        int finalDollars = absAllCents/100;
        int finalCents = absAllCents%100;

        if (diffAllCents < 0){
            finalDollars = - finalDollars;
            finalCents = - finalCents;
        }
        
        return Money(finalDollars, finalCents);
}
*/


