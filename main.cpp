#include <iostream>
using namespace std;
#include <iomanip>

#include<math.h>
#include<cmath>

#include "Nave.h"
#include "Player.h"

int main(){
    Player Player1("pietro");
    Player1.setCella(0,2,2);
    Player1.setCella(4,5,3);
    Player1.drawScacchiera();
    return 0;
}