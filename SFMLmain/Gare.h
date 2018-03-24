#pragma once
#ifndef GARE_H_INCLUDED
#define GARE_H_INCLUDED

#include<string>
#include<vector>

#include"Train.h"


class Ligne;
class Train;

class Gare
{
    // trouve la station "name" dans le vecteur "gares". Retourne un pointeur sur cette gare.
    friend Gare* find_stations(const std::vector<Gare*> &gares, std::string name);
public:
    // constructeur d'une garre: nom de la gare et une pair de coordonn�es sont pass�s en param�tre
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
