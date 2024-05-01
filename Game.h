#ifndef GAME_H
#define GAME_H
#include <iostream>
using namespace std;
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
using std::string;
#include "Player.h" 


class Game {
public:
    Game(Player* p1, Player* p2);
    ~Game() {
        delete player1;
        delete player2;
    }
    // DA completare tutto
    void setVittoria(); // per cambiare vittoria a True
    void checkVittoria(Player *p); // verifica quando finire la partita
    void switchPlayer(); // fa cambiare turno
    Player chiInizia(Player*, Player*); // lancio un dado (estraggo a caso un numero) chi fa il numero più alto inizia, restituisco il giocatore che inizia --> CurrentPlayer = quello che ha vinto
    void Gioco(Game, Player* , Player*); // implementa in ordine: chiInizia --> Player --> posizionamento, cambioPlayer, posizionamento, cambioPlayer
                                  // turno e checkVittoria finchè non finisce il gioco

private:
    Player* player1;
    Player* player2;
    Player* currentPlayer;
    bool vittoria;
};


/*

class Player {
public:
    Grid grid;
    std::string name;

    Player(const std::string& name) : name(name) {}

    void placeShips() {
        // Simplified ship placement logic here
        // In a real game, you would ask for user input or have a more complex placement algorithm
        grid.placeShip(3, 3, 5, 'h'); // Place a horizontal ship
    }
};



class Game {
private:
    Player player1;
    Player player2;
    Player* currentPlayer;

public:
    Game() : player1("Player 1"), player2("Player 2"), currentPlayer(&player1) {
        player1.placeShips();
        player2.placeShips();
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
    }

    void start() {
        while (true) {
            std::cout << currentPlayer->name << "'s turn\n";
            currentPlayer->grid.printGrid();

            int row, col;
            std::cout << "Enter row and column to hit: ";
            std::cin >> row >> col;

            if (currentPlayer->grid.makeMove(row, col) && currentPlayer->grid.checkWin()) {
                std::cout << currentPlayer->name << " wins!\n";
                break;
            }

            switchPlayer();
        }
    }
};


int main() {
    Game battleshipGame;
    battleshipGame.start();
    return 0;
}


*/

#endif
