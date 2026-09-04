// Absolute C++ (Savitch, 5th ed) - Chapter 14, Programming Project 9
// THE STARTING CODE, as printed in the book (pp. 658-660).
//
//   g++ -std=c++20 -Wall -Wextra -g -D_GLIBCXX_ASSERTIONS PP14_09_creature_original.cpp -o creature
//
// ---------------------------------------------------------------------------
// THE TASK
//
// "One problem with this implementation is that it is unwieldy to add new
//  creatures. Rewrite the class to use inheritance, which will eliminate the
//  need for the variable type."
//
//   Creature                     <- base: basic damage, 0 < r <= strength
//     +-- Human
//     +-- Elf                    <- 10% chance to double the damage
//     +-- Demon                  <- 5% chance of +50 damage
//           +-- Cyberdemon
//           +-- Balrog           <- also attacks a second time
//
// "The getDamage() function in each class should only compute the damage
//  appropriate for that object. The total damage is then calculated by
//  combining the results of getDamage() at each level of the inheritance
//  hierarchy. Invoking getDamage() for a Balrog should invoke getDamage() for
//  the Demon, which should invoke getDamage() for the Creature."
//
// Also include accessors and mutators, and a main() driver that creates one of
// each creature and repeatedly prints the result of getDamage().
// ---------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>
using std::cout, std::endl, std::string;
using std::setw;

class Creature
{
    protected:
        int strength {10};        // How much damage we can inflict
        int hitpoints {10}; 
        string species {"Creature"};     
        
    public:
        Creature() = default; 
        // Initalizes default to 10 hp, 10 strength and species= "Creature"
        Creature(int newStrength, int newHit, string newSpecies);
        // Initialize creature to new type, strength, hit points

        // accessors / mutators (not given in the book)
        int  getStrength() const  { return strength; }
        int  getHitpoints() const { return hitpoints; }
        string  getSpecies() const {return species;}

        void setStrength(int s)   { strength = s; }
        void setHitpoints(int h)  { hitpoints = h; }

        virtual int getDamage();
        virtual ~Creature() = default;
        // Returns amount of damage this creature
        // inflicts in one round of combat
};

Creature::Creature(int newStrength, int newHit, string newSpecies) : strength{newStrength}, hitpoints{newHit}, species{newSpecies}{}

int Creature::getDamage(){
    int dmg = (rand()%strength+1);
    cout << species << " attacks for " << dmg << " points!" << endl;
    return dmg;
}

class Human : public Creature
{
    public:
        Human();
        // defaults to species human, 10 str, 10 hp
        Human(int newStrength, int newHit);
};

Human::Human() : Creature{10, 10, "Human"} {}
Human::Human(int newStrength, int newHit) : Creature{newStrength, newHit, "Human"} {}

class Demon : public Creature
{
    public:
        Demon();
        // defaults to 10 str, 10 hp, species demon
        Demon(int newStrength, int newHit);
        Demon(int newStrength, int newHit, string newSpecies);

        int getDamage() override;
};

Demon::Demon() : Creature{10, 10, "Demon"}{}
Demon::Demon(int newStrength, int newHit) : Creature{newStrength, newHit, "Demon"}{}
Demon::Demon(int newStrength, int newHit, string newSpecies) : Creature{newStrength, newHit, newSpecies}{}
int Demon::getDamage(){
    int dmg = Creature::getDamage();
    if (rand()%100 <5)
    {
        cout << "Demonic attack inflicts 50 additional damage points" << endl;
        dmg += 50;
    }
    return dmg;
}

class Elf : public Creature
{
    public:
        Elf();
        // defaults to 10 str, 10 hp, species elf
        Elf(int newStrength, int newHit);
        
        int getDamage() override;
};

Elf::Elf() : Creature{10, 10, "Elf"} {}
Elf::Elf(int newStrength, int newHit) : Creature{newStrength, newHit, "Elf"}{}

int Elf::getDamage(){
    int dmg = Creature::getDamage();
    if (rand()%100 < 10)
    {
        cout << "Magical attack inflicts " << dmg << " additional damage points!" << endl;
        dmg *= 2;
    }
    return dmg;
}

class Cyberdemon : public Demon
{
    public:
        Cyberdemon();
        // defaults to 10 str, 10 hp, species Cyberdemon
        Cyberdemon(int newStrength, int newHit);

};

Cyberdemon::Cyberdemon() : Demon{10, 10, "Cyberdemon"}{}
Cyberdemon::Cyberdemon(int newStrength, int newHit) : Demon{newStrength, newHit, "Cyberdemon"}{}

class Balrog : public Demon
{
    public:
        Balrog();
        // defaults to 10 str, 10 hp, species Ballrog
        Balrog(int newStrength, int newHit);

        int getDamage() override;
};

Balrog::Balrog() : Demon{10, 10, "Balrog"}{}
Balrog::Balrog(int newStrength, int newHit) : Demon{newStrength, newHit, "Balrog"}{}

int Balrog::getDamage()
{
    int dmg = Demon::getDamage();
    int dmg2 = (rand() % strength) + 1;
    cout << "Balrog speed attack inflicts " << dmg2 << " additional damage points!" << endl;
    return dmg + dmg2;
}


void battleArena(Creature& c1, Creature& c2){
    while (true){
        int dmg1 = c1.getDamage(), dmg2 = c2.getDamage();
        c1.setHitpoints(c1.getHitpoints()-dmg2);
        c2.setHitpoints(c2.getHitpoints()-dmg1);
        if (c1.getHitpoints() <= 0 && c2.getHitpoints() <= 0){
            cout << "It's a tie.\n" ;
            break;
        } else if (c2.getHitpoints() <= 0){
            cout << c1.getSpecies() << " wins.\n";
            break;
        } else if (c1.getHitpoints() <= 0){
            cout << c2.getSpecies() << " wins.\n";
            break;
        }
    }
}

int main()
{
    srand(42);

    // ---- 1. 14.9: each creature attacking, dispatched through Creature* ----
    cout << "########## 1. each creature attacks three times ##########\n";
    {
        Human      human;
        Elf        elf{12, 15};
        Cyberdemon cyber{20, 40};
        Balrog     balrog{25, 50};
        Creature*  one_of_each[] { &human, &elf, &cyber, &balrog };

        for (Creature* c : one_of_each){
            cout << "\n=== " << c->getSpecies() << " (strength " << c->getStrength()
                 << ", " << c->getHitpoints() << " hp) ===\n";
            for (int round = 0; round < 3; ++round){
                int total = c->getDamage();           // call first...
                cout << "  total: " << total << "\n"; // ...then print
            }
        }
    }

    // ---- 2. 15.4: battles, through Creature& ----
    cout << "\n\n########## 2. battleArena, which knows no species ##########\n";
    {
        cout << "\n--- Balrog vs Elf ---\n";
        Balrog balrog{25, 60};
        Elf    elf{15, 60};
        battleArena(balrog, elf);

        cout << "\n--- Human vs Cyberdemon ---\n";
        Human      human{18, 60};
        Cyberdemon cyber{18, 60};
        battleArena(human, cyber);
    }

    // ---- 3. does the extra attack actually matter? 2000 battles each ----
    cout << "\n\n########## 3. win rates over 2000 battles each ##########\n";
    {
        auto fight = [](Creature& x, Creature& y){          // returns 1, 2 or 0
            while (true){
                int d1 = x.getDamage(), d2 = y.getDamage();
                x.setHitpoints(x.getHitpoints()-d2);
                y.setHitpoints(y.getHitpoints()-d1);
                if (x.getHitpoints() <= 0 && y.getHitpoints() <= 0) return 0;
                if (y.getHitpoints() <= 0) return 1;
                if (x.getHitpoints() <= 0) return 2;
            }
        };

        // getDamage() prints; silence cout for the bulk runs by swapping its buffer
        std::ostringstream sink;
        std::streambuf* real = cout.rdbuf(sink.rdbuf());

        int be[3] {}, hc[3] {}, bc[3] {};
        for (int i = 0; i < 2000; ++i){
            { Balrog x{20,60}; Elf        y{20,60}; ++be[fight(x,y)]; }
            { Human  x{20,60}; Cyberdemon y{20,60}; ++hc[fight(x,y)]; }
            { Balrog x{20,60}; Cyberdemon y{20,60}; ++bc[fight(x,y)]; }
        }
        cout.rdbuf(real);                                    // restore

        cout << "  " << setw(24) << std::left << "matchup"
             << setw(10) << "first" << setw(10) << "second" << "ties\n";
        auto row = [](const char* label, int* r){
            cout << "  " << setw(24) << std::left << label
                 << setw(10) << r[1] << setw(10) << r[2] << r[0] << "\n"; };
        row("Balrog vs Elf",        be);
        row("Human vs Cyberdemon",  hc);
        row("Balrog vs Cyberdemon", bc);
    }
    return 0;
}