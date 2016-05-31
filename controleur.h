#ifndef CONTROLEUR_H
#define CONTROLEUR_H
#include <QString>
#include "expression.h"

using namespace Exp;

class Controleur{
    Pile p;
    QString chaine;
public:
    Controleur(Pile a):p(a){}
    void checkString();
    void plus();
    void moins();
    QString affiche();
    QString affiche2();
    void contructionchaine(QString a);
};





#endif // CONTROLEUR_H
