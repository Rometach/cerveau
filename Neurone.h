#ifndef NEURONE_H
#define NEURONE_H

#include <iostream>


class Neurone
{
    public:
        Neurone();
        virtual ~Neurone();

    protected:
        static const int LIENS_MAX=10;
        Neurone* copains[5];
        int quantite;
        int satiete;
        static const int satieteMax=10;
    private:
};

#endif
