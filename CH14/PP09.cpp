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
using std::cout, std::endl, std::string;

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

        int getDamage();
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

        int getDamage();
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
        
        int getDamage();
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

        int getDamage();
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

int main()
{
    // ---------- part 1: called on the objects directly ----------
    // This works correctly with or without `virtual` - the compiler knows
    // the exact type of each object, so it picks the right getDamage().
    cout << "########## called on the objects directly ##########\n";
    {
        srand(42);                       // fixed seed: reproducible runs
        Human      human;
        Elf        elf{12, 15};
        Cyberdemon cyber{20, 40};
        Balrog     balrog{25, 50};

        Human*      ph = &human;
        Elf*        pe = &elf;
        Cyberdemon* pc = &cyber;
        Balrog*     pb = &balrog;

        cout << "\n=== " << ph->getSpecies() << " ===\n";
        for (int i = 0; i < 3; ++i){ int t = ph->getDamage(); cout << "  total: " << t << "\n"; }

        cout << "\n=== " << pe->getSpecies() << " ===\n";
        for (int i = 0; i < 3; ++i){ int t = pe->getDamage(); cout << "  total: " << t << "\n"; }

        cout << "\n=== " << pc->getSpecies() << " ===\n";
        for (int i = 0; i < 3; ++i){ int t = pc->getDamage(); cout << "  total: " << t << "\n"; }

        cout << "\n=== " << pb->getSpecies() << " ===\n";
        for (int i = 0; i < 3; ++i){ int t = pb->getDamage(); cout << "  total: " << t << "\n"; }
    }

    // ---------- part 2: the same objects through a Creature* ----------
    // THIS is the part that changes when you add `virtual`.
    // Without it: every call runs Creature::getDamage(), so the elf never
    // doubles and the balrog never gets its second attack.
    cout << "\n\n########## the same objects, through a Creature* ##########\n";
    {
        srand(42);                       // same seed, so the rolls line up
        Human      human;
        Elf        elf{12, 15};
        Cyberdemon cyber{20, 40};
        Balrog     balrog{25, 50};

        Creature* party[] { &human, &elf, &cyber, &balrog };

        for (Creature* c : party){
            cout << "\n=== " << c->getSpecies() << " ===\n";
            for (int i = 0; i < 3; ++i){
                int t = c->getDamage();          // note: call first...
                cout << "  total: " << t << "\n";  // ...then print
            }
        }
    }

    return 0;
}