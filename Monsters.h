#include "Character.h"
#include <map>
#include <vector>
#include<string>
using namespace std;


class gMonsters{
    private:
        map<string, Character> gM;
    public:
        gMonsters(){
            vector<Power> vP;

            //Fire-Snake
            vP.push_back(Power("Health", "Fire", 20, 5));
            vP.push_back(Power("Attack", "Fire", 50, 5));
            vP.push_back(Power("Shields", "Fire", 50, 5));
            vP.push_back(Power("Ultimate", "Fire", 20, 5));
            gM.insert(make_pair("Fire-Storm", Character("Fire-Snake", 500, vP)));
            vP.clear();

            //Leviatan
            vP.push_back(Power("Health", "Water", 20, 5));
            vP.push_back(Power("Attack", "Water", 50, 5));
            vP.push_back(Power("Shields", "Water", 50, 5));
            vP.push_back(Power("Ultimate", "Water", 20, 5));
            gM.insert(make_pair("Leviatan", Character("Leviatan", 500, vP)));
            vP.clear();

            //Thunder-Eagle
            vP.push_back(Power("Health", "Fire", 20, 5));
            vP.push_back(Power("Attack", "Fire", 50, 5));
            vP.push_back(Power("Shields", "Fire", 50, 5));
            vP.push_back(Power("Ultimate", "Fire", 20, 5));
            gM.insert(make_pair("Thunder-Eagle", Character("Thunder-Eagle", 500, vP)));
            vP.clear();

            //Earth-Colossus
            vP.push_back(Power("Health", "Fire", 20, 5));
            vP.push_back(Power("Attack", "Fire", 50, 5));
            vP.push_back(Power("Shields", "Fire", 50, 5));
            vP.push_back(Power("Ultimate", "Fire", 20, 5));
            gM.insert(make_pair("Fire-Storm", Character("Earth-Colossus", 500, vP)));
            vP.clear();         
        }

        map<string, Character> getMap(){
            return gM;
        }

};

class bMonsters{
    private:
        map<string, Character> bM;
    public:
        bMonsters(){
            vector<Power> vP;

            //Bad-Skull
            vP.push_back(Power("Health", "Fire", 20, 5));
            vP.push_back(Power("Attack", "Fire", 50, 5));
            vP.push_back(Power("Shields", "Fire", 50, 5));
            vP.push_back(Power("Ultimate", "Fire", 20, 5));
            bM.insert(make_pair("Bad-Skull", Character("Bad-Skull", 500, vP)));
            vP.clear();

            //Bat-Storm
            vP.push_back(Power("Health", "Water", 20, 5));
            vP.push_back(Power("Attack", "Water", 50, 5));
            vP.push_back(Power("Shields", "Water", 50, 5));
            vP.push_back(Power("Ultimate", "Water", 20, 5));
            bM.insert(make_pair("Bad-Storm", Character("Bad-Storm", 500, vP)));
            vP.clear();

            //Black-Ghost
            vP.push_back(Power("Health", "Fire", 20, 5));
            vP.push_back(Power("Attack", "Fire", 50, 5));
            vP.push_back(Power("Shields", "Fire", 50, 5));
            vP.push_back(Power("Ultimate", "Fire", 20, 5));
            bM.insert(make_pair("Black-Ghost", Character("Black-Ghost", 500, vP)));
            vP.clear();

            //
            vP.push_back(Power("Health", "Fire", 20, 5));
            vP.push_back(Power("Attack", "Fire", 50, 5));
            vP.push_back(Power("Shields", "Fire", 50, 5));
            vP.push_back(Power("Ultimate", "Fire", 20, 5));
            bM.insert(make_pair("Fire-Storm", Character("Earth-Colossus", 500, vP)));
            vP.clear();         
        }

        map<string, Character> getMap(){
            return bM;
        }

};