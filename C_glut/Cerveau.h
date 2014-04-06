#ifndef CERVEAU_H
#define CERVEAU_H

#include "Neurone.h"

class Cerveau
{
    public:
        Cerveau();
        virtual ~Cerveau();
        void frame();
    protected:
    private:

        Neurone ***_neu; // tableau dyn 3d de neurones
        unsigned int taille[3]; // taille (agrandissement symétrique)
};

#endif // CERVEAU_H
