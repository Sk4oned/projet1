#include <string>
#include <iostream>
#include "numerique.h"
#include "controleur.h"
#include <sstream>
#include <QString>
#include "pile.h"
#include "complexe.h"
#include "entier.h"
#include "fraction.h"
#include "reel.h"
#include "atome.h"
#include "programme.h"
#include "expression.h"


using namespace std;
using namespace Exp;

/*
Pile::Pile(Pile const& objet)
{
    nb=0;
    nbMax=0;
    nbAffiche=4;
    current=0;

    Litteral* tab[100];

    for(int i=0; i<100; i++)
    {
        Litteral* a= objet.tab[i];


        if(a->getType()=="Entier")
        {
            Entier* b=dynamic_cast<Entier*>(a);
            tab[i]=new Entier(b->getEntier());
        }
        else if(a->getType()=="Reel")
        {
            Reel* b=dynamic_cast<Reel*>(a);
            tab[i]=new Reel(b->getReel());
        }
        else if(a->getType()=="Fraction")
        {
            Fraction* b=dynamic_cast<Fraction*>(a);
            tab[i]=new Fraction(b->getNumerateur(), b->getDenominateur());
        }
        else if(a->getType()=="Complexe")
        {
            Complexe* b=dynamic_cast<Complexe*>(a);
            tab[i]=new Complexe(b->getP_reelle(), b->getP_imaginaire());
        }
        else if(a->getType()=="Atome")
        {
            Atome* b=dynamic_cast<Atome*>(a);
            tab[i]=new Atome(b->getAtome(),b->getVariable());
        }
        else if(a->getType()=="LitteralProgramme")
        {
            LitteralProgramme* b=dynamic_cast<LitteralProgramme*>(a);
            tab[i]=new LitteralProgramme(b->getProg());
        }
        else if(a->getType()=="LitteralExpression")
        {
            LitteralExpression* b=dynamic_cast<LitteralExpression*>(a);
            tab[i]=new LitteralExpression(b->getProg());
        }


    }

}
*/


QString& PileException::affiche()
{

        return m_phrase;
}

ostream& operator<<(ostream& flux,Exp::Pile& m)
{
    m.affiche(flux);

    return flux;
}


Litteral* Pile::simplifier(Litteral* e)
{
    if(e->getType()=="Complexe")
    {
        Complexe* c=dynamic_cast<Complexe*>(e);
        if(c->getP_imaginaire()->getType() =="Entier")
        {
            Entier* my_im=dynamic_cast<Entier*>(c->getP_imaginaire());
                if(my_im->getEntier() ==0)
                {
                    if(c->getP_reelle()->getType() =="Entier")
                    {
                        Entier* my_e=dynamic_cast<Entier*>(c->getP_reelle());
                        return new Entier(my_e->getEntier());
                    }
                    if(c->getP_reelle()->getType() =="Reel")
                    {
                        Reel* my_e=dynamic_cast<Reel*>(c->getP_reelle());
                        return new Reel(my_e->getReel());
                    }
                    if(c->getP_reelle()->getType() =="Fraction")
                    {
                        Fraction* my_e=dynamic_cast<Fraction*>(c->getP_reelle());
                        return new Fraction(my_e->getNumerateur(),my_e->getDenominateur());
                    }

                }
                else
                {
                    return c;
                }
        }
        else
        {
            return c;
        }
    }
    else if(e->getType()=="Fraction")
    {
            Fraction* f=dynamic_cast<Fraction*>(e);
            if(f->getDenominateur() ==1)
            {
                 return (new Entier(f->getNumerateur()));
            }

            else
            {
                return f;
            }

    }

    else if(e->getType()=="Reel")
    {


            Reel* r=dynamic_cast<Reel*>(e);
            int i = r->getReel();

            if(r->getReel()-i ==0)
            {
                 return new Entier(i);
            }

            else
            {
                return r;
            }

    }

    else
    {
        return e;
    }


}

void Pile::push(Litteral* e)
{

    tab[current]=simplifier(e);
    current++;
    nb++;
}

Litteral* Pile::pop()
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

QString Pile::afficheall()
{
    QString a("");

    for(int i=0; i<current; i++)
    {

            //a += QString::fromStdString(tab[i]->getType());
            //a += QString::fromStdString(" : ");
            a=tab[i]->affiche(a);
            a += QString::fromStdString("\n");


     }
    return a;
}

QString Pile::affiche()
{
    QString a("");

    if(current < nbAffiche)
    {
        for(int i=0; i<current; i++)
        {

                a += QString::fromStdString(tab[i]->getType());
                a += QString::fromStdString(" : ");
                a=tab[i]->affiche(a);
                a += QString::fromStdString("\n");


         }
    }
    else
    {
            for(int i=current-nbAffiche; i<current; i++)
            {

                    a += QString::fromStdString(tab[i]->getType());
                    a += QString::fromStdString(" : ");
                    a=tab[i]->affiche(a);
                    a += QString::fromStdString("\n");
             }
            if(current>nbAffiche)
            {
                a += QString::fromStdString("...");
            }

    }

    return a;
}


QString& operator<<(QString& flux,string a)
{
    flux = QString::fromStdString(a);
    return flux;

}

QString Pile::top() const
{
    QString a;
    tab[current-1]->affiche(a);
    return a;
}
