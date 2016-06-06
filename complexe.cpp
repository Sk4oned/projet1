#include <string>
#include <iostream>
#include "controleur.h"
#include <sstream>
#include <QString>
#include "expression.h"
#include "entier.h"
#include "reel.h"
#include "fraction.h"
#include "atome.h"
#include "complexe.h"

using namespace std;
using namespace Exp;

Complexe::Complexe(LitteralNumerique* a, LitteralNumerique* b)
{
    p_reelle=a;
    p_imaginaire=b;
};


ostream& operator<<(ostream& flux,Exp::Complexe& m)
{
    m.affiche(flux);

    return flux;
}

void Complexe::affiche(ostream& flux)const
{


    if(p_reelle->getType()=="Entier" && p_imaginaire->getType()=="Entier" )
    {
        Entier* my_a =dynamic_cast<Entier*>(p_reelle);
        Entier* my_b =dynamic_cast<Entier*>(p_imaginaire);

        flux << my_a << "$" <<  my_b;

    }
    else if(p_reelle->getType()=="Entier" && p_imaginaire->getType()=="Reel")
    {
        Entier* my_a =dynamic_cast<Entier*>(p_reelle);
        Reel* my_b =dynamic_cast<Reel*>(p_imaginaire);


        flux << my_a << "$" <<  my_b;
    }
    else if(p_reelle->getType()=="Entier" && p_imaginaire->getType()=="Fraction")
    {
       Entier* my_a =dynamic_cast<Entier*>(p_reelle);
       Fraction* my_b =dynamic_cast<Fraction*>(p_imaginaire);

       flux << my_a << "$" <<  my_b;
    }
    else if(p_reelle->getType()=="Reel" && p_imaginaire->getType()=="Entier" )
    {
        Reel* my_a =dynamic_cast<Reel*>(p_reelle);
        Entier* my_b =dynamic_cast<Entier*>(p_imaginaire);

        flux << my_a << "$" <<  my_b;
    }
    else if(p_reelle->getType()=="Reel" && p_imaginaire->getType()=="Reel")
    {
        Reel* my_a =dynamic_cast<Reel*>(p_reelle);
        Reel* my_b =dynamic_cast<Reel*>(p_imaginaire);

        flux << my_a << "$" <<  my_b;
    }
    else if(p_reelle->getType()=="Reel" && p_imaginaire->getType()=="Fraction")
    {
       Reel* my_a =dynamic_cast<Reel*>(p_reelle);
       Fraction* my_b =dynamic_cast<Fraction*>(p_imaginaire);

       flux << my_a << "$" <<  my_b;
    }
    else if(p_reelle->getType()=="Fraction" && p_imaginaire->getType()=="Entier" )
    {
        Fraction* my_a =dynamic_cast<Fraction*>(p_reelle);
        Entier* my_b =dynamic_cast<Entier*>(p_imaginaire);

        flux << my_a << "$" <<  my_b;
    }
    else if(p_reelle->getType()=="Fraction" && p_imaginaire->getType()=="Reel")
    {
        Fraction* my_a =dynamic_cast<Fraction*>(p_reelle);
        Reel* my_b =dynamic_cast<Reel*>(p_imaginaire);

        flux << my_a << "$" <<  my_b;
    }
    else if(p_reelle->getType()=="Fraction" && p_imaginaire->getType()=="Fraction")
    {
        Fraction* my_a =dynamic_cast<Fraction*>(p_reelle);
        Fraction* my_b =dynamic_cast<Fraction*>(p_imaginaire);

        flux << my_a << "$" <<  my_b;
    }
}



QString& Complexe::affiche(QString& flux) const
{
    QString a;
    QString b;

    if(p_reelle->getType()=="Entier" && p_imaginaire->getType()=="Entier" )
    {
        Entier* my_a =dynamic_cast<Entier*>(p_reelle);
        Entier* my_b =dynamic_cast<Entier*>(p_imaginaire);

        flux+= my_a->affiche(a) + QString::fromStdString("$") +  my_b->affiche(b);
        return flux;
    }
    else if(p_reelle->getType()=="Entier" && p_imaginaire->getType()=="Reel")
    {
        Entier* my_a =dynamic_cast<Entier*>(p_reelle);
        Reel* my_b =dynamic_cast<Reel*>(p_imaginaire);


        flux+= my_a->affiche(a) + QString::fromStdString("$") +  my_b->affiche(b);
        return flux;
    }
    else if(p_reelle->getType()=="Entier" && p_imaginaire->getType()=="Fraction")
    {
       Entier* my_a =dynamic_cast<Entier*>(p_reelle);
       Fraction* my_b =dynamic_cast<Fraction*>(p_imaginaire);

       flux+= my_a->affiche(a) + QString::fromStdString("$") +  my_b->affiche(b);
       return flux;
    }
    else if(p_reelle->getType()=="Reel" && p_imaginaire->getType()=="Entier" )
    {
        Reel* my_a =dynamic_cast<Reel*>(p_reelle);
        Entier* my_b =dynamic_cast<Entier*>(p_imaginaire);

        flux+= my_a->affiche(a) + QString::fromStdString("$") +  my_b->affiche(b);
        return flux;
    }
    else if(p_reelle->getType()=="Reel" && p_imaginaire->getType()=="Reel")
    {
        Reel* my_a =dynamic_cast<Reel*>(p_reelle);
        Reel* my_b =dynamic_cast<Reel*>(p_imaginaire);

        flux+= my_a->affiche(a) + QString::fromStdString("$") +  my_b->affiche(b);
        return flux;
    }
    else if(p_reelle->getType()=="Reel" && p_imaginaire->getType()=="Fraction")
    {
       Reel* my_a =dynamic_cast<Reel*>(p_reelle);
       Fraction* my_b =dynamic_cast<Fraction*>(p_imaginaire);

       flux+= my_a->affiche(a) + QString::fromStdString("$") +  my_b->affiche(b);
       return flux;
    }
    else if(p_reelle->getType()=="Fraction" && p_imaginaire->getType()=="Entier" )
    {
        Fraction* my_a =dynamic_cast<Fraction*>(p_reelle);
        Entier* my_b =dynamic_cast<Entier*>(p_imaginaire);

        flux+= my_a->affiche(a) + QString::fromStdString("$") +  my_b->affiche(b);
        return flux;
    }
    else if(p_reelle->getType()=="Fraction" && p_imaginaire->getType()=="Reel")
    {
        Fraction* my_a =dynamic_cast<Fraction*>(p_reelle);
        Reel* my_b =dynamic_cast<Reel*>(p_imaginaire);

        flux+= my_a->affiche(a) + QString::fromStdString("$") +  my_b->affiche(b);
        return flux;
    }
    else if(p_reelle->getType()=="Fraction" && p_imaginaire->getType()=="Fraction")
    {
        Fraction* my_a =dynamic_cast<Fraction*>(p_reelle);
        Fraction* my_b =dynamic_cast<Fraction*>(p_imaginaire);

        flux+= my_a->affiche(a) + QString::fromStdString("$") +  my_b->affiche(b);
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
        else if(b->getType()=="Fraction" )
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return (new Complexe(my_p_reelle->operator+(my_b),my_p_imaginaire));
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
        else if(b->getType()=="Fraction" )
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return (new Complexe(my_p_reelle->operator+(my_b),my_p_imaginaire));
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
       else if(b->getType()=="Fraction" )
       {
           Fraction* my_b =dynamic_cast<Fraction*>(b);
           return (new Complexe(my_p_reelle->operator+(my_b),my_p_imaginaire));
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
        else if(b->getType()=="Fraction" )
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return (new Complexe(my_p_reelle->operator+(my_b),my_p_imaginaire));
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
        else if(b->getType()=="Fraction" )
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return (new Complexe(my_p_reelle->operator+(my_b),my_p_imaginaire));
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
       else if(b->getType()=="Fraction" )
       {
           Fraction* my_b =dynamic_cast<Fraction*>(b);
           return (new Complexe(my_p_reelle->operator+(my_b),my_p_imaginaire));
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
        else if(b->getType()=="Fraction" )
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return (new Complexe(my_p_reelle->operator+(my_b),my_p_imaginaire));
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
        else if(b->getType()=="Fraction" )
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return (new Complexe(my_p_reelle->operator+(my_b),my_p_imaginaire));
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
        else if(b->getType()=="Fraction" )
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return (new Complexe(my_p_reelle->operator+(my_b),my_p_imaginaire));
        }
        else if(b->getType()=="Atome" ) //WTF is atom
        {
            Atome* my_b =dynamic_cast<Atome*>(b);
            return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
        }


    }

    return 0;

 }

//COMPLEXE OPERATOR -



LitteralNumerique* Complexe::operator-(LitteralNumerique* b)
{

    if(b->getType()=="Complexe" )
    {
        Complexe* my_b =dynamic_cast<Complexe*>(b);
        return (new Complexe(p_reelle->operator-(my_b->p_reelle),p_imaginaire->operator-(my_b->p_imaginaire)));
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
            return (new Complexe(my_b->operator-(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Fraction" )
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return (new Complexe(my_p_reelle->operator-(my_b),my_p_imaginaire));
        }
        else if(b->getType()=="Atome" ) //WTF is atom
        {
            Atome* my_b =dynamic_cast<Atome*>(b);
            return (new Complexe(my_b->operator-(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Atome" ) //WTF is atom
        {
            Atome* my_b =dynamic_cast<Atome*>(b);
            return (new Complexe(my_b->operator-(my_p_reelle),my_p_imaginaire));
        }

    }
    else if(p_reelle->getType()=="Entier" && p_imaginaire->getType()=="Reel")
    {
        Entier* my_p_reelle =dynamic_cast<Entier*>(p_reelle);
        Reel* my_p_imaginaire =dynamic_cast<Reel*>(p_imaginaire);


        if(b->getType()=="Entier" )
        {
            Entier* my_b =dynamic_cast<Entier*>(b);
            return (new Complexe(my_b->operator-(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Reel" )
        {
            Reel* my_b =dynamic_cast<Reel*>(b);
            return (new Complexe(my_b->operator-(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Fraction" )
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return (new Complexe(my_p_reelle->operator-(my_b),my_p_imaginaire));
        }
        else if(b->getType()=="Atome" ) //WTF is atom
        {
            Atome* my_b =dynamic_cast<Atome*>(b);
            return (new Complexe(my_b->operator-(my_p_reelle),my_p_imaginaire));
        }



    }
    else if(p_reelle->getType()=="Entier" && p_imaginaire->getType()=="Fraction")
    {
       Entier* my_p_reelle =dynamic_cast<Entier*>(p_reelle);
       Fraction* my_p_imaginaire =dynamic_cast<Fraction*>(p_imaginaire);


       if(b->getType()=="Entier" )
       {
           Entier* my_b =dynamic_cast<Entier*>(b);
           return (new Complexe(my_b->operator-(my_p_reelle),my_p_imaginaire));
       }
       else if(b->getType()=="Reel" )
       {
           Reel* my_b =dynamic_cast<Reel*>(b);
           return (new Complexe(my_b->operator-(my_p_reelle),my_p_imaginaire));
       }
       else if(b->getType()=="Fraction" )
       {
           Fraction* my_b =dynamic_cast<Fraction*>(b);
           return (new Complexe(my_p_reelle->operator-(my_b),my_p_imaginaire));
       }
       else if(b->getType()=="Atome" ) //WTF is atom
       {
           Atome* my_b =dynamic_cast<Atome*>(b);
           return (new Complexe(my_b->operator-(my_p_reelle),my_p_imaginaire));
       }


    }
    else if(p_reelle->getType()=="Reel" && p_imaginaire->getType()=="Entier" )
    {
        Reel* my_p_reelle =dynamic_cast<Reel*>(p_reelle);
        Entier* my_p_imaginaire =dynamic_cast<Entier*>(p_imaginaire);


        if(b->getType()=="Entier" )
        {
            Entier* my_b =dynamic_cast<Entier*>(b);
            return (new Complexe(my_b->operator-(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Reel" )
        {
            Reel* my_b =dynamic_cast<Reel*>(b);
            return (new Complexe(my_b->operator-(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Fraction" )
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return (new Complexe(my_p_reelle->operator-(my_b),my_p_imaginaire));
        }
        else if(b->getType()=="Atome" ) //WTF is atom
        {
            Atome* my_b =dynamic_cast<Atome*>(b);
            return (new Complexe(my_b->operator-(my_p_reelle),my_p_imaginaire));
        }


    }
    else if(p_reelle->getType()=="Reel" && p_imaginaire->getType()=="Reel")
    {
        Reel* my_p_reelle =dynamic_cast<Reel*>(p_reelle);
        Reel* my_p_imaginaire =dynamic_cast<Reel*>(p_imaginaire);


        if(b->getType()=="Entier" )
        {
            Entier* my_b =dynamic_cast<Entier*>(b);
            return (new Complexe(my_b->operator-(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Reel" )
        {
            Reel* my_b =dynamic_cast<Reel*>(b);
            return (new Complexe(my_b->operator-(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Fraction" )
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return (new Complexe(my_p_reelle->operator-(my_b),my_p_imaginaire));
        }
        else if(b->getType()=="Atome" ) //WTF is atom
        {
            Atome* my_b =dynamic_cast<Atome*>(b);
            return (new Complexe(my_b->operator-(my_p_reelle),my_p_imaginaire));
        }


    }
    else if(p_reelle->getType()=="Reel" && p_imaginaire->getType()=="Fraction")
    {
       Reel* my_p_reelle =dynamic_cast<Reel*>(p_reelle);
       Fraction* my_p_imaginaire =dynamic_cast<Fraction*>(p_imaginaire);

       if(b->getType()=="Entier" )
       {
           Entier* my_b =dynamic_cast<Entier*>(b);
           return (new Complexe(my_b->operator-(my_p_reelle),my_p_imaginaire));
       }
       else if(b->getType()=="Reel" )
       {
           Reel* my_b =dynamic_cast<Reel*>(b);
           return (new Complexe(my_b->operator-(my_p_reelle),my_p_imaginaire));
       }
       else if(b->getType()=="Fraction" )
       {
           Fraction* my_b =dynamic_cast<Fraction*>(b);
           return (new Complexe(my_p_reelle->operator-(my_b),my_p_imaginaire));
       }
       else if(b->getType()=="Atome" ) //WTF is atom
       {
           Atome* my_b =dynamic_cast<Atome*>(b);
           return (new Complexe(my_b->operator-(my_p_reelle),my_p_imaginaire));
       }


    }
    else if(p_reelle->getType()=="Fraction" && p_imaginaire->getType()=="Entier" )
    {
        Fraction* my_p_reelle =dynamic_cast<Fraction*>(p_reelle);
        Entier* my_p_imaginaire =dynamic_cast<Entier*>(p_imaginaire);


        if(b->getType()=="Entier" )
        {
            Entier* my_b =dynamic_cast<Entier*>(b);
            return (new Complexe(my_b->operator-(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Reel" )
        {
            Reel* my_b =dynamic_cast<Reel*>(b);
            return (new Complexe(my_b->operator-(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Fraction" )
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return (new Complexe(my_p_reelle->operator-(my_b),my_p_imaginaire));
        }
        else if(b->getType()=="Atome" ) //WTF is atom
        {
            Atome* my_b =dynamic_cast<Atome*>(b);
            return (new Complexe(my_b->operator-(my_p_reelle),my_p_imaginaire));
        }


    }
    else if(p_reelle->getType()=="Fraction" && p_imaginaire->getType()=="Reel")
    {
        Fraction* my_p_reelle =dynamic_cast<Fraction*>(p_reelle);
        Reel* my_p_imaginaire =dynamic_cast<Reel*>(p_imaginaire);


        if(b->getType()=="Entier" )
        {
            Entier* my_b =dynamic_cast<Entier*>(b);
            return (new Complexe(my_b->operator-(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Reel" )
        {
            Reel* my_b =dynamic_cast<Reel*>(b);
            return (new Complexe(my_b->operator-(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Fraction" )
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return (new Complexe(my_p_reelle->operator-(my_b),my_p_imaginaire));
        }
        else if(b->getType()=="Atome" ) //WTF is atom
        {
            Atome* my_b =dynamic_cast<Atome*>(b);
            return (new Complexe(my_b->operator-(my_p_reelle),my_p_imaginaire));
        }


    }
    else if(p_reelle->getType()=="Fraction" && p_imaginaire->getType()=="Fraction")
    {
        Fraction* my_p_reelle =dynamic_cast<Fraction*>(p_reelle);
        Fraction* my_p_imaginaire =dynamic_cast<Fraction*>(p_imaginaire);


        if(b->getType()=="Entier" )
        {
            Entier* my_b =dynamic_cast<Entier*>(b);
            return (new Complexe(my_b->operator-(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Reel" )
        {
            Reel* my_b =dynamic_cast<Reel*>(b);
            return (new Complexe(my_b->operator-(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Fraction" )
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return (new Complexe(my_p_reelle->operator-(my_b),my_p_imaginaire));
        }
        else if(b->getType()=="Atome" ) //WTF is atom
        {
            Atome* my_b =dynamic_cast<Atome*>(b);
            return (new Complexe(my_b->operator-(my_p_reelle),my_p_imaginaire));
        }


    }

    return 0;

 }



//COMPLEXE OPERATOR *



LitteralNumerique* Complexe::operator*(LitteralNumerique* b)
{

    if(b->getType()=="Complexe" )
    {
        Complexe* my_b =dynamic_cast<Complexe*>(b);
        return (new Complexe(my_b->p_reelle->operator*(p_reelle),my_b->p_imaginaire->operator*(p_imaginaire)));
    }
    else if(p_reelle->getType()=="Entier" && p_imaginaire->getType()=="Entier" )
    {
        Entier* my_p_reelle =dynamic_cast<Entier*>(p_reelle);
        Entier* my_p_imaginaire =dynamic_cast<Entier*>(p_imaginaire);

        if(b->getType()=="Entier" )
        {
            Entier* my_b =dynamic_cast<Entier*>(b);
            return (new Complexe(my_b->operator*(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Reel" )
        {
            Reel* my_b =dynamic_cast<Reel*>(b);
            return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
        }
        else if(b->getType()=="Fraction" )
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return (new Complexe(my_p_reelle->operator+(my_b),my_p_imaginaire));
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
        else if(b->getType()=="Fraction" )
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return (new Complexe(my_p_reelle->operator+(my_b),my_p_imaginaire));
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
       else if(b->getType()=="Fraction" )
       {
           Fraction* my_b =dynamic_cast<Fraction*>(b);
           return (new Complexe(my_p_reelle->operator+(my_b),my_p_imaginaire));
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
        else if(b->getType()=="Fraction" )
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return (new Complexe(my_p_reelle->operator+(my_b),my_p_imaginaire));
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
        else if(b->getType()=="Fraction" )
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return (new Complexe(my_p_reelle->operator+(my_b),my_p_imaginaire));
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
       else if(b->getType()=="Fraction" )
       {
           Fraction* my_b =dynamic_cast<Fraction*>(b);
           return (new Complexe(my_p_reelle->operator+(my_b),my_p_imaginaire));
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
        else if(b->getType()=="Fraction" )
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return (new Complexe(my_p_reelle->operator+(my_b),my_p_imaginaire));
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
        else if(b->getType()=="Fraction" )
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return (new Complexe(my_p_reelle->operator+(my_b),my_p_imaginaire));
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
        else if(b->getType()=="Fraction" )
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return (new Complexe(my_p_reelle->operator+(my_b),my_p_imaginaire));
        }
        else if(b->getType()=="Atome" ) //WTF is atom
        {
            Atome* my_b =dynamic_cast<Atome*>(b);
            return (new Complexe(my_b->operator+(my_p_reelle),my_p_imaginaire));
        }


    }

    return 0;

 }


LitteralNumerique* Complexe::operator/(LitteralNumerique* b)
{
    return b;
}

