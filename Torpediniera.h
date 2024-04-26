#ifndef Torpediniera_h
#define Torpediniera_h
#include <iostream>
#include <string>
#include <iomanip>
#include<math.h>
#include<cmath>
#include <vector>
using std::string;
using namespace std;

class Torpediniera : public Nave
{

public:
    Torpediniera();
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


#endif // Torpediniera_h
