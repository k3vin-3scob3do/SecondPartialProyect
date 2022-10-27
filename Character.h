#include <string>
#include <vector>
#include "Power.h"
#include <windows.h>
#include <iostream>
using namespace std;

class Character{
    private:
        int life;
        vector<Power> powers;
        int attempts = 3;
        bool action = false;
    
    public:
        Character(int life, vector<Power> powers) : life(life), powers(powers){}
        int getLife(){return life;}
        int getAttempts(){return attempts;}
        vector<Power> getPowers(){return powers;}
        bool isAction(){
            return action;
        }
        void setLife(int life){
            this->life = life;
        }
        void setAttempts(int attempts){
            this->attempts = attempts;
        }  

        void setQuantityC(int quantity, int i){
            powers[i].setQuantity(quantity);
        }

        string getNameC(int i){
            return powers[i].getName();
        }

        int getDamageC(int i){
            return powers[i].getDamage();
        }

        int getQuantityC(int i){
            return powers[i].getQuantity();
        }

};





