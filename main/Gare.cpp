#include "Gare.h"
#include <iostream>

using namespace std;

Gare::Gare(string _nom, pair<int,int> _coords)
{
    nom = _nom;
    voyageurs = 20;
    coords = _coords;

    freq = 10;


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


