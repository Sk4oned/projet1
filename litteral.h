#ifndef LITTERAL_H
#define LITTERAL_H
#include <string>
#include <iostream>
#include <QString>


using namespace std;

namespace Exp{


class Litteral{

public:

    virtual bool isValide()const=0;
    virtual void affiche(ostream& flux)const=0;
    virtual QString& affiche(QString& flux)const=0;
    virtual string getType()=0;

};

}


#endif // LITTERAL_H
