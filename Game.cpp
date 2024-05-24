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
#include <chrono>
#include <thread>

#include "Game.h"

Game::Game(Player* p1, Player* p2) : player1(p1), player2(p2), currentPlayer(p1), vittoria(false) {};



Player* Game::chiInizia(Player* p1, Player* p2){
    int result1;
    int result2;
    do
    {
    cout << p1->getName() << " lancia il dado premendo Invio ..." << endl;
    cin.ignore(); // Attendiamo che l'utente prema Invio
    srand(static_cast<unsigned int>(time(nullptr))); // Inizializziamo il generatore di numeri casuali
    result1 = (rand() % 6) + 1; // Generiamo un numero casuale tra 1 e 6
    cout << "E' uscito " << result1 << endl;   
    
    cout << p2->getName() << " lancia il dado premendo Invio ..." << endl;
    cin.ignore(); // Attendiamo che l'utente prema Invio
    srand(static_cast<unsigned int>(time(nullptr))); // Inizializziamo il generatore di numeri casuali
    result2 = (rand() % 6) + 1; // Generiamo un numero casuale tra 1 e 6
    cout << "E' uscito " << result2 << endl;
    } while (result1==result2);
     

    if(result1 > result2){
        cout << "Inizia " << p1->getName() << endl;
        return p1;
    }

    else{
        cout << "Inizia " << p2->getName() << endl;
        return p2;
    } 

    }

void Game::switchPlayer() {
        currentPlayer = (currentPlayer == player1) ? player2 : player1;
        otherPlayer = (currentPlayer == player1) ? player2 : player1;
    }

void Game::setVittoria(){
    vittoria = false;
}

void Game::checkVittoria(Player *p) {
    vittoria = !(p->checkDefeat()); // checkDefeat restituisce true quando le navi sono a 0
    if(vittoria == false){
        cout << "Hai perso!" << endl;
        cout.flush(); // Assicura che l'output sia immediatamente visibile

         int numDots = 3;
         int delay = 2000 / numDots;

    for (int i = 0; i < numDots; ++i) {
        cout << ".";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(delay));
    }

        cout << endl;
        cout << "Ha Vinto: "<< currentPlayer->getName() << "!" << endl; 
    }
    else cout << endl;


}


void Game::Gioco(Game gioco, Player* p1, Player* p2){
    // setto vittoria a true, quando si vince si setta a false

    vittoria = true;
    currentPlayer = gioco.chiInizia(p1, p2);

    // Fase iniziale di posizionamento
    cout << currentPlayer->getName() << " posiziona le tue navi: " << endl;
    currentPlayer->drawScacchiera();
    currentPlayer->createFleet();
    switchPlayer();
    cout << currentPlayer->getName() << " posiziona le tue navi: " << endl; 
    currentPlayer->drawScacchiera();
    currentPlayer->createFleet();
    switchPlayer();

    // Inizio turni
    while(vittoria == true){
        cout << "\n------------------------------------------------ \n" << endl;
        cout << currentPlayer->getName() << " è il tuo turno: " << endl;
        currentPlayer->shooting(*otherPlayer);
        cout << otherPlayer->getName() << ": " << endl;
        otherPlayer->updateFleet();
        otherPlayer->drawScacchiera();
        checkVittoria(otherPlayer);
        switchPlayer();
    }


}