#include "Metro.h"
#include <fstream>
#include<iostream>
#include <cstdlib>
#include <utility>
#include <string>
#include <sstream>
#include "Gare.h"
#include "Ligne.h"

using namespace std;

void error_msg(string msg)
{
        cerr << msg << endl;
        exit(1);
}

vector<string> split(string str, char c)
{
    string tmp = "";
    vector<string> vect;
    int len = str.size();
    for(int i = 0; i < len; i++)
    {
        if(str[i] == c)
        {
            vect.push_back(tmp);
            tmp = "";
        }
        else
        {
            tmp += str[i];
        }
    }
    vect.push_back(tmp);
    return vect;
}


Metro::Metro(const char* file)
{
    ifstream plans(file,ios::in);
    vector<string> tmp;
    if(plans)
    {
        string info;
        getline(plans, info);
        tmp = split(info,' ');

        cout << tmp.size() << endl;
        if(tmp.size() != 2 && tmp[0] != "g")
        {
            error_msg("Erreur lecture fichier: s'attend à g");
        }

        lire_gares(plans,stoi(tmp[1]));

    }
    else
    {
        error_msg("Erreur ouverture fichier");
    }
}

Metro::~Metro()
{
    for(size_t i = 0; i < stations.size(); i++)
    {
        if(stations[i] != nullptr)
            delete stations[i];
    }
    for(size_t i = 0; i < lignes.size(); i++)
    {
        if(lignes[i] != nullptr)
        {
            delete lignes[i];
        }
    }
}

void Metro::lire_gares(std::ifstream& file, int n)
{
        string data;
        Gare* tmp;
        for(int i = 0; i < n; i++)
        {
            getline(file, data);
            tmp = new_gare(data);
            stations.push_back(tmp);
            tmp->presentation();
        }
}

Gare* Metro::new_gare(string data)
{
    vector<string> vect = split(data,' ');
    if(vect.size() != 3)
    {
        error_msg("Erreur lecture fichier: s'attend à 3 param (gare)");
    }
    pair<int,int> coords = make_pair(stoi(vect[1]),stoi(vect[2]));
    return new Gare(vect[0],coords);
}