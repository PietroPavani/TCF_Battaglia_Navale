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

int main(){
    Player Player1("Pietro");
    Player Player2("Ezio Maina");
    Game Game(&Player1, &Player2);

    Game.chiInizia(&Player1, &Player2);

    Player1.setCella(0,2,2);
    Player1.setCella(4,5,3);
    Player1.drawScacchiera();


    return 0;
}