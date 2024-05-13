#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
using namespace std;
#include <iomanip>
#include<vector>
#include<algorithm>
#include<math.h>
#include<cmath>
#include "Nave.h"
#include "Lancia.h"
#include "Sottomarino.h"
#include "Torpediniera.h"
#include "Corazzata.h"
#include "Player.h"



class Computer: public Player{
    
public:

    Computer(string);
    ~Computer() {
        for (Nave* ship : Flotta) {
            delete ship;
        }
    }
    virtual void shooting(Player &);
    virtual void createFleet(); // crea flotta e posiziona
    

 
private:

    int Scacchiera[10][10]={0};
    string Name;
    vector<Nave*> Flotta;


};


#endif