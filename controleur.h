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
    void multiplier();
    void diviser();
    void neg();
    QString affiche();
    QString affiche2();
    void contructionchaine(QString a);
    void contructionchaine2(QString arg1);
};





#endif // CONTROLEUR_H
