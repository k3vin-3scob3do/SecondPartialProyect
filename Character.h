#include <string>
#include <vector>
#include "Power.h"
using namespace std;

class Character{
    private:
        string name;
        int life;
        vector<Power> powers;
        int attempts = 5;
    
    public:
        Character(string name, int life, vector<Power> powers) : name(name), life(life), powers(powers){}
        string getName(){return name;}
        int getLife(){return life;}
        int getAttempts(){return attempts;}
        vector<Power> getPowers(){return powers;}
        void setLife(int life){
            this->life = life;
        }
        void setAttempts(int attempts){
            this->attempts = attempts;
        }

};





