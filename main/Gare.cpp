#include "Gare.h"
#include <iostream>

using namespace std;

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
