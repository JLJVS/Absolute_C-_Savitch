#include <iostream>
using namespace std;

int own_strlen(char s[]){
    int length {};
    int index {0};
    while (s[index] != '\0'){
        index++;
        length++;
    }
    return length;
}

int main()
{
    char s[] = "abcde";
    char s2[] = "abc";
    char s3[] = "Why hello there!";

    cout << s << " has length " << own_strlen(s) << endl;
    cout << s2 << " has length " << own_strlen(s2) << endl;
    cout << s3 << " has length " << own_strlen(s3) << endl;

    return 0;
}