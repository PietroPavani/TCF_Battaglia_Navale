#include <iostream>
using namespace std;
#include <iomanip>
#include<vector>
#include<algorithm>
#include<math.h>
#include<cmath>
#include <string>
#include "Player.h"
#include "Nave.h"

Player::Player(string nome):Name(nome){};

void Player::setCella(int x, int y, int value){
    Scacchiera[x][y]=value;
}


// non serve a un cazzo ma la teniamo per ora, nel caso
string Player::traduciCoordinate_in_Lettere(int riga, int colonna) {
    char lettera = 'A' + riga; // Converti l'indice della riga in una lettera dell'alfabeto 
    int numero = colonna;
    return string(1, lettera) + to_string(numero); // Componi la stringa con la lettera della riga e il numero della colonna
}



string Player::getName() const{
	return Name;
}

// 0 mare 	1 nave nascosta		2 nave colpita 		3 mare mancato
void Player::drawScacchiera()const{
    cout << "                   "+Name+"\n             0 1 2 3 4 5 6 7 8 9\n";
	char letter = 'A';

	for (int i = 0; i < 10; i++) {
		cout << "          " << letter++ << " ";
		for (int j = 0; j < 10; j++) {

			if (Scacchiera[i][j] == 0 ||Scacchiera[i][j] == 1 ) // 0 for free Coordinate; 2 for Ship sides
				cout << "|_";
			if (Scacchiera[i][j] == 2) // 1 for SHIP
				cout << "|X";
			if(Scacchiera[i][j] == 3) 
				cout << "|" << "\u25CF";
		}
		cout << endl;
	}

}
// per adesso controllo solo nella direzione destra
bool Player::checkCaselle(int x, int y, int size, string direction)const{
	bool result=true;
	//qui potremmo fare controllo nel caso si siano date coordinate sbagliate ecc con un return e una stampa
	if(direction=="Est"||direction=="est"){
		if(x+size>=10){
			result=false;
			}
	else{
		for(int i=0;i<size;i++){
			if(Scacchiera[x+i][y]!=0){
				result=false;
				}	
			}
		}
	}
	if(direction=="Ovest"||direction=="ovest"){
		if(x-size<0){
			result=false;
			}
	else{
		for(int i=0;i<size;i++){
			if(Scacchiera[x-i][y]!=0){
				result=false;
				}	
			}
		}
	}	
	if(direction=="Nord"||direction=="nord"){
		if(y+size>=10){
			result=false;
			}
	else{
		for(int i=0;i<size;i++){
			if(Scacchiera[x][y+i]!=0){
				result=false;
				}	
			}
		}
	}
	if(direction=="Sud"||direction=="sud"){
		if(x-size<0){
			result=false;
			}
	else{
		for(int i=0;i<size;i++){
			if(Scacchiera[x][y-i]!=0){
				result=false;
				}	
			}
		}
	}	

	
	return result;
}

void Player::shooting(Player &p){
	
	const int value_colpito = 2; 
	const int value_mancato = 3;  
	int x;
	int y;
	string coord;
	// mettere il codice per nome giocatore
	bool test=false;
	do{cout << "\n Casella: inserire coordinate nel formato tipo A1\n";
	cin >> coord;
	// eventualmente aggiungere check se il formato della stringa è corretto
	if(p.Scacchiera[x][y] == 2 || p.Scacchiera[x][y] == 3){
		cout << "\n La Casella è già stata colpita \n";
		test=true;
	}
	if(p.Scacchiera[x][y] == 0 || p.Scacchiera[x][y] == 1){
		test=false;
	}
	
	}
	while(test);

	if(p.Scacchiera[x][y] == 1){
		p.setCella(x,y, value_colpito);
		// Volendo aggiungere coordinata colpita con eventuale traduzione in lettere
		cout << "\nColpito!\n" << endl;
	}
	if(p.Scacchiera[x][y] == 0){
		p.setCella(x,y, value_mancato);
		cout << "\nMancato!\n" << endl;
	}
}

void Player::addNave(Nave* ship){
	Flotta.push_back(ship);
}
//un po di cose da aggiungere
void Player::createFleet(){
	Torpediniera pacciani (&Scacchiera[5][5],"ovest");
	pacciani.setPosition();
}