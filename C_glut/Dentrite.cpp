#include "Dentrite.h"

Dentrite::Dentrite()
{
    //ctor
}

Dentrite::~Dentrite()
{
    //dtor
}

//Synapse* Dentrite::get_synapse(unsigned int indice_synapse) const {return *???;}
unsigned int Dentrite::get_nb_synapse() const {return _n;}
