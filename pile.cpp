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

using namespace std;
using namespace Exp;

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
    QString a("\n");

    for(int i=0; i<current; i++)
    {

            a += QString::fromStdString(tab[i]->getType());
            a += QString::fromStdString(" : ");
            a=tab[i]->affiche(a);
            a += QString::fromStdString("\n");


     }
    return a;
}

QString Pile::affiche()
{
    QString a("Application So Fucking Fonctionnelle \n");



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
            if(current==nbAffiche+1)
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
