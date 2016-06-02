#ifndef MATHS_H
#define MATHS_H
#include <string>
#include <iostream>

int PGCD(int a, int b){
    while(b!=0){
        int c=a%b;
        a=b;
        b=c;
    }
    return a;
}

void reduc_frac(int &n, int &d)
{
    int pgcd=PGCD(n,d);
    n/=pgcd;
    d/=pgcd;
}

#endif // MATHS_H
