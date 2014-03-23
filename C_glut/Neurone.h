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

        Axone *_axo; // pointeur sur un axone
};

#endif // NEURONE_H
