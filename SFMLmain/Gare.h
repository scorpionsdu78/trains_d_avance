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
    // constructeur d'une garre: nom de la gare et une pair de coordonnées sont passés en paramètre
    Gare(std::string _nom, std::pair<int,int> _coords);
<<<<<<< HEAD
    ~Gare();
    void recuperer_voyageur(int nombre);
    int donner_voyageur(Train* tr);
    int nb_voyageur();
    void liberer_voyageur();
    void nouv_voyageur();
    void presentation() const;
    int ping_freq() const;

    std::pair<int,int> getCoords() const; // simple getter des coords
=======
	~Gare();
	void recuperer_voyageur(int nombre);
	int donner_voyageur(Train* tr);
	int nb_voyageur();
	void liberer_voyageur();
	void nouv_voyageur();
	void presentation() const;
	int ping_freq() const;
	std::pair<int,int> get_coords() const;
>>>>>>> 3d15c44de59d8bbfdaea465ee6d53bf46bda06c7


private:
    std::string nom;
    int voyageurs;
    std::vector<Ligne*> lignes;
    std::pair<int,int> coords;
    int freq;




};











#endif
