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
    //void turno(Player*); // current Player
    //void setVittoria(); // per cambiare vittoria a True
    //void checkVittoria() const; // verifica quando finire la partita
    //void cambioPlayer() const; // fa cambiare turno
    Player chiInizia(Player*, Player*); // lancio un dado (estraggo a caso un numero) chi fa il numero più alto inizia, restituisco il giocatore che inizia --> CurrentPlayer = quello che ha vinto
    //void posizionamento(Player*); // fase iniziale di Gioco in cui i giocatori posizionano le navi
    //void Gioco(Player*, Player*); // implementa in ordine: chiInizia --> Player --> posizionamento, cambioPlayer, posizionamento, cambioPlayer
                                  // turno e checkVittoria finchè non finisce il gioco

private:
    Player* player1;
    Player* player2;
    Player* currentPlayer;
    bool vittoria;
};



#endif
