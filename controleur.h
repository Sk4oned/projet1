#ifndef CONTROLEUR_H
#define CONTROLEUR_H
#include <QString>
#include "numerique.h"
#include "pile.h"
#include <vector>

using namespace Exp;

class Controleur{
    Pile *p;
    QString chaine;
    vector <Litteral*> variable;

public:
    Controleur(Pile* a):p(a){}
    bool chaineIsValide(){return (chaine!= ""); }
    void checkString();
    void plus();
    void moins();
    void multiplier();
    void diviser();
    void divEntiere();
    void modulo();
    void neg();
    void num();
    void den();
    void complexe();
    void re();
    void im();
    void dup();
    void drop();
    void swap();
    void clear();
    void edit();
    void evaluer();
    void egal();
    void different();
    void infEgal();
    void infStrict();
    void supEgal();
    void supStrict();
    QString affiche();
    QString affiche2();
    QString afficheVariable();
    QString afficheProgramme();
    QString afficheNomProgramme();
    void constructionchaine(QString a);
    void constructionchaine2(QString arg1);
    void enregistrePile();
    void chargePile();
    void ChangeNombrePileAffiche(int n);
    void ajouterVariable(Litteral* v);
    void editChaine(QString m_chaine);
    void creerProgramme(QString nom, QString programme);

};





#endif // CONTROLEUR_H
