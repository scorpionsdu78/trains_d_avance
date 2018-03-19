#ifndef METRO_H_INCLUDED
#define METRO_H_INCLUDED

#include <vector>


class Gare;
class Ligne;

class Metro
{
    private:

        std::vector<Gare*> stations;

        std::vector<Ligne*> lignes;


};

#endif // METRO_H_INCLUDED
