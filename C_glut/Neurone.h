#ifndef NEURONE_H
#define NEURONE_H

//#include "Synapse.h" déjà inclue dans dentrite
#include "Dentrite.h"

class Neurone
{
    public:
        Neurone();
        virtual ~Neurone();
    protected:
    private:

        Synapse _syn;
        Dentrite _den;
};

#endif // NEURONE_H
