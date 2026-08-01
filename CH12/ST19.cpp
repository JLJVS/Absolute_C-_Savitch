#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int num;
    string sampleString = "1234";
    stringstream ss(sampleString);
    ss >> num;
    return 0;
}