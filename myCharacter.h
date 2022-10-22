#include <string>
#include <vector>
#include "myPowers.h"
using namespace std;

class Character{
    private:
        string name;
        int life;
        vector<Power> powers;
    
    public:
        Character() : name(""), life(0), powers({}){}
        Character(string name, int life, vector<Power> powers) : name(name), life(life), powers(powers){}
        string getName(){return name;}
        int getLife(){return life;}
        vector<Power> getPowers(){return powers;}

};


