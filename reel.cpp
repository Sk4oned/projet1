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

void Reel::affiche(ostream& flux) const
{
    flux << m_r;
}

QString& Reel::affiche(QString& flux) const
{
    flux += QString::number(m_r);
    return flux;
}


ostream& operator<<(ostream& flux,Exp::Reel& m)
{
    m.affiche(flux);

    return flux;
}


LitteralNumerique* Reel::operator+(LitteralNumerique* b)
{
    if(b->getType()=="Entier" )
    {
        Entier* my_b =dynamic_cast<Entier*>(b);
        return (new Reel(my_b->getEntier()+this->getReel()));
    }
    else if(b->getType()=="Reel" )
    {
        Reel* my_b =dynamic_cast<Reel*>(b);
        return (new Reel(my_b->getReel()+this->getReel()));
    }
    else if(b->getType()=="Fraction" )
    {
        Fraction* my_b =dynamic_cast<Fraction*>(b);
        return (new Reel(float(my_b->getNumerateur())/float(my_b->getDenominateur())+this->getReel()));
    }
  /*  else if(b->getType()=="Atome" )
    {

        Atome* my_b =dynamic_cast<Atome*>(b);
        return (new Reel(my_b->getAtome()+this->getReel()));
    } */
    else if(b->getType()=="Complexe" )
    {
        Complexe* my_b =dynamic_cast<Complexe*>(b);
        return my_b->operator +(this);
    }

    return 0;
}



LitteralNumerique* Reel::operator-(LitteralNumerique* b)
{
    if(b->getType()=="Entier" )
    {
        Entier* my_b =dynamic_cast<Entier*>(b);
        return (new Reel(my_b->getEntier()-this->getReel()));
    }
    else if(b->getType()=="Reel" )
    {
        Reel* my_b =dynamic_cast<Reel*>(b);
        return (new Reel(my_b->getReel()-this->getReel()));
    }
    else if(b->getType()=="Fraction" )
    {
        Fraction* my_b =dynamic_cast<Fraction*>(b);
        return (new Reel(float(my_b->getNumerateur())/float(my_b->getDenominateur())-this->getReel()));
    }
 /*   else if(b->getType()=="Atome" )
    {
        Atome* my_b =dynamic_cast<Atome*>(b);
        return (new Reel(my_b->getAtome()-this->getReel()));
    } */

    else if(b->getType()=="Complexe" )
    {
        Complexe* my_b =dynamic_cast<Complexe*>(b);
        return my_b->operator +(this->operator *(new Entier(-1)));
    }
    return 0;
}



LitteralNumerique* Reel::operator*(LitteralNumerique* b)
{
    if(b->getType()=="Entier" )
    {
        Entier* my_b =dynamic_cast<Entier*>(b);
        return (new Reel(my_b->getEntier()*this->getReel()));
    }
    else if(b->getType()=="Reel" )
    {
        Reel* my_b =dynamic_cast<Reel*>(b);
        return (new Reel(my_b->getReel()*this->getReel()));
    }
    else if(b->getType()=="Fraction" )
    {
        Fraction* my_b =dynamic_cast<Fraction*>(b);
        return (new Reel((float(my_b->getNumerateur())/float(my_b->getDenominateur()))*this->getReel()));
    }
    else if(b->getType()=="Complexe" )
    {
        Complexe* my_b =dynamic_cast<Complexe*>(b);
        return my_b->operator*(this);
    }

 /*   else if(b->getType()=="Atome" )
    {
        Atome* my_b =dynamic_cast<Atome*>(b);
        return (new Reel(my_b->getAtome()*this->getReel()));
    } */
    return 0;
}


LitteralNumerique* Reel::operator/(LitteralNumerique* b)
{
    if(b->getType()=="Entier" )
    {
        Entier* my_b =dynamic_cast<Entier*>(b);
        return (new Reel(my_b->getEntier()/this->getReel()));
    }
    else if(b->getType()=="Reel" )
    {
        Reel* my_b =dynamic_cast<Reel*>(b);
        return (new Reel(my_b->getReel()/this->getReel()));
    }
    else if(b->getType()=="Fraction" )
    {
        Fraction* my_b =dynamic_cast<Fraction*>(b);
        return (new Reel((float(my_b->getNumerateur())/float(my_b->getDenominateur()))/this->getReel()));
    }
    else if(b->getType()=="Complexe" )
    {
        Complexe* my_b =dynamic_cast<Complexe*>(b);
        return my_b->operator /(this);
    }

 /*   else if(b->getType()=="Atome" )
    {
        Atome* my_b =dynamic_cast<Atome*>(b);
        return (new Fraction(my_b->getAtome(),this->getReel()));
    } */
    return 0;
}

