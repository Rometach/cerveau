#ifndef NEURONE_H
#define NEURONE_H

#include "Axone.h"

class Neurone
{
    public:
        Neurone();
        virtual ~Neurone();
    protected:
    private:

        Axone _axo; // axone
        Dendrite *_den; // tableau dyn de dendrites
        Quanta _q; // quanta
};

#endif // NEURONE_H
