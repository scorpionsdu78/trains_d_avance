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

    std::pair<float,float> getCoords() const;



private:

	int nb_passager;

	int pos_ligne;

    bool transition;

    bool sens_logique;

    int mode;

    int a;

    int b;

    float dist;

	Gare* position;

	Ligne* ligne;

	std::pair<float,float> coords;

	void init_transport();



};

void test1(void);









#endif
