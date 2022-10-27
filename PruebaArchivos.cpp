#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std; 

int main(){
    string text;
    ifstream archivo;
    archivo.open("Fire-Snake.txt", ios::in);

    if(archivo.fail()){
        cout<<"El archivo no se puede abrir"<<endl;
    }

    while(!archivo.eof()){
        getline(archivo, text);
        cout<<text<<endl;
    }

    archivo.close();
    
}