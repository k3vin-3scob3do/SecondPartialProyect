#include <iostream>
#include <conio.h>
using namespace std;
#define ENTER 13
//#define key1 

int main(){
    int teclaE, tecla;
    teclaE = getch();
    while(teclaE != ENTER){
        if(teclaE != ENTER){
            tecla = teclaE; 
            teclaE = getch();  
        }
    }
    cout<<tecla;
}
        
