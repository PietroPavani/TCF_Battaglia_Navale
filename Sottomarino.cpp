#include "Sottomarino.h"
#include "Nave.h"
#include <iostream>
#include <string>
#include <iomanip>
#include<math.h>
#include<cmath>
#include <vector>
using std::string;
using namespace std;

Sottomarino::Sottomarino(int &P, string D, int L, const string& naveType):Direzione(D),Size(3),type("Sottomarino"),Affondato(false),StartPosition(&P)
{}
void Sottomarino::calcoloDanni(){
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

bool Sottomarino::getAffondato()const{
    return Affondato;
}
int Sottomarino::getSize() const {
    return Size;
}
char Sottomarino::getSimbolo() const {
    return 'S';
}

