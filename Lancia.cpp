#include "Lancia.h"
#include "Nave.h"
#include <iostream>
#include <string>
#include <iomanip>
#include<math.h>
#include<cmath>
#include <vector>
using std::string;
using namespace std;

Lancia::Lancia(int &P, string D, int L, const string& naveType):Direzione(D),Size(1),type("Lancia"),Affondato(false),StartPosition(&P)
{}
void Lancia::calcoloDanni(){
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

bool Lancia::getAffondato()const{
    return Affondato;
}
int Lancia::getSize() const {
    return Size;
}
char Lancia::getSimbolo() const {
    return 'L';
}
