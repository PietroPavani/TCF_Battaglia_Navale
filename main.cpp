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
Player Player1("Pietro");   
string coord = "A1";
int x;
int y;
Player1.traduciLettere_in_Coordinate(&x,&y,coord);
cout<<x<<endl<<y<<endl;


/*
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
    cout<<Player1.checkDefeat();
*/
    return 0;
}