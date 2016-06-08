#ifndef ATOME_H
#define ATOME_H
#include "numerique.h"
#include <string>
#include <QString>
#include "programme.h"
#include "litteral.h"

using namespace std;

namespace Exp{


    class Atome: public Litteral{

        QString nom;
        string type="Atome";
        Litteral* variable;

    public:
        Atome(QString atome, Litteral* prog=nullptr);
        virtual bool isValide()const{return (variable->isValide());};
        virtual void affiche(ostream& flux)const;
        virtual QString& affiche(QString& flux)const;
        Litteral* getAtome(){return variable;}
        string getType(){return type;}
        virtual bool isVariableValide()const{return (variable!=nullptr);};
        Litteral* getVariable(){if(isVariableValide())return variable;};
        virtual LitteralNumerique* operator+(LitteralNumerique* b){};
        virtual LitteralNumerique* operator-(LitteralNumerique* b){};
        virtual LitteralNumerique* operator*(LitteralNumerique* b){};
        virtual LitteralNumerique* operator/(LitteralNumerique* b){};
    };


}




ostream& operator<<(ostream& flux,Exp::Atome& m);



#endif // ATOME_H
