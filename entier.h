#ifndef ENTIER_H
#define ENTIER_H
#include "expression.h"
#include <string>
#include <QString>

using namespace std;
using namespace Exp;

namespace Exp{

    class Entier: public LitteralNumerique{

        int m_entier;
        string type="Entier";

    public:

        Entier(int e): m_entier(e){};
        virtual bool isValide()const{return (m_entier!=0);};
        virtual void affiche(ostream& flux)const;
        virtual QString& affiche(QString& flux)const;
        int getEntier(){return m_entier;}
        string getType(){return type;}
        //virtual Entier* operator+(Entier* a);
        //virtual Entier* operator-(Entier* a);
        //virtual Fraction* operator/(Entier* a);
        void setEntier(int a){this->m_entier=a;}
        virtual LitteralNumerique* operator+(LitteralNumerique* b);
        virtual LitteralNumerique* operator-(LitteralNumerique* b);
        virtual LitteralNumerique* operator*(LitteralNumerique* b);
        virtual LitteralNumerique* operator/(LitteralNumerique* b);
    };

}


ostream& operator<<(ostream& flux,Exp::Entier& m);


#endif // ENTIER_H
