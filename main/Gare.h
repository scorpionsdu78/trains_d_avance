#pragma once
#ifndef GARE_H_INCLUDED
#define GARE_H_INCLUDED

#include<string>
#include<vector>



class Ligne;
class Train;

class Gare
{
public:
    Gare(std::string _nom, std::vector<Ligne*> _lignes, std::pair<int,int> _coords);
	~Gare();
	void recuperer_voyageur(int nombre);
	int donner_voyageur(Train* tr);
	int nb_voyageur();
	void liberer_voyageur();
	void nouv_voyageur();


private:
    std::string nom;
    int voyageurs;
    std::vector<Ligne*> lignes;

    std::pair<int,int> coords;




};











#endif
