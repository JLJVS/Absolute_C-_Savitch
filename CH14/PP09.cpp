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
        int type;            // 0 human, 1 cyberdemon, 2 balrog, 3 elf
        int strength;        // How much damage we can inflict
        int hitpoints; 
        string species;     
        string getSpecies(); // Returns type of species
    public:
        Creature();
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

Creature::Creature(){
    
}