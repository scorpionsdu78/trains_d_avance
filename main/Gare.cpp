#include "Gare.h"
using namespace std;

Gare::Gare(string _nom, vector<Ligne*> _lignes, pair<int,int> _coords)
{
    nom = _nom;
    lignes = _lignes;
    voyageurs = vector<int>();
    coords = _coords;
}

Gare::~Gare()
{
}
