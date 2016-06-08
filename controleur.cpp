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
#include <vector>
#include <iterator>

using namespace Exp;


void Controleur::checkString()
{
        QString q= chaine;
        chaine="";


    if(q[0]=='+')
    {
        plus();
    }
    else if(q[0]=='[')
    {
        LitteralProgramme* v = new LitteralProgramme(q);
        p.push(v);
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
    else if(q=="EVAL")
    {
        evaluer();
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
    else if(q.contains("STO"))
    {
        QStringList l;
        l=q.split(" ");

        if(l[0].contains('.'))
            {
                float b;
                //istringstream
                b=l[0].toFloat();
                Reel* v = new Reel(b);
                Atome* at= new Atome(l[1], v);
                ajouterVariable(at);
            }
            else if(l[0].contains('/'))
            {
                QStringList m;
                m=l[0].split("/");
                Entier* m1= new Entier(m[0].toInt());
                Entier* m2= new Entier(m[1].toInt());
                p.push(m1);
                p.push(m2);
                diviser();
                Atome* at= new Atome(l[1], p.pop());
                ajouterVariable(at);
            }
            else
            {
                        int c;
                        //istringstream
                        c=l[0].toInt();
                        Entier* v = new Entier(c);
                        Atome* at= new Atome(l[1], v);
                        ajouterVariable(at);

            }



    }
    else if(q.isSimpleText())
    {
        QString a("");
        int j=0;

                    if(q.contains('.'))
                    {
                        float b;
                        //istringstream
                        b=q.toFloat();

                        Reel* v = new Reel(b);
                        p.push(v);
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
                     else if(q != "")
                     {
                           int c;
                           //istringstream
                           c=q.toInt();

                           if(q=="0")
                           {
                               Entier* v = new Entier(0);
                               p.push(v);
                           }
                           else
                           {
                               if(c!=0)
                               {
                               Entier* v = new Entier(c);
                               p.push(v);
                               }

                            }

                        }


        for(unsigned int i=0; i< variable.size(); i++)
        {
            Atome* my_var =dynamic_cast<Atome*>(variable[j]);
            j++;
            if( q == my_var->getAtome() )
            {
                p.push(my_var);
            }
            else
            {
                p.push(new Atome(q));
            }

        }


    }
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
               if(my_a->isVariableValide())
               {
                   LitteralNumerique* my_a2 =dynamic_cast<LitteralNumerique*>(my_a->getVariable());
                   LitteralNumerique* c= my_a2->operator +(my_b);
                   p.push(c);
               }

            }
            else if(a->getType()=="Complexe")
            {
               Complexe* my_a =dynamic_cast<Complexe*>(a);
               LitteralNumerique* c= my_a->operator+(my_b);
               p.push(c);
            }
         }
        else if(b->getType()=="Atome")
        {
            Atome* my_b =dynamic_cast<Atome*>(b);
            LitteralNumerique* c= my_b->operator +(a);
            p.push(c);
        }

        cout << p;

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
                else if(a->getType()=="Atome")
                {
                   Atome* my_a =dynamic_cast<Atome*>(a);
                   if(my_a->isVariableValide())
                   {
                       LitteralNumerique* my_a2 =dynamic_cast<LitteralNumerique*>(my_a->getVariable());
                       LitteralNumerique* c= my_a2->operator -(my_b);
                       p.push(c);
                   }

                }
                else if(a->getType()=="Complexe")
                {
                  Complexe* my_a =dynamic_cast<Complexe*>(a);
                  LitteralNumerique* c= my_a->operator-(my_b);
                  p.push(c);
                }
         }
         else if(b->getType()=="Atome")
         {
            Atome* my_b =dynamic_cast<Atome*>(b);
             LitteralNumerique* c= my_b->operator +(a);
            p.push(c);
         }



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
                else if(a->getType()=="Atome")
                {
                    Atome* my_a =dynamic_cast<Atome*>(a);
                    if(my_a->isVariableValide())
                    {

                        LitteralNumerique* my_a2 =dynamic_cast<LitteralNumerique*>(my_a->getVariable());
                        LitteralNumerique* c= my_b->operator *(my_a2);
                        p.push(c);
                    }
                }
        }
        else if(b->getType()=="Atome")
        {
           Atome* my_b =dynamic_cast<Atome*>(b);
            LitteralNumerique* c= my_b->operator +(a);
           p.push(c);
        }

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
                }
                else if(a->getType()=="Atome")
                {
                    Atome* my_a =dynamic_cast<Atome*>(a);
                    if(my_a->isVariableValide())
                    {

                        LitteralNumerique* my_a2 =dynamic_cast<LitteralNumerique*>(my_a->getVariable());
                        LitteralNumerique* c= my_b->operator *(my_a2);
                        p.push(c);
                    }
                }
        }
        else if(b->getType()=="Atome")
        {
           Atome* my_b =dynamic_cast<Atome*>(b);
            LitteralNumerique* c= my_b->operator +(a);
           p.push(c);
        }

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

QString Controleur::afficheVariable()
{

    QString a("");
    int j=0;

    for(unsigned int i=0; i< variable.size(); i++)
    {
        Atome* my_var =dynamic_cast<Atome*>(variable[j]);
        if(my_var->getVariable()->getType()!= "LitteralProgramme")
        {
            my_var->affiche(a);
            a+="\n";
            j++;
        }
    }
    return a;
}

void Controleur::constructionchaine(QString a)
{
    chaine =chaine + a;

}

void Controleur::constructionchaine2(QString arg1)
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
        p.push(new Complexe(my_a,my_b));
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



       writer.writeTextElement("Pile",p.afficheall());


       // Finalise le document XML
       writer.writeEndDocument();

       // Fermer le fichier pour bien enregistrer le document et ferme l'élément root
       fileXml.close();


}

void Controleur::chargePile()
{
    QString fileName = "D:/Documents/LO21/projet1/sauvegarde.xml";
    QFile fileXml(fileName);

    if(!fileXml.open(QFile::ReadOnly | QFile::Text))
        throw PileException("Erreur fichier XML");
    QXmlStreamReader reader(&fileXml);
    QString text("");
    QXmlStreamWriter writer(&text);




       reader.readElementText();

       reader.readNext();

       fileXml.close();

       writer.writeCurrentToken(reader);

       for(int i=0; i< text.size(); i++)
       {
            QStringList l=text.split(":");
            //if(l[1].isSimpleText())
            //p.push(new Entier(l[0].toInt()));
       }


}

void Controleur::ChangeNombrePileAffiche(int n)
{

    p.setNbItemsToAffiche(n);

}


void Controleur::ajouterVariable(Litteral* v)
{
    variable.push_back(v);
}

void Controleur::evaluer()
{
    Litteral* a = p.pop();

    if(a->getType()=="LitteralProgramme")
    {

        LitteralProgramme* my_a= dynamic_cast<LitteralProgramme*>(a);

        QStringList l;
        l=my_a->getProg().split(" ");

        for(int i=1; i< l.size() ; i++)
        {
            editChaine(l[i]);
            checkString();
        }
    }
    else if(a->getType()=="Atome")
    {
        Atome* my_a= dynamic_cast<Atome*>(a);
        if(my_a->getVariable()->getType()=="LitteralProgramme")
        {
            LitteralProgramme* my_a2= dynamic_cast<LitteralProgramme*>(my_a->getVariable());
            p.push(my_a2);
            evaluer();
        }
    }
}

void Controleur::editChaine(QString m_chaine)
{

    chaine=m_chaine;

}

QString Controleur::afficheProgramme()
{
    QString a("");
    int j=0;

    for(unsigned int i=0; i< variable.size(); i++)
    {
        Atome* my_var =dynamic_cast<Atome*>(variable[j]);
        if(my_var->getVariable()->getType()== "LitteralProgramme")
        {
            my_var->affiche(a);
            a+="\n";
            j++;
        }

    }

    return a;
}

QString Controleur::afficheNomProgramme()
{
    QString a("");
    int j=0;

    for(unsigned int i=0; i< variable.size(); i++)
    {
        Atome* my_var =dynamic_cast<Atome*>(variable[j]);
        if(my_var->getVariable()->getType()== "LitteralProgramme")
        {
            a+=my_var->getAtome();
            a+="\n";
            j++;
        }

    }

    return a;
}

void Controleur::creerProgramme(QString nom, QString programme)
{
    Atome* prog=new Atome(nom,new LitteralProgramme(programme));

    variable.push_back(prog);


}
