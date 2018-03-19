#pragma once
#ifndef TRAIN_H_INCLUDED
#define TRAIN_H_INCLUDED

#include "Gare.h"
#include "Ligne.h"

class Train
{
public:
	Train();
	~Train();

private:

	int nb_passager;

	Gare* position;

	Ligne ligne;



};










#endif