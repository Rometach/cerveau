#ifndef DENTRITE_H
#define DENTRITE_H

#include "Synapse.h" // je sais pas si c'est necessaire pour retourner un pointeur vers un synapse??

/******************************
    Si tu es d'accord, on fait
    une classe avec des fonctions
    histoire que tout soit auto-gèré
    et qu'on ne soit qu'utilisateur
    de cette classe
******************************/

class Dentrite
{
    public:
        Dentrite();
        virtual ~Dentrite();

        Synapse* get_synapse(unsigned int indice_synapse) const; /* "const"
                                                                    signale à la l'objet
                                                                    que ses attributs ne
                                                                    sont pas modifié par
                                                                    la méthode: ça génère
                                                                    un meilleur code binaire
                                                                    */
        unsigned int get_nb_synapse() const;
    protected:
    private:
        unsigned int _n; // nb de dentrites que l'on retourne
        unsigned int _taille_tab; // nb cases dispo (ultra privé)
        // tab dyn de pointeurs vers synapse ??

};

#endif // DENTRITE_H
