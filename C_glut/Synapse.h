#ifndef SYNAPSE_H
#define SYNAPSE_H

#include "Dendrite.h"

class Synapse
{
    public:
        Synapse();
        virtual ~Synapse();
    protected:
    private:

        Dendrite **_den; // Tableau dyn de pointeurs sur des dendrites
};

#endif // SYNAPSE_H
