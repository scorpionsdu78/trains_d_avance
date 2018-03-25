#pragma once
#ifndef LIGNE_H_INCLUDED
#define LIGNE_H_INCLUDED

#include<vector>

#include"Train.h"

class Gare;


class Ligne
{
public:
	Ligne(int _id, std::vector<Gare*> _stations, std::vector<Train> _trains);
	~Ligne();
	void actualiser_trains();
	void presentation();
    void ajout_train(Train tr);
private:

    int id;

    std::vector<Gare*> stations_lst;

    std::vector<Train> trains;


};



#endif
