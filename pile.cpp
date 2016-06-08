#include <string>
#include <iostream>
#include "numerique.h"
#include "controleur.h"
#include <sstream>
#include <QString>
#include "pile.h"

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


void Pile::push(Litteral* e)
{
    tab[current]=e;
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


