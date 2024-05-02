#include <iostream>
using namespace std;
#include <iomanip>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<vector>
#include <string>
#include "Nave.h"
#include "Player.h"
#include "Game.h"
#include "Lancia.h"
#include "Sottomarino.h"
#include "Torpediniera.h"
#include "Corazzata.h"




int main(){
/*
int a[5][5]={0};
Torpediniera prova(&a[2][2],"ovest");
prova.setPosition();

vector<Nave*> Fleet ;
Fleet.push_back(&prova);
vector<Nave*>::iterator iter;
iter=Fleet.begin();

cout<<(*Fleet[0]).getAffondato()<<endl;
cout<<(*(*iter)).getAffondato()<<endl;
a[2][2]=2;
a[2][1]=2;
prova.calcoloDanni();
cout<<(*Fleet[0]).getAffondato();
*/




    Player Player1("Pietro");
    Player1.createFleet();
    
   // Player Player2("Ezio Maina");
   // Game Game(&Player1, &Player2);

   // Game.chiInizia(&Player1, &Player2);
    Player1.drawScacchiera();
    Player1.setCella(5,5,2);
    Player1.setCella(5,4,2);
    Player1.drawScacchiera();

    Player1.updateFleet();

    return 0;
}