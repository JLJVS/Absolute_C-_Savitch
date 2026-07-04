#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class BoxOfProduce
{
    public:
        void set_item(int index, string s);
        string get_item(int index);
        void output();
        void output_to_file(const string& filename);
        void get_three_items(string selection[3]);
        
    private:
        string items[5];
};

void BoxOfProduce::set_item(int index, string s){
    items[index] = s;
}
string BoxOfProduce::get_item(int index){
    return items[index];
}
void BoxOfProduce::output(){
    cout << "Your box contains: ";
    for (int i {}; i < 5; i++){
        cout << get_item(i) << ", ";
    }
    cout << endl;
    
}
void BoxOfProduce::get_three_items(string selection[3]){
    for (int i = 0; i < 3; i++){
        selection[i] = items[rand() % 5];
    }
}

void BoxOfProduce::output_to_file(const string& filename){
    ofstream out(filename);

    if (!out){
        cout << "Error opening file.\n";
        return;
    }

    out << "Your box contains: ";
    for (int i = 0; i < 5; i++){
        out << items[i];
        if (i < 4) out << ", ";
    }
    out << endl;

    out.close();
}

int main()
{
    srand(time(nullptr));

    // Prepare a box with 5 items
    BoxOfProduce box;
    box.set_item(0, "Tomato");
    box.set_item(1, "Lettuce");
    box.set_item(2, "Onion");
    box.set_item(3, "Pepper");
    box.set_item(4, "Spinach");

    cout << "Initial box contents:\n";
    box.output();
    cout << "\n";


    // ---------- Test Case 1 ----------
    cout << "=== Test Case 1 ===\n";
    cout << "Pulling 3 items three times:\n";

    for (int i = 0; i < 3; i++){
        string pulled[3];
        box.get_three_items(pulled);

        cout << "Pull " << i+1 << ": ";
        cout << pulled[0] << ", " << pulled[1] << ", " << pulled[2] << endl;
    }
    cout << "\n";


    // ---------- Test Case 2 ----------
    cout << "=== Test Case 2 ===\n";
    cout << "Pulling 3 items five times:\n";

    for (int i = 0; i < 5; i++){
        string pulled[3];
        box.get_three_items(pulled);

        cout << "Pull " << i+1 << ": ";
        cout << pulled[0] << ", " << pulled[1] << ", " << pulled[2] << endl;
    }
    cout << "\n";


    // ---------- Test Case 3 ----------
    cout << "=== Test Case 3 ===\n";
    cout << "Pulling 3 items ten times:\n";

    for (int i = 0; i < 10; i++){
        string pulled[3];
        box.get_three_items(pulled);

        cout << "Pull " << i+1 << ": ";
        cout << pulled[0] << ", " << pulled[1] << ", " << pulled[2] << endl;
    }
    cout << "\n";


    // -- testing the output to file

    box.output_to_file("produce.txt");
    return 0;
}
