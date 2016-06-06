#ifndef ATOME_H
#define ATOME_H
#include "expression.h"
#include <string>
#include <QString>
#include "programme.h"

using namespace std;

namespace Exp{


    class Atome: public LitteralNumerique{

        QString m_atome;
        string type="Atome";
        LitteralNumerique* variable;
        LitteralProgramme* programme;

    public:
        Atome(QString atome, LitteralNumerique* var=nullptr, LitteralProgramme* prog=nullptr);
        virtual bool isValide()const{return (m_atome.isEmpty());};
        virtual void affiche(ostream& flux)const;
        virtual QString& affiche(QString& flux)const;
        QString getAtome(){return m_atome;}
        string getType(){return type;}
        virtual bool isVariableValide()const{return (variable!=nullptr);};
        virtual bool isProgrammeValide()const{return (programme!=nullptr);};
        LitteralNumerique* getVariable(){if(isVariableValide())return variable;};
        LitteralProgramme* getProgramme(){if(isProgrammeValide())return programme;};
        virtual LitteralNumerique* operator+(LitteralNumerique* b);
        virtual LitteralNumerique* operator-(LitteralNumerique* b){};
        virtual LitteralNumerique* operator*(LitteralNumerique* b){};
        virtual LitteralNumerique* operator/(LitteralNumerique* b){};
    };


}




ostream& operator<<(ostream& flux,Exp::Atome& m);



#endif // ATOME_H
