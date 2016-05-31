#include <string>
#include <iostream>
#include "expression.h"
#include "controleur.h"
#include "expression.h"
#include <sstream>
#include <QString>

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

void FractionException::affiche(ostream& flux)
{
        flux << m_phrase;
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

QString& FractionException::affiche(QString& flux) const
{
        flux += QString::fromStdString(m_phrase);
        return flux;
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


ostream& operator<<(ostream& flux,Exp::FractionException& m)
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

}

LitteralExpression* Pile::pop()
{
    return tab[--current];
    tab[current]=nullptr;

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

