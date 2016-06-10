#ifndef REEL_H
#define REEL_H
#include "numerique.h"
#include <string>
#include <QString>

using namespace std;
using namespace Exp;

namespace Exp{

class Reel: public LitteralNumerique{

    float m_r;
    string type="Reel";

public:

    Reel(float r=0): m_r(r){};
    virtual  bool isValide()const{return (m_r!=0);};
    virtual void affiche(ostream& flux)const;
    virtual QString& affiche(QString& flux)const;
    float getReel(){return m_r;}
    string getType(){return type;}
    //virtual Reel* operator+(Reel* a);
    //virtual Reel* operator-(Reel* a);
    //virtual Fraction* operator/(Reel* a);
    virtual LitteralNumerique* operator+(LitteralNumerique* b);
    virtual LitteralNumerique* operator-(LitteralNumerique* b);
    virtual LitteralNumerique* operator*(LitteralNumerique* b);
    virtual LitteralNumerique* operator/(LitteralNumerique* b);
    bool operator>(Litteral* b);



};

}

ostream& operator<<(ostream& flux,Exp::Reel& m);


#endif // REEL_H
