#include <string>
#include <iostream>
#include "expression.h"
#include "controleur.h"
#include "expression.h"
#include <sstream>
#include <QString>
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

void Entier::affiche(ostream& flux) const
{
    flux << m_entier;
}

void Atome::affiche(ostream& flux) const
{
    flux << m_atome;
}

void Fraction::affiche(ostream& flux) const
{
    flux << m_numerateur << "/" << m_denominateur;
}

void Reel::affiche(ostream& flux) const
{
    flux << m_r;
}


void Complexe::affiche(ostream& flux)const
{


    if(p_reelle->getType()=="Entier" && p_imaginaire->getType()=="Entier" )
    {
        Entier* my_a =dynamic_cast<Entier*>(p_reelle);
        Entier* my_b =dynamic_cast<Entier*>(p_imaginaire);

        flux << my_a << "+" <<  my_b << "i";

    }
    else if(p_reelle->getType()=="Entier" && p_imaginaire->getType()=="Reel")
    {
        Entier* my_a =dynamic_cast<Entier*>(p_reelle);
        Reel* my_b =dynamic_cast<Reel*>(p_imaginaire);


        flux << my_a << "+" <<  my_b << "i";
    }
    else if(p_reelle->getType()=="Entier" && p_imaginaire->getType()=="Fraction")
    {
       Entier* my_a =dynamic_cast<Entier*>(p_reelle);
       Fraction* my_b =dynamic_cast<Fraction*>(p_imaginaire);

       flux << my_a << "+" <<  my_b << "i";;
    }
    else if(p_reelle->getType()=="Reel" && p_imaginaire->getType()=="Entier" )
    {
        Reel* my_a =dynamic_cast<Reel*>(p_reelle);
        Entier* my_b =dynamic_cast<Entier*>(p_imaginaire);

        flux << my_a << "+" <<  my_b << "i";
    }
    else if(p_reelle->getType()=="Reel" && p_imaginaire->getType()=="Reel")
    {
        Reel* my_a =dynamic_cast<Reel*>(p_reelle);
        Reel* my_b =dynamic_cast<Reel*>(p_imaginaire);

        flux << my_a << "+" <<  my_b << "i";
    }
    else if(p_reelle->getType()=="Reel" && p_imaginaire->getType()=="Fraction")
    {
       Reel* my_a =dynamic_cast<Reel*>(p_reelle);
       Fraction* my_b =dynamic_cast<Fraction*>(p_imaginaire);

       flux << my_a << "+" <<  my_b << "i";
    }
    else if(p_reelle->getType()=="Fraction" && p_imaginaire->getType()=="Entier" )
    {
        Fraction* my_a =dynamic_cast<Fraction*>(p_reelle);
        Entier* my_b =dynamic_cast<Entier*>(p_imaginaire);

        flux << my_a << "+" <<  my_b << "i";
    }
    else if(p_reelle->getType()=="Fraction" && p_imaginaire->getType()=="Reel")
    {
        Fraction* my_a =dynamic_cast<Fraction*>(p_reelle);
        Reel* my_b =dynamic_cast<Reel*>(p_imaginaire);

        flux << my_a << "+" <<  my_b << "i";
    }
    else if(p_reelle->getType()=="Fraction" && p_imaginaire->getType()=="Fraction")
    {
        Fraction* my_a =dynamic_cast<Fraction*>(p_reelle);
        Fraction* my_b =dynamic_cast<Fraction*>(p_imaginaire);

        flux << my_a << "+" <<  my_b << "i";
    }
}



//VERSION QSTRING

QString& Entier::affiche(QString& flux) const
{
    flux+= QString::number(m_entier);
    return flux;
}

QString& Atome::affiche(QString& flux) const
{
    flux+= QString::number(m_atome);
    return flux;
}

QString& Fraction::affiche(QString& flux) const
{
    flux+= QString::number(m_numerateur) + QString::fromStdString("/") +  QString::number(m_denominateur);
    return flux;
}

QString& Reel::affiche(QString& flux) const
{
    flux += QString::number(m_r);
    return flux;
}

QString& FractionException::affiche()
{
        return m_phrase;
}

QString& PileException::affiche()
{
        return m_phrase;
}

ostream& operator<<(ostream& flux,Fraction& m)
{
    m.affiche(flux);

    return flux;
}


ostream& operator<<(ostream& flux,Exp::Entier& m)
{
    m.affiche(flux);

    return flux;
}

ostream& operator<<(ostream& flux,Exp::Atome& m)
{
    m.affiche(flux);

    return flux;
}

ostream& operator<<(ostream& flux,Exp::Reel& m)
{
    m.affiche(flux);

    return flux;
}

ostream& operator<<(ostream& flux,Exp::Complexe& m)
{
    m.affiche(flux);

    return flux;
}


ostream& operator<<(ostream& flux,Exp::Pile& m)
{
    m.affiche(flux);

    return flux;
}


void Pile::push(LitteralNumerique* e)
{
    tab[current]=e;
    current++;
    nb++;

}

LitteralNumerique* Pile::pop()
{
    return tab[--current];
    tab[current]=nullptr;
    nb--;

}

void Pile::affiche(ostream& flux)
{
    for(int i=0; i<(current); i++)
    {
        flux << tab[i]->getType();
        cout << " : " ;
        tab[i]->affiche(cout);
        cout << "\n" << endl;
    }
}


QString Pile::affiche()
{
    QString a("Application So Fucking Fonctionnelle \n");
    for(int i=0; i<(current); i++)
    {
        a += QString::fromStdString(tab[i]->getType());
        a += QString::fromStdString(" : ");
        a=tab[i]->affiche(a);
        a += QString::fromStdString("\n");
    }
    return a;
}


QString& operator<<(QString& flux,string a)
{
    flux = QString::fromStdString(a);
    return flux;

}



/*
LitteralNumerique* LitteralNumerique::getType(string entree)
{
    int n;
    int d;

    if(entree)

    Fraction* f= new Fraction(n,d);

    Entier* e= new Entier(n);

    Atome* a= new Atome(n);

    Reel* r= new Reel(n);



}
*/

/*
Entier* Entier::operator+(Exp::Entier* a)
 {
        return (new Entier(a->getEntier()+this->getEntier()));

 }

Fraction* Fraction::operator+(Fraction* a)
{

    return a;
}

Atome* Atome::operator+(Atome* a)
{
    return (new Atome(a->getAtome()+this->getAtome()));

}

Reel* Reel::operator+(Reel* a)
{
    return (new Reel(a->getReel()+this->getReel()));

}

Entier* Entier::operator-(Exp::Entier* a)
 {
        return (new Entier(a->getEntier()-this->getEntier()));

 }

Reel* Reel::operator-(Reel* a)
{
    return (new Reel(a->getReel()-this->getReel()));

}



Fraction* Entier::operator/(Exp::Entier* a)
 {
        return (new Fraction(a->getEntier(),this->getEntier()));

 }

Fraction* Reel::operator/(Reel* a)
{
    return (new Fraction(a->getReel(),this->getReel()));

}

*/

// OPERATOR +
//
//
//


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
        return (new Fraction(this->getEntier()*my_b->getDenominateur()+my_b->getNumerateur(),my_b->getDenominateur()));
    }
    else if(b->getType()=="Atome" )
    {
        Atome* my_b =dynamic_cast<Atome*>(b);
        return (new Atome(my_b->getAtome()+this->getEntier()));
    }
    else if(b->getType()=="Complexe" )
    {
        Complexe* my_b =dynamic_cast<Complexe*>(b);
        return my_b->operator +(this);
    }
    return 0;
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
        return (new Fraction(this->getReel()*my_b->getDenominateur()+my_b->getNumerateur(),my_b->getDenominateur()));
    }
    else if(b->getType()=="Atome" )
    {
        Atome* my_b =dynamic_cast<Atome*>(b);
        return (new Reel(my_b->getAtome()+this->getReel()));
    }
    else if(b->getType()=="Complexe" )
    {
        Complexe* my_b =dynamic_cast<Complexe*>(b);
        return my_b->operator +(this);
    }

    return 0;
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
    else if(b->getType()=="Atome" )
    {
        Atome* my_b =dynamic_cast<Atome*>(b);
        return (new Fraction(this->getNumerateur()+this->getDenominateur()*my_b->getAtome(),this->getDenominateur()));
    }
    else if(b->getType()=="Complexe" )
    {
        Complexe* my_b =dynamic_cast<Complexe*>(b);
        return my_b->operator +(this);
    }



    return 0;
}

// OPERATOR -
//
//
//

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
        return (new Fraction(this->getEntier()*my_b->getDenominateur()-my_b->getNumerateur(),my_b->getDenominateur()));
    }
    else if(b->getType()=="Atome" )
    {
        Atome* my_b =dynamic_cast<Atome*>(b);
        return (new Atome(my_b->getAtome()-this->getEntier()));
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
        return (new Fraction(this->getReel()*my_b->getDenominateur()-my_b->getNumerateur(),my_b->getDenominateur()));
    }
    else if(b->getType()=="Atome" )
    {
        Atome* my_b =dynamic_cast<Atome*>(b);
        return (new Reel(my_b->getAtome()-this->getReel()));
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
    else if(b->getType()=="Atome" )
    {
        Atome* my_b =dynamic_cast<Atome*>(b);
        return (new Fraction(this->getNumerateur()-this->getDenominateur()*my_b->getAtome(),this->getDenominateur()));
    }

    return 0;
}

// OPERATOR *
//
//
//

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
        return (new Fraction(this->getEntier()*my_b->getNumerateur(),my_b->getDenominateur()));
    }
    else if(b->getType()=="Atome" )
    {
        Atome* my_b =dynamic_cast<Atome*>(b);
        return (new Atome(my_b->getAtome()*this->getEntier()));
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
        return (new Fraction(this->getReel()*my_b->getNumerateur(),my_b->getDenominateur()));
    }
    else if(b->getType()=="Atome" )
    {
        Atome* my_b =dynamic_cast<Atome*>(b);
        return (new Reel(my_b->getAtome()*this->getReel()));
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
    else if(b->getType()=="Atome" )
    {
        Atome* my_b =dynamic_cast<Atome*>(b);
        return (new Fraction(this->getNumerateur()*my_b->getAtome(),this->getDenominateur()));
    }

    return 0;
}


// OPERATOR /
//
//
//

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
        return (new Fraction(my_b->getReel(),this->getEntier()));
    }
    else if(b->getType()=="Fraction" )
    {
        Fraction* my_b =dynamic_cast<Fraction*>(b);
        int c=this->getEntier()*my_b->getDenominateur();
        int d=my_b->getNumerateur();
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
    else if(b->getType()=="Atome" )
    {
        Atome* my_b =dynamic_cast<Atome*>(b);
        int c=my_b->getAtome();
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
    return 0;
}

LitteralNumerique* Reel::operator/(LitteralNumerique* b)
{
    if(b->getType()=="Entier" )
    {
        Entier* my_b =dynamic_cast<Entier*>(b);
        return (new Fraction(my_b->getEntier(),this->getReel()));
    }
    else if(b->getType()=="Reel" )
    {
        Reel* my_b =dynamic_cast<Reel*>(b);
        return (new Fraction(my_b->getReel(),this->getReel()));
    }
    else if(b->getType()=="Fraction" )
    {
        Fraction* my_b =dynamic_cast<Fraction*>(b);
        return (new Fraction(this->getReel()*my_b->getDenominateur(),my_b->getNumerateur()));
    }
    else if(b->getType()=="Atome" )
    {
        Atome* my_b =dynamic_cast<Atome*>(b);
        return (new Fraction(my_b->getAtome(),this->getReel()));
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
    else if(b->getType()=="Atome" )
    {
        Atome* my_b =dynamic_cast<Atome*>(b);
        return (new Fraction(this->getNumerateur(),this->getDenominateur()*my_b->getAtome()));
    }

    return 0;
}


//Complexe


Complexe::Complexe(LitteralNumerique* a, LitteralNumerique* b)
{
    p_reelle=a;
    p_imaginaire=b;
};



QString& Complexe::affiche(QString& flux) const
{
    QString a;
    QString b;

    if(p_reelle->getType()=="Entier" && p_imaginaire->getType()=="Entier" )
    {
        Entier* my_a =dynamic_cast<Entier*>(p_reelle);
        Entier* my_b =dynamic_cast<Entier*>(p_imaginaire);

        flux+= my_a->affiche(a) + QString::fromStdString("+") +  my_b->affiche(b) + QString::fromStdString("i");
        return flux;
    }
    else if(p_reelle->getType()=="Entier" && p_imaginaire->getType()=="Reel")
    {
        Entier* my_a =dynamic_cast<Entier*>(p_reelle);
        Reel* my_b =dynamic_cast<Reel*>(p_imaginaire);


        flux+= my_a->affiche(a) + QString::fromStdString("+") +  my_b->affiche(b) + QString::fromStdString("i");
        return flux;
    }
    else if(p_reelle->getType()=="Entier" && p_imaginaire->getType()=="Fraction")
    {
       Entier* my_a =dynamic_cast<Entier*>(p_reelle);
       Fraction* my_b =dynamic_cast<Fraction*>(p_imaginaire);

       flux+= my_a->affiche(a) + QString::fromStdString("+") +  my_b->affiche(b) + QString::fromStdString("i");
       return flux;
    }
    else if(p_reelle->getType()=="Reel" && p_imaginaire->getType()=="Entier" )
    {
        Reel* my_a =dynamic_cast<Reel*>(p_reelle);
        Entier* my_b =dynamic_cast<Entier*>(p_imaginaire);

        flux+= my_a->affiche(a) + QString::fromStdString("+") +  my_b->affiche(b) + QString::fromStdString("i");
        return flux;
    }
    else if(p_reelle->getType()=="Reel" && p_imaginaire->getType()=="Reel")
    {
        Reel* my_a =dynamic_cast<Reel*>(p_reelle);
        Reel* my_b =dynamic_cast<Reel*>(p_imaginaire);

        flux+= my_a->affiche(a) + QString::fromStdString("+") +  my_b->affiche(b) + QString::fromStdString("i");
        return flux;
    }
    else if(p_reelle->getType()=="Reel" && p_imaginaire->getType()=="Fraction")
    {
       Reel* my_a =dynamic_cast<Reel*>(p_reelle);
       Fraction* my_b =dynamic_cast<Fraction*>(p_imaginaire);

       flux+= my_a->affiche(a) + QString::fromStdString("+") +  my_b->affiche(b) + QString::fromStdString("i");
       return flux;
    }
    else if(p_reelle->getType()=="Fraction" && p_imaginaire->getType()=="Entier" )
    {
        Fraction* my_a =dynamic_cast<Fraction*>(p_reelle);
        Entier* my_b =dynamic_cast<Entier*>(p_imaginaire);

        flux+= my_a->affiche(a) + QString::fromStdString("+") +  my_b->affiche(b) + QString::fromStdString("i");
        return flux;
    }
    else if(p_reelle->getType()=="Fraction" && p_imaginaire->getType()=="Reel")
    {
        Fraction* my_a =dynamic_cast<Fraction*>(p_reelle);
        Reel* my_b =dynamic_cast<Reel*>(p_imaginaire);

        flux+= my_a->affiche(a) + QString::fromStdString("+") +  my_b->affiche(b) + QString::fromStdString("i");
        return flux;
    }
    else if(p_reelle->getType()=="Fraction" && p_imaginaire->getType()=="Fraction")
    {
        Fraction* my_a =dynamic_cast<Fraction*>(p_reelle);
        Fraction* my_b =dynamic_cast<Fraction*>(p_imaginaire);

        flux+= my_a->affiche(a) + QString::fromStdString("+") +  my_b->affiche(b) + QString::fromStdString("i");
        return flux;
    }
}

//COMPLEXE OPERATOR +



LitteralNumerique* Complexe::operator+(LitteralNumerique* b)
{

    if(b->getType()=="Complexe" )
    {
        Complexe* my_b =dynamic_cast<Complexe*>(b);
        return (new Complexe(my_b->p_reelle->operator+(p_reelle),my_b->p_imaginaire->operator+(p_imaginaire)));
    }
    else if(p_reelle->getType()=="Entier" && p_imaginaire->getType()=="Entier" )
    {
        Entier* my_p_reelle =dynamic_cast<Entier*>(p_reelle);
        Entier* my_p_imaginaire =dynamic_cast<Entier*>(p_imaginaire);

        if(b->getType()=="Entier" )
        {
            Entier* my_b =dynamic_cast<Entier*>(b);
            return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Reel" )
        {
            Reel* my_b =dynamic_cast<Reel*>(b);
            return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Fraction" ) //A REVOIR
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return (new Complexe(my_p_reelle->operator*(my_b),my_p_imaginaire));
        }
        else if(b->getType()=="Atome" ) //WTF is atom
        {
            Atome* my_b =dynamic_cast<Atome*>(b);
            return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Atome" ) //WTF is atom
        {
            Atome* my_b =dynamic_cast<Atome*>(b);
            return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
        }

    }
    else if(p_reelle->getType()=="Entier" && p_imaginaire->getType()=="Reel")
    {
        Entier* my_p_reelle =dynamic_cast<Entier*>(p_reelle);
        Reel* my_p_imaginaire =dynamic_cast<Reel*>(p_imaginaire);


        if(b->getType()=="Entier" )
        {
            Entier* my_b =dynamic_cast<Entier*>(b);
            return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Reel" )
        {
            Reel* my_b =dynamic_cast<Reel*>(b);
            return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Fraction" ) //A REVOIR
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return (new Complexe(my_p_reelle->operator*(my_b),my_p_imaginaire));
        }
        else if(b->getType()=="Atome" ) //WTF is atom
        {
            Atome* my_b =dynamic_cast<Atome*>(b);
            return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
        }



    }
    else if(p_reelle->getType()=="Entier" && p_imaginaire->getType()=="Fraction")
    {
       Entier* my_p_reelle =dynamic_cast<Entier*>(p_reelle);
       Fraction* my_p_imaginaire =dynamic_cast<Fraction*>(p_imaginaire);


       if(b->getType()=="Entier" )
       {
           Entier* my_b =dynamic_cast<Entier*>(b);
           return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
       }
       else if(b->getType()=="Reel" )
       {
           Reel* my_b =dynamic_cast<Reel*>(b);
           return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
       }
       else if(b->getType()=="Fraction" ) //A REVOIR
       {
           Fraction* my_b =dynamic_cast<Fraction*>(b);
           return (new Complexe(my_p_reelle->operator*(my_b),my_p_imaginaire));
       }
       else if(b->getType()=="Atome" ) //WTF is atom
       {
           Atome* my_b =dynamic_cast<Atome*>(b);
           return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
       }


    }
    else if(p_reelle->getType()=="Reel" && p_imaginaire->getType()=="Entier" )
    {
        Reel* my_p_reelle =dynamic_cast<Reel*>(p_reelle);
        Entier* my_p_imaginaire =dynamic_cast<Entier*>(p_imaginaire);


        if(b->getType()=="Entier" )
        {
            Entier* my_b =dynamic_cast<Entier*>(b);
            return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Reel" )
        {
            Reel* my_b =dynamic_cast<Reel*>(b);
            return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Fraction" ) //A REVOIR
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return (new Complexe(my_p_reelle->operator*(my_b),my_p_imaginaire));
        }
        else if(b->getType()=="Atome" ) //WTF is atom
        {
            Atome* my_b =dynamic_cast<Atome*>(b);
            return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
        }


    }
    else if(p_reelle->getType()=="Reel" && p_imaginaire->getType()=="Reel")
    {
        Reel* my_p_reelle =dynamic_cast<Reel*>(p_reelle);
        Reel* my_p_imaginaire =dynamic_cast<Reel*>(p_imaginaire);


        if(b->getType()=="Entier" )
        {
            Entier* my_b =dynamic_cast<Entier*>(b);
            return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Reel" )
        {
            Reel* my_b =dynamic_cast<Reel*>(b);
            return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Fraction" ) //A REVOIR
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return (new Complexe(my_p_reelle->operator*(my_b),my_p_imaginaire));
        }
        else if(b->getType()=="Atome" ) //WTF is atom
        {
            Atome* my_b =dynamic_cast<Atome*>(b);
            return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
        }


    }
    else if(p_reelle->getType()=="Reel" && p_imaginaire->getType()=="Fraction")
    {
       Reel* my_p_reelle =dynamic_cast<Reel*>(p_reelle);
       Fraction* my_p_imaginaire =dynamic_cast<Fraction*>(p_imaginaire);

       if(b->getType()=="Entier" )
       {
           Entier* my_b =dynamic_cast<Entier*>(b);
           return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
       }
       else if(b->getType()=="Reel" )
       {
           Reel* my_b =dynamic_cast<Reel*>(b);
           return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
       }
       else if(b->getType()=="Fraction" ) //A REVOIR
       {
           Fraction* my_b =dynamic_cast<Fraction*>(b);
           return (new Complexe(my_p_reelle->operator*(my_b),my_p_imaginaire));
       }
       else if(b->getType()=="Atome" ) //WTF is atom
       {
           Atome* my_b =dynamic_cast<Atome*>(b);
           return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
       }


    }
    else if(p_reelle->getType()=="Fraction" && p_imaginaire->getType()=="Entier" )
    {
        Fraction* my_p_reelle =dynamic_cast<Fraction*>(p_reelle);
        Entier* my_p_imaginaire =dynamic_cast<Entier*>(p_imaginaire);


        if(b->getType()=="Entier" )
        {
            Entier* my_b =dynamic_cast<Entier*>(b);
            return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Reel" )
        {
            Reel* my_b =dynamic_cast<Reel*>(b);
            return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Fraction" ) //A REVOIR
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return (new Complexe(my_p_reelle->operator*(my_b),my_p_imaginaire));
        }
        else if(b->getType()=="Atome" ) //WTF is atom
        {
            Atome* my_b =dynamic_cast<Atome*>(b);
            return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
        }


    }
    else if(p_reelle->getType()=="Fraction" && p_imaginaire->getType()=="Reel")
    {
        Fraction* my_p_reelle =dynamic_cast<Fraction*>(p_reelle);
        Reel* my_p_imaginaire =dynamic_cast<Reel*>(p_imaginaire);


        if(b->getType()=="Entier" )
        {
            Entier* my_b =dynamic_cast<Entier*>(b);
            return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Reel" )
        {
            Reel* my_b =dynamic_cast<Reel*>(b);
            return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Fraction" ) //A REVOIR
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return (new Complexe(my_p_reelle->operator*(my_b),my_p_imaginaire));
        }
        else if(b->getType()=="Atome" ) //WTF is atom
        {
            Atome* my_b =dynamic_cast<Atome*>(b);
            return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
        }


    }
    else if(p_reelle->getType()=="Fraction" && p_imaginaire->getType()=="Fraction")
    {
        Fraction* my_p_reelle =dynamic_cast<Fraction*>(p_reelle);
        Fraction* my_p_imaginaire =dynamic_cast<Fraction*>(p_imaginaire);


        if(b->getType()=="Entier" )
        {
            Entier* my_b =dynamic_cast<Entier*>(b);
            return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Reel" )
        {
            Reel* my_b =dynamic_cast<Reel*>(b);
            return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Fraction" ) //A REVOIR
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return (new Complexe(my_p_reelle->operator*(my_b),my_p_imaginaire));
        }
        else if(b->getType()=="Atome" ) //WTF is atom
        {
            Atome* my_b =dynamic_cast<Atome*>(b);
            return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
        }


    }

    return 0;

 }


LitteralNumerique* Complexe::operator-(LitteralNumerique* b)
{
    return b;
}

LitteralNumerique* Complexe::operator*(LitteralNumerique* b)
{
    return b;
}

LitteralNumerique* Complexe::operator/(LitteralNumerique* b)
{
    return b;
}


