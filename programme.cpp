#include <string>
#include <iostream>
#include "controleur.h"
#include <sstream>
#include <QString>
#include "numerique.h"
#include "entier.h"
#include "reel.h"
#include "fraction.h"
#include "atome.h"
#include "complexe.h"
#include "maths.h"
#include "programme.h"

using namespace std;
using namespace Exp;

LitteralProgramme::LitteralProgramme(QString programme)
{
    if(this->isValide())
    {
        m_programme=programme;
    }
    else
    {
        throw PileException("Erreur programme");
    }

};


bool LitteralProgramme::isValide(){

    if(m_programme[0]=='[' && m_programme.endsWith(']'))
    {
        return true;
    }
    return false;
}

void LitteralProgramme::affiche(ostream& flux)
{
    flux << this->getProg().toStdString();
}



QString& LitteralProgramme::affiche(QString& flux)
{
    flux += this->getProg();
    return flux;
}


ostream& operator<<(ostream& flux,Exp::LitteralProgramme& m)
{
    m.affiche(flux);
    return flux;
}

LitteralNumerique* evaluer()
{

}
