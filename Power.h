#include <string>
using namespace std;

class Power{
    private:
        string type;
        string name;
        int damage;
        int quantity;

    public:
        Power(){}
        Power(string type, string name, int damage, int quantity) : type(type), name(name),damage(damage), quantity(quantity){}
        string getType(){return type;}
        int getDamage(){return damage;}
        int getQuantity(){return quantity;}
    
};

