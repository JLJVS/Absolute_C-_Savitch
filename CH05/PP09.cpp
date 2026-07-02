#include <iostream>
using namespace std;

void print_grid(char a[]){
    for (int i {}; i < 3; i++){
        for (int j{}; j < 3; j++){
            cout << a[3*i+j] << " ";
        }
        cout << endl;
    }
}

bool someone_wins(char grid[]){
    // rows
    bool row1 {(grid[0]==grid[1])&&(grid[0]==grid[2])};
    bool row2 {(grid[3]==grid[4])&&(grid[3]==grid[5])};
    bool row3 {(grid[6]==grid[7])&&(grid[6]==grid[8])};
    // columns
    bool col1 {(grid[0]==grid[3])&&(grid[0]==grid[6])};
    bool col2 {(grid[1]==grid[4])&&(grid[1]==grid[7])};
    bool col3 {(grid[2]==grid[5])&&(grid[2]==grid[8])};
    // diagonals
    bool diag1 {(grid[0]==grid[4])&&(grid[0]==grid[8])};
    bool diag2 {(grid[2]==grid[4])&&(grid[2]==grid[6])};
    return row1 || row2 || row3 || col1 || col2 || col3 || diag1 || diag2;
}

void TicTacToe()
{   
    char grid[9] {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    cout << "Welcome to tic tac toe press the number to select where to enter your mark" << endl;
    cout << endl;

    bool winner {false};
    int round {1};

    while (!winner && round < 9){
        print_grid(grid);
        char mark {'O'};
        if (round%2==1){
            mark = {'X'};
        }
        round++;
        char choice {};
        bool valid_choice {false};
        while (!valid_choice){
            cin >> choice;
            switch (choice){
                case '1':
                    if (grid[0] == choice){
                        grid[0] = mark;
                        valid_choice = true;
                        break;
                    }
                case '2':
                    if (grid[1] == choice){
                        grid[1] = mark;
                        valid_choice = true;
                        break;
                    }
                case '3':
                    if (grid[2] == choice){
                        grid[2] = mark;
                        valid_choice = true;
                        break;
                    }
                case '4':
                    if (grid[3] == choice){
                        grid[3] = mark;
                        valid_choice = true;
                        break;
                    }
                case '5':
                    if (grid[4] == choice){
                        grid[4] = mark;
                        valid_choice = true;
                        break;
                    }
                case '6':
                    if (grid[5] == choice){
                        grid[5] = mark;
                        valid_choice = true;
                        break;
                    }
                case '7':
                    if (grid[6] == choice){
                        grid[6] = mark;
                        valid_choice = true;
                        break;
                    }
                case '8':
                    if (grid[7] == choice){
                        grid[7] = mark;
                        valid_choice = true;
                        break;
                    }
                case '9':
                    if (grid[8] == choice){
                        grid[8] = mark;
                        valid_choice = true;
                        break;
                    }
                default:
                    break;
            }
        }
        if (someone_wins(grid)){
            cout << "Player " << mark << " has won" << endl;
            break;
        }
        if (round == 9){
            cout << "noone wins" << endl;
        }
    }
    




    return;
}

int main()
{
    TicTacToe();


    return 0;
}