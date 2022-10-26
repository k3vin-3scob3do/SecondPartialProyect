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

void menu(){
    system("cls");
    m.mainMenu();
    switch(m.opc()){
        case 49: //Iniciar Juego
        {
            
        }
        case 50: //Seleccionar Personaje
        {
            p = m.menuCharacters();
            cout<<p;
            Sleep(2000);
        }
        return menu();

        case 51: //Salir del juego
        
        break;

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
   

