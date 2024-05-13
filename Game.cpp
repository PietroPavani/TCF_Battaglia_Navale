#include <iostream>
using namespace std;
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "Game.h"

Game::Game(Player* p1, Player* p2) : player1(p1), player2(p2), currentPlayer(p1), vittoria(false) {};



Player Game::chiInizia(Player* p1, Player* p2){
    cout << p1->getName() << " lancia il dado premendo Invio ..." << endl;
    cin.ignore(); // Attendiamo che l'utente prema Invio
    srand(static_cast<unsigned int>(time(nullptr))); // Inizializziamo il generatore di numeri casuali
    int result1 = (rand() % 6) + 1; // Generiamo un numero casuale tra 1 e 6
    cout << "E' uscito " << result1 << endl;   
    
    cout << p2->getName() << "Lancia il dado premendo Invio ..." << endl;
    cin.ignore(); // Attendiamo che l'utente prema Invio
    srand(static_cast<unsigned int>(time(nullptr))); // Inizializziamo il generatore di numeri casuali
    int result2 = (rand() % 6) + 1; // Generiamo un numero casuale tra 1 e 6
    cout << "E' uscito " << result2 << endl;  

    if(result1 > result2){
        cout << "Inizia " << p1->getName() << endl;
        return *p1;
    }
    else{
        cout << "Inizia " << p2->getName() << endl;
        return *p2;
    } 

    }

void Game::switchPlayer() {
        currentPlayer = (currentPlayer == player1) ? player2 : player1;
    }

void Game::setVittoria(){
    vittoria = false;
}

void Game::checkVittoria(Player *p) {
    // si potrebbe fare un check su tutta la matrice, se trovo un 1 esco
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (p->Scacchiera[i][j]) // è sbagliato, dovrei avere un getscacchiera
            {
                /* code */
            }
            
        }
    }
    
}


void Game::Gioco(Game gioco, Player* p1, Player* p2){
    // setto vittoria a true, quando si vince si setta a false
    vittoria = true;
    currentPlayer = &gioco.chiInizia(p1, p2);

    // Fase iniziale di posizionamento
    cout << currentPlayer->getName() << " posiziona le tue navi: " << endl;
    currentPlayer->posizionamento();
    switchPlayer();
    cout << currentPlayer->getName() << " posiziona le tue navi: " << endl; 
    switchPlayer();

    // Inizio turni
    while(vittoria == true){
        cout << currentPlayer->getName() << " è il tuo turno: " << endl;
        currentPlayer->shooting(*p2);
        checkVittoria();
        switchPlayer();
    }


}