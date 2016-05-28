#include "Synapse.h"

bool Synapse::cycle=0;

Synapse::Synapse()
{
    _axo=0;
    _den=0;
}

Synapse::~Synapse()
{
    //dtor
}

Activite Synapse::get_activite(){ if(_axo == 0 && _den == 0) _act.reset();return _act;}

void Synapse::changer_cycle(){cycle =(cycle+1)%2;}
