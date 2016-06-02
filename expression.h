#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <string>
#include <iostream>
#include <QString>

using namespace std;

namespace Exp{

class FractionException{
    QString m_phrase;

public:
    FractionException(QString p):m_phrase(p){};
    void affiche(ostream& flux);
    QString& affiche();
};

class PileException{
    QString m_phrase;

public:
    PileException(QString p):m_phrase(p){};
    QString& affiche();
};



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


class Fraction: public LitteralNumerique{

    int m_numerateur;
    int m_denominateur;
    string type="Fraction";


public:

    Fraction(int n, int d=1);
    virtual bool isValide()const;
    virtual void affiche(ostream& flux)const;
    virtual QString& affiche(QString& flux)const;
    int getNumerateur(){return m_numerateur;}
    int getDenominateur(){return m_denominateur;}
    string getType(){return type;}
    //virtual Fraction* operator+(Fraction* a);
    virtual LitteralNumerique* operator+(LitteralNumerique* b);
    virtual LitteralNumerique* operator-(LitteralNumerique* b);
    virtual LitteralNumerique* operator*(LitteralNumerique* b);
    virtual LitteralNumerique* operator/(LitteralNumerique* b);

};

class Atome: public LitteralNumerique{

    int m_atome;
    string type="Atome";

public:
    Atome(int atome): m_atome(atome){};
    virtual bool isValide()const{return (m_atome!=0);};
    virtual void affiche(ostream& flux)const;
    virtual QString& affiche(QString& flux)const;
    int getAtome(){return m_atome;}
    string getType(){return type;}
    //virtual Atome* operator+(Atome* a);
    virtual LitteralNumerique* operator+(LitteralNumerique* b);
    virtual LitteralNumerique* operator-(LitteralNumerique* b);
    virtual LitteralNumerique* operator*(LitteralNumerique* b);
    virtual LitteralNumerique* operator/(LitteralNumerique* b);

};


class Reel: public LitteralNumerique{

    float m_r;
    string type="Reel";

public:

    Reel(float r=0): m_r(r){};
    virtual  bool isValide()const{return (m_r!=0);};
    virtual void affiche(ostream& flux)const;
    virtual QString& affiche(QString& flux)const;
    float getReel(){return m_r;}
    string getType(){return type;}
    //virtual Reel* operator+(Reel* a);
    //virtual Reel* operator-(Reel* a);
    //virtual Fraction* operator/(Reel* a);
    virtual LitteralNumerique* operator+(LitteralNumerique* b);
    virtual LitteralNumerique* operator-(LitteralNumerique* b);
    virtual LitteralNumerique* operator*(LitteralNumerique* b);
    virtual LitteralNumerique* operator/(LitteralNumerique* b);



};

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
    virtual LitteralNumerique* operator+(LitteralNumerique* b);
    virtual LitteralNumerique* operator-(LitteralNumerique* b);
    virtual LitteralNumerique* operator*(LitteralNumerique* b);
    virtual LitteralNumerique* operator/(LitteralNumerique* b);
};


class Pile {
    unsigned int nb;
	unsigned int nbMax;
    string message;
	void agrandissementCapacite();
	unsigned int nbAffiche;
    LitteralNumerique* tab [100];
	int current=0;
public:
	Pile():nb(0),nbMax(0),message(""),nbAffiche(4){}
    void push(LitteralNumerique* e);
    LitteralNumerique* pop();
	bool estVide() const { return nb==0; }
    unsigned int taille() const { return current; }
	void affiche(ostream& flux);
	Reel& top() const;
	unsigned int getNbItemsToAffiche()const { return nbAffiche; }
	void setNbItemsToAffiche(unsigned int n) { nb=n; }
    void setMessage(const string& m) { message=m; }
    string getMessage() const { return message; }
    QString affiche();


};







}


ostream& operator<<(ostream& flux,Exp::Fraction& m);

ostream& operator<<(ostream& flux,Exp::Entier& m);

ostream& operator<<(ostream& flux,Exp::Atome& m);

ostream& operator<<(ostream& flux,Exp::Reel& m);

ostream& operator<<(ostream& flux,Exp::FractionException& m);

ostream& operator<<(ostream& flux,Exp::Pile& m);

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
