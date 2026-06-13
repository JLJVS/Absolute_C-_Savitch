#include <iostream>
using namespace std;

int main(void)
{
    int temperature {150}, pressure{190};

    if ((temperature >= 100) || (pressure >= 200) ){
        cout << "Warning" << endl;
    } else {
        cout << "OK" << endl;
    }




    return 0;
}