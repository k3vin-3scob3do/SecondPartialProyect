#include <iostream>
#include <cctype>
#include <cstring>
#include <vector>
#include "myCharacter.h"
#include "myPowers.h"
#include "myMenus.h"
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

void menuCharacters(){
    int sel = 0;
    switch(sel){
        case 1:

        break;

        case 2:

        break;

        case 3:

        break;

    }
}

void menu(){
    int sel;
    while(sel != 3){ 
        
        switch(sel){
            case 1: //Iniciar Juego
            
            break;

            case 2: //Seleccionar Personaje
            menuCharacters();

            break;

            case 3: //Salir del juego

            break;

            default:
            sel = 3;
            break;
        }
    }
}

        
int main(){
    system("cls");
    Menu m;
    m.title();
    m.mainMenu();
    menu();
}   
