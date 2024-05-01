#include <iostream>
using namespace std;
#include <iomanip>
#include<algorithm>
#include<vector>
#include<math.h>
#include<cmath>
#include <string>
//commento perché non capisco come funzionano le branch su github
#include "Nave.h"

//bisogna aggiungere la parte riguardo alla posizione
Nave::Nave(int &P, string D, int L, const string& naveType):Direzione(D),Size(L),type(naveType),Affondato(false),StartPosition(&P)
{}
void Nave::calcoloDanni(){
    int x=Size;
    for(int i=0;i<Size;i++){
        if(*Position[i]==2){
            x--;
        }
    }
    if(x==0){
        Affondato = true;
    }
}

bool Nave::getAffondato()const{
    return Affondato;
}

//da qui parte nuova


int Nave::getSize() const {
    return Size;
}
char Nave::getSimbolo() const {
    return ' '; // di default
}

Lancia::Lancia(int &P, string D) : Nave(P, D, 1, "Lancia") {}

char Lancia::getSimbolo() const {
    return 'L';
}

Torpediniera::Torpediniera(int &P, string D) : Nave(P, D, 2, "Torpediniera") {}

char Torpediniera::getSimbolo() const {
    return 'T';
}

Sottomarino::Sottomarino(int &P, string D) : Nave(P, D, 3, "Sottomarino") {}

char Sottomarino::getSimbolo() const {
    return 'S';
}

Corazzata::Corazzata(int &P, string D) : Nave(P, D, 4, "Corazzata") {}

char Corazzata::getSimbolo() const {
    return 'C';
}
