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
        void lire_gares(std::ifstream& file, int n);
        void lire_lignes(std::ifstream& file, int n);
        Gare* new_gare(std::string data);
        Ligne* new_ligne(std::string data);

    public:
        Metro(const char* file);
        ~Metro();
        void presentation();
        void lancer();

};

int to_int(std::string a);

void test();

#endif // METRO_H_INCLUDED
