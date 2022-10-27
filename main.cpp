#include <iostream>
#include <cctype>
#include <cstring>
#include <vector>
#include "myMenus.h"
#include "Monsters.h"
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <pthread.h>
using namespace std;

Menu m;
string p = "Fire-Snake";
gMonsters gM;
map<string, Character> gmonsters = gM.getMap();
bMonsters bM;
map<string, Character> bmonsters = bM.getMap();
pthread_t player;
pthread_t cpu;
void *winnerP;
void *winnerC;
auto it = gmonsters.find(p);
pair<string, Character> auxMon = *it;
Levels levels(auxMon, bmonsters);

void *threadCPU(void* args){
    while(levels.getSuccess() == 0){
        levels.actionCPU();
    }
    int s = levels.getSuccess();
    if(s == 1) return (void * )true;
    else return (void *)false;
    pthread_exit(NULL);
}

void *threadPlayer(void *args){
    while(levels.getSuccess() == 0){
        levels.actionPlayer();
    }
    int s = levels.getSuccess();
    if(s == 1) return (void *)false;
    else return (void * )true;
    pthread_exit(NULL);
}

void runGame(){
        pthread_create(&player, NULL, threadPlayer, NULL);
        pthread_create(&cpu, NULL, threadCPU, NULL);
        pthread_join(player, &winnerP);
        pthread_join(cpu, &winnerC);
        if((bool)winnerP == true){
            levels.setLevel(levels.getLevel() + 1);
        }else if((bool)winnerC == true){
            auxMon.second.setAttempts(auxMon.second.getAttempts() - 1);
        }
                  
}



void menu(){
    system("cls");
    m.mainMenu();
    switch(m.opc()){
        case 49: //Iniciar Juego
        {
            
            runGame();
            return menu();
        }
        case 50: //Seleccionar Personaje
        {
            p = m.menuCharacters();
            auto it2 = gmonsters.find(p);
            pair<string, Character> monster = *it2;
            levels.setMonster(monster);
            return menu();
        }

        case 51: //Salir del juego
        break;

        default:
        return menu();

    
    }
}

        
int main(){
    
    system("cls");
    m.title();
    menu();
    
    
    
   /*
    gMonsters monsters;
    map<string, Character> gM = monsters.getMap();
    map<string, Character>::iterator it = gM.find("Fire-Storm");
    pair<string, Character> age = *it;
    cout<<age.first<<" "<<age.second.getAttempts();
    */
} 
