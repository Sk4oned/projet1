#include <string>
#include <iostream>
#include "controleur.h"
#include <sstream>
#include <QString>
#include <QStringList>
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
    m_programme=programme;

    if(this->isValide() == false)
    {
        throw PileException("Erreur programme");
    }

};


bool LitteralProgramme::isValide()const
{

    if(m_programme=="")
        throw PileException("Erreur programme");
    if(m_programme[0]=='[' && m_programme.endsWith(']'))
    {
        return true;
    }
    return false;
}

void LitteralProgramme::affiche(ostream& flux)const
{
    flux << m_programme.toStdString();
}



QString& LitteralProgramme::affiche(QString& flux)const
{
    flux += m_programme;
    return flux;
}


ostream& operator<<(ostream& flux,Exp::LitteralProgramme& m)
{
    m.affiche(flux);
    return flux;
}


