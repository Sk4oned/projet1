#ifndef PROGRAMME_H
#define PROGRAMME_H
#include "numerique.h"
#include <string>
#include <QString>
#include "litteral.h"

using namespace std;
using namespace Exp;

namespace Exp{


    class LitteralProgramme: public Litteral{

        QString m_programme;
        string type="LitteralProgramme";

    public:
        LitteralProgramme(QString programme);
        virtual bool isValide() const;
        virtual void affiche(ostream& flux)const;
        virtual QString& affiche(QString& flux)const;
        QString& getProg(){return m_programme;}
        string getType(){return type;}

    };


}




ostream& operator<<(ostream& flux,Exp::LitteralProgramme& m);




#endif // PROGRAMME_H
