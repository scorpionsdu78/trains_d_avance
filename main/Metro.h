#ifndef METRO_H_INCLUDED
#define METRO_H_INCLUDED

#include <vector>
#include <string>

class Gare;
class Ligne;

class Metro
{
    private:
        std::vector<Gare*> stations;
        std::vector<Ligne*> lignes;
        void lire_gare(std::ifstream& file);
        void lire_ligne(std::ifstream& file, int i);
        Gare* new_gare(std::string data);


    public:
        Metro(const char* file);
        //~Metro();
        void lancer();

};

#endif // METRO_H_INCLUDED
