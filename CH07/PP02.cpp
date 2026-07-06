#include <iostream>
#include <string>
using namespace std;

class Day
{
    public:
        Day(char l1, char l2, char l3);
        Day(int d);
        Day ();
        void setDay( int d);
        void setDay(char letters[3]);
        void output();
        Day nextDay();
    private:
        char l1;
        char l2;
        char l3;
        void Daynum( int d);

};

void Day::Daynum(int d){
    if (d < 1 || d >7){
        cout << "Please enter a value between (includsive) 1 (Monday) and 7 (Sunday)." << endl;
        cout << "Defaulted to Monday" << endl;
        l1 = 'M';
        l2 = 'o';
        l3 = 'n';
    } else {
        switch(d){
            case 1:
                l1 = 'M';
                l2 = 'o';
                l3 = 'n';
                break;
            case 2:
                l1 = 'T';
                l2 = 'u';
                l3 = 'e';
                break;
            case 3:
                l1 = 'W';
                l2 = 'e';
                l3 = 'd';
                break;
            case 4:
                l1 = 'T';
                l2 = 'h';
                l3 = 'u';
                break;
            case 5:
                l1 = 'F';
                l2 = 'r';
                l3 = 'i';
                break;
            case 6:
                l1 = 'S';
                l2 = 'a';
                l3 = 't';
                break;
            case 7:
                l1 = 'S';
                l2 = 'u';
                l3 = 'n';
                break;
            default:
                l1 = 'M';
                l2 = 'o';
                l3 = 'n';
                break;
        }      
    }
}
Day::Day(){
    // Defaults to monday
    Daynum(1);
}
Day::Day(int d){
    Daynum(d);
}
Day::Day(char l1, char l2, char l3){
    char s[3];
    s[0] = l1;
    s[1] = l2;
    s[2] = l3;

    int d {};
    if (s[0] == 'M' && s[1]== 'o' && s[2] == 'n'){
        Daynum(1);
    } else if (s[0] == 'T' && s[1]== 'u' && s[2] == 'e'){
        Daynum(2);
    } else if (s[0] == 'W' && s[1]== 'e' && s[2] == 'd'){
        Daynum(3);
    } else if (s[0] == 'T' && s[1]== 'h' && s[2] == 'u'){
        Daynum(4);
    } else if (s[0] == 'F' && s[1]== 'r' && s[2] == 'i'){
        Daynum(5);
    } else if (s[0] == 'S' && s[1]== 'a' && s[2] == 't'){
        Daynum(6);
    } else if (s[0] == 'S' && s[1]== 'u' && s[2] == 'n'){
        Daynum(7);
    }
}
void Day::output(){
    
    cout << l1 << l2 << l3 << endl;
}
Day Day::nextDay(){
    if (l1 == 'M' && l2== 'o' && l3 == 'n'){
        return Day(2);
    } else if (l1 == 'T' && l2 == 'u' && l3 == 'e'){
        return Day(3);
    } else if (l1 == 'W' && l2 == 'e' && l3 == 'd'){
        return Day(4);
    } else if (l1 == 'T' && l2 == 'h' && l3 == 'u'){
        return Day(5);
    } else if (l1 == 'F' && l2 == 'r' && l3 == 'i'){
        return Day(6);
    } else if (l1 == 'S' && l2 == 'a' && l3 == 't'){
        return Day(7);
    } else if (l1 == 'S' && l2 == 'u' && l3 == 'n'){
        return Day(1);
    } else {
        return Day(1);
    }
}


int main(){
    cout << "Test 1: Default constructor (should be Mon)" << endl;
    Day d1;
    d1.output();
    cout << endl;

    cout << "Test 2: Day(3) (should be Wed), then nextDay() (should be Thu)" << endl;
    Day d2(3);
    d2.output();
    d2.nextDay().output();
    cout << endl;

    cout << "Test 3: Day(7) (should be Sun), then nextDay() wraps to Mon" << endl;
    Day d3(7);
    d3.output();
    d3.nextDay().output();
    cout << endl;

    cout << "Test 4: Day('T','u','e') (should be Tue)" << endl;
    Day d4('T', 'u', 'e');
    d4.output();
    cout << endl;

    cout << "Test 5: Day('S','a','t') (should be Sat), then nextDay() (should be Sun)" << endl;
    Day d5('S', 'a', 't');
    d5.output();
    d5.nextDay().output();
    cout << endl;

    cout << "Test 6: Day(0) - invalid day number, should print error message" << endl;
    Day d6(0);
    cout << endl;

    cout << "Test 7: Day('F','r','i') (should be Fri), then nextDay() (should be Sat)" << endl;
    Day d7('F', 'r', 'i');
    d7.output();
    d7.nextDay().output();
    cout << endl;

    return 0;
}