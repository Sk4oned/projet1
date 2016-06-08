#include <string>
#include <iostream>
#include "controleur.h"
#include <string>
#include <iostream>
#include <sstream>
#include <QString>
#include "numerique.h"
#include "entier.h"
#include "reel.h"
#include "fraction.h"
#include "atome.h"
#include "complexe.h"

Atome::Atome(QString atome, Litteral* var): m_atome(atome), variable(var)
 {

 };

void Atome::affiche(ostream& flux) const
{
    flux << m_atome.toStdString();
}
/*
QString& Atome::affiche(QString& flux) const
{
    return affiche2(flux);
}
*/
QString& Atome::affiche(QString& flux) const
{
    flux+= m_atome;
    flux+= " : ";



    if(variable->getType()== "Entier")
    {
        Entier* my_var = dynamic_cast<Entier*>(variable);
        my_var->affiche(flux);
        return flux;
    }
    else if(variable->getType()== "Reel")
    {
        Reel* my_var = dynamic_cast<Reel*>(variable);
        my_var->affiche(flux);
        return flux;
    }
    else if(variable->getType()== "Fraction")
    {
        Fraction* my_var = dynamic_cast<Fraction*>(variable);
        my_var->affiche(flux);
        return flux;
    }
    else if(variable->getType()== "Complexe")
    {
        Complexe* my_var = dynamic_cast<Complexe*>(variable);
        my_var->affiche(flux);
        return flux;
    }
    else if(variable->getType()== "Atome")
    {
        Atome* my_var = dynamic_cast<Atome*>(variable);
        my_var->getVariable()->affiche(flux);
        return flux;
    }

    return flux="Erreur";

}

ostream& operator<<(ostream& flux,Exp::Atome& m)
{
    m.affiche(flux);

    return flux;
}


LitteralNumerique* Atome::operator+(Litteral* b)
{
    if(b->getType()!="Atome" )
    {
        LitteralNumerique* a =dynamic_cast<LitteralNumerique*>(this->getVariable());

        if(b->getType()=="Entier" )
        {
            Entier* my_b =dynamic_cast<Entier*>(b);
            return my_b->operator +(a);
        }
        else if(b->getType()=="Reel" )
        {
            Reel* my_b =dynamic_cast<Reel*>(b);
            return my_b->operator +(a);
        }
        else if(b->getType()=="Fraction" )
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return my_b->operator +(a);
        }
        else if(b->getType()=="Complexe" )
        {
            Complexe* my_b =dynamic_cast<Complexe*>(b);
            return my_b->operator +(a);
        }
        else if(b->getType()=="Atome" )
        {
            Atome* my_b =dynamic_cast<Atome*>(b);
            return my_b->operator +(a);
        }

    }
    else if(b->getType()=="Atome" )
    {
        Atome* my_b =dynamic_cast<Atome*>(b);
        if(this->isVariableValide() && my_b->isVariableValide())
        {
            LitteralNumerique* a =dynamic_cast<LitteralNumerique*>(this->getVariable());
            if(my_b->getVariable()->getType()=="Entier" )
            {
                Entier* my_b2 =dynamic_cast<Entier*>(my_b->getVariable());
                return my_b2->operator +(a);
            }
            else if(my_b->getVariable()->getType()=="Reel" )
            {
                Reel* my_b2 =dynamic_cast<Reel*>(my_b->getVariable());
                return my_b2->operator +(a);
            }
            else if(my_b->getVariable()->getType()=="Fraction" )
            {
                Fraction* my_b2 =dynamic_cast<Fraction*>(my_b->getVariable());
                return my_b2->operator +(a);
            }
            else if(my_b->getVariable()->getType()=="Complexe" )
            {
                Complexe* my_b2 =dynamic_cast<Complexe*>(my_b->getVariable());
                return my_b2->operator +(a);
            }
            else if(my_b->getVariable()->getType()=="Atome" )
            {
                Atome* my_b2 =dynamic_cast<Atome*>(my_b->getVariable());
                return my_b2->operator +(a);
            }


        }

    }

    return 0;

}


LitteralNumerique* Atome::operator-(Litteral* b)
{
    if(b->getType()!="Atome" )
    {
        LitteralNumerique* a =dynamic_cast<LitteralNumerique*>(this->getVariable());

        if(b->getType()=="Entier" )
        {
            Entier* my_b =dynamic_cast<Entier*>(b);
            return my_b->operator -(a);
        }
        else if(b->getType()=="Reel" )
        {
            Reel* my_b =dynamic_cast<Reel*>(b);
            return my_b->operator -(a);
        }
        else if(b->getType()=="Fraction" )
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return my_b->operator -(a);
        }
        else if(b->getType()=="Complexe" )
        {
            Complexe* my_b =dynamic_cast<Complexe*>(b);
            return my_b->operator -(a);
        }
        else if(b->getType()=="Atome" )
        {
            Atome* my_b =dynamic_cast<Atome*>(b);
            return my_b->operator -(a);
        }

    }
    else if(b->getType()=="Atome" )
    {
        Atome* my_b =dynamic_cast<Atome*>(b);
        if(this->isVariableValide() && my_b->isVariableValide())
        {
            LitteralNumerique* a =dynamic_cast<LitteralNumerique*>(this->getVariable());
            if(my_b->getVariable()->getType()=="Entier" )
            {
                Entier* my_b2 =dynamic_cast<Entier*>(my_b->getVariable());
                return my_b2->operator -(a);
            }
            else if(my_b->getVariable()->getType()=="Reel" )
            {
                Reel* my_b2 =dynamic_cast<Reel*>(my_b->getVariable());
                return my_b2->operator -(a);
            }
            else if(my_b->getVariable()->getType()=="Fraction" )
            {
                Fraction* my_b2 =dynamic_cast<Fraction*>(my_b->getVariable());
                return my_b2->operator -(a);
            }
            else if(my_b->getVariable()->getType()=="Complexe" )
            {
                Complexe* my_b2 =dynamic_cast<Complexe*>(my_b->getVariable());
                return my_b2->operator -(a);
            }
            else if(my_b->getVariable()->getType()=="Atome" )
            {
                Atome* my_b2 =dynamic_cast<Atome*>(my_b->getVariable());
                return my_b2->operator -(a);
            }


        }

    }

    return 0;
}

LitteralNumerique* Atome::operator*(Litteral* b)
{
    if(b->getType()!="Atome" )
    {
        LitteralNumerique* a =dynamic_cast<LitteralNumerique*>(this->getVariable());

        if(b->getType()=="Entier" )
        {
            Entier* my_b =dynamic_cast<Entier*>(b);
            return my_b->operator *(a);
        }
        else if(b->getType()=="Reel" )
        {
            Reel* my_b =dynamic_cast<Reel*>(b);
            return my_b->operator *(a);
        }
        else if(b->getType()=="Fraction" )
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return my_b->operator *(a);
        }
        else if(b->getType()=="Complexe" )
        {
            Complexe* my_b =dynamic_cast<Complexe*>(b);
            return my_b->operator *(a);
        }
        else if(b->getType()=="Atome" )
        {
            Atome* my_b =dynamic_cast<Atome*>(b);
            return my_b->operator *(a);
        }

    }
    else if(b->getType()=="Atome" )
    {
        Atome* my_b =dynamic_cast<Atome*>(b);
        if(this->isVariableValide() && my_b->isVariableValide())
        {
            LitteralNumerique* a =dynamic_cast<LitteralNumerique*>(this->getVariable());
            if(my_b->getVariable()->getType()=="Entier" )
            {
                Entier* my_b2 =dynamic_cast<Entier*>(my_b->getVariable());
                return my_b2->operator *(a);
            }
            else if(my_b->getVariable()->getType()=="Reel" )
            {
                Reel* my_b2 =dynamic_cast<Reel*>(my_b->getVariable());
                return my_b2->operator *(a);
            }
            else if(my_b->getVariable()->getType()=="Fraction" )
            {
                Fraction* my_b2 =dynamic_cast<Fraction*>(my_b->getVariable());
                return my_b2->operator *(a);
            }
            else if(my_b->getVariable()->getType()=="Complexe" )
            {
                Complexe* my_b2 =dynamic_cast<Complexe*>(my_b->getVariable());
                return my_b2->operator *(a);
            }
            else if(my_b->getVariable()->getType()=="Atome" )
            {
                Atome* my_b2 =dynamic_cast<Atome*>(my_b->getVariable());
                return my_b2->operator *(a);
            }


        }

    }

    return 0;
}


LitteralNumerique* Atome::operator/(Litteral* b)
{
    if(b->getType()!="Atome" )
    {
        LitteralNumerique* a =dynamic_cast<LitteralNumerique*>(this->getVariable());

        if(b->getType()=="Entier" )
        {
            Entier* my_b =dynamic_cast<Entier*>(b);
            return my_b->operator /(a);
        }
        else if(b->getType()=="Reel" )
        {
            Reel* my_b =dynamic_cast<Reel*>(b);
            return my_b->operator /(a);
        }
        else if(b->getType()=="Fraction" )
        {
            Fraction* my_b =dynamic_cast<Fraction*>(b);
            return my_b->operator /(a);
        }
        else if(b->getType()=="Complexe" )
        {
            Complexe* my_b =dynamic_cast<Complexe*>(b);
            return my_b->operator /(a);
        }
        else if(b->getType()=="Atome" )
        {
            Atome* my_b =dynamic_cast<Atome*>(b);
            return my_b->operator /(a);
        }

    }
    else if(b->getType()=="Atome" )
    {
        Atome* my_b =dynamic_cast<Atome*>(b);
        if(this->isVariableValide() && my_b->isVariableValide())
        {
            LitteralNumerique* a =dynamic_cast<LitteralNumerique*>(this->getVariable());
            if(my_b->getVariable()->getType()=="Entier" )
            {
                Entier* my_b2 =dynamic_cast<Entier*>(my_b->getVariable());
                return my_b2->operator /(a);
            }
            else if(my_b->getVariable()->getType()=="Reel" )
            {
                Reel* my_b2 =dynamic_cast<Reel*>(my_b->getVariable());
                return my_b2->operator /(a);
            }
            else if(my_b->getVariable()->getType()=="Fraction" )
            {
                Fraction* my_b2 =dynamic_cast<Fraction*>(my_b->getVariable());
                return my_b2->operator /(a);
            }
            else if(my_b->getVariable()->getType()=="Complexe" )
            {
                Complexe* my_b2 =dynamic_cast<Complexe*>(my_b->getVariable());
                return my_b2->operator /(a);
            }
            else if(my_b->getVariable()->getType()=="Atome" )
            {
                Atome* my_b2 =dynamic_cast<Atome*>(my_b->getVariable());
                return my_b2->operator /(a);
            }


        }

    }

    return 0;
}


