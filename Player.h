#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;
#include <iomanip>
#include<vector>
#include<algorithm>
#include<math.h>
#include<cmath>
#include "Nave.h"


class Player{
    
public:

    Player(string);
    ~Player() {
        for (Nave* ship : Flotta) {
            delete ship;
        }
    }
// i primi due valori sono la posizione nella scacchiera il terzo il valore da modificare
    void setCella(int, int, int );
    void drawScacchiera()const;
// verifica se le caselle sono libere per ospitare una nave primi due int casella iniziale il terzo 
// la lunghezza e la stringa india la direzione
    bool checkCaselle(int,int,int, string)const;
    void shooting(Player &);
    string traduciCoordinate_in_Lettere(int, int); // riga colonna
    void addNave(Nave*);
    string getName() const;
 
private:

    int Scacchiera[10][10]={0};
    string Name;
    vector<Nave*> Flotta;


};












#endif
