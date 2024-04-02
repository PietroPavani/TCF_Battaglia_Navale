#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;
#include <iomanip>

#include<math.h>
#include<cmath>

class Player{
    
public:

    Player(string);
// i primi due valori sono la posizione nella scacchiera il terzo il valore da modificare
    void setCella(int, int, int );

    void drawScacchiera()const;
// verifica se le caselle sono libere per ospitare una nave primi due int casella iniziale il terzo 
// la lunghezza e la stringa india la direzione

    bool checkCaselle(int,int,int, string)const;
 
private:

    int Scacchiera[10][10]={0};
    string Name;

};












#endif