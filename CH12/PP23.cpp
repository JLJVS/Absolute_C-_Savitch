// Absolute C++ (Savitch, 5th ed) - Chapter 12, Programming Project 23
// Anagram finder.
//
//   g++ -std=c++20 -Wall -Wextra -O2 PP12_23_anagrams_solution.cpp -o anagrams
//
// Approach: build an index of {word, canonical-form} pairs, sorted by the
// canonical form.  Anagram groups are then contiguous blocks, so one binary
// search plus two short walks yields a whole group.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout, std::cerr, std::cin, std::ifstream;
using std::string, std::vector;

struct Entry
{
    string word;
    string key;
};


// sorts the letters in alphabetical order
string canonical(const string& word)
{
    string k {word};
    std::sort(k.begin(), k.end());
    return k;
}


bool by_key(const Entry& a, const Entry& b)
{
    return a.key < b.key;
}


// Reads every whitespace-delimited word from file_name, computes its key,
// and leaves `entries` sorted by key.  False if the file could not be opened.
bool load_index(const string& file_name, vector<Entry>& entries)
{
    ifstream in(file_name);
    if (!in) return false;

    entries.reserve(400000);
    string w;
    while (in >> w) entries.push_back({w, canonical(w)});

    std::sort(entries.begin(), entries.end(), by_key);
    return true;
}


// Index of SOME entry whose key == target, or -1 if there is none.
// Note it is not necessarily the first such entry - which is why the
// callers below walk outwards in both directions.
int find_key(const vector<Entry>& entries, const string& target)
{
    int low {0}, high {static_cast<int>(entries.size())};
    while (low < high)
    {
        int middle {low + (high - low) / 2};
        if      (target < entries[middle].key) high = middle;
        else if (target > entries[middle].key) low  = middle + 1;
        else                                   return middle;
    }
    return -1;
}


// Every word sharing `word`'s canonical form, excluding `word` itself.
vector<string> anagrams_of(const vector<Entry>& entries, const string& word)
{
    vector<string> out;
    const string key {canonical(word)};

    const int hit {find_key(entries, key)};
    if (hit < 0) return out;

    // Walk to the first entry of the block.  The bounds test comes first in
    // each condition so short-circuiting stops us indexing out of range.
    int first {hit};
    while (first > 0 && entries[first - 1].key == key) --first;

    int last {hit};
    while (last + 1 < static_cast<int>(entries.size()) && entries[last + 1].key == key) ++last;

    for (int i {first}; i <= last; ++i)
        if (entries[i].word != word) out.push_back(entries[i].word);

    return out;
}


int main()
{
    vector<Entry> entries;
    if (!load_index("words.txt", entries))
    {
        cerr << "Error: could not open words.txt\n";
        return 1;
    }
    cout << entries.size() << " words indexed.\n";

    string query;
    while (cout << "\nWord (blank to quit): " && std::getline(cin, query) && !query.empty())
    {
        const vector<string> hits {anagrams_of(entries, query)};
        if (hits.empty()) { cout << "  no anagrams found\n"; continue; }
        for (const string& w : hits) cout << "  " << w << "\n";
    }
    return 0;
}


// ---------------------------------------------------------------------------
// The standard library does the search-plus-walk for you:
//
//     Entry probe {"", canonical(query)};
//     auto [lo, hi] = std::equal_range(entries.begin(), entries.end(), probe, by_key);
//     for (auto it = lo; it != hi; ++it) cout << it->word << "\n";
//
// std::lower_bound gives the first element not less than the key (the left end
// of the block, no backwards walk needed); std::upper_bound gives one past the
// right end; std::equal_range returns both.  Worth writing find_key by hand
// once, then using these.
// ---------------------------------------------------------------------------