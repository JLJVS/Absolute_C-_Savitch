#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
 
using std::cout, std::cerr, std::cin, std::ifstream;
using std::string, std::vector;

struct Entry {
    string word;
    string key;
};


string canonical(const string& word)
{
    string key{word};
    std::sort(key.begin(), key.end());
    return key;

}
{
    return 0;
}