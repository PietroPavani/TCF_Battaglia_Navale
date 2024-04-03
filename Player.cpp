#include <iostream>
using namespace std;
#include <iomanip>

#include<math.h>
#include<cmath>

#include "Player.h"

Player::Player(string nome):Name(nome){};

void Player::setCella(int x, int y, int value){
    Scacchiera[x][y]=value;
}


// nons erve a un cazzo
string Player::traduciCoordinate_in_Lettere(int riga, int colonna) {
    char lettera = 'A' + riga; // Converti l'indice della riga in una lettera dell'alfabeto 
    int numero = colonna;
    return string(1, lettera) + to_string(numero); // Componi la stringa con la lettera della riga e il numero della colonna
}




void Player::drawScacchiera()const{
    cout << "                   "+Name+"\n            0 1 2 3 4 5 6 7 8 9\n";
	char letter = 'A';

	for (int i = 0; i < 10; i++) {
		cout << "          " << letter++ << " ";
		for (int j = 0; j < 10; j++) {

			if (Scacchiera[i][j] == 0 ||Scacchiera[i][j] == 1 ) // 0 for free Coordinate; 2 for Ship sides
				cout << "_ ";
			else if (Scacchiera[i][j] == 2) // 1 for SHIP
				cout << "X ";
		}
		cout << endl;
	}

}
// per adesso controllo solo nella direzione destra
bool Player::checkCaselle(int x, int y, int size, string direction)const{
	bool result=true;
	if(x+size>=10){
		result=false;
	}
	for(int i=0;i<size;i++){
		if(Scacchiera[x+i][y]!=0){
			result=false;
		}
	}

	return result;
}

void Player::shooting(Player &p){
	
	const int value_colpito = 2;  
	int x;
	int y;
	string coord;
	// mettere il codice per nome giocatore
	cout << "\n Casella: inserire coordinate nel formato tipo A1\n";
	cin >> coord;

	if(p.Scacchiera[x][y] == 1){
		p.setCella(x,y, value_colpito);
		// Volendo aggiungere coordinata colpita con eventuale traduzione in lettere
		cout << "\nColpito!\n" << endl;
	}
	if(p.Scacchiera[x][y] == 0){
		cout << "\nMancato!\n" << endl;
	}
}
