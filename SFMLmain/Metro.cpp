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

int nstoi(string str)
{
    int res = 0;
    for(size_t i = 0; i < str.size(); i++)
    {
        if(str[i] < '0' || str[i] > '9')
            error_msg("Erreur stoi: non compris entre 0 et 9");
        res *= 10;
        res += str[i] - '0';
    }
    return res;
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

        if(tmp.size() != 2 && tmp[0] != "g")
        {
            error_msg("Erreur lecture fichier: s'attend a g");
        }

        lire_gares(plans,nstoi(tmp[1]));

        getline(plans,info);
        getline(plans, info);
        tmp = split(info,' ');

        if(tmp.size() != 2 && tmp[0] != "l")
        {
            error_msg("Erreur lecture fichier: s'attend a l");
        }

        lire_lignes(plans,nstoi(tmp[1]));

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
    pair<int,int> coords = make_pair(nstoi(vect[1]),nstoi(vect[2]));
    return new Gare(vect[0],coords);
}

void Metro::lire_lignes(std::ifstream& file, int n)
{
    string data;
    Ligne* tmp;
    for(int i = 0; i < n; i++)
    {
        getline(file,data);
        tmp = new_ligne(data);
        lignes.push_back(tmp);
    }
}

Ligne* Metro::new_ligne(string data)
{
    vector<string> vect = split(data,' ');
    int id = nstoi(vect[0]);
    int nb_train = nstoi(vect[1]);
    vector<Train> trains;
    vector<Gare*> stations_ligne;

    for(size_t i = 2; i < vect.size(); i++)
    {
        Gare* tmp = find_stations(stations,vect[i]);
        if(tmp == nullptr)
        {
            error_msg("Train non trouvé lors de la création de ligne. Vérifier fichier.");
        }
        stations_ligne.push_back(tmp);
    }
    Ligne* new_l = new Ligne(id,stations_ligne,trains);

    for(int i = 0; i < nb_train; i++)
    {
        new_l->ajout_train(Train(stations_ligne[0],new_l,stations_ligne[0]->get_coords()));
    }
    return new_l;
}

void Metro::presentation()
{
    for(size_t i = 0; i < lignes.size(); i++)
    {
        lignes[i]->presentation();
    }
}
