#pragma once
#ifndef GARE_H_INCLUDED
#define GARE_H_INCLUDED
#include<string>
#include<vector>
#include "Ligne.h"


class Gare
{
public:
    Gare(std::string _nom, std::vector<Ligne*> _lignes);
	~Gare();

private:
    std::string nom;
    std::vector<int> voyageurs;
    std::vector<Ligne*> lignes;



};











#endif
