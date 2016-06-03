#include <QString>
#include "expression.h"
#include <sstream>
#include "controleur.h"


using namespace Exp;


void Controleur::checkString()
{
        QString q= chaine;
        chaine="";


    if(q[0]=='+')
    {
        plus();
    }
    else if(q[0]=='-')
    {
        moins();
    }
    else if(q[0]=='*')
    {
        multiplier();
    }
    else if(q[0]=='/')
    {
        diviser();
    }
    else if(q=="NEG")
    {
        neg();
    }
    else if(q=="$")
    {
        complexe();
    }
    else{



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


                if(d==1)
                {
                    Entier* v=new Entier(n);
                    p.push(v);
                }
                else
                {
                    Fraction* v = new Fraction(n,d);
                    p.push(v);
                }


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
}


void Controleur::plus()
{
    if(p.taille() >= 2)
    {

        LitteralNumerique* a= p.pop();
        LitteralNumerique* b= p.pop();

        if(a->getType()=="Entier" )
        {
            Entier* my_a =dynamic_cast<Entier*>(a);
            LitteralNumerique* c= my_a->operator+(b);
            p.push(c);
         }
        else if(a->getType()=="Reel")
        {
            Reel* my_a =dynamic_cast<Reel*>(a);
            LitteralNumerique* c= my_a->operator+(b);
            p.push(c);
        }
        else if(a->getType()=="Fraction")
        {
           Fraction* my_a =dynamic_cast<Fraction*>(a);
           LitteralNumerique* c= my_a->operator+(b);
           p.push(c);
        }
        else if(a->getType()=="Atome")
        {
           Atome* my_a =dynamic_cast<Atome*>(a);
           LitteralNumerique* c= my_a->operator+(b);
           p.push(c);
        }

 /*
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
*/
    }
    else
    {
        throw PileException("Pas Assez d'argument");
    }


}

void Controleur::moins()
{
    if(p.taille() >= 2)
    {

        LitteralNumerique* a= p.pop();
        LitteralNumerique* b= p.pop();

        if(a->getType()=="Entier" )
        {
            Entier* my_a =dynamic_cast<Entier*>(a);
            LitteralNumerique* c= my_a->operator-(b);
            p.push(c);
         }
        else if(a->getType()=="Reel")
        {
            Reel* my_a =dynamic_cast<Reel*>(a);
            LitteralNumerique* c= my_a->operator-(b);
            p.push(c);
        }
        else if(a->getType()=="Fraction")
        {
           Fraction* my_a =dynamic_cast<Fraction*>(a);
           LitteralNumerique* c= my_a->operator-(b);
           p.push(c);
        }
        else if(a->getType()=="Atome")
        {
           Atome* my_a =dynamic_cast<Atome*>(a);
           LitteralNumerique* c= my_a->operator-(b);
           p.push(c);
        }

       /*
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
*/

        cout << p;
    }


    else
    {
            throw PileException("Pas Assez d'argument");
    }


}


void Controleur::multiplier()
{
    if(p.taille() >= 2)
    {

        LitteralNumerique* a= p.pop();
        LitteralNumerique* b= p.pop();

        if(a->getType()=="Entier" )
        {
            Entier* my_a =dynamic_cast<Entier*>(a);
            LitteralNumerique* c= my_a->operator*(b);
            p.push(c);
         }
        else if(a->getType()=="Reel")
        {
            Reel* my_a =dynamic_cast<Reel*>(a);
            LitteralNumerique* c= my_a->operator*(b);
            p.push(c);
        }
        else if(a->getType()=="Fraction")
        {
           Fraction* my_a =dynamic_cast<Fraction*>(a);
           LitteralNumerique* c= my_a->operator*(b);
           p.push(c);
        }
        else if(a->getType()=="Atome")
        {
           Atome* my_a =dynamic_cast<Atome*>(a);
           LitteralNumerique* c= my_a->operator*(b);
           p.push(c);
        }

       /*
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
*/

        cout << p;
    }


    else
    {
            throw PileException("Pas Assez d'argument");
    }


}




void Controleur::diviser()
{
    if(p.taille() >= 2)
    {

        LitteralNumerique* a= p.pop();
        LitteralNumerique* b= p.pop();

        if(a->getType()=="Entier" )
        {
            Entier* my_a =dynamic_cast<Entier*>(a);
            LitteralNumerique* c= my_a->operator/(b);
            p.push(c);
         }
        else if(a->getType()=="Reel")
        {
            Reel* my_a =dynamic_cast<Reel*>(a);
            LitteralNumerique* c= my_a->operator/(b);
            p.push(c);
        }
        else if(a->getType()=="Fraction")
        {
           Fraction* my_a =dynamic_cast<Fraction*>(a);
           LitteralNumerique* c= my_a->operator/(b);
           p.push(c);
        }
        else if(a->getType()=="Atome")
        {
           Atome* my_a =dynamic_cast<Atome*>(a);
           LitteralNumerique* c= my_a->operator/(b);
           p.push(c);
        }

 /*
    if((a->getType()=="Entier" ) & (b->getType()=="Entier"))
    {
        Entier* my_a =dynamic_cast<Entier*>(a);
        Entier* my_b =dynamic_cast<Entier*>(b);
        Fraction* c= my_a->operator/(my_b);
        p.push(c);
    }
    else if((a->getType()=="Reel") & (b->getType()=="Reel"))
    {
        Reel* my_a =dynamic_cast<Reel*>(a);
        Reel* my_b =dynamic_cast<Reel*>(b);
        Fraction* c= my_a->operator/(my_b);
        p.push(c);
    }
    else if((a->getType()=="Entier") & (b->getType()=="Reel"))
    {
        Reel* my_a =dynamic_cast<Reel*>(a);
        Reel* my_b =dynamic_cast<Reel*>(b);
        Fraction* c= my_a->operator/(my_b);
        p.push(c);
    }
    else if((a->getType()=="Reel") & (b->getType()=="Entier"))
    {
        Reel* my_a =dynamic_cast<Reel*>(a);
        Reel* my_b =dynamic_cast<Reel*>(b);
        Fraction* c= my_a->operator/(my_b);
        p.push(c);
    }
*/
    cout << p;
    }
    else
    {
        throw PileException("Pas Assez d'argument");
    }


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

void Controleur::contructionchaine2(QString arg1)
{
    chaine =arg1;

}

//NEG

void Controleur::neg()
{
    LitteralNumerique*  a=p.pop();


    if(a->getType()=="Entier" )
    {
        Entier* my_a =dynamic_cast<Entier*>(a);
        p.push(new Entier(- my_a->getEntier()));
    }
    else if(a->getType()=="Reel")
    {
        Reel* my_a =dynamic_cast<Reel*>(a);
        p.push(new Reel(- my_a->getReel()));
    }
    else if(a->getType()=="Fraction")
    {
       Fraction* my_a =dynamic_cast<Fraction*>(a);
       p.push(new Fraction(- my_a->getNumerateur(),my_a->getDenominateur()));
    }
    else if(a->getType()=="Atome")
    {
       Atome* my_a =dynamic_cast<Atome*>(a);
       p.push(new Atome(- my_a->getAtome()));
    }
}

// Complexe

void Controleur::complexe()
{
    LitteralNumerique* a = p.pop();
    LitteralNumerique* b = p.pop();

    if(a->getType()=="Atome" || a->getType()=="Complexe" || b->getType()=="Atome" || b->getType()=="Complexe")
    {
        throw PileException("Erreur création complexe");
        p.push(b);
        p.push(a);
    }
    else
    {
        p.push(new Complexe(a,b));
    }

}
