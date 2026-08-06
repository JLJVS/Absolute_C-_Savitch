#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using std::cout, std::ifstream, std::ofstream, std::string;

struct Score{
    string name{"Anonymous"};
    int score {0};
};

class HighScoreTable{
    public:
        explicit HighScoreTable(const string& file_name = "highscores.txt");
        ~HighScoreTable();
        void print_high_scores() const;
        void update_high_scores( const Score& new_score);
        
    private:
        void load();
        Score high_scores[5];
        string file_name;
};



int main()
{   
    // set up IO
    string fileName {"highscores.txt"};
    ifstream readFile {fileName};
    ofstream writeFile{fileName};

    

    return 0;
}


HighScoreTable::HighScoreTable(const string& fn) : file_name {fn}
{
    load();
}

void HighScoreTable::load()
{
    ifstream input(file_name);
    if (!input) return; // no high scores file found just use the default Score(anonymous, 0)

    Score s;
    int i {0};

    // left check is to ensure we don't read more than 5 scores
    // middle check reads the score from input with >> and then skips the whitespace with std::ws from istream library
    // right check reads the name (with possible white spaces) with std::geline from the string library
    while (i < 5 && (input >> s.score >> std::ws) && std::getline(input, s.name))
    {
        high_scores[i] = s;
        ++i;
    }

}