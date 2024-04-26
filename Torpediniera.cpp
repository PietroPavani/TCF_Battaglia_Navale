#include "Torpediniera.h"
#include "Nave.h"
#include <iostream>
#include <string>
#include <iomanip>
#include<math.h>
#include<cmath>
#include <vector>
using std::string;
using namespace std;

Torpediniera::Torpediniera(int &P, string D, int L, const string& naveType):Direzione(D),Size(2),type("Torpediniera"),Affondato(false),StartPosition(&P)
{}
void Torpediniera::calcoloDanni(){
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

bool Torpediniera::getAffondato()const{
    return Affondato;
}
int Torpediniera::getSize() const {
    return Size;
}
char Torpediniera::getSimbolo() const {
    return 'T';
}
