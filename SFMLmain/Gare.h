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
<<<<<<< HEAD
    Gare(std::string _nom, std::pair<float,float> _coords);
=======
    // constructeur d'une garre: nom de la gare et une pair de coordonn�es sont pass�s en param�tre
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
>>>>>>> f211f464a25e2eac2940051fdbb2738d6ae273fb
	~Gare();
	void recuperer_voyageur(int nombre);
	int donner_voyageur(Train* tr);
	int nb_voyageur();
	void liberer_voyageur();
	void nouv_voyageur();
	void presentation() const;
	int ping_freq() const;
<<<<<<< HEAD
	std::pair<float,float> get_coords() const;
=======
	std::pair<int,int> get_coords() const;
>>>>>>> 3d15c44de59d8bbfdaea465ee6d53bf46bda06c7
>>>>>>> f211f464a25e2eac2940051fdbb2738d6ae273fb


private:
    std::string nom;
    int voyageurs;
    std::vector<Ligne*> lignes;
    std::pair<float,float> coords;
    int freq;




};











#endif
