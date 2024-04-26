#ifndef Sottomarino_h
#define Sottomarino_h
#include <iostream>
#include <string>
#include <iomanip>
#include<math.h>
#include<cmath>
#include <vector>
using std::string;
using namespace std;

class Sottomarino : public Nave
{

public:
    Sottomarino();
    virtual void calcoloDanni();
    virtual bool getAffondato() const;
    virtual void setPosition();
    virtual char getSimbolo() const;
    virtual int getSize() const;

private:
    string Direzione;
    int Size;
    bool Affondato;
    int *StartPosition;
    int *Position[];


};


#endif // Sottomarino_h

