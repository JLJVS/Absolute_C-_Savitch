#include <iostream>
#include <queue>
using namespace std;

class Suitor
{
    public:
        Suitor(int n, int k);
        void winner();

    private:
        queue<int> q;
        int stepSize;
};

Suitor::Suitor(int n, int k){
    for (int i{}; i < n; i++){
        q.push(i+1);
    }
    stepSize = k;
}

void Suitor::winner(){
    while (q.size() > 1){
        for (int i{}; i < stepSize; i++){
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    cout << q.front() << " is the winner." << endl;
}

int main(){
    Suitor s = Suitor(6, 3);
    s.winner();

    return 0;
}