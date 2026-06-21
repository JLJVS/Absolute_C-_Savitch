#include <iostream>
#include <string>
using namespace std;


string number_to_string(int n){
    if (n < 20){
        switch (n){
            case (0):
                return "Zero";
            case (1):
                return "One";
            case (2):
                return "Two";
            case (3):
                return "Three";
            case (4):
                return "Four";
            case (5):
                return "Five";
            case (6):
                return "Six";
            case (7):
                return "Seven";
            case (8):
                return "Eight";
            case (9):
                return "Nine";
            case (10):
                return "Ten";
            case (11):
                return "Eleven";
            case (12):
                return "Twelve";
            case (13):
                return "Thirteen";
            case (14):
                return "Fourteen";
            case (15):
                return "Fifteen";
            case (16):
                return "Sixteen";
            case (17):
                return "Seventeen";
            case (18):
                return "Eighteen";
            case (19):
                return "Nineteen";
            default:
                return "Zero";
        }
    }

    int first_digit {n/10}, second_digit {n%10};
    string first_part {};

    switch(first_digit){
        case (2):
            first_part = "Twenty";
            break;
        case (3):
            first_part = "Thirty";
            break;
        case (4):
            first_part = "Fourty";
            break;
        case (5):
            first_part = "Fifty";
            break;
        case (6):
            first_part = "Sixty";
            break;
        case (7):
            first_part = "Seventy";
            break;
        case (8):
            first_part = "Eighty";
            break;
        case (9):
            first_part = "Ninety";
            break;
        default :
            break;
    }

    switch(second_digit){
        case (0):
            return first_part;
        case (1):
            return first_part + "-one";
        case (2):
            return first_part + "-two";
        case (3):
            return first_part + "-three";
        case (4):
            return first_part + "-four";
        case (5):
            return first_part + "-five";
        case (6):
            return first_part + "-six";
        case (7):
            return first_part + "-seven";
        case (8):
            return first_part + "-eight";
        case (9):
            return first_part + "-nine";
        default:
            return first_part;
    }   
}

void print_bottles_song(){

    for (int i{99}; i>=0; i--){
        string num_string = number_to_string(i);
        if (i==0){
            cout << "Zero bottles of beer on the wall";
        } else if (i==1){
            cout << num_string << " bottle of beer on the wall,\n";
            cout << num_string << " bottle of beer,\n";
            cout << "Take one down, pass it around," << endl;
        } else {
            cout << num_string << " bottles of beer on the wall,\n";
            cout << num_string << " bottles of beer,\n";
            cout << "Take one down, pass it around," << endl;
        }
    }
}

int main()
{
    print_bottles_song();

    return 0;
}