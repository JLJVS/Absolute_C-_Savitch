#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
    int num = 1234;
    stringstream ss("");
    ss << num;
    string sampleString = ss.str();


    return 0;
}