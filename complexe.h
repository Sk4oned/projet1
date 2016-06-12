#ifndef COMPLEXE_H
#define COMPLEXE_H
#include "numerique.h"
#include <string>
#include <QString>

using namespace std;
using namespace Exp;

namespace Exp{

class Complexe: public LitteralNumerique{

    /*!
        *  \brief Partie réel du complexe
        *Partie réel du complexe
        *Elle peut être un Entier, Complexe, Reel, Fraction
        */
    LitteralNumerique* p_reelle;

    /*!
        *  \brief Partie imaginaire du complexe
        *Partie réel du complexe
        *Elle peut être un Entier, Complexe, Reel, Fraction
        */
    LitteralNumerique* p_imaginaire;

    /*!
        *  \brief Champs type
        *
        *
        */
    string type="Complexe";

public:

    /*!
        *  \brief Constructeur Complexe
        *Prends en deux LitteralNumerique
        *
        */
    Complexe(LitteralNumerique* a, LitteralNumerique* b);

    /*!
        *  \brief Vérifie si le complexe est vraiment un complexe
        *
        *
        */
    virtual bool isValide()const{ return (p_imaginaire!=0); };

    /*!
        *  \brief Affiche le complexe dans la console
        *
        *
        */
    virtual void affiche(ostream& flux)const;

    /*!
        *  \brief Renvoi un QString corrsepondant au Complexe
        *
        *
        */
    virtual QString& affiche(QString& flux)const;

    /*!
        *  \brief Renvoi le type
        *
        *
        */
    string getType(){return type;}

    /*!
        *  \brief Renvoi la partie réel Complexe
        *
        *
        */
    LitteralNumerique* getP_reelle(){ return p_reelle; }

    /*!
        *  \brief Renvoi la partie imaginaire Complexe
        *
        *
        */
    LitteralNumerique* getP_imaginaire(){ return p_imaginaire; }

    /*!
        *  \brief Méthode qui gère l'addition d'un LitteralNumerique avec un complexe
        *
        *
        */
    virtual LitteralNumerique* operator+(LitteralNumerique* b);

    /*!
        *  \brief Méthode qui gère la soustraction d'un LitteralNumerique avec un complexe
        *
        *
        */
    virtual LitteralNumerique* operator-(LitteralNumerique* b);

    /*!
        *  \brief Méthode qui gère la multiplication d'un LitteralNumerique avec un complexe
        *
        *
        */
    virtual LitteralNumerique* operator*(LitteralNumerique* b);

    /*!
        *  \brief Méthode qui gère la division d'un LitteralNumerique avec un complexe
        *
        *
        */
    virtual LitteralNumerique* operator/(LitteralNumerique* b);
 };

}



#endif // COMPLEXE_H
