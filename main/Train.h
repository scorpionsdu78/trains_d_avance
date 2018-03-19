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


private:

	int nb_passager;

	Gare* position;

	Ligne* lignes;



};










#endif
