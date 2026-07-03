#include <iostream>
using namespace std;

class quizz
{
    public:
        void set(double points);
        double get();
    private:
        double p;
};

class midterm
{
    public:
        void set(double points);
        double get();
    private:
        double p;
};

class finals
{
    public:
        void set(double points);
        double get();
    private:
        double p;
};

void quizz::set(double points){
    p = points;
} 
double quizz::get(){
    return p;
}
void midterm::set(double points){
    p = points;
} 
double midterm::get(){
    return p;
}
void finals::set(double points){
    p = points;
} 
double finals::get(){
    return p;
}


class GradingProgram
{
    public:
        void set_q1(double points);
        void set_q2(double points);
        void set_midterm(double points);
        void set_finals(double points);
        double get_grade();
    private:
        double q1;
        double q2;
        double midterm;
        double finals;
};

void GradingProgram::set_q1(double points){
    q1 = points;
}
void GradingProgram::set_q2(double points){
    q2 = points;
}
void GradingProgram::set_midterm(double points){
    midterm = points;
}
void GradingProgram::set_finals(double points){
    finals = points;
}

double GradingProgram::get_grade()
{
    double total = (q1/10+q2/10)/2*0.25 + (midterm/100)*0.25 + (finals/100)*0.5;
    cout << "Numeric grade: " << total << endl;

    char letter;

    if (total >= 0.90) letter = 'A';
    else if (total >= 0.80) letter = 'B';
    else if (total >= 0.70) letter = 'C';
    else if (total >= 0.60) letter = 'D';
    else letter = 'F';

    cout << "Letter grade: " << letter << endl;

    return total;
}

int main()
{
    // ---------- Test Case 1 ----------
    GradingProgram s1;
    s1.set_q1(8);        // out of 10
    s1.set_q2(9);        // out of 10
    s1.set_midterm(85);  // out of 100
    s1.set_finals(92);   // out of 100

    cout << "=== Test Case 1 ===\n";
    cout << "Inputs: q1=8, q2=9, midterm=85, finals=92\n";

    double expected1 = (8/10.0 + 9/10.0)/2*0.25 + (85/100.0)*0.25 + (92/100.0)*0.5;
    cout << "Expected numeric: " << expected1 << endl;

    char expLetter1 =
        expected1 >= 0.90 ? 'A' :
        expected1 >= 0.80 ? 'B' :
        expected1 >= 0.70 ? 'C' :
        expected1 >= 0.60 ? 'D' : 'F';

    cout << "Expected letter: " << expLetter1 << endl;

    cout << "Actual output:\n";
    s1.get_grade();
    cout << "\n";


    // ---------- Test Case 2 ----------
    GradingProgram s2;
    s2.set_q1(5);
    s2.set_q2(6);
    s2.set_midterm(70);
    s2.set_finals(75);

    cout << "=== Test Case 2 ===\n";
    cout << "Inputs: q1=5, q2=6, midterm=70, finals=75\n";

    double expected2 = (5/10.0 + 6/10.0)/2*0.25 + (70/100.0)*0.25 + (75/100.0)*0.5;
    cout << "Expected numeric: " << expected2 << endl;

    char expLetter2 =
        expected2 >= 0.90 ? 'A' :
        expected2 >= 0.80 ? 'B' :
        expected2 >= 0.70 ? 'C' :
        expected2 >= 0.60 ? 'D' : 'F';

    cout << "Expected letter: " << expLetter2 << endl;

    cout << "Actual output:\n";
    s2.get_grade();
    cout << "\n";


    // ---------- Test Case 3 ----------
    GradingProgram s3;
    s3.set_q1(10);
    s3.set_q2(10);
    s3.set_midterm(95);
    s3.set_finals(98);

    cout << "=== Test Case 3 ===\n";
    cout << "Inputs: q1=10, q2=10, midterm=95, finals=98\n";

    double expected3 = (10/10.0 + 10/10.0)/2*0.25 + (95/100.0)*0.25 + (98/100.0)*0.5;
    cout << "Expected numeric: " << expected3 << endl;

    char expLetter3 =
        expected3 >= 0.90 ? 'A' :
        expected3 >= 0.80 ? 'B' :
        expected3 >= 0.70 ? 'C' :
        expected3 >= 0.60 ? 'D' : 'F';

    cout << "Expected letter: " << expLetter3 << endl;

    cout << "Actual output:\n";
    s3.get_grade();
    cout << "\n";

    return 0;
}