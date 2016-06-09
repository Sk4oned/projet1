#include <string>
#include <iostream>
#include "controleur.h"
#include <sstream>
#include <QString>
#include "numerique.h"
#include "entier.h"
#include "reel.h"
#include "fraction.h"
#include "atome.h"
#include "complexe.h"
#include "maths.h"


using namespace std;
using namespace Exp;


Fraction::Fraction(int n, int d)
{

    m_numerateur=n;
    m_denominateur=d;

    if(isValide()!=true)
    {
        throw FractionException("Erreur denominateur = 0");
    }

};

bool Fraction::isValide()const
{
    return (m_denominateur!=0);
}

void Fraction::affiche(ostream& flux) const
{
    flux << m_numerateur << "/" << m_denominateur;
}

QString& Fraction::affiche(QString& flux) const
{
    flux+= QString::number(m_numerateur) + QString::fromStdString("/") +  QString::number(m_denominateur);
    return flux;
}

QString& FractionException::affiche()
{
        return m_phrase;
}

ostream& operator<<(ostream& flux,Fraction& m)
{
    m.affiche(flux);

    return flux;
}


LitteralNumerique* Fraction::operator+(LitteralNumerique* b)
{
    if(b->getType()=="Entier" )
    {
        Entier* my_b =dynamic_cast<Entier*>(b);
        return (new Fraction(this->getNumerateur()+this->getDenominateur()*my_b->getEntier(),this->getDenominateur()));
    }
    else if(b->getType()=="Reel" )
    {
        Reel* my_b =dynamic_cast<Reel*>(b);
        return (new Fraction(this->getNumerateur()+this->getDenominateur()*my_b->getReel(),this->getDenominateur()));
    }
    else if(b->getType()=="Fraction" )
    {
        Fraction* my_b =dynamic_cast<Fraction*>(b);
        return (new Fraction(this->getNumerateur()*my_b->getDenominateur()+this->getDenominateur()*my_b->getNumerateur(),this->getDenominateur()*my_b->getDenominateur()));
    }
 /*   else if(b->getType()=="Atome" )
    {
        Atome* my_b =dynamic_cast<Atome*>(b);
        return (new Fraction(this->getNumerateur()+this->getDenominateur()*my_b->getAtome(),this->getDenominateur()));
    } */
    else if(b->getType()=="Complexe" )
    {
        Complexe* my_b =dynamic_cast<Complexe*>(b);
        return my_b->operator +(this);
    }



    return 0;
}



LitteralNumerique* Fraction::operator-(LitteralNumerique* b)
{
    if(b->getType()=="Entier" )
    {
        Entier* my_b =dynamic_cast<Entier*>(b);
        return (new Fraction(this->getNumerateur()-this->getDenominateur()*my_b->getEntier(),this->getDenominateur()));
    }
    else if(b->getType()=="Reel" )
    {
        Reel* my_b =dynamic_cast<Reel*>(b);
        return (new Fraction(this->getNumerateur()-this->getDenominateur()*my_b->getReel(),this->getDenominateur()));
    }
    else if(b->getType()=="Fraction" )
    {
        Fraction* my_b =dynamic_cast<Fraction*>(b);
        return (new Fraction(this->getNumerateur()*my_b->getDenominateur()-this->getDenominateur()*my_b->getNumerateur(),this->getDenominateur()*my_b->getDenominateur()));
    }
   /* else if(b->getType()=="Atome" )
    {
        Atome* my_b =dynamic_cast<Atome*>(b);
        return (new Fraction(this->getNumerateur()-this->getDenominateur()*my_b->getAtome(),this->getDenominateur()));
    }
*/
    return 0;
}



LitteralNumerique* Fraction::operator*(LitteralNumerique* b)
{
    if(b->getType()=="Entier" )
    {
        Entier* my_b =dynamic_cast<Entier*>(b);
        return (new Fraction(this->getNumerateur()*my_b->getEntier(),this->getDenominateur()));
    }
    else if(b->getType()=="Reel" )
    {
        Reel* my_b =dynamic_cast<Reel*>(b);
        return (new Fraction(this->getNumerateur()*my_b->getReel(),this->getDenominateur()));
    }
    else if(b->getType()=="Fraction" )
    {
        Fraction* my_b =dynamic_cast<Fraction*>(b);
        return (new Fraction(this->getNumerateur()*my_b->getNumerateur(),this->getDenominateur()*my_b->getDenominateur()));
    }
  /*  else if(b->getType()=="Atome" )
    {
        Atome* my_b =dynamic_cast<Atome*>(b);
        return (new Fraction(this->getNumerateur()*my_b->getAtome(),this->getDenominateur()));
    }
*/
    return 0;
}


LitteralNumerique* Fraction::operator/(LitteralNumerique* b)
{
    if(b->getType()=="Entier" )
    {
        Entier* my_b =dynamic_cast<Entier*>(b);
        int c=this->getNumerateur();
        int d=this->getDenominateur()*my_b->getEntier();
        reduc_frac(c,d);
        if(d==1)
        {
            return(new Entier(c));
        }
        else
        {
            return (new Fraction(c,d));
        }
    }
    else if(b->getType()=="Reel" )
    {
        Reel* my_b =dynamic_cast<Reel*>(b);
        return (new Fraction(this->getNumerateur(),this->getDenominateur()*my_b->getReel()));
    }
    else if(b->getType()=="Fraction" )
    {
        Fraction* my_b =dynamic_cast<Fraction*>(b);
        return (new Fraction(this->getNumerateur()*my_b->getDenominateur(),this->getDenominateur()*my_b->getNumerateur()));
    }
/*    else if(b->getType()=="Atome" )
    {
        Atome* my_b =dynamic_cast<Atome*>(b);
        return (new Fraction(this->getNumerateur(),this->getDenominateur()*my_b->getAtome()));
    }*/

    return 0;
}


