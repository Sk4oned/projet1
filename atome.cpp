#include <string>
#include <iostream>
#include "controleur.h"
#include <sstream>
#include <QString>
#include "expression.h"
#include "entier.h"
#include "reel.h"
#include "fraction.h"
#include "atome.h"
#include "complexe.h"


void Atome::affiche(ostream& flux) const
{
    flux << m_atome;
}


QString& Atome::affiche(QString& flux) const
{
    flux+= QString::number(m_atome);
    return flux;
}

ostream& operator<<(ostream& flux,Exp::Atome& m)
{
    m.affiche(flux);

    return flux;
}


LitteralNumerique* Atome::operator+(LitteralNumerique* b)
{
    if(b->getType()=="Entier" )
    {
        Entier* my_b =dynamic_cast<Entier*>(b);
        return (new Atome(my_b->getEntier()+this->getAtome()));
    }
    else if(b->getType()=="Reel" )
    {
        Reel* my_b =dynamic_cast<Reel*>(b);
        return (new Atome(my_b->getReel()+this->getAtome()));
    }
    else if(b->getType()=="Fraction" )
    {
        Fraction* my_b =dynamic_cast<Fraction*>(b);
        return (new Fraction(this->getAtome()*my_b->getDenominateur()+my_b->getNumerateur(),my_b->getDenominateur()));
    }
    else if(b->getType()=="Atome" )
    {
        Atome* my_b =dynamic_cast<Atome*>(b);
        return (new Atome(my_b->getAtome()+this->getAtome()));
    }
    else if(b->getType()=="Complexe" )
    {
        Complexe* my_b =dynamic_cast<Complexe*>(b);
        return my_b->operator +(this);
    }

    return 0;
}

LitteralNumerique* Atome::operator-(LitteralNumerique* b)
{
    if(b->getType()=="Entier" )
    {
        Entier* my_b =dynamic_cast<Entier*>(b);
        return (new Atome(my_b->getEntier()-this->getAtome()));
    }
    else if(b->getType()=="Reel" )
    {
        Reel* my_b =dynamic_cast<Reel*>(b);
        return (new Atome(my_b->getReel()-this->getAtome()));
    }
    else if(b->getType()=="Fraction" )
    {
        Fraction* my_b =dynamic_cast<Fraction*>(b);
        return (new Fraction(this->getAtome()*my_b->getDenominateur()-my_b->getNumerateur(),my_b->getDenominateur()));
    }
    else if(b->getType()=="Atome" )
    {
        Atome* my_b =dynamic_cast<Atome*>(b);
        return (new Atome(my_b->getAtome()-this->getAtome()));
    }
    return 0;
}


LitteralNumerique* Atome::operator*(LitteralNumerique* b)
{
    if(b->getType()=="Entier" )
    {
        Entier* my_b =dynamic_cast<Entier*>(b);
        return (new Atome(my_b->getEntier()*this->getAtome()));
    }
    else if(b->getType()=="Reel" )
    {
        Reel* my_b =dynamic_cast<Reel*>(b);
        return (new Atome(my_b->getReel()*this->getAtome()));
    }
    else if(b->getType()=="Fraction" )
    {
        Fraction* my_b =dynamic_cast<Fraction*>(b);
        return (new Fraction(this->getAtome()*my_b->getNumerateur(),my_b->getDenominateur()));
    }
    else if(b->getType()=="Atome" )
    {
        Atome* my_b =dynamic_cast<Atome*>(b);
        return (new Atome(my_b->getAtome()*this->getAtome()));
    }
    return 0;
}


LitteralNumerique* Atome::operator/(LitteralNumerique* b)
{
    if(b->getType()=="Entier" )
    {
        Entier* my_b =dynamic_cast<Entier*>(b);
        return (new Fraction(my_b->getEntier(),this->getAtome()));
    }
    else if(b->getType()=="Reel" )
    {
        Reel* my_b =dynamic_cast<Reel*>(b);
        return (new Fraction(my_b->getReel(),this->getAtome()));
    }
    else if(b->getType()=="Fraction" )
    {
        Fraction* my_b =dynamic_cast<Fraction*>(b);
        return (new Fraction(this->getAtome()*my_b->getDenominateur(),my_b->getNumerateur()));
    }
    else if(b->getType()=="Atome" )
    {
        Atome* my_b =dynamic_cast<Atome*>(b);
        return (new Fraction(my_b->getAtome(),this->getAtome()));
    }
    return 0;
}

