#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

#include <utility>

#include "Gare.h"
#include "Train.h"

std::pair<float,float> equation(Gare* garea, Gare* gareb);

float distf(std::pair<float,float> g_a, std::pair<float,float> g_b);


#endif // FONCTION_H_INCLUDED
