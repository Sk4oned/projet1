#ifndef FRACTION_H
#define FRACTION_H
#include "expression.h"
#include <string>
#include <QString>


using namespace Exp;
using namespace std;


namespace Exp{

class FractionException{
    QString m_phrase;

public:
    FractionException(QString p):m_phrase(p){};
    void affiche(ostream& flux);
    QString& affiche();
};


class Fraction: public LitteralNumerique{

    int m_numerateur;
    int m_denominateur;
    string type="Fraction";


public:

    Fraction(int n, int d=1);
    virtual bool isValide()const;
    virtual void affiche(ostream& flux)const;
    virtual QString& affiche(QString& flux)const;
    int getNumerateur(){return m_numerateur;}
    int getDenominateur(){return m_denominateur;}
    string getType(){return type;}
    //virtual Fraction* operator+(Fraction* a);
    virtual LitteralNumerique* operator+(LitteralNumerique* b);
    virtual LitteralNumerique* operator-(LitteralNumerique* b);
    virtual LitteralNumerique* operator*(LitteralNumerique* b);
    virtual LitteralNumerique* operator/(LitteralNumerique* b);

};

}

ostream& operator<<(ostream& flux,Exp::Fraction& m);

ostream& operator<<(ostream& flux,Exp::FractionException& m);


#endif // FRACTION_H
