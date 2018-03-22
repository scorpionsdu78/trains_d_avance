#include "Metro.h"
#include <fstream>
#include<iostream>
#include <cstdlib>
#include <utility>
#include <string>
#include <sstream>
#include "Gare.h"

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

void Metro::lire_gare(std::ifstream& file)
{
        string ligne;
        Gare* gare = NULL;
        getline(file, ligne);
        gare = new_gare(ligne);
        stations.push_back(gare);

}

Gare* Metro::new_gare(string data)
{
    int taille=0;

    taille = data.size();

    string nom="";
    string x="";
    string y="";
	int i = 0;
    for(; i<taille && data[i]!=' '; i++)
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

    coord.first = to_int(x);
    coord.second = to_int(y);

    Gare* n_gare = new Gare(nom,coord);
	return n_gare;
}

int to_int(string a)
{
    int taille,r=0;

    taille = a.size();

    for(int i=0; i<taille; i++)
    {
        r= (r*10) + (a[i]-48);
    }

    return r;
}

void test()
{
    int a;
    string b="14";

    a=to_int(b);

    cout << a << endl;
}
