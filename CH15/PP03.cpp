#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>
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

// ----------------------------------------

class Organism{
    public:
        Organism() = default;
        virtual void move(World& world, Position from) = 0;
        virtual ~Organism() = default;
        virtual char symbol() const = 0;
        virtual bool isPredator() const =0;
        
        bool hasMoved() const { return moved;}
        void setMoved(bool m) {moved  = m;}
    protected:
        bool moved {false};
        int stepsSurvied {0};
        

};

// ----------------------------------------

class Ant : public Organism{
    public:
        void move(World& world, Position from) override {};
        char symbol() const override {return 'O';}
        bool isPredator() const override {return false;}
};

void Ant::move(World& world, Position from)
{
    Position around[4];
    neighbours(from, around);

    const Position target = around[rand() % 4];
    if (world.isEmpty(target))
        world.moveTo(from, target);
}

class Doodlebug: public Organism{
    public:
        void move(World& world, Position from) override {};
        char symbol() const override {return 'X';}
        bool isPredator() const override {return true;}
};



// ----------------------------------------

class World
{   
    static constexpr int SIZE = 20;
    public:
        explicit World(int nDoodleBugs=5, int nAnts = 100);
        ~World();
        void draw() const;
        bool inBounds(Position p) const;
        bool isEmpty(Position p) const;
        Organism* at(Position p) const;
        void moveTo(Position from, Position to);
        void timeStep();
        void remove(Position p);

    private:
        Organism* grid[SIZE][SIZE] {};
        void populate(int nDoodleBugs, int nAnts);

};

// ----------------------------------------

World::World(int nDoodlebugs, int nAnts) { populate(nDoodlebugs, nAnts);}

World::~World()
{
    for (int r{}; r < SIZE; ++r){
        for (int c{}; c < SIZE; ++c){
            delete grid[r][c];
        }
    }
}

void World::populate(int nDoodleBugs, int nAnts){
    int x{}, y{};
    
    while (nDoodleBugs > 0){
        x = rand()%SIZE;
        y = rand()%SIZE;
        if (!grid[x][y]){
            grid[x][y] = new Doodlebug();
            nDoodleBugs--;
        }
    }
    while (nAnts>0){
        x = rand()%SIZE;
        y = rand()%SIZE;
        if (!grid[x][y]){
            grid[x][y] = new Ant();
            nAnts--;
        }
    }
}

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
}