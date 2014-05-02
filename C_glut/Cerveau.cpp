#include "Cerveau.h"

using namespace std;

Cerveau::Cerveau()
{
    cout<<"Debut construction cerveau"<<endl;
    taille = 0;
    taille_max=1000000;
    taux=5;
    nouveau = Geometrie::get_cube_centre();
    nouveau=3*nouveau*nouveau + 4 - 6*nouveau;
    allouee = 0;
    actif = 0;
    redimensionnement();

    cout<<"Fin construction cerveau"<<endl;
}

Cerveau::~Cerveau()
{
    cout<<"Destruction cerveau "<<endl;
    cout<<actif<<" "<<allouee<<" "<<taille<<endl;
    for(unsigned int i=0;i<taille;i++)
    {
        delete(_neu[i]);
    }
    free(_neu);

}

void Cerveau::frame()
{
    unsigned int i;

    //neu_mise_a_jour();


    if(nouveau>0)
    {

        creer_neuronne(nouveau);
        nouveau = 100;
        if(neu_mise_a_jour()){}
    }
    for(i=0; i<actif; i++)
    {
        _neu[i]->afficher();
    }
}

bool Cerveau::creer_neuronne(int quantite)
{
    Neurone **neu_inactif = NULL;
    if(actif<taille)
    {
        neu_inactif = (Neurone**) malloc((taille-actif) * sizeof(Neurone*));
        for(unsigned int i=0;i<(taille-actif);i++)
        {
            neu_inactif[i] = _neu[actif+i];
        }
        _gsyn.nouveau_neurone(neu_inactif, taille-actif, quantite);

        for(unsigned int i=0;i<(taille-actif);i++)
        {
            if(_neu[actif+i] == NULL) _neu[actif+i] = neu_inactif[i];
        }
        free(neu_inactif);
    }
}

bool Cerveau::redimensionnement()
{
    bool b(false);
    if(taille == 0)
    {
        taille = 2*nouveau;
        _neu = (Neurone**) malloc(taille * sizeof(Neurone*));
        for(unsigned int i=0;i<taille;i++)
        {
            _neu[i] = NULL;
        }
        b = true;
    }
    else if(taille < 2*allouee)
    {
        // Creation transfert
        Neurone** transfert = NULL;
        transfert = (Neurone**) malloc(taille * sizeof(Neurone*));
        for(unsigned int i=0;i<taille;i++)
        {
            transfert[i] = _neu[i];
        }

        // Desalocation et realocation de _neu

        free(_neu);

        unsigned int copie_taille(taille);
        taille*=2;
        _neu = (Neurone**) malloc(taille * sizeof(Neurone*));
        for(unsigned int i=0;i<taille;i++)
        {
            if(i<copie_taille) _neu[i] = transfert[i];
            else _neu[i] = NULL;
        }

        //desallocation de transfert

        free(transfert);

        b =  true;
    }
    return b;
}

bool Cerveau::neu_mise_a_jour()
{
    unsigned int i;
    bool b(false);
    for(i=allouee;i<taille;i++)
    {
        if(_neu[i] != NULL)
        {
            _neu[allouee]=_neu[i];
            allouee++;
            b = true;
        }
    }
    for(i=0;i<actif;i++)
    {
        if(_neu[i] == NULL)
        {
            _neu[i] = _neu[actif-1];
            actif--;
            _neu[actif] = _neu[allouee-1];
            allouee--;
            i--;
            b=true;
        }
        else if(_neu[i]->get_actif() == false)
        {
            _neu[allouee] = _neu[i];
            _neu[i] = _neu[actif-1];
            _neu[actif-1] = _neu[allouee];
            _neu[allouee] = NULL;
            actif--;
            i--;
            b=true;
        }
    }
    for(i=actif;i<allouee;i++)
    {
        if(_neu[i] == NULL)
        {
            _neu[i] = _neu[allouee-1];
            allouee--;
            i--;
            b=true;
        }
        else if(_neu[i]->get_actif() == true)
        {
            _neu[allouee] = _neu[actif];
            _neu[actif] = _neu[i];
            _neu[i] = _neu[allouee];
            _neu[allouee] = NULL;
            actif++;
            b=true;
        }
    }
    while(redimensionnement()==true) {cout<<"redimensionnement"<<endl;}
    cout<<actif<<" "<<allouee<<" "<<taille<<endl;
    return b;
}

bool Cerveau::destruction_doublons()
{
    unsigned int i, j;
    bool b(false);
    for(i=0;i<taille;i++)
    {
        for(j=i+1;j<taille;j++)
        {
            if(_neu[i] == _neu[j])
            {
                _neu[i]=NULL;
                b = true;
            }
        }
    }
    return b;
}
