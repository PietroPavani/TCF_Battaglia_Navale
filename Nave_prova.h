#ifndef Nave_H
#define Nave_H
#include <iostream>
#include <string>
using std::string;
using namespace std;
#include <iomanip>

#include<math.h>
#include<cmath>
#include <vector>

class Nave{

public:
    Nave();
   virtual ~Nave() {}
// check delle componenti della nave aggiorna il valore della variabile affondato
   virtual void calcoloDanni();
// return del valore di affondato
    virtual bool getAffondato() const;
// inizializza Position dando i puntotori alla scacchiera
    virtual void setPosition();
//simbolo delle navi (lettera iniziale)
    virtual char getSimbolo() const;
//return size navi
    virtual int getSize() const;
//Private nelle singole classi concrete?
/*private:
    string Direzione;
    int Size;
    bool Affondato;
    int *StartPosition;
    int *Position[];*/

private: 
    string type;
    // navi del giocatore (???) Se non sbaglio la metterei in Player la flotta
    vector<Nave*> navi;

};


#endif