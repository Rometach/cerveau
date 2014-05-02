#ifndef NEURONE_H
#define NEURONE_H

#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Axone.h"
#include "Geometrie.h"
#include "Zone_Synaptique.h"

class Neurone
{
    public:
        Neurone();
        virtual ~Neurone();

        bool creation(Position pos, Position vect);
        void reinitialiser();
        void reinitialiser(Position const& vect);

        // get
        bool get_actif();
        Position get_position();
        Position get_vect();


        void ajouter_zsyn(Zone_Synaptique *zsyn, bool axone);

        // GLUUUUUT
        void afficher();
        void afficher(int couleur);
        void afficher(int couleur, int alpha);

        Axone _axo; // axone
        Dendrite _den; // tableau dyn de dendrites

    protected:
    private:

        Zone_Synaptique **_zden;
        Zone_Synaptique **_zaxo;
        unsigned int t_zden;
        unsigned int t_zaxo;
        Position _pos; // toujours centrer en (0, 0)
        Position _vect;
        Quanta _q; // quanta
        bool actif;
};

#endif // NEURONE_H
