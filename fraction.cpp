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
#include <windows.h>


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
        Entier* my_b = dynamic_cast<Entier*>(b);
        int n(this->getNumerateur()+this->getDenominateur()*my_b->getEntier());
        int d(this->getDenominateur());
        reduc_frac(n,d);
        return new Fraction(n,d);
    }
    else if(b->getType()=="Reel" )
    {
        Reel* my_b =dynamic_cast<Reel*>(b);
        return (new Reel(my_b->getReel()+(float(this->getNumerateur())/float(this->getDenominateur()))));
    }
    else if(b->getType()=="Fraction" )
    {
        Fraction* my_b =dynamic_cast<Fraction*>(b);
        int n=this->getNumerateur()*my_b->getDenominateur()+this->getDenominateur()*my_b->getNumerateur();
        int d=this->getDenominateur()*my_b->getDenominateur();
        reduc_frac(n,d);
        if (d == 1)
         {
            return new Entier (n);
         }
        else
        {
            return new Fraction(n,d);
        }
    }

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
        int n=this->getDenominateur()*my_b->getEntier()-this->getNumerateur();
        int d=this->getDenominateur();
        reduc_frac(n,d);

        return (new Fraction(n,d));
    }
    else if(b->getType()=="Reel" )
    {
        Reel* my_b =dynamic_cast<Reel*>(b);
        return (new Reel(my_b->getReel()-(float(this->getNumerateur())/float(this->getDenominateur()))));
    }
    else if(b->getType()=="Fraction" )
    {
        Fraction* my_b =dynamic_cast<Fraction*>(b);
        int n=this->getDenominateur()*my_b->getNumerateur()-this->getNumerateur()*my_b->getDenominateur();
        int d=this->getDenominateur()*my_b->getDenominateur();
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



LitteralNumerique* Fraction::operator*(LitteralNumerique* b)
{
    if(b->getType()=="Entier" )
    {
        Entier* my_b =dynamic_cast<Entier*>(b);
        int n(this->getNumerateur()*my_b->getEntier());
        int d(this->getDenominateur());
        reduc_frac(n,d);
        if (d == 1)
            {return new Entier(n);}
        else {return new Fraction(n,d);}
    }
    else if(b->getType()=="Reel" )
    {
        Reel* my_b =dynamic_cast<Reel*>(b);
        return (new Reel(my_b->getReel()*(float(this->getNumerateur())/float(this->getDenominateur()))));
    }
    else if(b->getType()=="Fraction" )
    {
        Fraction* my_b =dynamic_cast<Fraction*>(b);
        int n=this->getNumerateur()*my_b->getNumerateur();
        int d=this->getDenominateur()*my_b->getDenominateur();
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
}


LitteralNumerique* Fraction::operator/(LitteralNumerique* b)
{
    if(b->getType()=="Entier" )
    {
        Entier* my_b =dynamic_cast<Entier*>(b);
        int c=this->getDenominateur()*my_b->getEntier();
        int d=this->getNumerateur();
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
        return (new Reel(my_b->getReel()/(float(this->getNumerateur())/float(this->getDenominateur()))));
    }   else if(b->getType()=="Fraction" )
    {
        Fraction* my_b =dynamic_cast<Fraction*>(b);
        int n=this->getDenominateur()*my_b->getNumerateur();
        int d=this->getNumerateur()*my_b->getDenominateur();
        reduc_frac(n,d);
        if (d == 1)
            {return new Entier(n);}
        else {return new Fraction(n,d);}
    }

    else if(b->getType()=="Complexe" )
    {
        Complexe* my_b =dynamic_cast<Complexe*>(b);
        return new Complexe(this->operator/(my_b->getP_reelle()),this->operator /(my_b->getP_imaginaire()));
    }

    return 0;
}

bool Fraction::operator >(Litteral* b)
{
    if(b->getType() =="Entier")
    {
        Entier* my_b=dynamic_cast<Entier*>(b);
        return (this->getNumerateur()>my_b->getEntier()*this->getDenominateur());
    }
    else if(b->getType() =="Reel")
    {
        Reel* my_b=dynamic_cast<Reel*>(b);
        return (this->getNumerateur()>my_b->getReel()*this->getDenominateur());
    }
    else if(b->getType() =="Fraction")
    {
        Fraction* my_b=dynamic_cast<Fraction*>(b);
        return ((this->getNumerateur()*my_b->getDenominateur())>my_b->getNumerateur()*this->getDenominateur());
    }
    else
    {
        throw PileException("Erreur");
    }
}
