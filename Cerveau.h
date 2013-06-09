#ifndef CERVEAU_H
#define CERVEAU_H
#include "Neurone.h"
#include <stdlib.h>

class Cerveau
{
    public:
        Cerveau();
        virtual ~Cerveau();

    protected:
        Neurone* tabDyn;
        int nbNeurones;
        int nbMax;
        Neurone* neurin;
        Neurone* neurout;
    private:
        bool ajouterNeurone();
};

#endif // CERVEAU_H
