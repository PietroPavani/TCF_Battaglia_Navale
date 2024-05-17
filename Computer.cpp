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
    //colpisce a random (da finire)
if(Status==0){
srand(time(NULL));
int x;
int y;
const int value_colpito = 2; 
const int value_mancato = 3;  

bool test=false;
	do{
    x = rand()%10;
    y = rand()%10;
	if(p.getCella(x,y) == 2 || p.getCella(x,y) == 3){
		test=true;
	}
	if(p.getCella(x,y) == 0 ||p.getCella(x,y)== 1){
		test=false;
	}
	}	
	while(test);

	if(p.getCella(x,y) == 1){
		p.setCella(x,y, value_colpito);
		// Volendo aggiungere coordinata colpita con eventuale traduzione in lettere
		cout << "\nColpito!\n" << endl;
        XLastShot=x;
        YLastShot=y;
        Status=1;
	}
	if(p.getCella(x,y) == 0){
		p.setCella(x,y, value_mancato);
		cout << "\nMancato!\n" << endl;
	}

}

    //spara vicino in direzione casuale
if(Status==1){

    
}
    //continua a sparare nella stessa direzione
if(Status==2){

    
}
    

}


