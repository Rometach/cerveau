#include "Neurone.h"



Neurone::Neurone()
{
    int i;
    for(i=0;i<LIENS_MAX;i++)
    {copains[i]=NULL;}
    quantite=0;
    satiete=1;
}


Neurone::~Neurone()
{
    int i;
    for(i=0;i<LIENS_MAX;i++)
    {
        if(copains[i]!=NULL) {delete copains[i];}
    }
}
