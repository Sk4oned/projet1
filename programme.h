#ifndef PROGRAMME_H
#define PROGRAMME_H
#include "expression.h"
#include <string>
#include <QString>

using namespace std;
using namespace Exp;

namespace Exp{


    class LitteralProgramme{

        QString m_programme;
        string type="LitteralProgramme";

    public:
        LitteralProgramme(QString programme);
        virtual bool isValide();
        virtual void affiche(ostream& flux);
        virtual QString& affiche(QString& flux);
        QString& getProg(){return m_programme;}
        string getType(){return type;}
        LitteralNumerique* evaluer();

    };


}




ostream& operator<<(ostream& flux,Exp::LitteralProgramme& m);




#endif // PROGRAMME_H
