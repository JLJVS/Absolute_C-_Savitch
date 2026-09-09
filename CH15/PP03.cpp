#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <cassert>
using std::cout, std::endl, std::string;
using std::setw;

struct Position
{
    int row {0};
    int col {0};
};

// ----------------------------------------

inline void neighbours(Position p, Position out[4])
{
    out[0] = { p.row - 1, p.col };      // up
    out[1] = { p.row + 1, p.col };      // down
    out[2] = { p.row,     p.col - 1 };  // left
    out[3] = { p.row,     p.col + 1 };  // right
}

// ----------------------------------------

class World;
class Organism;

// -----------------------------------------

struct BirthRec
{
    Organism* who {nullptr};
    Position  at  {};
};

// ----------------------------------------

class Organism{
    public:
        Organism() = default;
        virtual void move(World& world, Position from) = 0;
        virtual ~Organism() = default;
        virtual char symbol() const = 0;
        virtual bool isPredator() const =0;
 
        void breed(World& world, Position from, BirthRec* out, int& count);
        virtual int  breedInterval() const = 0;
        virtual Organism* createOffspring() const=0;
 
        // Not pure: ants cannot starve, so they inherit a sensible default
        // rather than being forced to implement something meaningless.
        virtual bool hasStarved() const { return false; }
 
        bool hasMoved() const { return moved;}
        void setMoved(bool m) {moved  = m;}
    protected:
        bool moved {false};
        int stepsSurvived {0};
  
};

// ----------------------------------------

class Ant : public Organism{
    public:
        void move(World& world, Position from) override;
        char symbol() const override {return 'O';}
        bool isPredator() const override {return false;}
        int  breedInterval() const override {return 3;}
        Organism* createOffspring() const override { return new Ant{}; }
};

class Doodlebug: public Organism{
    public:
        void move(World& world, Position from) override;
        char symbol() const override {return 'X';}
        bool isPredator() const override {return true;}
        int breedInterval() const override {return 8;}
        Organism* createOffspring() const override { return new Doodlebug{}; }
        bool      hasStarved() const override      { return stepsSinceEating >= 3; }
    private:
        int stepsSinceEating {};
};

// ----------------------------------------

class World
{
    static constexpr int SIZE = 20;
    public:
        explicit World(int nDoodleBugs=5, int nAnts = 100);
        ~World();
 
        World(const World&)            = delete;
        World& operator=(const World&) = delete;
 
        void draw() const;
        void report(int step) const;
        bool inBounds(Position p) const;
        bool isEmpty(Position p) const;
        Organism* at(Position p) const;
        void moveTo(Position from, Position to);
        void timeStep();
        void remove(Position p);
        void place(Organism* who, Position p);
 
    private:
        Organism* grid[SIZE][SIZE] {};
        void populate(int nDoodleBugs, int nAnts);
 
};
// ----------------------------------------

// constructor
World::World(int nDoodlebugs, int nAnts) { populate(nDoodlebugs, nAnts);}
 // destructor
World::~World()
{
    for (int r{}; r < SIZE; ++r){
        for (int c{}; c < SIZE; ++c){
            delete grid[r][c];
        }
    }
}
 
void World::place(Organism* who, Position p){
    assert(isEmpty(p) && "place() requires an empty cell");
    grid[p.row][p.col] = who;
}
 
void World::populate(int nDoodleBugs, int nAnts){
    while (nDoodleBugs > 0){
        Position p { rand()%SIZE, rand()%SIZE };
        if (isEmpty(p)){
            place(new Doodlebug{}, p);
            nDoodleBugs--;
        }
    }
    while (nAnts > 0){
        Position p { rand()%SIZE, rand()%SIZE };
        if (isEmpty(p)){
            place(new Ant{}, p);
            nAnts--;
        }
    }
}
// helpers 
bool World::inBounds(Position p) const{
    return p.row >= 0 && p.row < SIZE && p.col >= 0 && p.col < SIZE;
}
 
bool World::isEmpty(Position p) const{
    return inBounds(p) && grid[p.row][p.col] == nullptr;
}
 
Organism* World::at(Position p) const
{
    return inBounds(p) ? grid[p.row][p.col] : nullptr;
}
 
void World::moveTo(Position from, Position to){
    grid[to.row][to.col] = grid[from.row][from.col];
    grid[from.row][from.col] = nullptr;
}
 
void World::draw() const{
    for (int r{}; r < SIZE; ++r){
        for (int c{}; c < SIZE; ++c){
            if (grid[r][c]){
                cout << grid[r][c]->symbol();
            } else {
                cout << '_';
            }
        }
        cout << "\n";
    }
}
 
void World::report(int step) const{
    int ants{}, bugs{};
    for (int r{}; r < SIZE; ++r)
        for (int c{}; c < SIZE; ++c)
            if (grid[r][c]) { grid[r][c]->isPredator() ? ++bugs : ++ants; }
    cout << "  step " << setw(4) << step
         << ":  ants " << setw(4) << ants
         << ",  doodlebugs " << setw(3) << bugs << "\n";
}
 
void World::remove(Position p){
    delete grid[p.row][p.col];
    grid[p.row][p.col] = nullptr;
}
 
void World::timeStep()
{
    // 1. everyone is eligible again
    for (int r {}; r < SIZE; ++r)
        for (int c {}; c < SIZE; ++c)
            if (grid[r][c]) grid[r][c]->setMoved(false);
 
    // 2. predators first, then prey
    for (bool predatorPhase : { true, false })
        for (int r {}; r < SIZE; ++r)
            for (int c {}; c < SIZE; ++c){
                Organism* o = grid[r][c];
                if (o && !o->hasMoved() && o->isPredator() == predatorPhase){
                    o->setMoved(true);          // set BEFORE moving: afterwards
                    o->move(*this, {r, c});     // grid[r][c] is empty
                }
            }
 
    // 3. ageing and breeding. Births are collected, then placed.
    BirthRec births[SIZE * SIZE];
    int nBirths {};
    for (int r {}; r < SIZE; ++r)
        for (int c {}; c < SIZE; ++c)
            if (grid[r][c]) grid[r][c]->breed(*this, {r, c}, births, nBirths);
 
    for (int i {}; i < nBirths; ++i){
        // The cell was empty when the birth was recorded, but an earlier birth
        // in this same batch may have taken it since.
        if (isEmpty(births[i].at)) place(births[i].who, births[i].at);
        else                       delete births[i].who;
    }
 
    // 4. starvation, last, so a doodlebug that ate this step survives
    for (int r {}; r < SIZE; ++r)
        for (int c {}; c < SIZE; ++c)
            if (grid[r][c] && grid[r][c]->hasStarved()) remove({r, c});
}

// ----------------------------------------

void Organism::breed(World& world, Position from, BirthRec* out, int& count)
{
    ++stepsSurvived;
    if (stepsSurvived < breedInterval()) return;
 
    Position around[4];
    neighbours(from, around);
 
    for (Position p : around)
        if (world.isEmpty(p)){
            out[count++] = { createOffspring(), p };
            stepsSurvived = 0;            // reset ONLY on a successful birth
            return;
        }
    // No empty neighbour: no birth, counter untouched, try again next step.
}

void Ant::move(World& world, Position from)
{
    Position around[4];
    neighbours(from, around);

    const Position target = around[rand() % 4];
    if (world.isEmpty(target))
        world.moveTo(from, target);
}


void Doodlebug::move(World& world, Position from)
{
    Position around[4];
    neighbours(from, around);

    for (Position p : around){
        Organism* neighbour = world.at(p);
        if (neighbour && !neighbour->isPredator()){
            world.remove(p);
            world.moveTo(from, p);
            stepsSinceEating=0;
            return;
        }
    }
    const Position target = around[rand() % 4];
    if (world.isEmpty(target))
        world.moveTo(from, target);
    stepsSinceEating++;

}

// ----------------------------------------

int main()
{
    srand(42);
 
    World world;
    for (int step {}; step <= 120; ++step){
        if (step % 10 == 0) world.report(step);
        world.timeStep();
    }
 
    cout << "\nfinal grid:\n";
    world.draw();
    return 0;
}