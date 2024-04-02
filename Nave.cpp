#include <iostream>
using namespace std;
#include <iomanip>

#include<math.h>
#include<cmath>

#include "Nave.h"

//bisogna aggiungere la parte riguardo alla posizione
Nave::Nave(int &P, string D, int L):Direzione(D),Size(L),Affondato(false)
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

