#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <string>
#include <iostream>
#include <QString>


using namespace std;

namespace Exp{


class LitteralNumerique{

public:

    virtual bool isValide()const=0;

    virtual void affiche(ostream& flux)const=0;
    virtual QString& affiche(QString& flux)const=0;
    //LitteralNumerique(string entree){};
    virtual string getType()=0;
    virtual LitteralNumerique* operator+(LitteralNumerique* b)=0;
    virtual LitteralNumerique* operator-(LitteralNumerique* b)=0;
    virtual LitteralNumerique* operator*(LitteralNumerique* b)=0;
    virtual LitteralNumerique* operator/(LitteralNumerique* b)=0;


};

}





QString& operator<<(QString& flux,string a);


/*
template<class T>
T operator+(T& a,T& b)
 {
     return a+b;
 }

*/




/*
template<class T>
T addition(T& a,T& b)
 {
     return a+b;
 }

template<class T>
T Soustraction(T& a,T& b)
 {
     return a-b;
 }

template<class T>
T multiplication(T& a,T& b)
 {
     return a*b;
 }

template<class T>
T division(T& a,T& b)
 {
     return a/b;
 }
*/



#endif // EXPRESSION_H
