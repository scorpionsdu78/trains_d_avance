#include "Gare.h"
using namespace std;

Gare::Gare(string _nom, vector<Ligne*> _lignes)
{
    nom = _nom;
    lignes = _lignes;
    voyageurs = vector<int>();
}

Gare::~Gare()
{
}
