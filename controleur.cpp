#include <QString>
#include "expression.h"
#include <sstream>
#include "controleur.h"

using namespace Exp;


void Controleur::checkString()
{
        QString q= chaine;
        chaine="";



        for(int i=0; i<q.size(); i++)
        {
            if(q[i]=='.')
            {

                float b;
                //istringstream
                b=q.toFloat();

                Reel* v = new Reel(b);
                p.push(v);
            }
        }

        for(int i=0; i<q.size(); i++)
        {
            if(q[i]=='/')
            {   int n=5;
                int d=5;

                Fraction* v = new Fraction(n,d);
                p.push(v);
            }
        }

        int j=0;
        for(int i=0; i<q.size(); i++)
            if (q[i]=='.')
                j++;

            if(j==0)
            {
                int c;
                //istringstream
                c=q.toInt();
                Entier* v = new Entier(c);
                p.push(v);

            }

            cout << p;



}


void Controleur::plus()
{
    LitteralExpression* a= p.pop();
    LitteralExpression* b= p.pop();



    if((a->getType()=="Entier" ) & (b->getType()=="Entier"))
    {
        Entier* my_a =dynamic_cast<Entier*>(a);
        Entier* my_b =dynamic_cast<Entier*>(b);
        Entier* c= my_a->operator+(my_b);
        p.push(c);
    }
    else if((a->getType()=="Reel") & (b->getType()=="Reel"))
    {
        Reel* my_a =dynamic_cast<Reel*>(a);
        Reel* my_b =dynamic_cast<Reel*>(b);
        Reel* c= my_a->operator+(my_b);
        p.push(c);
    }
    else if((a->getType()=="Entier") & (b->getType()=="Reel"))
    {
        Reel* my_a =dynamic_cast<Reel*>(a);
        Reel* my_b =dynamic_cast<Reel*>(b);
        Reel* c= my_a->operator+(my_b);
        p.push(c);
    }
    else if((a->getType()=="Reel") & (b->getType()=="Entier"))
    {
        Reel* my_a =dynamic_cast<Reel*>(a);
        Reel* my_b =dynamic_cast<Reel*>(b);
        Reel* c= my_a->operator+(my_b);
        p.push(c);
    }

    cout << p;



}

void Controleur::moins()
{
    LitteralExpression* a= p.pop();
    LitteralExpression* b= p.pop();



    if((a->getType()=="Entier" ) & (b->getType()=="Entier"))
    {
        Entier* my_a =dynamic_cast<Entier*>(a);
        Entier* my_b =dynamic_cast<Entier*>(b);
        Entier* c= my_a->operator-(my_b);
        p.push(c);
    }
    else if((a->getType()=="Reel") & (b->getType()=="Reel"))
    {
        Reel* my_a =dynamic_cast<Reel*>(a);
        Reel* my_b =dynamic_cast<Reel*>(b);
        Reel* c= my_a->operator-(my_b);
        p.push(c);
    }
    else if((a->getType()=="Entier") & (b->getType()=="Reel"))
    {
        Reel* my_a =dynamic_cast<Reel*>(a);
        Reel* my_b =dynamic_cast<Reel*>(b);
        Reel* c= my_a->operator-(my_b);
        p.push(c);
    }
    else if((a->getType()=="Reel") & (b->getType()=="Entier"))
    {
        Reel* my_a =dynamic_cast<Reel*>(a);
        Reel* my_b =dynamic_cast<Reel*>(b);
        Reel* c= my_a->operator-(my_b);
        p.push(c);
    }

    cout << p;



}

QString Controleur::affiche()
{
    QString a = p.affiche();
    return a;
}


QString Controleur::affiche2()
{
    return chaine;
}

void Controleur::contructionchaine(QString a)
{
    chaine =chaine + a;

}


