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
#include <windows.h>
#include <QDialog>
#include "mainwindow.h"
#include "expression.h"

using namespace Exp;


void Controleur::checkString()
{
        QString q= chaine;
        chaine="";


        if(q.contains("STO"))
        {
            if(q.contains('['))
            {   QString l=q;
                int a =q.indexOf(']') + 1;
                QString b=q.remove(a,q.size());
                QString c=l.remove(0,a);
                QStringList d= c.split(" ");
                LitteralProgramme* v = new LitteralProgramme(b);
                Atome* at= new Atome(d[1], v);
                ajouterVariable(at);
            }
            else if(q.contains('.'))
            {
                QStringList l;
                l=q.split(" ");
                float b;
                //istringstream
                b=l[0].toFloat();
                Reel* v = new Reel(b);
                Atome* at= new Atome(l[1], v);
                ajouterVariable(at);
            }
            else if(q.contains('/'))
            {
                QStringList l;
                l=q.split(" ");
                QStringList m;
                m=l[0].split("/");
                Entier* m1= new Entier(m[0].toInt());
                Entier* m2= new Entier(m[1].toInt());
                p->push(m1);
                p->push(m2);
                diviser();
                Atome* at= new Atome(l[1], p->pop());
                ajouterVariable(at);
            }
            else
            {
                QStringList l;
                l=q.split(" ");
                int c;
                //istringstream
                c=l[0].toInt();
                Entier* v = new Entier(c);
                Atome* at= new Atome(l[1], v);
                ajouterVariable(at);

            }
    }
    else if(q[0]=='+')
    {
        plus();
    }
    else if(q[0]=='\'')
    {
        LitteralExpression* v = new LitteralExpression(q);
        p->push(v);
    }
    else if(q[0]=='[')
    {
        LitteralProgramme* v = new LitteralProgramme(q);
        p->push(v);
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
    else if(q[0]=='=')
    {
        egal();
    }
    else if(q[0]=='!')
    {
        if(q[1]=='=')
        {
            different();
        }
    }
    else if(q[0]=='<')
    {
        if(q[1]=='=')
        {
            infEgal();
        }
        else
        {
            infStrict();
        }

    }
    else if(q[0]=='>')
    {
        if(q[1]=='=')
        {
            supEgal();
        }
        else
        {
            supStrict();
        }

    }
    else if(q[0]=='/')
    {
        diviser();
    }
    else if(q=="DIV")
    {
        divEntiere();
    }
    else if(q=="AND")
    {
        et();
    }
    else if(q=="OR")
    {
        ou();
    }
    else if(q=="MOD")
    {
        modulo();
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
        num();
    }
    else if(q=="DEN")
    {
        den();
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
        chaine=q;
    }
    else
    {
        QString a("");
        int j=0;

                    if(q.contains('.'))
                    {
                        float b;
                        //istringstream
                        b=q.toFloat();

                        Reel* v = new Reel(b);
                        p->push(v);
                    }
                    else if(q.contains('/'))
                    {
                        QStringList l;
                        l=q.split("/");
                        Entier* l1= new Entier(l[0].toInt());
                        Entier* l2= new Entier(l[1].toInt());
                        p->push(l1);
                        p->push(l2);
                        diviser();
                    }
                     else if(q != "")
                     {

                        int c;
                        //istringstream
                        c=q.toInt();
                        bool etat=false;

                        if(q=="0")
                        {
                            Entier* v = new Entier(0);
                            p->push(v);
                            etat=true;
                        }
                        else
                        {
                            if(c!=0)
                            {
                            Entier* v = new Entier(c);
                            p->push(v);
                            etat=true;
                            }

                         }
                        if(!etat)
                        {
                            for(unsigned int i=0; i< variable.size(); i++)
                            {
                                Atome* my_var =dynamic_cast<Atome*>(variable[j]);
                                j++;
                                if( q == my_var->getAtome() )
                                {
                                    if(my_var->getVariable()->getType()=="LitteralProgramme")
                                    {
                                        LitteralProgramme* my_var2 =dynamic_cast<LitteralProgramme*>(my_var->getVariable());
                                        p->push(my_var2);
                                        evaluer();
                                    }
                                    else
                                    {
                                        p->push(my_var);
                                    }
                                }
                            }
                        }




                        }





    }
}


void Controleur::plus()
{
    if(p->taille() >= 2)
    {

        Litteral* a= p->pop();
        Litteral* b= p->pop();

        if(b->getType()=="Entier" ||b->getType()=="Fraction" ||b->getType()=="Reel" ||b->getType()=="Complexe" )
        {
            LitteralNumerique* my_b =dynamic_cast<LitteralNumerique*>(b);
            if(a->getType()=="Entier" )
            {
                Entier* my_a =dynamic_cast<Entier*>(a);
                LitteralNumerique* c= my_a->operator+(my_b);
                p->push(c);
             }
            else if(a->getType()=="Reel")
            {
                Reel* my_a =dynamic_cast<Reel*>(a);
                LitteralNumerique* c= my_a->operator+(my_b);
                p->push(c);
            }
            else if(a->getType()=="Fraction")
            {
               Fraction* my_a =dynamic_cast<Fraction*>(a);
               LitteralNumerique* c= my_a->operator+(my_b);
               p->push(c);
            }
            else if(a->getType()=="Atome")
            {
               Atome* my_a =dynamic_cast<Atome*>(a);
               if(my_a->isVariableValide())
               {
                   LitteralNumerique* my_a2 =dynamic_cast<LitteralNumerique*>(my_a->getVariable());
                   LitteralNumerique* c= my_a2->operator +(my_b);
                   p->push(c);
               }

            }
            else if(a->getType()=="Complexe")
            {
               Complexe* my_a =dynamic_cast<Complexe*>(a);
               LitteralNumerique* c= my_a->operator+(my_b);
               p->push(c);
            }
         }
        else if(b->getType()=="Atome")
        {
            Atome* my_b =dynamic_cast<Atome*>(b);
            LitteralNumerique* c= my_b->operator +(a);
            p->push(c);
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
    if(p->taille() >= 2)
    {

        Litteral* a= p->pop();
        Litteral* b= p->pop();

         if(b->getType()=="Entier" ||b->getType()=="Fraction" ||b->getType()=="Reel" ||b->getType()=="Complexe" )
        {
                LitteralNumerique* my_b =dynamic_cast<LitteralNumerique*>(b);

                if(a->getType()=="Entier" )
                {
                    Entier* my_a =dynamic_cast<Entier*>(a);
                    LitteralNumerique* c= my_a->operator-(my_b);
                    p->push(c);
                 }
                else if(a->getType()=="Reel")
                {
                    Reel* my_a =dynamic_cast<Reel*>(a);
                    LitteralNumerique* c= my_a->operator-(my_b);
                    p->push(c);
                }
                else if(a->getType()=="Fraction")
                {
                   Fraction* my_a =dynamic_cast<Fraction*>(a);
                   LitteralNumerique* c= my_a->operator-(my_b);
                   p->push(c);
                }
                else if(a->getType()=="Atome")
                {
                   Atome* my_a =dynamic_cast<Atome*>(a);
                   if(my_a->isVariableValide())
                   {
                       LitteralNumerique* my_a2 =dynamic_cast<LitteralNumerique*>(my_a->getVariable());
                       LitteralNumerique* c= my_a2->operator -(my_b);
                       p->push(c);
                   }

                }
                else if(a->getType()=="Complexe")
                {
                  Complexe* my_a =dynamic_cast<Complexe*>(a);
                  LitteralNumerique* c= my_a->operator-(my_b);
                  p->push(c);
                }
         }
         else if(b->getType()=="Atome")
         {
            Atome* my_b =dynamic_cast<Atome*>(b);
             LitteralNumerique* c= my_b->operator +(a);
            p->push(c);
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
    if(p->taille() > 1)
    {

        Litteral* a= p->pop();
        Litteral* b= p->pop();

        if(b->getType()=="Entier" ||b->getType()=="Fraction" ||b->getType()=="Reel" ||b->getType()=="Complexe" )
        {
                LitteralNumerique* my_b =dynamic_cast<LitteralNumerique*>(b);

                if(a->getType()=="Entier" )
                {
                    Entier* my_a =dynamic_cast<Entier*>(a);
                    LitteralNumerique* c= my_a->operator*(my_b);
                    p->push(c);
                 }
                else if(a->getType()=="Reel")
                {
                    Reel* my_a =dynamic_cast<Reel*>(a);
                    LitteralNumerique* c= my_a->operator*(my_b);
                    p->push(c);
                }
                else if(a->getType()=="Fraction")
                {
                   Fraction* my_a =dynamic_cast<Fraction*>(a);
                   LitteralNumerique* c= my_a->operator*(my_b);
                   p->push(c);
                }
                else if(a->getType()=="Complexe")
                {
                  Complexe* my_a =dynamic_cast<Complexe*>(a);
                  LitteralNumerique* c= my_a->operator*(my_b);
                  p->push(c);
                }
                else if(a->getType()=="Atome")
                {
                    Atome* my_a =dynamic_cast<Atome*>(a);
                    if(my_a->isVariableValide())
                    {

                        LitteralNumerique* my_a2 =dynamic_cast<LitteralNumerique*>(my_a->getVariable());
                        LitteralNumerique* c= my_b->operator *(my_a2);
                        p->push(c);
                    }
                }
        }
        else if(b->getType()=="Atome")
        {
           Atome* my_b =dynamic_cast<Atome*>(b);
            LitteralNumerique* c= my_b->operator +(a);
           p->push(c);
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
    if(p->taille() >= 2)
    {

        Litteral* a= p->pop();
        Litteral* b= p->pop();

        if(b->getType()=="Entier" ||b->getType()=="Fraction" ||b->getType()=="Reel" ||b->getType()=="Complexe" )
        {
                LitteralNumerique* my_b =dynamic_cast<LitteralNumerique*>(b);

                if(a->getType()=="Entier" )
                {
                    Entier* my_a =dynamic_cast<Entier*>(a);
                    LitteralNumerique* c= my_a->operator/(my_b);
                    p->push(c);
                 }
                else if(a->getType()=="Reel")
                {
                    Reel* my_a =dynamic_cast<Reel*>(a);
                    LitteralNumerique* c= my_a->operator/(my_b);
                    p->push(c);
                }
                else if(a->getType()=="Fraction")
                {
                   Fraction* my_a =dynamic_cast<Fraction*>(a);
                   LitteralNumerique* c= my_a->operator/(my_b);
                   p->push(c);
                }
                else if(a->getType()=="Complexe")
                {
                  Complexe* my_a =dynamic_cast<Complexe*>(a);
                  LitteralNumerique* c= my_a->operator/(my_b);
                  p->push(c);
                }
                else if(a->getType()=="Atome")
                {
                    Atome* my_a =dynamic_cast<Atome*>(a);
                    if(my_a->isVariableValide())
                    {

                        LitteralNumerique* my_a2 =dynamic_cast<LitteralNumerique*>(my_a->getVariable());
                        LitteralNumerique* c= my_b->operator *(my_a2);
                        p->push(c);
                    }
                }
        }
        else if(b->getType()=="Atome")
        {
           Atome* my_b =dynamic_cast<Atome*>(b);
            LitteralNumerique* c= my_b->operator +(a);
           p->push(c);
        }

}
else
{
throw PileException("Pas Assez d'argument");
}


}

void Controleur::divEntiere()
{
    if(p->taille() > 1)
    {
        Litteral* b= p->pop();
        Litteral* a= p->pop();

        if(a->getType()=="Entier" && b->getType()=="Entier")
        {
                Entier* my_a =dynamic_cast<Entier*>(a);
                Entier* my_b =dynamic_cast<Entier*>(b);
                p->push(new Entier(my_a->getEntier()/my_b->getEntier()));
        }
        else
        {
            throw PileException("Erreur argument(s) non entier");
        }
    }
    else
    {
        throw PileException("Pas Assez d'argument");
    }
}

void Controleur::modulo()
{
    if(p->taille() > 1)
    {
        Litteral* b= p->pop();
        Litteral* a= p->pop();

        if(a->getType()=="Entier" && b->getType()=="Entier")
        {
                Entier* my_a =dynamic_cast<Entier*>(a);
                Entier* my_b =dynamic_cast<Entier*>(b);
                p->push(new Entier(my_a->getEntier()%my_b->getEntier()));
        }
        else
        {
            throw PileException("Erreur argument(s) non entier");
        }
    }
    else
    {
    throw PileException("Pas Assez d'argument");
    }
}



QString Controleur::affiche()
{
    QString a = p->affiche();
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
        else
        {
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
    Litteral*  a=p->pop();


    if(a->getType()=="Entier" )
    {
        Entier* my_a =dynamic_cast<Entier*>(a);
        p->push(new Entier(- my_a->getEntier()));
    }
    else if(a->getType()=="Reel")
    {
        Reel* my_a =dynamic_cast<Reel*>(a);
        p->push(new Reel(- my_a->getReel()));
    }
    else if(a->getType()=="Fraction")
    {
       Fraction* my_a =dynamic_cast<Fraction*>(a);
       p->push(new Fraction(- my_a->getNumerateur(),my_a->getDenominateur()));
    }
    else if(a->getType()=="Complexe")
    {
       Complexe* my_a =dynamic_cast<Complexe*>(a);
       p->push(new Complexe(my_a->getP_reelle()->operator *(new Entier(-1)),my_a->getP_imaginaire()));
    }
  /*  else if(a->getType()=="Atome")
    {
       Atome* my_a =dynamic_cast<Atome*>(a);
       Entier* my_b= new Entier(-1);
       p->push(new Atome(my_b->operator*(my_a->getVariable())));
    }*/
}


//NUM

void Controleur::num()
{
    Litteral*  a=p->pop();


    if(a->getType()=="Entier" )
    {
        Entier* my_a =dynamic_cast<Entier*>(a);
        p->push(my_a);
    }
    else if(a->getType()=="Reel")
    {
        throw PileException("Erreur NUM ne peut pas etre utilise sur un Reel");
    }
    else if(a->getType()=="Fraction")
    {
       Fraction* my_a =dynamic_cast<Fraction*>(a);
       p->push(new Entier(my_a->getNumerateur()));
    }
    else if(a->getType()=="Atome")
    {
        throw PileException("Erreur DEN ne peut pas etre utilise sur un Atome");
      /*
        Atome* my_a =dynamic_cast<Atome*>(a);
        if(my_a->getVariable()->getType() == "LitteralVariable")
        {
            p->push(my_a->getVariable());
            num();
        }
        else
        {
            throw PileException("Erreur DEN ne peut pas etre utilise sur un LitteralProgramme");
        }
        */
    }
    else if(a->getType()=="Complexe")
    {
        throw PileException("Erreur NUM ne peut pas etre utilise sur un Complexe");
    }

}

//DEN

void Controleur::den()
{
    Litteral*  a=p->pop();


    if(a->getType()=="Entier" )
    {
        p->push(new Entier(1));
    }
    else if(a->getType()=="Reel")
    {
        throw PileException("Erreur DEN ne peut pas etre utilise sur un Reel");
    }
    else if(a->getType()=="Fraction")
    {
       Fraction* my_a =dynamic_cast<Fraction*>(a);
       p->push(new Entier (my_a->getDenominateur()));
    }
    else if(a->getType()=="Atome")
    {
        throw PileException("Erreur DEN ne peut pas etre utilise sur un Atome");
        /*
       Atome* my_a =dynamic_cast<Atome*>(a);
        if(my_a->getVariable()->getType() == "LitteralVariable")
        {
            p->push(my_a->getVariable());
            den();
        }
        else
        {
            throw PileException("Erreur DEN ne peut pas etre utilise sur un LitteralProgramme");
        }
        */
    }
    else if(a->getType()=="Complexe")
    {
        throw PileException("Erreur DEN ne peut pas etre utilise sur un Complexe");
    }

}


void Controleur::re()
{
    Litteral*  a=p->pop();


    if(a->getType()=="Complexe" )
    {
        Complexe* my_a =dynamic_cast<Complexe*>(a);
        p->push(my_a->getP_reelle());
    }
    else
    {
        p->push(a);
    }

}

void Controleur::im()
{
    Litteral*  a=p->pop();


    if(a->getType()=="Complexe" )
    {
        Complexe* my_a =dynamic_cast<Complexe*>(a);
        p->push(my_a->getP_imaginaire());
    }
    else
    {
        p->push(new Entier(0));
    }
}

void Controleur::dup()
{
    Litteral*  a=p->pop();

    if(a->getType()=="Entier" )
    {
        Entier* my_a =dynamic_cast<Entier*>(a);
        p->push(my_a);
        p->push(new Entier(my_a->getEntier()));
    }
    else if(a->getType()=="Reel")
    {
        Reel* my_a =dynamic_cast<Reel*>(a);
        p->push(my_a);
        p->push(new Entier(my_a->getReel()));
    }
    else if(a->getType()=="Fraction")
    {
       Fraction* my_a =dynamic_cast<Fraction*>(a);
       p->push(my_a);
       p->push(new Fraction(my_a->getNumerateur(),my_a->getDenominateur()));
    }
  /*  else if(a->getType()=="Atome")
    {
        Atome* my_a =dynamic_cast<Atome*>(a);
        p->push(my_a);
        p->push(new Atome(my_a->getAtome(),my_a->getVariable(),my_a->getProgramme()));
    }
  */  else if(a->getType()=="Complexe")
    {
       throw PileException("Erreur RE ne peut pas etre utilise sur un Complexe");
    }
}

void Controleur::drop()
{
    p->pop();
}

void Controleur::swap()
{
    Litteral*  a=p->pop();
    Litteral*  b=p->pop();

    p->push(a);
    p->push(b);
}

void Controleur::clear()
{
    for(int i=0; i<p->taille();i++)
    {
        p->pop();
    }

}

// Complexe

void Controleur::complexe()
{
    if(p->taille() >= 2) {
    Litteral* a = p->pop();
    Litteral* b = p->pop();

    if(a->getType()=="Atome" || a->getType()=="Complexe" || b->getType()=="Atome" || b->getType()=="Complexe")
    {
        throw PileException("Erreur création complexe");
        p->push(b);
        p->push(a);
    }
    else
    {
        LitteralNumerique* my_a= dynamic_cast<LitteralNumerique*>(a);
        LitteralNumerique* my_b= dynamic_cast<LitteralNumerique*>(b);
        p->push(new Complexe(my_b,my_a));
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

    writer.setAutoFormatting(true);
    writer.writeStartDocument();

    QStringList afPile=affiche().split("\n");

    writer.writeStartElement("DPile");

    for(int i=0; i<afPile.size()-1; i++)
    {
        writer.writeTextElement("ElementPile",afPile[i]);
    }

    QString b= beep ? "true" : "false";
    QString b2= "BIP : " + b;
    QString c= clavier ? "true" : "false";
    QString c2=  "CLAVIER : " + c;
    QString nbAf= "NBPILEAFFICHE : " + QString::number(p->getNbItemsToAffiche());

    writer.writeTextElement("Beep",b2);
    writer.writeTextElement("Clavier",c2);
    writer.writeTextElement("NombreElementAAfficher",nbAf);

    writer.writeEndElement();

    writer.writeEndDocument();

    fileXml.close();


}

void Controleur::enregistreVarEtProg()
{
    QString fileName = "D:/Documents/LO21/projet1/Programme.xml";
    QFile fileXml(fileName);

    if(!fileXml.open(QFile::WriteOnly | QFile::Text))
        throw PileException("Erreur fichier XML");
    QXmlStreamWriter writer(&fileXml);

       writer.setAutoFormatting(true);
       writer.writeStartDocument();

       QStringList afNomProgramme=afficheNomProgramme().split("\n");
       QStringList afProgramme=afficheProgramme().split("\n");

       writer.writeStartElement("DProgramme");

       for(int i=0; i<afProgramme.size()-1; i++)
       {
           writer.writeTextElement("NomProgramme",afNomProgramme[i]);
           writer.writeTextElement("Programme",afProgramme[i]);
       }

       writer.writeEndElement();

       writer.writeEndDocument();

       fileXml.close();


       QString fileName2 = "D:/Documents/LO21/projet1/Variable.xml";
       QFile fileXml2(fileName2);

       if(!fileXml2.open(QFile::WriteOnly | QFile::Text))
           throw PileException("Erreur fichier XML");
       QXmlStreamWriter writer2(&fileXml2);

          writer2.setAutoFormatting(true);
          writer2.writeStartDocument();

          QStringList afVariable=afficheVariable().split("\n");

          writer2.writeStartElement("DVariable");

          for(int j=0; j<afVariable.size()-1; j++)
          {
              writer2.writeTextElement("Variable",afVariable[j]);
          }

          writer2.writeEndElement();

          writer2.writeEndDocument();

          fileXml2.close();

}

void Controleur::chargeVarEtProg()
{
    QString fileName = "D:/Documents/LO21/projet1/Programme.xml";
    QFile fileXml(fileName);

    if(!fileXml.open(QFile::ReadOnly | QFile::Text))
        throw PileException("Erreur fichier XML");

    QXmlStreamReader reader(&fileXml);

    reader.readNextStartElement();

    QString m_nom("");
    QString m_programme("");

    while(!reader.atEnd())
    {



            if(reader.name()=="NomProgramme")
            {
                m_nom=reader.readElementText();
                reader.readNextStartElement();
                reader.readNext();
                m_programme=reader.text().toString();
                reader.readNext();

              if(m_nom!="" && m_programme!="")
              {
                 creerProgramme(m_nom,m_programme);
                 reader.readNext();
                 QString m_nom("");
                 QString m_programme("");
               }


            }
            else
            {
                reader.readNext();

            }

    }


    fileXml.close();



    QString fileName2 = "D:/Documents/LO21/projet1/Variable.xml";
    QFile fileXml2(fileName2);

    if(!fileXml2.open(QFile::ReadOnly | QFile::Text))
        throw PileException("Erreur fichier XML");

    QXmlStreamReader reader2(&fileXml2);

    reader2.readNextStartElement();


    QString m_variable("");

    while(!reader2.atEnd())
    {



            if(reader2.name()=="DVariable" || reader2.name()=="Variable")
            {
                m_variable=reader2.text().toString();
                reader2.readNextStartElement();
                m_variable=reader2.text().toString();
                reader2.readNext();
                m_variable=reader2.text().toString();
                reader2.readNext();
                QStringList m= m_variable.split(" : ");
                if(m.size()>1)
                {
                    constructionchaine2(m[1]+ " " +m[0] + " STO");
                    checkString();
                    reader.readNext();
                }


            }
            else
            {
                reader2.readNext();

            }

    }


    fileXml2.close();


}


void Controleur::chargePile()
{


    QString fileName2 = "D:/Documents/LO21/projet1/sauvegarde.xml";
    QFile fileXml2(fileName2);

    if(!fileXml2.open(QFile::ReadOnly | QFile::Text))
        throw PileException("Erreur fichier XML");

    QXmlStreamReader reader2(&fileXml2);

    reader2.readNextStartElement();


    QString m_variable("");

    while(!reader2.atEnd())
    {

            if(reader2.name()=="DPile")
            {
                m_variable=reader2.text().toString();
                reader2.readNextStartElement();
            }
            else if(1)
            {
                reader2.readNext();
                m_variable=reader2.text().toString();

            }

            if(reader2.text()!= "\n")
            {
                QStringList m= m_variable.split(" : ");
                if(m.size()>1)
                {

                    if(m[0]== "BIP")
                    {
                        if(m[1]=="false")
                        {
                            beep=false;
                        }
                        else
                        {
                            beep=true;
                        }

                    }
                    else if(m[0]== "CLAVIER")
                    {
                        if(m[1]=="false")
                        {
                            clavier=false;
                        }
                        else
                        {
                            clavier=true;
                        }
                    }
                    else if(m[0]== "NBPILEAFFICHE")
                    {
                        ChangeNombrePileAffiche(m[1].toInt());
                    }
                    else
                    {
                        constructionchaine2(m[1]);
                        checkString();
                        m_variable="";
                    }

                }

            }

    }


    fileXml2.close();

}

void Controleur::ChangeNombrePileAffiche(int n)
{

    p->setNbItemsToAffiche(n);

}


void Controleur::ajouterVariable(Litteral* v)
{
    variable.push_back(v);
}

void Controleur::evaluer()
{
    Litteral* a = p->pop();

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
    else if(a->getType()=="LitteralExpression")
    {

        LitteralExpression* my_a= dynamic_cast<LitteralExpression*>(a);
        constructionchaine2(my_a->toPostfixe());
        checkString();
    }
    else if(a->getType()=="Atome")
    {
        Atome* my_a= dynamic_cast<Atome*>(a);
        if(my_a->getVariable()->getType()=="LitteralProgramme")
        {
            LitteralProgramme* my_a2= dynamic_cast<LitteralProgramme*>(my_a->getVariable());
            p->push(my_a2);
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
            my_var->getVariable()->affiche(a);
            a+="\n";
            j++;
        }
        else
        {
            j++;
        }

    }

    return a;
}

QString Controleur::afficheProgrammeRecherche(QString selection)
{
    QString a("");
    int j=0;

    for(unsigned int i=0; i< variable.size(); i++)
    {
        Atome* my_var =dynamic_cast<Atome*>(variable[j]);
        if(my_var->getVariable()->getType()== "LitteralProgramme")
        {
                j++;
                if( selection == my_var->getAtome() )
                {
                    my_var->getVariable()->affiche(a);
                    return a;
                }

        }
        else
        {
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
        else
        {
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

void Controleur::egal()
{
    if(p->taille() > 1)
    {

        Litteral* a= p->pop();
        Litteral* b= p->pop();


            if(a->getType()==b->getType())
            {
                if(a->getType()=="Entier" )
                {
                    Entier* my_a =dynamic_cast<Entier*>(a);
                    Entier* my_b =dynamic_cast<Entier*>(b);
                    if(my_a->getEntier()==my_b->getEntier())
                    {
                        p->push(new Entier(1));
                    }
                    else
                    {
                        p->push(new Entier(0));
                    }

                 }
                else if(a->getType()=="Reel" )
                {
                    Reel* my_a =dynamic_cast<Reel*>(a);
                    Reel* my_b =dynamic_cast<Reel*>(b);
                    if(my_a->getReel()==my_b->getReel())
                    {
                        p->push(new Entier(1));
                    }
                    else
                    {
                        p->push(new Entier(0));
                    }

                 }
               else if(a->getType()=="Fraction" )
                {
                    Fraction* my_a =dynamic_cast<Fraction*>(a);
                    Fraction* my_b =dynamic_cast<Fraction*>(b);
                    if(my_a->getNumerateur()==my_b->getNumerateur() && my_a->getDenominateur()==my_b->getDenominateur())
                    {
                        p->push(new Entier(1));
                    }
                    else
                    {
                        p->push(new Entier(0));
                    }

                 }
                else if(a->getType()=="Complexe")
                {
                    Complexe* my_a =dynamic_cast<Complexe*>(a);
                    Complexe* my_b =dynamic_cast<Complexe*>(b);
                    p->push(my_a->getP_reelle());
                    p->push(my_b->getP_reelle());
                    egal();
                    p->push(my_a->getP_imaginaire());
                    p->push(my_b->getP_imaginaire());
                    egal();
                    et();
                }

               }
            else p->push(new Entier(0));
            }


    else
    {
        throw PileException("Pas Assez d'argument");
    }
}

void Controleur::different()
{
    egal();
    Litteral* a = p->pop();
    Entier* my_a =dynamic_cast<Entier*>(a);
    if (my_a->getEntier()==0)
        p->push(new Entier(1));
    else p->push(new Entier(0));
}

void Controleur::infEgal()
{
    Litteral* b= p->pop();
    Litteral* a= p->pop();
    p->push(b);
    p->push(a);
    supEgal();
}


void Controleur::supStrict()
{
    if(p->taille() > 1)
    {

        Litteral* b= p->pop();
        Litteral* a= p->pop();


            if(a->getType() =="Entier")
            {
                Entier* my_a=dynamic_cast<Entier*>(a);
                if(my_a->operator>(b))
                {
                    p->push(new Entier(1));
                }
                else
                {
                    p->push(new Entier(0));
                }
            }
            else if(a->getType() =="Reel")
            {
                Reel* my_a=dynamic_cast<Reel*>(a);
                my_a->operator>(b);
                if(my_a->operator>(b))
                {
                    p->push(new Entier(1));
                }
                else
                {
                    p->push(new Entier(0));
                }
            }
            else if(a->getType() =="Fraction")
            {
                Fraction* my_a=dynamic_cast<Fraction*>(a);
                my_a->operator>(b);
                if(my_a->operator>(b))
                {
                    p->push(new Entier(1));
                }
                else
                {
                    p->push(new Entier(0));
                }
            }
            else
            {
                throw PileException("Erreur");
            }
    }

}

void Controleur::supEgal()
{
    if(p->taille() > 1)
    {
        Litteral* b= p->pop();
        Litteral* a= p->pop();
        p->push(a);
        p->push(b);
        supStrict();
        p->push(a);
        p->push(b);
        egal();
        ou();

    }
}

void Controleur::infStrict()
{
    Litteral* b= p->pop();
    Litteral* a= p->pop();
    p->push(b);
    p->push(a);
    supStrict();
}

void Controleur::et()
{
    Litteral* b= p->pop();
    Litteral* a= p->pop();
    if(a->getType() =="Entier" || b->getType()=="Entier")
    {
        if (a->getType()=="Entier" && b->getType()!="Entier")
        {
            Entier* my_a=dynamic_cast<Entier*>(a);
            if(my_a->getEntier()==0)
            {
                p->push(new Entier(0));
            }
            else
            {
                p->push(new Entier(1));
            }
        }
        else if (a->getType()!="Entier" && b->getType()=="Entier")
        {
            Entier* my_b=dynamic_cast<Entier*>(b);
            if(my_b->getEntier()==0)
            {
                p->push(new Entier(0));
            }
            else
            {
                p->push(new Entier(1));
            }
        }
        else if (a->getType()=="Entier" && b->getType()=="Entier")
        {
            Entier* my_a=dynamic_cast<Entier*>(a);
            Entier* my_b=dynamic_cast<Entier*>(b);
            if(my_a->getEntier()==0 || my_b->getEntier()==0)
            {
                p->push(new Entier(0));
            }
            else
            {
                p->push(new Entier(1));
            }
        }
    }
    else p->push(new Entier(1));
}

void Controleur::ou()
{
    Litteral* b= p->pop();
    Litteral* a= p->pop();
    if(a->getType() =="Entier" && b->getType()=="Entier")
    {
        Entier* my_a=dynamic_cast<Entier*>(a);
        Entier* my_b=dynamic_cast<Entier*>(b);
        if(my_a->getEntier()==0 && my_b->getEntier()==0)
        {
        p->push(new Entier(0));
        }
        else
        {
            p->push(new Entier(1));
        }
    }
    else p->push(new Entier(1));
}

bool Controleur::supprVariable(QString id)
{
    int j=0;

    for (vector<Litteral*>::iterator it = variable.begin() ; it != variable.end(); it++)
    {
            Atome* my_var =dynamic_cast<Atome*>(variable[j]);
            j++;
            if(my_var->getType()!="LitteralProgramme")
            {
                if( id == my_var->getAtome() )
                {
                    variable.erase(it);
                    j--;
                    return true;
                }
            }


    }
}

bool Controleur::supprProgramme(QString id)
{
    int j=0;

    for (vector<Litteral*>::iterator it = variable.begin() ; it != variable.end(); it++)
    {
            Atome* my_var =dynamic_cast<Atome*>(variable[j]);
            j++;

            if(my_var->getVariable()->getType()=="LitteralProgramme")
            {
                if( id == my_var->getAtome() )
                {
                    variable.erase(it);
                    j--;
                    return true;
                }
            }

    }

}



void Controleur::Bip()
{
    if(beep==true)
    {
        Beep(1000,500); //1000HZ, 500ms
    }

}

void Controleur::changeBeepStatut()
{
    if(beep==true)
    {
        beep=false;
    }
    else
    {
        beep=true;
    }

}

QString& Controleur::getchaine()
{
    return chaine;
}

QString Controleur::top()
{
    return p->top();
}

void Controleur::changeClavierStatut(bool etat)
{
   clavier=etat;
}


bool Controleur::getClavierStatut()
{
   return clavier;
}

bool Controleur::getBipStatut()
{
   return beep;
}




