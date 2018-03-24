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


Gare::Gare(string _nom, pair<int,int> _coords)
{
    nom = _nom;
    voyageurs = 0;
    coords = _coords;


}

Gare::~Gare()
{
}


void Gare::presentation() const
{
    cout << nom << " " << coords.first << " " << coords.second << " " << endl;

}

void Gare::recuperer_voyageur(int nombre)
{
    voyageurs += nombre;

}

int Gare::donner_voyageur(Train* tr)
{
    int dispo=0;
    int don=0;

    dispo = tr->place_disponible();

    if(voyageurs<=dispo)
        don = voyageurs;

    else if(voyageurs > dispo)
        don = dispo;

    voyageurs = voyageurs - don;
    return don;

}

int Gare::ping_freq() const
{
    return freq;
}

pair<int,int> Gare::getCoords() const
{
    return coords;
}
