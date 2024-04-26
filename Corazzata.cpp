#include "Corazzata.h"
#include "Nave.h"
#include <iostream>
#include <string>
#include <iomanip>
#include<math.h>
#include<cmath>
#include <vector>
using std::string;
using namespace std;

Corazzata::Corazzata(int &P, string D, int L, const string& naveType):Direzione(D),Size(4),type("Corazzata"),Affondato(false),StartPosition(&P)
{}
void Corazzata::calcoloDanni(){
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

bool Corazzata::getAffondato()const{
    return Affondato;
}
int Corazzata::getSize() const {
    return Size;
}
char Corazzata::getSimbolo() const {
    return 'C';
}


