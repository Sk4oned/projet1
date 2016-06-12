#include <string>
#include <iostream>
#include "numerique.h"
#include "controleur.h"
#include "expression.h"
#include <sstream>
#include <QString>
#include "maths.h"
#include "fraction.h"
#include "complexe.h"
#include <QStringList>

LitteralExpression::LitteralExpression(QString programme)
{
    m_expression=programme;
}

bool LitteralExpression::isValide() const
{
    if(m_expression[0]=='\'')
    {
       return true;
    }
    else
    {
        return false;
    }
}

void LitteralExpression::affiche(ostream& flux)const
{
    flux << m_expression.toStdString();
}

QString& LitteralExpression::affiche(QString& flux)const
{
    flux+= m_expression;
}

QString LitteralExpression::toPostfixe()
{

        QString postfixe("");
        QString operateur("");
        QString chaine("");


        for(int i=1; i<m_expression.size()-1; i++)
        {
           if(m_expression[i]=='*')
           {
               operateur+=" *";
           }
           else if(m_expression[i]=='/')
           {
               operateur+=" /";
           }
           else if(m_expression[i]=='+')
           {
               operateur+=" +";
           }
           else if(m_expression[i]=='-')
           {
               operateur+=" -";
           }
           else
           {
               postfixe+=" " + m_expression[i];
           }

        }

        chaine= postfixe+operateur;

        return chaine;







}

bool LitteralExpression::isNumber(QString a)
{
    for(int i=0; i< 10; i++)
    {
        if( a == QString::number(i))
        {
            return true;
        }
    }

}
