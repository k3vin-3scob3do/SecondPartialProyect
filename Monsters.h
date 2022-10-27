#include "Character.h"
#include <map>
#include <vector>
#include <string>
#include <string.h>
#include <pthread.h>
#include <cstdlib>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
using namespace std;

class gMonsters{
    private:
        map<string, Character> gM;
    public:
        gMonsters(){
            vector<Power> vP;

            //Fire-Snake
            vP.push_back(Power("Health", "Fenix", 20, 5));
            vP.push_back(Power("Attack", "Fire-Ball", 50, 5));
            vP.push_back(Power("Shields", "Smoke", 50, 5));
            vP.push_back(Power("Ultimate", "Final-Fire", 100, 1));
            gM.insert(make_pair("Fire-Snake", Character(500, vP)));
            vP.clear();

            //Leviatan
            vP.push_back(Power("Health", "Ocean-Health", 20, 5));
            vP.push_back(Power("Attack", "Marine-Tornado", 50, 5));
            vP.push_back(Power("Shields", "Waves", 50, 5));
            vP.push_back(Power("Ultimate", "7Seas-Power", 20, 5));
            gM.insert(make_pair("Leviatan", Character(500, vP)));
            vP.clear();

            //Thunder-Eagle
            vP.push_back(Power("Health", "Recharge", 20, 5));
            vP.push_back(Power("Attack", "Zap", 50, 5));
            vP.push_back(Power("Shields", "Storm-Shield", 50, 5));
            vP.push_back(Power("Ultimate", "Thunderbolt", 20, 5));
            gM.insert(make_pair("Thunder-Eagle", Character(500, vP)));
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
            vP.push_back(Power("Health", "Souls", 20, 5));
            vP.push_back(Power("Attack", "Bones", 50, 5));
            vP.push_back(Power("Shields", "Breastplate", 50, 5));
            vP.push_back(Power("Ultimate", "Walkind-Dead", 20, 1));
            bM.insert(make_pair("Bad-Skull", Character(250, vP)));
            vP.clear();

            //Bat-Storm
            vP.push_back(Power("Health", "Water", 20, 5));
            vP.push_back(Power("Attack", "Ultrasound", 50, 5));
            vP.push_back(Power("Shields", "Bat-Wings", 50, 5));
            vP.push_back(Power("Ultimate", "Fang-Storm", 20, 1));
            bM.insert(make_pair("Bat-Storm", Character(350, vP)));
            vP.clear();

            //Black-Ghost
            vP.push_back(Power("Health", "Souls", 20, 5));
            vP.push_back(Power("Attack", "Nightmare", 50, 5));
            vP.push_back(Power("Shields", "Bed-Sheets", 50, 5));
            vP.push_back(Power("Ultimate", "Shaking-Chills", 20, 1));
            bM.insert(make_pair("Black-Ghost", Character(500, vP)));
            vP.clear();

            //Cronos
            vP.push_back(Power("Health", "Divine-Health", 20, 5));
            vP.push_back(Power("Attack", "Earthquake", 50, 5));
            vP.push_back(Power("Shields", "Stone-Armor", 50, 5));
            vP.push_back(Power("Ultimate", "Volcanic-Explosion", 20, 1));
            bM.insert(make_pair("Cronos", Character(650, vP)));
            vP.clear();         
        }

        map<string, Character> getMap(){
            return bM;
        }

};

class Levels{
    private:
        int success = 0;
        bool isAction = true;
        pair<string, Character> monster;
        map<string, Character> bmonsters;
        int level = 1;

    public:
        Levels(pair<string, Character> monster, map<string, Character> bmonsters): monster(monster), bmonsters(bmonsters){}
        
        void setLevel(int level){
            this->level = level;
        }

        void setMonster(pair<string, Character> monster){
            this->monster = monster;
        }

        int getLevel(){
            return level;
        }

        int getSuccess(){
            return success;
        }

        void openGame(){
            string text;
            string fileName = monster.first + ".txt";
            ifstream archivo;
            archivo.open(fileName, ios::in);
            while(!archivo.eof()){
                getline(archivo, text);
                cout<<text<<endl;
            }
            archivo.close();
            cout<<endl<<"       Life : "<<monster.second.getLife()<<endl;
            
            auto it = bmonsters.begin();
            if(level == 1) it = bmonsters.find("Bad-Skull");
            else if(level == 2) it = bmonsters.find("Bat-Storm");
            else if(level == 3) it = bmonsters.find("Black-Ghost");
            else if(level == 2) it = bmonsters.find("Cronos");
            pair<string, Character> auxMon = *it;

            fileName = auxMon.first + ".txt";
            archivo.open(fileName, ios::in);

            while(!archivo.eof()){
                getline(archivo, text);
                cout<<text<<endl;
            }
            archivo.close();
            cout<<endl<<"					 Life : "<<auxMon.second.getLife()<<endl;
            
        }

        void hearts(){
            system("cls");
            switch(monster.second.getAttempts()){
                case 0:
                cout<<"\n\n\n\n\n\n\n\n\n\n";
                break;

                case 3:
                cout<<"\n _  _    _  _    _  _\n/ \\/ \\  / \\/ \\  / \\/ \\\n\\    /  \\    /  \\    /\n \\  /    \\  /    \\  /\n  \\/      \\/      \\/\n"<<endl;
                break;

                case 2:
                cout<<" _  _    _  _ \n/ \\/ \\  / \\/ \\\n\\    /  \\    /\n \\  /    \\  /\n  \\/      \\/\n"<<endl;
                break;

                case 1:
                cout<<" _  _\n/ \\/ \\\n\\    /\n \\  /\n  \\/\n"<<endl;
                break;
            }
            
        }

        void printLevel(){
            hearts();
            openGame();
        }

        int menuActionP(){
            int teclaE, tecla;
            vector<Power> powers = monster.second.getPowers();
            system("cls");
            printLevel();
            string sec = " ________________________________\n|          - Powers -            |\n|                                |\n";
            
            cout<<sec<<"|       1. Health        "<<powers[0].getQuantity()<<"       |"<<endl;
            cout<<"|       2. Attack        "<<powers[1].getQuantity()<<"       |"<<endl;
            cout<<"|       3. Recharge      "<<powers[2].getQuantity()<<"       |"<<endl;                 
            cout<<"|       4. Ultimate      "<<powers[3].getQuantity()<<"       |"<<endl;
        
            teclaE = getch();
            while(teclaE != 13){
                system("cls");
                printLevel();
                if(teclaE != 13){
                    tecla = teclaE; 
                    switch(tecla){

                        case 49:
                        cout<<sec<<"|    -> 1. Health        "<<powers[0].getQuantity()<<"       |"<<endl;
                        cout<<"|       2. Attack        "<<powers[1].getQuantity()<<"       |"<<endl;
                        cout<<"|       3. Recharge      "<<powers[2].getQuantity()<<"       |"<<endl;
                        cout<<"|       4. Ultimate      "<<powers[3].getQuantity()<<"       |"<<endl;
                        break;

                        case 50:
                        cout<<sec<<"|       1. Health        "<<powers[0].getQuantity()<<"       |"<<endl;
                        cout<<"|    -> 2. Attack        "<<powers[1].getQuantity()<<"       |"<<endl;
                        cout<<"|       3. Recharge      "<<powers[2].getQuantity()<<"       |"<<endl;
                        cout<<"|       4. Ultimate      "<<powers[3].getQuantity()<<"       |"<<endl;
                        break;
                        
                        case 51:
                        cout<<sec<<"|       1. Health        "<<powers[0].getQuantity()<<"       |"<<endl;
                        cout<<"|       2. Attack        "<<powers[1].getQuantity()<<"       |"<<endl;
                        cout<<"|    -> 3. Recharge      "<<powers[2].getQuantity()<<"       |"<<endl;
                        cout<<"|       4. Ultimate      "<<powers[3].getQuantity()<<"       |"<<endl;
                        break;

                        case 52:
                        cout<<sec<<"|       1. Health        "<<powers[0].getQuantity()<<"       |"<<endl;
                        cout<<"|       2. Attack        "<<powers[1].getQuantity()<<"       |"<<endl;
                        cout<<"|       3. Recharge      "<<powers[2].getQuantity()<<"       |"<<endl;
                        cout<<"|    -> 4. Ultimate      "<<powers[3].getQuantity()<<"       |"<<endl;
                        break;

                        default:
                        return menuActionP();
                    } 
                    teclaE = getch(); 
                }

            }
            return tecla;
        }

        auto whatLevel(){
            auto it = bmonsters.begin();
            if(level == 1) it = bmonsters.find("Bad-Skull");
            else if(level == 2) it = bmonsters.find("Bat-Storm");
            else if(level == 3) it = bmonsters.find("Black-Ghost");
            else if(level == 2) it = bmonsters.find("Cronos");
            
            return it;
        }
        
        void compareLife(){
            int bl = whatLevel()->second.getLife();
            if(monster.second.getLife() <= 0) success = 1;
            else if(bl <= 0) success = 2;
            else success = 0;
        } 

        void actionPlayer(){
            compareLife();
            if(isAction && success == 0){
                system("cls");
                printLevel();
                int bl = whatLevel()->second.getLife();

                switch(menuActionP()){
                    case 49:{ //Health
                        if(monster.second.getQuantityC(0) > 0){
                           monster.second.setQuantityC(monster.second.getQuantityC(0) - 1, 0);
                           cout<<endl<<monster.first<<" ha utilizado "<<monster.second.getNameC(0);
                           monster.second.setLife(monster.second.getLife() + monster.second.getDamageC(0));
                            
                        }else{
                            cout<<endl<<"Out of Powers";
                            Sleep(3000);
                            return actionPlayer();
                        } 

                        Sleep(2000);
                        break;
                    }

                    case 50:{//Attack
                        if(monster.second.getQuantityC(1) > 0){
                            monster.second.setQuantityC(monster.second.getQuantityC(1) - 1, 1);
                            cout<<endl<<monster.first<<" ha utilizado "<<monster.second.getNameC(1);
                            whatLevel()->second.setLife(whatLevel()->second.getLife() - monster.second.getDamageC(1));
                        }else{
                            cout<<endl<<"Out of Powers";
                            Sleep(3000);
                            return actionPlayer();
                        } 
                        Sleep(2000);
                        break;
                    }

                    case 51:{//Recharge
                        if(monster.second.getQuantityC(2) > 0){
                            monster.second.setQuantityC(monster.second.getQuantityC(2) - 1, 2);
                            cout<<endl<<monster.first<<" ha utilizado "<<monster.second.getNameC(2);
                            monster.second.setQuantityC(monster.second.getQuantityC(1) + 1, 1);
                        }else{
                            cout<<endl<<"Out of Powers";
                            Sleep(3000);
                            return actionPlayer();
                        } 
                        Sleep(2000);
                        break;
                    }

                    case 52:{//Ultimate
                        if(monster.second.getQuantityC(3) > 0){
                            monster.second.setQuantityC(monster.second.getQuantityC(3) - 1, 3); 
                            cout<<endl<<monster.first<<" ha utilizado "<<monster.second.getNameC(3);
                            whatLevel()->second.setLife(whatLevel()->second.getLife() - monster.second.getDamageC(3));
                        }else{
                            cout<<endl<<"Out of Powers";
                            Sleep(3000);
                            return actionPlayer();
                        }
                        Sleep(2000);
                        break;
                    }
                    
                    default:
                    return actionPlayer();
                    
                }
                isAction = false;
                
            }
        }

        void actionCPU(){
            vector<Power> powers = whatLevel()->second.getPowers();
            compareLife();
            if(!isAction && success == 0){
                system("cls");
                hearts();
                openGame();
                int n = 1 + rand() % 4;

                switch(n){
                    case 1:{//Health
                        if(whatLevel()->second.getQuantityC(0) > 0){
                            whatLevel()->second.setQuantityC(whatLevel()->second.getQuantityC(0) - 1, 0);
                            cout<<whatLevel()->first<<" ha utilizado "<<whatLevel()->second.getNameC(0);
                            whatLevel()->second.setLife(whatLevel()->second.getLife() - whatLevel()->second.getDamageC(0));
                        }else{
                            cout<<endl<<"Out of Powers";
                            Sleep(3000);
                            return actionPlayer();
                        }
                        Sleep(2000);
                        break;
                    }

                    case 2:{//Attack
                        if(whatLevel()->second.getQuantityC(1) > 0){
                            whatLevel()->second.setQuantityC(whatLevel()->second.getQuantityC(1) - 1, 1);
                            cout<<whatLevel()->first<<" ha utilizado "<<whatLevel()->second.getNameC(1);
                            monster.second.setLife(monster.second.getLife() - whatLevel()->second.getDamageC(1));
                        }else{
                            cout<<endl<<"Out of Powers";
                            Sleep(3000);
                            return actionPlayer();
                        }
                        Sleep(2000);
                        break;
                    }

                    case 3:{//Recharge
                        if(whatLevel()->second.getQuantityC(2) > 0){
                            whatLevel()->second.setQuantityC(whatLevel()->second.getQuantityC(2) - 1, 2);
                            cout<<whatLevel()->first<<" ha utilizado "<<whatLevel()->second.getNameC(2);
                            whatLevel()->second.setQuantityC(whatLevel()->second.getQuantityC(1) + 1, 1);
                        }else{
                            cout<<endl<<"Out of Powers";
                            Sleep(3000);
                            return actionPlayer();
                        }
                        Sleep(2000);
                        break;
                    }

                    case 4:{//Ultimate
                        if(whatLevel()->second.getQuantityC(3) > 0){
                            whatLevel()->second.setQuantityC(whatLevel()->second.getQuantityC(3) - 1, 3);
                            cout<<whatLevel()->first<<" ha utilizado "<<whatLevel()->second.getNameC(3);
                            monster.second.setLife(monster.second.getLife() - whatLevel()->second.getDamageC(3));
                        }else{
                            cout<<endl<<"Out of Powers";
                            Sleep(3000);
                            return actionPlayer();
                        }
                        Sleep(2000);
                        break;
                    }
                    
                    default:
                    return actionCPU();
                    
                }
                isAction = true;
            }
        }       
};