#include "Neurone.h"

using namespace std;
Neurone::Neurone()
{
    _zden=NULL;
    _zaxo=NULL;
    _zden=(Zone_Synaptique**) malloc( Geometrie::get_nb_sommet()/2 * sizeof(Zone_Synaptique*));
    _zaxo=(Zone_Synaptique**) malloc( Geometrie::get_nb_sommet()/2 * sizeof(Zone_Synaptique*));
    t_zaxo=Geometrie::get_nb_sommet()/2;
    t_zden=Geometrie::get_nb_sommet()/2;

    for(unsigned int i=0;i<t_zden;i++)
    {
        _zden[i] = NULL;
    }
    for(unsigned int i=0;i<t_zaxo;i++)
    {
        _zaxo[i] = NULL;
    }

    t_zden=0;
    t_zaxo=0;
    actif=0;
    _pos= {0, 0, 0};
    _vect = {0, 0, 0};
}

Neurone::~Neurone()
{
    free(_zden);
    free(_zaxo);

}

bool Neurone::creation(Position pos, Position vect)
{
    bool Maj(false);
    _pos=pos;
    _vect=vect;
    actif = 1;
}

void Neurone::reinitialiser()
{
    actif = 1;
}

void Neurone::reinitialiser(Position const& vect)
{
    _vect=vect;
    actif = 1;
}

bool Neurone::get_actif(){return actif;}
Position Neurone::get_position(){return _pos;}
Position Neurone::get_vect(){return _vect;}

void Neurone::ajouter_zsyn(Zone_Synaptique *zsyn, bool axone)
{
    if(axone)
    {
        if(_zaxo[t_zaxo-1]==NULL)
        {
            for(unsigned int i=0;i<t_zaxo;i++)
            {
                if(_zaxo[i] == NULL)
                {
                    _zaxo[i]=zsyn;
                    i = t_zaxo;
                }
            }
        }
    }
    else
    {
        if(_zden[t_zden-1]==NULL)
        {
            for(unsigned int i=0;i<t_zden;i++)
            {
                if(_zden[i] == NULL)
                {
                    _zden[i]=zsyn;
                    i = t_zden;
                }
            }
        }
    }
}

void Neurone::afficher(){afficher(0, 1);}
void Neurone::afficher(int couleur){afficher(couleur, 1);}
void Neurone::afficher(int couleur, int alpha)
{

    unsigned int r(0), v(0), b(0);
    switch(couleur)
    {
        default:
        break;
    }

    glColor3d(r/1000000, v/1000000, b/1000000);

    glPushMatrix();
        glTranslated(_pos.x, _pos.y,_pos.z);
        glutSolidSphere(0.5,16,16);
    glPopMatrix();
}

