#include <QString>
#include <QStringList>
#include <sstream>
#include "controleur.h"
#include "numerique.h"
#include "entier.h"
#include "reel.h"
#include "fraction.h"
#include "atome.h"
#include "complexe.h"
#include "programme.h"
#include "pile.h"
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QFile>


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
    else if(q=="NUM")
    {
        p.push(new Entier(num()));

    }
    else if(q=="DEN")
    {
        p.push(new Entier (den()));
    }
    else if(q=="$")
    {
        complexe();
    }
    else if(q=="RE")
    {
        re();
    }
    else if(q=="IM")
    {
        im();
    }
    else if(q=="DUP")
    {
        dup();
    }
    else if(q=="DROP")
    {
        drop();
    }
    else if(q=="SWAP")
    {
        swap();
    }
    else if(q=="CLEAR")
    {
        clear();
    }
    else if(q=="EDIT")
    {

    }
    else if(q.contains('.'))
    {
        float b;
        int b2;
        //istringstream
        b=q.toFloat();
        b2=b;
        if (b-b2==0)
        {
            Entier* v = new Entier(b2);
            p.push(v);
        }
        else
        {
            Reel* v = new Reel(b);
            p.push(v);
        }
    }
    else if(q.contains('/'))
    {
        QStringList l;
        l=q.split("/");
        Entier* l1= new Entier(l[0].toInt());
        Entier* l2= new Entier(l[1].toInt());
        p.push(l1);
        p.push(l2);
        diviser();
    }
    else if(q.contains(" "))
    {
        QStringList l;
        l=q.split(" ");

            if(l[1].contains('.'))
                {
                    float b;
                    int b2;
                    //istringstream
                    b=l[1].toFloat();
                    b2=b;
                    if (b-b2==0)
                    {
                        Entier* v = new Entier(b2);
                        p.push(v);
                    }
                    else
                    {
                        Reel* v = new Reel(b);
                        p.push(v);
                    }

                }
                else if(l[1].contains('/'))
                {
                    QStringList m;
                    m=l[1].split("/");
                    Entier* m1= new Entier(m[0].toInt());
                    Entier* m2= new Entier(m[1].toInt());
                    p.push(m1);
                    p.push(m2);
                    diviser();
                }
                else
                {
                            int c;
                            //istringstream
                            c=l[1].toInt();
                            Entier* v = new Entier(c);
                            p.push(v);

                }

            if(l[0].isSimpleText())
            {

                Litteral* data=p.pop();
                Atome* at= new Atome(l[0], data);
                p.push(at);

            }

    }
    else
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
    if(p.taille() >= 2)
    {

        Litteral* a= p.pop();
        Litteral* b= p.pop();

if(b->getType()=="Entier" ||b->getType()=="Fraction" ||b->getType()=="Reel" ||b->getType()=="Complexe" )
{
        LitteralNumerique* my_b =dynamic_cast<LitteralNumerique*>(b);
        if(a->getType()=="Entier" )
        {
            Entier* my_a =dynamic_cast<Entier*>(a);
            LitteralNumerique* c= my_a->operator+(my_b);
            p.push(c);
         }
        else if(a->getType()=="Reel")
        {
            Reel* my_a =dynamic_cast<Reel*>(a);
            LitteralNumerique* c= my_a->operator+(my_b);
            p.push(c);
        }
        else if(a->getType()=="Fraction")
        {
           Fraction* my_a =dynamic_cast<Fraction*>(a);
           LitteralNumerique* c= my_a->operator+(my_b);
           p.push(c);
        }
        else if(a->getType()=="Atome")
        {
           Atome* my_a =dynamic_cast<Atome*>(a);
           LitteralNumerique* c= my_a->operator +(my_b);
           p.push(c);
        }
        else if(a->getType()=="Complexe")
        {
           Complexe* my_a =dynamic_cast<Complexe*>(a);
           LitteralNumerique* c= my_a->operator+(my_b);
           p.push(c);
        }
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

        Litteral* a= p.pop();
        Litteral* b= p.pop();

 if(b->getType()=="Entier" ||b->getType()=="Fraction" ||b->getType()=="Reel" ||b->getType()=="Complexe" )
{
        LitteralNumerique* my_b =dynamic_cast<LitteralNumerique*>(b);

        if(a->getType()=="Entier" )
        {
            Entier* my_a =dynamic_cast<Entier*>(a);
            LitteralNumerique* c= my_a->operator-(my_b);
            p.push(c);
         }
        else if(a->getType()=="Reel")
        {
            Reel* my_a =dynamic_cast<Reel*>(a);
            LitteralNumerique* c= my_a->operator-(my_b);
            p.push(c);
        }
        else if(a->getType()=="Fraction")
        {
           Fraction* my_a =dynamic_cast<Fraction*>(a);
           LitteralNumerique* c= my_a->operator-(my_b);
           p.push(c);
        }
        /*else if(a->getType()=="Atome")
        {
           Atome* my_a =dynamic_cast<Atome*>(a);
           Entier* my_a2 =dynamic_cast<Entier*>(my_a->getVariable());
           LitteralNumerique* c= my_a2->getEntier()->operator-(my_b);
           p.push(c);
        }*/
        else if(a->getType()=="Complexe")
        {
          Complexe* my_a =dynamic_cast<Complexe*>(a);
          LitteralNumerique* c= my_a->operator-(my_b);
          p.push(c);
        }

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

        Litteral* a= p.pop();
        Litteral* b= p.pop();

if(b->getType()=="Entier" ||b->getType()=="Fraction" ||b->getType()=="Reel" ||b->getType()=="Complexe" )
{
        LitteralNumerique* my_b =dynamic_cast<LitteralNumerique*>(b);

        if(a->getType()=="Entier" )
        {
            Entier* my_a =dynamic_cast<Entier*>(a);
            LitteralNumerique* c= my_a->operator*(my_b);
            p.push(c);
         }
        else if(a->getType()=="Reel")
        {
            Reel* my_a =dynamic_cast<Reel*>(a);
            LitteralNumerique* c= my_a->operator*(my_b);
            p.push(c);
        }
        else if(a->getType()=="Fraction")
        {
           Fraction* my_a =dynamic_cast<Fraction*>(a);
           LitteralNumerique* c= my_a->operator*(my_b);
           p.push(c);
        }
       /* else if(a->getType()=="Atome")
        {
           Atome* my_a =dynamic_cast<Atome*>(a);
           LitteralNumerique* c= my_a->getVariable()->operator*(my_b);
           p.push(c);
        }
*/
        else if(a->getType()=="Complexe")
        {
          Complexe* my_a =dynamic_cast<Complexe*>(a);
          LitteralNumerique* c= my_a->operator*(my_b);
          p.push(c);
        }
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

        Litteral* a= p.pop();
        Litteral* b= p.pop();

if(b->getType()=="Entier" ||b->getType()=="Fraction" ||b->getType()=="Reel" ||b->getType()=="Complexe" )
{
        LitteralNumerique* my_b =dynamic_cast<LitteralNumerique*>(b);

        if(a->getType()=="Entier" )
        {
            Entier* my_a =dynamic_cast<Entier*>(a);
            LitteralNumerique* c= my_a->operator/(my_b);
            p.push(c);
         }
        else if(a->getType()=="Reel")
        {
            Reel* my_a =dynamic_cast<Reel*>(a);
            LitteralNumerique* c= my_a->operator/(my_b);
            p.push(c);
        }
        else if(a->getType()=="Fraction")
        {
           Fraction* my_a =dynamic_cast<Fraction*>(a);
           LitteralNumerique* c= my_a->operator/(my_b);
           p.push(c);
        }/*
        else if(a->getType()=="Atome")
        {
           Atome* my_a =dynamic_cast<Atome*>(a);
           LitteralNumerique* c= my_a->getVariable()->operator/(my_b);
           p.push(c);
        }*/

        else if(a->getType()=="Complexe")
        {
          Complexe* my_a =dynamic_cast<Complexe*>(a);
          LitteralNumerique* c= my_a->operator/(my_b);
          p.push(c);
        }
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
    Litteral*  a=p.pop();


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
  /*  else if(a->getType()=="Atome")
    {
       Atome* my_a =dynamic_cast<Atome*>(a);
       p.push(new Atome(my_a->getAtome(),((Entier(-1)).operator*(my_a->getVariable()))));
    }*/
}


//NUM

int Controleur::num()
{
    Litteral*  a=p.pop();


    if(a->getType()=="Entier" )
    {
        Entier* my_a =dynamic_cast<Entier*>(a);
        p.push(my_a);
        return my_a->getEntier();
    }
    else if(a->getType()=="Reel")
    {
        throw PileException("Erreur NUM ne peut pas etre utilise sur un Reel");
    }
    else if(a->getType()=="Fraction")
    {
       Fraction* my_a =dynamic_cast<Fraction*>(a);
       p.push(my_a);
       return my_a->getNumerateur();
    }
    else if(a->getType()=="Atome")
    {
       throw PileException("Erreur NUM ne peut pas etre utilise sur un Atome");
    }

    return 0;

}

//DEN

int Controleur::den()
{
    Litteral*  a=p.pop();


    if(a->getType()=="Entier" )
    {
        return 1;
    }
    else if(a->getType()=="Reel")
    {
        throw PileException("Erreur DEN ne peut pas etre utilise sur un Reel");
    }
    else if(a->getType()=="Fraction")
    {
       Fraction* my_a =dynamic_cast<Fraction*>(a);
       p.push(my_a);
       return my_a->getDenominateur();
    }
    else if(a->getType()=="Atome")
    {
       throw PileException("Erreur DEN ne peut pas etre utilise sur un Atome");
    }

    return 0;
}


int Controleur::re()
{
    Litteral*  a=p.pop();


    if(a->getType()=="Entier" )
    {
        Entier* my_a =dynamic_cast<Entier*>(a);
        p.push(my_a);
        return my_a->getEntier();
    }
    else if(a->getType()=="Reel")
    {
        Reel* my_a =dynamic_cast<Reel*>(a);
        p.push(my_a);
        return my_a->getReel();
    }
    else if(a->getType()=="Fraction")
    {
       Fraction* my_a =dynamic_cast<Fraction*>(a);
       p.push(my_a);
       return my_a->getNumerateur();
    }
    else if(a->getType()=="Atome")
    {
       throw PileException("Erreur RE ne peut pas etre utilise sur un Atome");
    }
    else if(a->getType()=="Complexe")
    {
       throw PileException("Erreur RE ne peut pas etre utilise sur un Complexe");
    }

    return 0;
}

void Controleur::im()
{

}

void Controleur::dup()
{
    Litteral*  a=p.pop();

    if(a->getType()=="Entier" )
    {
        Entier* my_a =dynamic_cast<Entier*>(a);
        p.push(my_a);
        p.push(new Entier(my_a->getEntier()));
    }
    else if(a->getType()=="Reel")
    {
        Reel* my_a =dynamic_cast<Reel*>(a);
        p.push(my_a);
        p.push(new Entier(my_a->getReel()));
    }
    else if(a->getType()=="Fraction")
    {
       Fraction* my_a =dynamic_cast<Fraction*>(a);
       p.push(my_a);
       p.push(new Fraction(my_a->getNumerateur(),my_a->getDenominateur()));
    }
  /*  else if(a->getType()=="Atome")
    {
        Atome* my_a =dynamic_cast<Atome*>(a);
        p.push(my_a);
        p.push(new Atome(my_a->getAtome(),my_a->getVariable(),my_a->getProgramme()));
    }
  */  else if(a->getType()=="Complexe")
    {
       throw PileException("Erreur RE ne peut pas etre utilise sur un Complexe");
    }
}

void Controleur::drop()
{
    p.pop();
}

void Controleur::swap()
{
    Litteral*  a=p.pop();
    Litteral*  b=p.pop();

    p.push(a);
    p.push(b);
}

void Controleur::clear()
{
    for(int i=0; i<p.taille();i++)
    {
        p.pop();
    }

}

void Controleur::edit()
{

}

// Complexe

void Controleur::complexe()
{
    if(p.taille() >= 2) {
    Litteral* a = p.pop();
    Litteral* b = p.pop();

    if(a->getType()=="Atome" || a->getType()=="Complexe" || b->getType()=="Atome" || b->getType()=="Complexe")
    {
        throw PileException("Erreur création complexe");
        p.push(b);
        p.push(a);
    }
    else
    {
        LitteralNumerique* my_a= dynamic_cast<LitteralNumerique*>(a);
        LitteralNumerique* my_b= dynamic_cast<LitteralNumerique*>(b);
        p.push(new Complexe(my_b,my_a));
    }
    }

    else
    {
            throw PileException("Pas Assez d'argument");
    }


}



void Controleur::enregistrePile()
{
    QString fileName = "D:/Documents/LO21/projet1/sauvegarde.xml";
    QFile fileXml(fileName);

    if(!fileXml.open(QFile::WriteOnly | QFile::Text))
        throw PileException("Erreur fichier XML");
    QXmlStreamWriter writer(&fileXml);

       // Active l'indentation automatique du fichier XML pour une meilleur visibilité
       writer.setAutoFormatting(true);

       // Insert la norme de codification du fichier XML :
       writer.writeStartDocument();



       writer.writeTextElement("Pile",p.affiche());


       // Finalise le document XML
       writer.writeEndDocument();

       // Fermer le fichier pour bien enregistrer le document et ferme l'élément root
       fileXml.close();


}

void Controleur::chargePile()
{



}

void Controleur::ChangeNombrePileAffiche(int n)
{

    p.setNbItemsToAffiche(n);

}



