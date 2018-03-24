#pragma once
#ifndef TRAIN_H_INCLUDED
#define TRAIN_H_INCLUDED

#include <utility>
#include <cstdlib>

#include "Gare.h"

class Gare;
class Ligne;

class Train
{
public:
	Train();
	~Train();
	int donner_voyageur(Gare* gr);
	void recuperer_voyageur(Gare* gr);
	void actualiser_position();
	int place_disponible();
	void passage_gare(Gare* gr);




private:

	int nb_passager;

	Gare* position;

	Ligne* lignes;

	std::pair<int,int> positions;



};










#endif
