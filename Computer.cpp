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


// in tutti i casi bisogna aggiungere che se la nave è affondata il computer torna allo status 0
//forse bisogna cambiare l'ordine degli if altrimenti li fa tutti in una botta sola oppure sostituire con switch case
void Computer::shooting(Player &p){
    //colpisce a random (da finire i cout)
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
		cout << "\nIl Computer ha colpito una tua nave\n" << endl;
        XLastShot=x;
        YLastShot=y;
		SizeShip=1;
        Status=1;
	}
	if(p.getCella(x,y) == 0){
		p.setCella(x,y, value_mancato);
		cout << "\nMancato!\n" << endl;
	}

}
    //spara vicino in direzione casuale(da finire)
if(Status==1){
	srand(time(NULL));
	const int value_colpito = 2; 
	const int value_mancato = 3;  
	vector<string> PosDir;

	if(XLastShot<9){
	if(p.getCella(XLastShot+1,YLastShot) == 0 ||p.getCella(XLastShot+1,YLastShot)== 1){
		PosDir.push_back("est");}}
	if(XLastShot>0){
	if(p.getCella(XLastShot-1,YLastShot) == 0 ||p.getCella(XLastShot-1,YLastShot)== 1){
		PosDir.push_back("ovest");}}
	if(YLastShot<9){
	if(p.getCella(XLastShot,YLastShot+1) == 0 ||p.getCella(XLastShot,YLastShot+1)== 1){
		PosDir.push_back("nord");}}
	if(YLastShot>0){
	if(p.getCella(XLastShot,YLastShot-1) == 0 ||p.getCella(XLastShot,YLastShot-1)== 1){
		PosDir.push_back("sud");}}
	//bisogna aggiungere controllo che effettivamente ci sia una direzione possibile
	int CasualIndex= rand()%PosDir.size();
	DirShip = PosDir[CasualIndex];

	if(DirShip=="ovest"){
		if(p.getCella(XLastShot-1,YLastShot)== 1){
		p.setCella(XLastShot-1,YLastShot, value_colpito);
		// Volendo aggiungere coordinata colpita con eventuale traduzione in lettere
		cout << "\nIl Computer ha colpito una tua nave\n" << endl;
        XLastShot--;
		SizeShip=2;
        Status=2;
	}
	if(p.getCella(XLastShot-1,YLastShot)==0){
		p.setCella(XLastShot-1,YLastShot, value_mancato);
		cout << "\nMancato!\n" << endl;
	}
	}
	if(DirShip=="est"){
		if(p.getCella(XLastShot+1,YLastShot)== 1){
		p.setCella(XLastShot+1,YLastShot, value_colpito);
		// Volendo aggiungere coordinata colpita con eventuale traduzione in lettere
		cout << "\nIl Computer ha colpito una tua nave\n" << endl;
        XLastShot++;
		SizeShip=2;
        Status=2;
	}
	if(p.getCella(XLastShot+1,YLastShot)==0){
		p.setCella(XLastShot+1,YLastShot, value_mancato);
		cout << "\nMancato!\n" << endl;
	}
	}
	if(DirShip=="nord"){
		if(p.getCella(XLastShot,YLastShot+1)== 1){
		p.setCella(XLastShot,YLastShot+1, value_colpito);
		// Volendo aggiungere coordinata colpita con eventuale traduzione in lettere
		cout << "\nIl Computer ha colpito una tua nave\n" << endl;
        YLastShot++;
		SizeShip=2;
        Status=2;
	}
	if(p.getCella(XLastShot,YLastShot+1)==0){
		p.setCella(XLastShot,YLastShot+1, value_mancato);
		cout << "\nMancato!\n" << endl;
	}
	}
	if(DirShip=="sud"){
		if(p.getCella(XLastShot,YLastShot-1)== 1){
		p.setCella(XLastShot,YLastShot-1, value_colpito);
		// Volendo aggiungere coordinata colpita con eventuale traduzione in lettere
		cout << "\nIl Computer ha colpito una tua nave\n" << endl;
        YLastShot--;
		SizeShip=2;
        Status=2;
	}
	if(p.getCella(XLastShot,YLastShot-1)==0){
		p.setCella(XLastShot,YLastShot-1, value_mancato);
		cout << "\nMancato!\n" << endl;
	}
	}

}
    //continua a sparare nella stessa direzione e se trova il mare torna in dietro status 2 ma dir opposta
	//se trova di nuovo il mare senza affondare nulla vuol dire che erano due navi attaccate
	//torna nel punto di partenza e status 1(da fare ancora tutto)
if(Status==2){

    
}
    

}

void Computer::createFleet(){





}
