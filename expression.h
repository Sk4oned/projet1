#ifndef EXPRESSION_H
#include "numerique.h"
#include <string>
#include <QString>
#include "litteral.h"

using namespace std;
using namespace Exp;

namespace Exp{


    class LitteralExpression: public Litteral{

        QString m_expression;
        string type="LitteralExpression";

    public:
        LitteralExpression(QString programme);
        virtual bool isValide() const;
        virtual void affiche(ostream& flux)const;
        virtual QString& affiche(QString& flux)const;
        QString& getProg(){return m_expression;}
        string getType(){return type;}
        QString toPostfixe();
        bool isNumber(QString a);

    };


}




ostream& operator<<(ostream& flux,Exp::LitteralExpression& m);



#endif // EXPRESSION_H
