#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int generate_winning_door(){
    return rand()%3+1;
}
int generate_player_choice(){
    return rand()%3+1;
}

bool original_choice(int wd, int pc){
    return (wd == pc);
}

bool swapped_choice(int wd, int pc){
    return (wd != pc);

}

int main()
{   
    srand(time(0));
    int N {10000}, original_wins {}, swapped_wins{};

    for (int i {}; i < N; i++){
        int winning_door {generate_winning_door()}, player_choice {generate_player_choice()};
        original_wins += original_choice(winning_door, player_choice);
        swapped_wins += swapped_choice(winning_door, player_choice);
    }

    cout << "After " << N << " rounds the original choice has " << original_wins << " wins and swapping yielded " << swapped_wins <<" wins." <<endl; 
}