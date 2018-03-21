#include "Metro.h"
#include <fstream>
#include<iostream>
#include <cstdlib>
#include <utility>
#include <string>

using namespace std;

Metro::Metro(const char* file)
{

    ifstream plans(file,ios::in);

    if(plans)
    {
        lire_gare(plans);

    }

    else
    {

        cerr << "erreur ouverture fichier" << endl;
        exit(1);
    }



}

void Metro::lire_gare(std::ifstream file)
{
        string ligne;
        Gare* gare = NULL;
        /*int j=0;


        while(getline(fichier, ligne))
        {
            if(ligne)
            {
                j=ligne.size();

                for()

            }

        }*/

        ligne=getline(file, ligne);

        gare = new_gare(ligne);

        gare->presentation();
}

Gare* Metro::new_gare(string data)
{
    int taille=0;

    taille = data.size();

    string nom="";
    string x="";
    string y="";

    for(int i=0; i<taille && data[i]!=' '; i++)
    {
        nom+=data[i];
    }

    i++;

    for(;i<taille && data[i]!=' ';i++)
    {
        x+=data[i];
    }

    i++;

    for(;i<taille && data[i]!=' ';i++)
    {
        y+=data[i];
    }

    pair<int,int> coord;

    coord.first = stoi(x);
    coord.second = stoi(y);

    Gare* n_gare = new Gare(nom,coord);

}

