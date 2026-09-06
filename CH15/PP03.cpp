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


class Organism{
    public:
        Organism() = default;
        Organism(int startX, int startY) : x{startX}, y{startY}{}
        virtual void move() = 0;
        virtual ~Organism() = default;
        virtual char symbol() const = 0;

        bool hasMoved() const { return moved;}
        void setMoved(bool m) {moved  = m;}
    protected:
        bool moved {false};
        int stepsSurvied {0};
        

};

class Ant : public Organism{
    public:
        Ant(int startX, int startY) : Organism{startX, startY} {}
        void move() override {};
        char symbol() const override {return 'O';}
};



class Doodlebug: public Organism{
    public:
        Doodlebug(int startX, int startY) : Organism{startX, startY} {}
        void move() override {};
        char symbol() const override {return 'X';}
};

class World
{   
    static constexpr int SIZE = 20;
    public:
        explicit World(int nDoodleBugs=5, int nAnts = 100);
        ~World();
        void draw() const;
        bool inBounds(int r, int c) const;
        bool isEmpty(int r, int c) const;
        Organism* at(int r, int c) const;
        void moveTo(Organism* who, int r, int c);
        
    private:
        Organism* grid[SIZE][SIZE] {};
        void populate(int nDoodleBugs, int nAnts);

};

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
            grid[x][y] = new Doodlebug(x, y);
            nDoodleBugs--;
        }
    }
    while (nAnts>0){
        x = rand()%SIZE;
        y = rand()%SIZE;
        if (!grid[x][y]){
            grid[x][y] = new Ant(x, y);
            nAnts--;
        }
    }
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

