#include "Cerveau.h"

Cerveau::Cerveau()
{
    tabDyn= (Neurone*) malloc(2*sizeof(Neurone));

    nbNeurones=1;
    nbMax=2;
    neurin=&tabDyn[0];
    neurout=&tabDyn[0];
}

bool Cerveau::ajouterNeurone()
{
    return 0;
}

Cerveau::~Cerveau()
{
    free(tabDyn= (Neurone*) malloc(2*sizeof(Neurone)));
}
