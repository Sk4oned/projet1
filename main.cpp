#include "mainwindow.h"
#include <QApplication>
#include "controleur.h"
#include "expression.h"
#include <sstream>

int main(int argc, char *argv[])
{

    using namespace Exp;

    Pile p;

    Controleur control(p);
    /*
    try{

    Fraction* f= new Fraction(5,1);
    Fraction* g= new Fraction(9);
    Entier* e= new Entier(5);
    Entier* m= new Entier(10);
    Atome* a= new Atome(7);
    Reel* r= new Reel(3.879);
    Reel* r1= new Reel(4.879);
    Reel* r2= new Reel(5.879);
    Reel* r3= new Reel(6.879);


    cout << *f << endl;
    cout << *g << endl;
    cout << *e << endl;
    cout << *m << endl;
    cout << *a << endl;
    cout << *r << endl;

    e=e->operator+(m);

    cout << *e << endl;

    cout << "\n" << endl;

    p.push(f);
    p.push(g);
    p.push(e);
    p.push(m);
    p.push(a);
    p.push(r);
    p.push(r1);
    p.push(r2);
    p.push(r3);



     cout << p;


    }catch(FractionException& fe)
    {
        cout << fe;
    }

    //cin >> Expression l;
    */

    QApplication a(argc, argv);
    MainWindow w(control);
    w.show();

    return a.exec();



}
