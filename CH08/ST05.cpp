/*

const Money Money::operator -(const MOney& secondOperand)const{
    int allCents1 = cents + dollars *100;
    int allCents2 = secondOperand.cents + secondOperand.dollars*100;
    int diffAllCents = allCents1 - allCents2;
    int absAllCents = abs(diffAllCents);
    int FinalDollars = absAllCents/100;
    int finalCents = absAllCents%100;

    if (diffAllCents<0){
    finalDollars = -finalDollars;
    finalCents = -finalCents;
    }
    return Money(finalDollars, finalCents);


}

*/