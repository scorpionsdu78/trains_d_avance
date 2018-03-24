#include "Ligne.h"

using namespace std;

Ligne::Ligne(int _id, vector<Gare*> _stations, vector<Train> _trains)
{

    id = _id;

    stations = _stations;

    trains = _trains;

}

Ligne::~Ligne()
{


}

