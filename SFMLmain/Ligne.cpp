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

int Ligne::getNombreGare() const
{
    return stations_lst.size();
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

int Ligne::getNombreLignes() const
{
    return stations_lst.size() - 1;
}

pair<float,float> Ligne::getCoordGare(int i) const
{
    return stations_lst[i]->get_coords();
}

void Ligne::actualiser_trains()
{
    unsigned int i;

    for(i=0; i<trains.size(); i++)
        trains[i].actualiser_position();
}

int Ligne::getNombreTrains() const
{
    return trains.size();
}

pair<float,float> Ligne::getCoordTrain(int i) const
{
    return trains[i].getCoords();
}
