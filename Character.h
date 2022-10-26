#include <string>
#include <vector>
#include "Power.h"
using namespace std;

class Character{
    private:
        int life;
        vector<Power> powers;
        int attempts = 5;
    
    public:
        Character(int life, vector<Power> powers) : life(life), powers(powers){}
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





