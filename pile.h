#ifndef PILE_H
#define PILE_H
#include "expression.h"
#include <string>
#include <QString>
#include "reel.h"

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
        unsigned int nbAffiche;
        LitteralNumerique* tab [100];
        int current=0;
    public:
        Pile():nb(0),nbMax(0),message(""),nbAffiche(4){}
        void push(LitteralNumerique* e);
        LitteralNumerique* pop();
        bool estVide() const { return nb==0; }
        unsigned int taille() const { return nb; }
        void affiche(ostream& flux);
        Reel& top() const;
        unsigned int getNbItemsToAffiche()const { return nbAffiche; }
        void setNbItemsToAffiche(unsigned int n) { nb=n; }
        void setMessage(const string& m) { message=m; }
        string getMessage() const { return message; }
        QString affiche();
    };

}

    ostream& operator<<(ostream& flux,Exp::Pile& m);


#endif // PILE_H
