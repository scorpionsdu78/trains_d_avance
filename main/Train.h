#pragma once
#ifndef TRAIN_H_INCLUDED
#define TRAIN_H_INCLUDED



class Gare;
class Ligne;

class Train
{
public:
	Train();
	~Train();
	int donner_voyageur();
	void recuperer_voyageur(Gare* gr);
	void actualiser_position();



private:

	int nb_passager;

	Gare* position;

	Ligne* lignes;

	std::pair<int,int> positions;



};










#endif
