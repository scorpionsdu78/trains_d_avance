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

	int pos_ligne;      // L'indice dans le vector de gare de [ligne] de la dernière gare où s'est trouvé le train

    bool transition;    // variable qui indique si on doit repasser par une initialisation de la fonctin d'acualisation

    bool sens_logique;

    int mode;

    float a;

    float b;

    float dist;

	Gare* position;     // INUTILE

	Ligne* ligne;       // Pointeur sur la ligne sur laquelle se trouve le train

	std::pair<float,float> coords;  // Les coordonnées absolue du train sur le plan de taille 16x16

	void init_transport();



};

void test1(void);









#endif
