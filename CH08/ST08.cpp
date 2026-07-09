/*

friend bool operator >(const Money& amount1, const Money& amount2);


friend bool operator >(const Money& amount1, const Money& amount2){

    return ((amount1.dollars > amount2.dollars) || ((amount1.dollars == amount2.dollars) && (amount1.cents > amount2.cents)));
}

*/