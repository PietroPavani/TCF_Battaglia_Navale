#ifndef NAVE_H
#define NAVE_H
#include <iostream>
using namespace std;
#include <iomanip>

#include<math.h>
#include<cmath>

class Nave{
    
public:

/* Per ora non ho messo il nome della nave perchè avevamo detto che stampiamo direttamente la board
ogni volta e pertanto il nome serviva per l'opzione di stampa, a questo punto inutile, di calcoloDanni */

//costruttore della nave posizione iniziale, direzione, lunghezza 
    Nave(int &, string, int);
// check delle componenti della nave aggiorna il valore della variabile affondato  
    void calcoloDanni();
// return del valore di affondato
    bool getAffondato() const;
// inizializza Position dando i puntotori alla scacchiera
    void setPosition();

private:

    string Direzione;
    int Size;
    bool Affondato;
    int *StartPosition;
    int *Position[];

};












#endif