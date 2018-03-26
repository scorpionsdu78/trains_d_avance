#include "Gare.h"
#include <iostream>

using namespace std;


Gare* find_stations(const std::vector<Gare*> &gares, std::string name)
{
    for(size_t i = 0; i < gares.size(); i++)
    {
        if(gares[i]->nom == name)
        {
            return gares[i];
        }
    }
    return nullptr;
}


Gare::Gare(string _nom, pair<float,float> _coords)
{
    nom = _nom;
    voyageurs = 25;
    coords = _coords;

    freq = 80;

}

Gare::~Gare()
{
}


void Gare::presentation() const
{
    cout << nom << " " << coords.first << " " << coords.second << " " << "possede " << voyageurs << "voyageur" << endl;

}

void Gare::recuperer_voyageur(int nombre)
{
    voyageurs += nombre;

}

int Gare::donner_voyageur(Train* tr)
{
    //(void)tr;
    int dispo=0;
    int don=0;

    dispo = tr->place_disponible();

    if(voyageurs<=dispo)
        don = voyageurs;

    else if(voyageurs > dispo)
        don = dispo;

    voyageurs = voyageurs - don;
    return don;

    /*int don=5;

    if(voyageurs - don <= 0)
    {
        voyageurs =0;
        recuperer_voyageur(15);
    }

    else
        voyageurs =- don;

    return don;*/

}

int Gare::nb_voyageur()
{
    return voyageurs;
}

int Gare::ping_freq() const
{
    return freq;
}

pair<float,float> Gare::get_coords() const
{
    return coords;
}

