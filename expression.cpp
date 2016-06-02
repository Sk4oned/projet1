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


ostream& operator<<(ostream& flux,Exp::Pile& m)
{
    m.affiche(flux);

    return flux;
}

void Pile::push(LitteralExpression* e)
{
    tab[current]=e;
    current++;
    nb++;

}

LitteralExpression* Pile::pop()
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
LitteralExpression* LitteralExpression::getType(string entree)
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

*/

Fraction* Entier::operator/(Exp::Entier* a)
 {
        return (new Fraction(a->getEntier(),this->getEntier()));

 }

Fraction* Reel::operator/(Reel* a)
{
    return (new Fraction(a->getReel(),this->getReel()));

}

// OPERATOR +
//
//
//


LitteralExpression* Entier::operator+(LitteralExpression* b)
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
    return 0;
}

LitteralExpression* Reel::operator+(LitteralExpression* b)
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
    return 0;
}

LitteralExpression* Atome::operator+(LitteralExpression* b)
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
    return 0;
}

LitteralExpression* Fraction::operator+(LitteralExpression* b)
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
    return 0;
}

// OPERATOR -
//
//
//

LitteralExpression* Entier::operator-(LitteralExpression* b)
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

LitteralExpression* Reel::operator-(LitteralExpression* b)
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

LitteralExpression* Atome::operator-(LitteralExpression* b)
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

LitteralExpression* Fraction::operator-(LitteralExpression* b)
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

LitteralExpression* Entier::operator*(LitteralExpression* b)
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

LitteralExpression* Reel::operator*(LitteralExpression* b)
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

LitteralExpression* Atome::operator*(LitteralExpression* b)
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

LitteralExpression* Fraction::operator*(LitteralExpression* b)
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

LitteralExpression* Entier::operator/(LitteralExpression* b)
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

LitteralExpression* Reel::operator/(LitteralExpression* b)
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

LitteralExpression* Atome::operator/(LitteralExpression* b)
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

LitteralExpression* Fraction::operator/(LitteralExpression* b)
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



