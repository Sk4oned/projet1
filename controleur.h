#ifndef CONTROLEUR_H
#define CONTROLEUR_H
#include <QString>
#include "numerique.h"
#include "pile.h"
#include <vector>

using namespace Exp;

class Controleur{
    friend class Dialog;

    Pile *p;
    QString chaine;
    vector <Litteral*> variable;
    bool beep=true;
    bool actualise=false;
    bool clavier=true;

public:
    Controleur(Pile* a):p(a){}
    bool chaineIsValide(){return (chaine!= ""); }
    void checkString();
    QString& getchaine();
    void plus();
    void moins();
    void multiplier();
    void diviser();
    void divEntiere();
    void et();
    void ou();
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
    void edit(Litteral* a);
    void evaluer();
    void egal();
    void different();
    void infEgal();
    void infStrict();
    void supEgal();
    void supStrict();
    QString top();
    QString affiche();
    QString affiche2();
    QString afficheVariable();
    QString afficheProgramme();
    QString afficheNomProgramme();
    QString afficheProgrammeRecherche(QString selection);
    void constructionchaine(QString a);
    void constructionchaine2(QString arg1);
    void enregistrePile();
    void enregistreVarEtProg();
    void chargePile();
    void chargeVarEtProg();
    void ChangeNombrePileAffiche(int n);
    void ajouterVariable(Litteral* v);
    void editChaine(QString m_chaine);
    void creerProgramme(QString nom, QString programme);
    bool supprVariable(QString id);
    bool supprProgramme(QString id);
    void changeBeepStatut();
    void changeClavierStatut(bool);
    bool getBipStatut();
    bool getClavierStatut();
    void Bip();

};





#endif // CONTROLEUR_H
