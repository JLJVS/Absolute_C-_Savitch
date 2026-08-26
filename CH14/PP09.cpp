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
    private:
        int type;            // 0 human, 1 cyberdemon, 2 balrog, 3 elf
        int strength;        // How much damage we can inflict
        int hitpoints;       // How much damage we can sustain
        string getSpecies(); // Returns type of species
    public:
        Creature();
        // Initialize to human, 10 strength, 10 hit points

        Creature(int newType, int newStrength, int newHit);
        // Initialize creature to new type, strength, hit points

        // accessors / mutators (not given in the book)
        int  getType() const      { return type; }
        int  getStrength() const  { return strength; }
        int  getHitpoints() const { return hitpoints; }
        void setType(int t)       { type = t; }
        void setStrength(int s)   { strength = s; }
        void setHitpoints(int h)  { hitpoints = h; }

        int getDamage();
        // Returns amount of damage this creature
        // inflicts in one round of combat
};

// constructor bodies are not given in the book; these match the comments
Creature::Creature() : type(0), strength(10), hitpoints(10) {}
Creature::Creature(int newType, int newStrength, int newHit)
    : type(newType), strength(newStrength), hitpoints(newHit) {}


string Creature::getSpecies()
{
  switch (type)
  {
    case 0: return "Human";
    case 1: return "Cyberdemon";
    case 2: return "Balrog";
    case 3: return "Elf";
  }
  return "Unknown";
}


int Creature::getDamage( )
{
  int damage;

    // All creatures inflict damage, which is a
    // random number up to their strength
    damage = (rand( ) % strength) + 1;
    cout << getSpecies( ) << " attacks for " <<
            damage << " points!" << endl;

    // Demons can inflict damage of 50 with a 5% chance
    //
    // *** BUG, AS PRINTED IN THE BOOK ***
    // (type = 2) is an ASSIGNMENT, not a comparison. It sets type to 2 and
    // evaluates to 2, which is true, so:
    //   - the branch is always taken, whatever the creature is, and
    //   - every creature permanently becomes a Balrog after one attack.
    // The extra parentheses also suppress GCC's -Wparentheses warning, so the
    // compiler says nothing. Should be (type == 2).
    if ((type = 2) || (type == 1))
       if ((rand( ) % 100) < 5)
       {
          damage = damage + 50;
          cout << "Demonic attack inflicts 50 "
              << " additional damage points!" << endl;
       }

    // Elves inflict double magical damage with a 10% chance
    if (type == 3)
    {
       if ((rand( ) % 10)==0)
       {
          cout << "Magical attack inflicts " << damage <<
                  " additional damage points!" << endl;
          damage = damage * 2;
       }
    }

    // Balrogs are so fast they get to attack twice
    if (type == 2)
    {
        int damage2 = (rand() % strength) + 1;
        cout << "Balrog speed attack inflicts " << damage2 <<
                 " additional damage points!" << endl;
        damage = damage + damage2;
    }
    return damage;
}


int main()
{
    srand(42);                       // fixed seed so runs are reproducible

    Creature human     (0, 10, 10);
    Creature cyberdemon(1, 20, 40);
    Creature balrog    (2, 25, 50);
    Creature elf       (3, 12, 15);

    Creature* all[] { &human, &cyberdemon, &balrog, &elf };

    for (Creature* c : all){
        cout << "\n=== creature starts as type " << c->getType() << " ===\n";
        for (int round = 0; round < 3; ++round)
            cout << "  round " << round + 1 << " total damage: " << c->getDamage()
                 << "   (type is now " << c->getType() << ")\n";
    }
    return 0;
}