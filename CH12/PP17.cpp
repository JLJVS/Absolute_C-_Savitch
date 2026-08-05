#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <chrono>
using std::cout, std::cerr, std::ifstream, std::ofstream, std::endl;
using std::vector, std::string;

bool find_match(const vector<string>& words, const string& target){
    size_t low {0}, high {words.size()};

    while (low < high)
    {
        size_t middle = low + (high-low)/2;
        if (target < words[middle]){
            high = middle;
        } else if (target > words[middle]){
            low = middle + 1;
        } else {
            return true;
        }
    }
    return false;
}


string reverse_word(const string& word){
    string reversed {};
    for (auto letter: word){
        reversed = letter + reversed;
    }
    return reversed;
}


int main()
{   
    
    ifstream wordList("words.txt");
    string word;
    vector<string> words {};
    int matches {};

    // first create our dynamic array of words
    while (wordList >> word)
    {   
        words.push_back(word);
    }
    auto t0 = std::chrono::steady_clock::now();
    string longest_word {};
    // reverse the word 
    for (const auto& w: words){
        string reversed {reverse_word(w)};
        if (reversed == w){
            continue;
        }
        if (find_match(words, reversed)){
            if (reversed.size() > longest_word.size()){
                longest_word = w;
                
            }
            matches++;
            continue;
        }
         
        
    }
    auto t1 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = t1 - t0;

    cout << words.size() << endl;
    cout << "Longest word: " << longest_word << " has a length of " << longest_word.size() << endl;
    cout << "Matches: " << matches << endl;
    cout << "search: " << elapsed.count() << " s\n";
    return 0;
}