#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cstdio>

using std::cout, std::ifstream, std::ostream, std::string;
using std::setw, std::left, std::right;

struct Score{
    string name{"Anonymous"};
    int score {0};
};

class HighScoreTable{
    public:
        explicit HighScoreTable(const string& file_name = "highscores.txt");
        ~HighScoreTable();
        void print_high_scores(ostream& out = cout) const;
        void update_high_scores( const Score& new_score);
        void save() const;
        
    private:
        void load();
        
        static constexpr int max_entries{5};
        Score high_scores[max_entries];
        string file_name;
};

bool by_score_desc(const Score& a, const Score& b) { return a.score > b.score; };

void show(const char* label, const HighScoreTable& t)
{
    cout << "== " << label << " ==\n";
    t.print_high_scores();
    cout << "\n";
}

int main()
{   
    std::remove("test_scores.txt");
    std::remove("tie_scores.txt");

    HighScoreTable table {"test_scores.txt"};
    show("initial (no file: all Anonymous/0)", table);

    table.update_high_scores({"Mary Jane", 9001}); show("Mary Jane 9001 - beats everything", table);
    table.update_high_scores({"Bob", 750});        show("Bob 750", table);
    table.update_high_scores({"Zoe", 120});        show("Zoe 120", table);
    table.update_high_scores({"Al", 3000});        show("Al 3000 - inserts at rank 2", table);
    table.update_high_scores({"Mid", 500});        show("Mid 500 - table now full", table);
    table.update_high_scores({"Low", 1});          show("Low 1 - loses, unchanged", table);
    table.update_high_scores({"New", 5000});       show("New 5000 - rank 2, Zoe falls off", table);

    HighScoreTable ties {"tie_scores.txt"};
    for (int i = 0; i < 5; i++) ties.update_high_scores({"Player", 500});
    show("five identical 500s", ties);
    ties.update_high_scores({"Tie", 500});
    show("Tie 500 against a full table of 500s - rejected by >", ties);
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
    while (i < max_entries && (input >> s.score >> std::ws) && std::getline(input, s.name))
    {
        high_scores[i] = s;
        ++i;
    }
    std::sort(std::begin(high_scores), std::end(high_scores), by_score_desc);
}

void HighScoreTable::print_high_scores(ostream& out) const{
    for (int i{0}; i < max_entries; i++){
        
        out << right << setw(2) << ". " << left << setw(16) << high_scores[i].name << right << setw(6) << high_scores[i].score << "\n" ;
    }   
}

void HighScoreTable::update_high_scores( const Score& new_score){
    // check if the score is at least larger than the lowest high score
    if (new_score.score <= high_scores[max_entries - 1].score) return;
    high_scores[max_entries - 1] = new_score;   
    // sort 
    std::sort(std::begin(high_scores), std::end(high_scores), by_score_desc);
}

void HighScoreTable::save() const
{
    std::ofstream out(file_name);
    if (!out) return;
    for (const Score& s : high_scores)
        out << s.score << " " << s.name << "\n";
}

HighScoreTable::~HighScoreTable() { save(); }