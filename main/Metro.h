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

    public:
        Metro(std::string file);
        ~Metro();
        void lancer();

};

#endif // METRO_H_INCLUDED
