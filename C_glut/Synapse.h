#ifndef SYNAPSE_H
#define SYNAPSE_H

#include "Quanta.h"
#include "Signal.h"
#include "Activite.h"
#include <stdlib.h>
#include <stdio.h>

class Synapse
{
    public:
        Synapse();
        virtual ~Synapse();

        static void changer_cycle();
        Activite get_activite();

    protected:
    private:

        static bool cycle; // permet

    Quanta _q;
    bool _axo;
    bool _den;
    Signal _sig1;
    Signal _sig2;
    Activite _act;
};

#endif // SYNAPSE_H
