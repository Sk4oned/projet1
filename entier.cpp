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

void Entier::affiche(ostream& flux) const
{
    flux << m_entier;
}


QString& Entier::affiche(QString& flux) const
{
    flux+= QString::number(m_entier);
    return flux;
}




ostream& operator<<(ostream& flux,Exp::Entier& m)
{
    m.affiche(flux);

    return flux;
}

LitteralNumerique* Entier::operator+(LitteralNumerique* b)
{
    if(b->getType()=="Entier" )
    {
        Entier* my_b =dynamic_cast<Entier*>(b);
        return (new Entier(my_b->getEntier()+this->getEntier()));
    }
    else if(b->getType()=="Reel" )
    {
        Reel* my_b =dynamic_cast<Reel*>(b);
        return (new Reel(my_b->getReel()+this->getEntier()));
    }
    else if(b->getType()=="Fraction" )
    {
        Fraction* my_b =dynamic_cast<Fraction*>(b);
        int n=this->getEntier()*my_b->getDenominateur()+my_b->getNumerateur();
        int d=my_b->getDenominateur();
        reduc_frac(n,d);
        return (new Fraction(n,d));
    }
    else if(b->getType()=="Atome" )
    {
        Atome* my_b =dynamic_cast<Atome*>(b);
        return (my_b->operator +(this));
    }
    else if(b->getType()=="Complexe" )
    {
        Complexe* my_b =dynamic_cast<Complexe*>(b);
        return my_b->operator +(this);
    }
    return 0;
}



LitteralNumerique* Entier::operator-(LitteralNumerique* b)
{
    if(b->getType()=="Entier" )
    {
        Entier* my_b =dynamic_cast<Entier*>(b);
        return (new Entier(my_b->getEntier()-this->getEntier()));
    }
    else if(b->getType()=="Reel" )
    {
        Reel* my_b =dynamic_cast<Reel*>(b);
        return (new Reel(my_b->getReel()-this->getEntier()));
    }
    else if(b->getType()=="Fraction" )
    {
        Fraction* my_b =dynamic_cast<Fraction*>(b);
        int n=-this->getEntier()*my_b->getDenominateur()+my_b->getNumerateur();
        int d=my_b->getDenominateur();
        reduc_frac(n,d);

        return (new Fraction(n,d));
    }

    else if(b->getType()=="Complexe" )
    {
        Complexe* my_b =dynamic_cast<Complexe*>(b);
        return my_b->operator +(this->operator *(new Entier(-1)));
    }

    return 0;
}


LitteralNumerique* Entier::operator*(LitteralNumerique* b)
{
    if(b->getType()=="Entier" )
    {
        Entier* my_b =dynamic_cast<Entier*>(b);
        return (new Entier(my_b->getEntier()*this->getEntier()));
    }
    else if(b->getType()=="Reel" )
    {
        Reel* my_b =dynamic_cast<Reel*>(b);
        return (new Reel(my_b->getReel()*this->getEntier()));
    }
    else if(b->getType()=="Fraction" )
    {
        Fraction* my_b =dynamic_cast<Fraction*>(b);
        int n=this->getEntier()*my_b->getNumerateur();
        int d=my_b->getDenominateur();
        reduc_frac(n,d);
        if (d == 1)
            {return new Entier(n);}
        else {return new Fraction(n,d);}
    }

    else if(b->getType()=="Complexe" )
    {
        Complexe* my_b =dynamic_cast<Complexe*>(b);
        return my_b->operator *(this);
    }
    return 0;

    return 0;
}


LitteralNumerique* Entier::operator/(LitteralNumerique* b)
{
    if(b->getType()=="Entier" )
    {
        Entier* my_b =dynamic_cast<Entier*>(b);
        int c=my_b->getEntier();
        int d=this->getEntier();
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
        return (new Reel(my_b->getReel()/this->getEntier()));
    }
    else if(b->getType()=="Fraction" )
    {
        Fraction* my_b =dynamic_cast<Fraction*>(b);
        int c=my_b->getNumerateur();
        int d=this->getEntier()*my_b->getDenominateur();
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
    else if(b->getType()=="Complexe" )
        {
            Complexe* my_b =dynamic_cast<Complexe*>(b);
            return new Complexe(this->operator/(my_b->getP_reelle()),this->operator /(my_b->getP_imaginaire()));


            //cast !!!!!!!!!!
            //return new Complexe(...);
        }

}

bool Entier::operator >(Litteral* b)
{

    if(b->getType() =="Entier")
    {
        Entier* my_b=dynamic_cast<Entier*>(b);
        return (this->getEntier()>my_b->getEntier());
    }
    else if(b->getType() =="Reel")
    {
        Reel* my_b=dynamic_cast<Reel*>(b);
        return (this->getEntier()>my_b->getReel());
    }
    else if(b->getType() =="Fraction")
    {
        Fraction* my_b=dynamic_cast<Fraction*>(b);
        return ((this->getEntier()*my_b->getDenominateur())>my_b->getNumerateur());
    }
    else
    {
        throw PileException("Erreur");
    }

}
