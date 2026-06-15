#include <iostream>
using namespace std;

/*
break statements are used in while/do-while/for loops to end the loop if a specific event occurs for example if we add 1/i to a total we should exit iteration when 
we encounter a 1/0 to prevent a divide by zero error.
*/

int main(void)
{   
    const int N {10};
    int grades[N] {6, 8, 7, 9, 1, 7, 5, 10, 8, 5};
    cout << "Example without a break will print three times: " << endl;
    for (int i {0}; i < N; i++ ){
        if (grades[i] < 6){
            cout << "You failed this course, you'll have to do a retake." << endl;
        }
    }  

    cout << "Example with a break will print once so you know to look at it more in-depth: " << endl;
    for (int i {0}; i < N; i++ ){
        if (grades[i] < 6){
            cout << "You failed this course, you'll have to do a retake." << endl;
            break;
        }
    }


    return 0;
}