#ifndef PILE_H
#define PILE_H
#include "numerique.h"
#include <string>
#include <QString>
#include "reel.h"
#include "litteral.h"


using namespace std;
using namespace Exp;

namespace Exp{


    class PileException{
        QString m_phrase;

    public:
        PileException(QString p):m_phrase(p){};
        QString& affiche();
    };



    class Pile {
        int nb;
        unsigned int nbMax;
        string message;
        void agrandissementCapacite();
        int nbAffiche;
        Litteral* tab [100];
        int current=0;
    public:
        Pile():nb(0),nbMax(0),message(""),nbAffiche(4){}
        void push(Litteral* e);
        Litteral* pop();
        bool estVide() const { return nb==0; }
        unsigned int taille() const { return nb; }
        void affiche(ostream& flux);
        QString top() const;
        unsigned int getNbItemsToAffiche()const { return nbAffiche; }
        void setNbItemsToAffiche(int n) { nbAffiche=n; }
        void setMessage(const string& m) { message=m; }
        string getMessage() const { return message; }
        QString affiche();
        QString afficheall();
        Litteral* simplifier(Litteral* e);
        Pile(Pile const& objet);

    };

}

    ostream& operator<<(ostream& flux,Exp::Pile& m);


#endif // PILE_H
