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
    // trouve la station "name" dans le vecteur "gares". Retourne un pointeur sur cette gare.
    friend Gare* find_stations(const std::vector<Gare*> &gares, std::string name);
public:
    Gare(std::string _nom, std::pair<float,float> _coords);
    ~Gare();
    void recuperer_voyageur(int nombre);
    int donner_voyageur(Train* tr);
    int nb_voyageur();
    void liberer_voyageur();
    void nouv_voyageur();
    void presentation() const;
    int ping_freq() const;

	std::pair<float,float> get_coords() const;
private:
    std::string nom;
    int voyageurs;
    std::vector<Ligne*> lignes;
    std::pair<float,float> coords;
    int freq;


};











#endif
