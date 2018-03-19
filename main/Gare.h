#pragma once
#ifndef GARE_H_INCLUDED
#define GARE_H_INCLUDED

#include<string>
#include<vector>
#include<utility>

#include "Ligne.h"

class Ligne;

class Gare
{
public:
    Gare(std::string _nom, std::vector<Ligne*> _lignes, std::pair<int,int> _coord);
	~Gare();

private:
    std::string nom;
    std::vector<int> voyageurs;
    std::vector<Ligne*> lignes;

    std::pair<int,int> coords;




};











#endif
