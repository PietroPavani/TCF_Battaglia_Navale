#ifndef Lancia_h
#define Lancia_h
#include <iostream>
#include <string>
#include <iomanip>
#include<math.h>
#include<cmath>
#include <vector>
#include "Nave.h"
using std::string;
using namespace std;

class Lancia : public Nave
{

public:
    Lancia(int &P, string D, int L, const string& naveType);
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


#endif // Lancia_h
