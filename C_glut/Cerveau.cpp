#include "Cerveau.h"

Cerveau::Cerveau()
{
    taille[0]=0;
    taille[1]=0;
    taille[2]=0;
}

Cerveau::~Cerveau()
{
    //dtor
}

void Cerveau::frame()
{
    int i;
    for(i= -1*taille[0]*taille[1]*taille[2]; i<taille[0]*taille[1]*taille[2]; i++)
    {

    }
}
