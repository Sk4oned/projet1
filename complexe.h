#ifndef COMPLEXE_H
#define COMPLEXE_H
#include "numerique.h"
#include <string>
#include <QString>

using namespace std;
using namespace Exp;

namespace Exp{

class Complexe: public LitteralNumerique{

    LitteralNumerique* p_reelle;
    LitteralNumerique* p_imaginaire;
    string type="Complexe";

public:

    Complexe(LitteralNumerique* a, LitteralNumerique* b);
    virtual bool isValide()const{ return (p_imaginaire!=0); };
    virtual void affiche(ostream& flux)const;
    virtual QString& affiche(QString& flux)const;
    string getType(){return type;}
    LitteralNumerique* getP_reelle(){ return p_reelle; }
    LitteralNumerique* getP_imaginaire(){ return p_imaginaire; }
    virtual LitteralNumerique* operator+(LitteralNumerique* b);
    virtual LitteralNumerique* operator-(LitteralNumerique* b);
    virtual LitteralNumerique* operator*(LitteralNumerique* b);
    virtual LitteralNumerique* operator/(LitteralNumerique* b);
 };

}



#endif // COMPLEXE_H
