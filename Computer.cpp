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


Computer::Computer(string nome):Name(nome),Status(0),SizeShip(0){};


//controllarlo magari facendoci una partita funziona solo se le navi non sono attaccate
//modificare i vari cout
void Computer::shooting(Player &p){
	const int value_colpito = 2; 
	const int value_mancato = 3;  
	int NumShipEnemyBefore;
	int NumShipEnemyAfter;
	int x;
	int y;
	bool test;
	switch (Status)
	{

	case 0:
		srand(time(NULL));

		test=false;
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
				SizeShip++;
        		Status=1;
			}
			if(p.getCella(x,y) == 0){
				p.setCella(x,y, value_mancato);
				cout << "\nMancato!\n" << endl;
			}

		NumShipEnemyBefore=p.getNumShip();
		p.updateFleet();
		NumShipEnemyAfter=p.getNumShip();
		if(NumShipEnemyAfter<NumShipEnemyBefore){
			Status=0;
			SizeShip=0;
		}


		break;
	case 1:
	{
		srand(time(NULL)); 
		vector<string> PosDir;

		if(XLastShot<9){
			if(p.getCella(XLastShot+1,YLastShot) == 0 ||p.getCella(XLastShot+1,YLastShot)== 1){
			PosDir.push_back("sud");}}
		if(XLastShot>0){
			if(p.getCella(XLastShot-1,YLastShot) == 0 ||p.getCella(XLastShot-1,YLastShot)== 1){
			PosDir.push_back("nord");}}
		if(YLastShot<9){
			if(p.getCella(XLastShot,YLastShot+1) == 0 ||p.getCella(XLastShot,YLastShot+1)== 1){
			PosDir.push_back("est");}}
		if(YLastShot>0){
			if(p.getCella(XLastShot,YLastShot-1) == 0 ||p.getCella(XLastShot,YLastShot-1)== 1){
			PosDir.push_back("ovest");}}
		//bisogna aggiungere controllo che effettivamente ci sia una direzione possibile
		int CasualIndex= rand()%PosDir.size();
		DirShip = PosDir[CasualIndex];

		if(DirShip=="nord"){
			if(p.getCella(XLastShot-1,YLastShot)== 1){
				p.setCella(XLastShot-1,YLastShot, value_colpito);
				// Volendo aggiungere coordinata colpita con eventuale traduzione in lettere
				cout << "\nIl Computer ha colpito una tua nave\n" << endl;

        		XLastShot--;
				SizeShip++;
        		Status=2;
			}
			if(p.getCella(XLastShot-1,YLastShot)==0){
				p.setCella(XLastShot-1,YLastShot, value_mancato);
				cout << "\nMancato!\n" << endl;
			}
		}
		if(DirShip=="sud"){
			if(p.getCella(XLastShot+1,YLastShot)== 1){
				p.setCella(XLastShot+1,YLastShot, value_colpito);
				// Volendo aggiungere coordinata colpita con eventuale traduzione in lettere
				cout << "\nIl Computer ha colpito una tua nave\n" << endl;
        		XLastShot++;
				SizeShip++;
        		Status=2;
			}
			if(p.getCella(XLastShot+1,YLastShot)==0){
				p.setCella(XLastShot+1,YLastShot, value_mancato);
				cout << "\nMancato!\n" << endl;
			}
		}
		if(DirShip=="ovest"){
			if(p.getCella(XLastShot,YLastShot-1)== 1){
				p.setCella(XLastShot,YLastShot-1, value_colpito);
				// Volendo aggiungere coordinata colpita con eventuale traduzione in lettere
				cout << "\nIl Computer ha colpito una tua nave\n" << endl;
        		YLastShot++;
				SizeShip++;
        		Status=2;
			}
			if(p.getCella(XLastShot,YLastShot-1)==0){
				p.setCella(XLastShot,YLastShot-1, value_mancato);
				cout << "\nMancato!\n" << endl;
			}
		}
		if(DirShip=="est"){
			if(p.getCella(XLastShot,YLastShot+1)== 1){
				p.setCella(XLastShot,YLastShot+1, value_colpito);
				// Volendo aggiungere coordinata colpita con eventuale traduzione in lettere
				cout << "\nIl Computer ha colpito una tua nave\n" << endl;
        		YLastShot--;
				SizeShip++;
        		Status=2;
			}
			if(p.getCella(XLastShot,YLastShot+1)==0){
				p.setCella(XLastShot,YLastShot+1, value_mancato);
				cout << "\nMancato!\n" << endl;
			}
		}

		if(Status==2){
			if(YLastShot=0 && DirShip=="ovest"){
					XLastShot++;
					SizeShip=1;
					DirShip="est";
				}
			if(YLastShot=9 && DirShip=="est"){
					XLastShot--;
					SizeShip=1;
					DirShip="ovest";
				}
			if(XLastShot=0 && DirShip=="nord"){
					YLastShot++;
					SizeShip=1;
					DirShip="sud";
				}
			if(XLastShot=9 && DirShip=="sud"){
					YLastShot--;
					SizeShip=1;
					DirShip="nord";
				}
		}


		NumShipEnemyBefore=p.getNumShip();
		p.updateFleet();
		NumShipEnemyAfter=p.getNumShip();
		if(NumShipEnemyAfter<NumShipEnemyBefore){
			Status=0;
			SizeShip=0;
		}

	}
		break;
	case 2:

		if(DirShip=="nord"){
			if(p.getCella(XLastShot-1,YLastShot)== 1){
				p.setCella(XLastShot-1,YLastShot, value_colpito);
				// Volendo aggiungere coordinata colpita con eventuale traduzione in lettere
				cout << "\nIl Computer ha colpito una tua nave\n" << endl;

        		XLastShot--;
				SizeShip++;
			}
			if(p.getCella(XLastShot-1,YLastShot)==0){
				p.setCella(XLastShot-1,YLastShot, value_mancato);
				cout << "\nMancato!\n" << endl;
				XLastShot+=(SizeShip-1);
				SizeShip=1;
				DirShip="sud";
			}
		}
		if(DirShip=="sud"){
			if(p.getCella(XLastShot+1,YLastShot)== 1){
				p.setCella(XLastShot+1,YLastShot, value_colpito);
				// Volendo aggiungere coordinata colpita con eventuale traduzione in lettere
				cout << "\nIl Computer ha colpito una tua nave\n" << endl;

        		XLastShot++;
				SizeShip++;
			}
			if(p.getCella(XLastShot+1,YLastShot)==0){
				p.setCella(XLastShot+1,YLastShot, value_mancato);
				cout << "\nMancato!\n" << endl;
				XLastShot-=(SizeShip-1);
				SizeShip=1;
				DirShip="nord";
			}
		}
		if(DirShip=="est"){
			if(p.getCella(XLastShot,YLastShot+1)== 1){
				p.setCella(XLastShot,YLastShot+1, value_colpito);
				// Volendo aggiungere coordinata colpita con eventuale traduzione in lettere
				cout << "\nIl Computer ha colpito una tua nave\n" << endl;

        		YLastShot++;
				SizeShip++;
			}
			if(p.getCella(XLastShot,YLastShot+1)==0){
				p.setCella(XLastShot,YLastShot+1, value_mancato);
				cout << "\nMancato!\n" << endl;
				YLastShot-=(SizeShip-1);
				SizeShip=1;
				DirShip="ovest";
			}
		}
		if(DirShip=="ovest"){
			if(p.getCella(XLastShot,YLastShot-1)== 1){
				p.setCella(XLastShot,YLastShot-1, value_colpito);
				// Volendo aggiungere coordinata colpita con eventuale traduzione in lettere
				cout << "\nIl Computer ha colpito una tua nave\n" << endl;

        		YLastShot--;
				SizeShip++;
			}
			if(p.getCella(XLastShot,YLastShot-1)==0){
				p.setCella(XLastShot,YLastShot-1, value_mancato);
				cout << "\nMancato!\n" << endl;
				YLastShot+=(SizeShip-1);
				SizeShip=1;
				DirShip="est";
			}
		}

		if(YLastShot=0 && DirShip=="ovest"){
					XLastShot+=(SizeShip-1);
					SizeShip=1;
					DirShip="est";
				}
		if(YLastShot=9 && DirShip=="est"){
				XLastShot-=(SizeShip-1);
				SizeShip=1;
				DirShip="ovest";
			}
		if(XLastShot=0 && DirShip=="nord"){
				YLastShot+=(SizeShip-1);
				SizeShip=1;
				DirShip="sud";
			}
		if(XLastShot=9 && DirShip=="sud"){
				YLastShot-=(SizeShip-1);
				SizeShip=1;
				DirShip="nord";
			}

		NumShipEnemyBefore=p.getNumShip();
		p.updateFleet();
		NumShipEnemyAfter=p.getNumShip();
		if(NumShipEnemyAfter<NumShipEnemyBefore){
			Status=0;
			SizeShip=0;
		}

		break;

	default:
		srand(time(NULL));

		test=false;
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
				SizeShip++;
        		Status=1;
			}
			if(p.getCella(x,y) == 0){
				p.setCella(x,y, value_mancato);
				cout << "\nMancato!\n" << endl;
			}

		NumShipEnemyBefore=p.getNumShip();
		p.updateFleet();
		NumShipEnemyAfter=p.getNumShip();
		if(NumShipEnemyAfter<NumShipEnemyBefore){
			Status=0;
			SizeShip=0;
		}



		break;
	}





}
//da finire
void Computer::createFleet(){





}
