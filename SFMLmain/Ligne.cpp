#include<iostream>
#include "Ligne.h"

using namespace std;


Ligne::Ligne (int _id, vector<Gare*> _stations, vector<Train> _trains): id(_id), stations_lst(_stations), trains(_trains)
{}

Ligne::~Ligne()
{


}

void Ligne::ajout_train(Train tr)
{
    trains.push_back(tr);
}


void Ligne::presentation()
{
    cout << "# Presentation ligne: " << endl;
    cout << "Identifiant: " << id << endl;
    cout << "Nombre de trains: " << trains.size() << endl;
    cout << "Liste des gares: " << endl;
    for(size_t i = 0; i < stations_lst.size(); i++)
    {
        stations_lst[i]->presentation();
    }
    cout << "Liste des Trains: " << endl;
    for(size_t i = 0; i < trains.size(); i++)
    {
        trains[i].presentation();
    }
    cout << endl;
}

Gare* Ligne::find_gare(int i)
{

    return stations_lst[i];

}

void Ligne::nom()
{
    cout << id << endl;
}
