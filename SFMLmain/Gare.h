#pragma once
#ifndef GARE_H_INCLUDED
#define GARE_H_INCLUDED

#include<string>
#include<vector>
#include<utility>

#include"Train.h"


class Ligne;
class Train;

class Gare
{
        friend Gare* find_stations(const std::vector<Gare*> &gares, std::string name);
public:
    Gare(std::string _nom, std::pair<int,int> _coords);
	~Gare();
	void recuperer_voyageur(int nombre);
	int donner_voyageur(Train* tr);
	int nb_voyageur();
	void liberer_voyageur();
	void nouv_voyageur();
	void presentation() const;
	int ping_freq() const;


private:
    std::string nom;
    int voyageurs;
    std::vector<Ligne*> lignes;
    std::pair<int,int> coords;
    int freq;




};











#endif
