#pragma once
#ifndef TRAIN_H_INCLUDED
#define TRAIN_H_INCLUDED

#include <utility>
#include <cstdlib>


#include "Gare.h"
#include "Ligne.h"

class Gare;
class Ligne;

class Train
{
public:
	Train(Gare* _position, Ligne* _ligne,std::pair<float,float> _coords);
	~Train();
	int donner_voyageur(Gare* gr);
	void recuperer_voyageur(Gare* gr);
	void actualiser_position();
	int place_disponible();
	void passage_gare(Gare* gr);
	void presentation();
    void init_tmp(Gare* origine, std::pair<float,float> coords);



private:

	int nb_passager;

	int pos_ligne;

	Gare* position;

	Ligne* ligne;

	std::pair<float,float> coords;



};

void test1(void);









#endif
