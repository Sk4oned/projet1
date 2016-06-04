#ifndef ATOME_H
#define ATOME_H
#include "expression.h"
#include <string>
#include <QString>

using namespace std;
using namespace Exp;

namespace Exp{


    class Atome: public LitteralNumerique{

        int m_atome;
        string type="Atome";

    public:
        Atome(int atome): m_atome(atome){};
        virtual bool isValide()const{return (m_atome!=0);};
        virtual void affiche(ostream& flux)const;
        virtual QString& affiche(QString& flux)const;
        int getAtome(){return m_atome;}
        string getType(){return type;}
        //virtual Atome* operator+(Atome* a);
        virtual LitteralNumerique* operator+(LitteralNumerique* b);
        virtual LitteralNumerique* operator-(LitteralNumerique* b);
        virtual LitteralNumerique* operator*(LitteralNumerique* b);
        virtual LitteralNumerique* operator/(LitteralNumerique* b);

    };


}




ostream& operator<<(ostream& flux,Exp::Atome& m);



#endif // ATOME_H
