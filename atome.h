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

        QString m_atome;
        string type="Atome";
        Litteral* variable;


    public:
        Atome(QString atome, Litteral* var=nullptr);
        virtual bool isValide()const{return (m_atome.isEmpty());};
        virtual void affiche(ostream& flux)const;
        virtual QString& affiche(QString& flux) const;
        //QString& affiche2(QString& flux);
        QString getAtome(){return m_atome;}
        string getType(){return type;}
        virtual bool isVariableValide()const{return (variable!=nullptr);};
        Litteral* getVariable(){if(isVariableValide())return variable;};
        virtual LitteralNumerique* operator+(Litteral* b);
        virtual LitteralNumerique* operator-(Litteral* b){};
        virtual LitteralNumerique* operator*(Litteral* b){};
        virtual LitteralNumerique* operator/(Litteral* b){};
    };


}




ostream& operator<<(ostream& flux,Exp::Atome& m);



#endif // ATOME_H
