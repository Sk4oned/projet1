#ifndef ATOME_H
#define ATOME_H
#include "numerique.h"
#include <string>
#include <QString>
#include "programme.h"
#include "litteral.h"

using namespace std;

namespace Exp{


    class Atome: public Litteral{

        /*!
            *  \brief Nom de l'atome
            *
            *
            */
        QString m_atome;

        /*!
            *  \brief Champ type
            *
            *
            */
        string type="Atome";

        /*!
            *  \brief Pointeur vers un Litteral
            *
            *
            */
        Litteral* variable;


    public:

        /*!
            *  \brief Constructeur d'atome
            *
            *  Prends en entrée le nom de l'atome et un pointeur vers la variable
            */
        Atome(QString atome, Litteral* var=nullptr);
        /*!
            *  \brief Fonction isValide
            *
            *  Teste si un atome est valide
            */
        virtual bool isValide()const{return (m_atome.isEmpty());};

        /*!
            *  \brief Ancienne fonction qui gère l'affichage d'un atome
            *
            *  Créée initialement pour l'affichage sur console, inutile dans Qt et remplacée par la fonction suivante
            */
        virtual void affiche(ostream& flux)const;

        /*!
            *  \brief Fonction qui gère l'affichage d'un atome
            *
            *  Gère l'affichage d'un atome
            */
        virtual QString& affiche(QString& flux) const;

        /*!
            *  \brief Accesseur Atome
            *
            *  Récupère l'attribut m_atome
            */
        QString getAtome(){return m_atome;}

        /*!
            *  \brief Accesseur du type
            *
            *  Récupère le type
            */
        string getType(){return type;}


        virtual bool isVariableValide()const{return (variable!=nullptr);};
        Litteral* getVariable(){if(isVariableValide())return variable;};

        /*!
            *  \brief Méthode qui gère la somme d'un LitteralNumerique avec un atome
            *
            *
            */
        virtual LitteralNumerique* operator+(Litteral* b);
        /*!
            *  \brief Méthode qui gère la soustraction d'un LitteralNumerique avec un atome
            *
            *
            */
        virtual LitteralNumerique* operator-(Litteral* b);

        /*!
            *  \brief Méthode qui gère le produit d'un LitteralNumerique avec un atome
            *
            *
            */
        virtual LitteralNumerique* operator*(Litteral* b);

        /*!
            *  \brief Méthode qui gère la division d'un LitteralNumerique avec un atome
            *
            *
            */
        virtual LitteralNumerique* operator/(Litteral* b);
    };


}



/*!
    *  \brief Surcharge de l'opérateur << pour afficher des Atomes dans la console
    *
    *
    */
ostream& operator<<(ostream& flux,Exp::Atome& m);



#endif // ATOME_H
