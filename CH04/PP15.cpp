#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (b==0){
        return a;
    } else {
        return gcd(b, a%b);
    }
}

bool convertToLowestTerms(int &numerator, int &denominator){
    if (denominator == 0){ return false;}
    int commonFactor = gcd(numerator, denominator);
    numerator /= commonFactor;
    denominator /= commonFactor;
    return true;
}

int main() {
    // Five test cases for convertToLowestTerms
    int num1 = 10, den1 = 5;
    int num2 = 24, den2 = 6;
    int num3 = 60, den3 = 20;
    int num4 = 37, den4 = 25;
    int num5 = 42, den5 = 56;

    cout << "Test 1: 10/5 -> ";
    convertToLowestTerms(num1, den1);
    cout << num1 << "/" << den1 << endl;

    cout << "Test 2: 24/6 -> ";
    convertToLowestTerms(num2, den2);
    cout << num2 << "/" << den2 << endl;

    cout << "Test 3: 60/20 -> ";
    convertToLowestTerms(num3, den3);
    cout << num3 << "/" << den3 << endl;

    cout << "Test 4: 37/25 -> ";
    convertToLowestTerms(num4, den4);
    cout << num4 << "/" << den4 << endl;

    cout << "Test 5: 42/56 -> ";
    convertToLowestTerms(num5, den5);
    cout << num5 << "/" << den5 << endl;

    return 0;
}