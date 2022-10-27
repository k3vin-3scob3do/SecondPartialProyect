#include <pthread.h>
#include <iostream>
#include <windows.h>
#include "Character.h"
#include <vector>
using namespace std;

void *changeLife(void *args){
    int i = 0;
    bool *aux = (bool *) args;
    while(aux){
        cout<<i;
        Sleep(1000);
        i++;
    }
}

int main(){
    vector<Power> vP;
    vP.push_back(Power("Health", "Fire", 20, 5));
    vP.push_back(Power("Attack", "Fire", 50, 5));
    vP.push_back(Power("Shields", "Fire", 50, 5));
    vP.push_back(Power("Ultimate", "Fire", 20, 5));

    Character monster(500, vP);
    bool aux = monster.isAction();
    pthread_t myThread;
    aux = true;
    Sleep(5000);
    pthread_create(&myThread, NULL, changeLife, (void *)aux);

    pthread_exit(NULL);
    return 0;
}