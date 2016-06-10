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
        return new Complexe(this->operator/(my_b->getP_reelle()),this->operator /(my_b->getP_imaginaire()));
    }

    return 0;
}

bool Reel::operator >(Litteral* b)
{
    if(b->getType() =="Entier")
    {
        Entier* my_b=dynamic_cast<Entier*>(b);
        return (this->getReel()>my_b->getEntier());
    }
    else if(b->getType() =="Reel")
    {
        Reel* my_b=dynamic_cast<Reel*>(b);
        return (this->getReel()>my_b->getReel());
    }
    else if(b->getType() =="Fraction")
    {
        Fraction* my_b=dynamic_cast<Fraction*>(b);
        return ((this->getReel()*my_b->getDenominateur())>my_b->getNumerateur());
    }
    else
    {
        throw PileException("Erreur");
    }
}
