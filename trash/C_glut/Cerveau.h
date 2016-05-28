#ifndef CERVEAU_H
#define CERVEAU_H

#include "Grille_Synaptique.h"

class Cerveau
{
    public:
        Cerveau();
        virtual ~Cerveau();
        void frame();
    protected:
    private:

        Neurone **_neu;
        Grille_Synaptique _gsyn;
        unsigned int taille; // taille
        unsigned int taille_max;
        unsigned int taux;
        unsigned int nouveau;
        unsigned int allouee;
        unsigned int actif;

        // méthodes privées

        // neuronnes
        bool creer_neuronne(int quantite);
        bool redimensionnement();
        bool neu_mise_a_jour();
        bool destruction_doublons();
};

#endif // CERVEAU_H
