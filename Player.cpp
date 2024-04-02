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

