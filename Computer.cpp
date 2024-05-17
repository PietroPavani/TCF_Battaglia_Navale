#include <iostream>
using namespace std;
#include <iomanip>
#include<vector>
#include<algorithm>
#include<math.h>
#include<cmath>
#include "Nave.h"
#include "Lancia.h"
#include "Sottomarino.h"
#include "Torpediniera.h"
#include "Corazzata.h"
#include "Player.h"
#include "Computer.h"
#include <cstdlib>
#include <ctime>


Computer::Computer(string nome):Name(nome),Status(0){};



void Computer::shooting(Player &p){
switch(Status){
    //colpisce a random (da finire)
    case 0:
    srand(time(NULL));
    int x = rand()%10;
    int y = rand()%10;
    break;
    //spara vicino in direzione casuale
    case 1:

    break;
    //continua a sparare nella stessa direzione
    case 2:

    break;
    

}
}

