#include <iostream>
using namespace std;
#include <iomanip>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<vector>
#include <string>
#include "Nave.h"
#include "Player.h"
#include "Computer.h"
#include "Game.h"

int main(){
bool Modalità;
bool test=true;
string answer;
    do{
        cout<<"Come vuoi giocare?\n1) Player vs Player \n2) Player vs Computer\n";
        cin>>answer;
        if(answer=="1"||answer=="2"){
            test=false;
        }
        else{
            cout<<"\nrisposta non valida";
        }
    }
    while(test);

    if(answer=="1"){
        Modalità=true;
    }
    else{
        Modalità=false;
    }

    Player Player1("Pietro");
    Player Player2("Ezio Maina");
    Computer Computer1("Paolo Bonolis");


if(Modalità){
    Game Game(&Player1, &Player2);
    Game.Gioco(Game, &Player1, &Player2);

}
else {
    Game Game(&Player1, &Computer1);
    Game.Gioco(Game, &Player1, &Computer1);

}


    return 0;
}