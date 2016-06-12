#ifndef ENTIER_H
#define ENTIER_H
#include "numerique.h"
#include <string>
#include <QString>

using namespace std;
using namespace Exp;

namespace Exp{

    class Entier: public LitteralNumerique{

        int m_entier;
        string type="Entier";

    public:

        Entier(int e): m_entier(e){};
        virtual bool isValide()const{return (m_entier!=0);};
        virtual void affiche(ostream& flux)const;
        virtual QString& affiche(QString& flux)const;
        int getEntier(){return m_entier;}
        string getType(){return type;}
        //virtual Entier* operator+(Entier* a);
        //virtual Entier* operator-(Entier* a);
        //virtual Fraction* operator/(Entier* a);
        void setEntier(int a){this->m_entier=a;}

        /*!
            *  \brief Méthode qui gère l'addition d'un LitteralNumerique avec un entier
            *
            *
            */
        virtual LitteralNumerique* operator+(LitteralNumerique* b);

        /*!
            *  \brief Méthode qui gère la soustraction d'un LitteralNumerique avec un entier
            *
            *
            */
        virtual LitteralNumerique* operator-(LitteralNumerique* b);

        /*!
            *  \brief Méthode qui gère la multiplication d'un LitteralNumerique avec un entier
            *
            *
            */
        virtual LitteralNumerique* operator*(LitteralNumerique* b);

        /*!
            *  \brief Méthode qui gère la division d'un LitteralNumerique avec un entier
            *
            *
            */
        virtual LitteralNumerique* operator/(LitteralNumerique* b);

        /*!
            *  \brief Méthode qui gère la  comparaison d'un Litteral avec un entier
            *
            *
            */
        bool operator>(Litteral* b);
    };

}

/*!
    *  \brief Surcharge de l'opérateur << pour afficher des Entiers dans la console
    *
    *
    */
ostream& operator<<(ostream& flux,Exp::Entier& m);




#endif // ENTIER_H
