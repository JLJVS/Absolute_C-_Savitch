#include <iostream>
#include <vector>

using std::cout;


class Suitor
{
public:
    Suitor(int theNumber, Suitor* theLink) : number(theNumber), next(theLink) {}

    int     getNumber() const     { return number; }
    Suitor* getLink() const       { return next; }
    void    setLink(Suitor* p)    { next = p; }

private:
    int     number;
    Suitor* next;
};

int josephus(int n)
{
    
    // guard against negative n
    if (n <= 0) return 0;

    // create the circular list of suitors
    Suitor* current = nullptr;
    Suitor* originalSuitor = nullptr;
    for (int i {1}; i <= n; ++i){
        if (! current){
            current = new Suitor(i, nullptr);
            originalSuitor = current;
        } else {
            Suitor* nextSuitor = new Suitor(i, nullptr);
            current->setLink(nextSuitor);
            current = current -> getLink();
        }
    }
    // Connect current to the original suitor
    current -> setLink(originalSuitor);
    
    while (current->getLink() != current)
    {   
        // move 2 to the right and remove the one to the right
        for (int i {}; i < 2; ++i) current = current -> getLink();
        Suitor* toRemove = current -> getLink();
        current -> setLink(toRemove->getLink());
        delete toRemove;
    }

    int winner = current -> getNumber();
    delete current;
    return winner;
}

// ============================================================================


// --------------------------------------------------------------- oracle ----
//
// The same answer computed a completely different way, as a check on the
// simulation. Work out WHY this recurrence is equivalent only after your
// linked-list version passes - deriving it is the reward for finishing.
//
//   J(1) = 0,  J(i) = (J(i-1) + 3) mod i,  answer = J(n) + 1
//
// (Positions are 0-based inside the recurrence, hence the +1 at the end.)

int oracle(int n)
{
    int j = 0;
    for (int i = 2; i <= n; ++i)
        j = (j + 3) % i;
    return j + 1;
}


// ---------------------------------------------------------------- tests ----

static int failures = 0;

void check(const char* label, int got, int want)
{
    const bool ok = (got == want);
    if (!ok) ++failures;
    cout << (ok ? "  ok   " : "  FAIL ") << label
         << " -> " << got << "   (expect " << want << ")\n";
}

int main()
{
    cout << "--- the book's example ---\n";
    check("n = 6 ", josephus(6), 1);

    cout << "\n--- small cases by hand ---\n";
    check("n = 1 ", josephus(1), 1);   // nobody is eliminated
    check("n = 2 ", josephus(2), 2);   // count 1,2,1 -> 1 goes
    check("n = 3 ", josephus(3), 2);   // 3 goes, then 1 goes

    cout << "\n--- agreement with the recurrence, n = 1..60 ---\n";
    int mismatches = 0;
    for (int n = 1; n <= 60; ++n)
        if (josephus(n) != oracle(n)){
            ++mismatches;
            if (mismatches <= 5)
                cout << "  n = " << n << ": simulation " << josephus(n)
                     << ", recurrence " << oracle(n) << "\n";
        }
    if (mismatches) { failures += mismatches; cout << "  " << mismatches << " mismatches\n"; }
    else            { cout << "  all 60 agree\n"; }

    cout << "\n--- the winners, n = 1..20 ---\n  ";
    for (int n = 1; n <= 20; ++n) cout << josephus(n) << ' ';
    cout << "\n  (look for the pattern - there is one, and it is the reason\n"
            "   the recurrence above works)\n";

    cout << (failures ? "\nSOME CHECKS FAILED\n" : "\nall checks passed\n");
    return failures;
}