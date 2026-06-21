#include <iostream>
#include <cstdlib>
using namespace std;

int game_of_pig(char player){
    int dice {rand()%6+1}, score{};
    char choice {};
    
    while (choice != 'h'){
        score += dice;
        if (dice==1){
            cout << "Too bad you rolled a one!" << endl;
            return 0;
        }
        if (player=='p'){
            cout << "Your score is " << score << endl;
            cout << "To roll again enter r or to hold enter h: ";
            cin >> choice;
            if (choice == 'h'){
                return score;
            } else {
                dice = rand()%6+1;
            }
        } else {
            if (score < 20){
                dice = rand()%6+1;
            } else {
                return score;
            }
        }
        
    }
}

int main()
{

    int player_score {}, computer_score{};

    while (true){
        cout << "player score: " << player_score << ", computer score: " << computer_score << endl;

        cout << "Player turn: " << endl;
        player_score += game_of_pig('p');
        cout << "Player score: " << player_score << endl;
        if (player_score>= 100){
            cout << "Player wins" << endl;
            break;
        }

        cout << "Computer turn: " << endl;
        computer_score += game_of_pig('c');
        cout << "Computer score: " << computer_score << endl;
        if (computer_score>= 100){
            cout << "Computer wins" << endl;
            break;
        }
    }


    return 0;
}