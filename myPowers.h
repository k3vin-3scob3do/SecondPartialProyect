#ifndef MYHEADEFILE_H
#define MYHEADEFILE_H
#include <string>
using namespace std;

class Power{
    private:
        string type;
        int damage;
        int quantity;

    public:
        Power(){}
        Power(string type, int damage, int quantity) : type(type), damage(damage), quantity(quantity){}
        string getType(){return type;}
        int getDamage(){return damage;}
        int getQuantity(){return quantity;}
    
};

#endif