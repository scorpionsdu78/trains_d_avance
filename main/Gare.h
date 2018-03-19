#pragma once
#ifndef GARE_H_INCLUDED
#define GARE_H_INCLUDED

#include<string>
#include<vector>



class Ligne;

class Gare
{
public:
    Gare(std::string _nom, std::vector<Ligne*> _lignes, std::pair<int,int> _coords);
	~Gare();

private:
    std::string nom;
    std::vector<int> voyageurs;
    std::vector<Ligne*> lignes;

    std::pair<int,int> coords;




};











#endif
