#include <iostream>
using namespace std;

 void deleteVowels(char letters[], int size)
 {  
    const int N {size};
    char noVowels[N];
    int lastIndex {};
    for (int i {}; i < size; i++){
        char c {letters[i]};
        noVowels[i] = ' ';
        switch (c){
            case 'A':
            case 'a':
            case 'E':
            case 'e':
            case 'I':
            case 'i':
            case 'O':
            case 'o':
            case 'U':
            case 'u':
                break;
            default:
                noVowels[lastIndex] = c;
                lastIndex++;
        }
    }
    for (int i {}; i < size; i++){
        letters[i] = noVowels[i];
    }
 }

 void printArray(const char arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
    }
    cout << "\n";
}

int main() {
    // Test Case 1: Simple word
    char test1[] = {'H','e','l','l','o'};
    cout << "Test 1 original: ";
    printArray(test1, 5);
    deleteVowels(test1, 5);
    cout << "Test 1 no vowels: ";
    printArray(test1, 5);
    cout << "\n";

    // Test Case 2: Word with many vowels
    char test2[] = {'A','p','p','l','e'};
    cout << "Test 2 original: ";
    printArray(test2, 5);
    deleteVowels(test2, 5);
    cout << "Test 2 no vowels: ";
    printArray(test2, 5);
    cout << "\n";

    // Test Case 3: All vowels
    char test3[] = {'a','e','i','o','u'};
    cout << "Test 3 original: ";
    printArray(test3, 5);
    deleteVowels(test3, 5);
    cout << "Test 3 no vowels: ";
    printArray(test3, 5);
    cout << "\n";

    // Test Case 4: Mixed characters
    char test4[] = {'C','o','d','e','1','2','3'};
    cout << "Test 4 original: ";
    printArray(test4, 7);
    deleteVowels(test4, 7);
    cout << "Test 4 no vowels: ";
    printArray(test4, 7);
    cout << "\n";

    // Test Case 5: Sentence fragment
    char test5[] = {'T','h','i','s',' ','i','s',' ','i','t'};
    cout << "Test 5 original: ";
    printArray(test5, 10);
    deleteVowels(test5, 10);
    cout << "Test 5 no vowels: ";
    printArray(test5, 10);
    cout << "\n";

    return 0;
}