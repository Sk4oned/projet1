#ifndef CONTROLEUR_H
#define CONTROLEUR_H
#include <QString>
#include "numerique.h"
#include "pile.h"

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
    int num();
    int den();
    void complexe();
    int re();
    void im();
    void dup();
    void drop();
    void swap();
    void clear();
    void edit();
    QString affiche();
    QString affiche2();
    void contructionchaine(QString a);
    void contructionchaine2(QString arg1);
    void enregistrePile();
    void chargePile();
    void ChangeNombrePileAffiche(int n);
};





#endif // CONTROLEUR_H
