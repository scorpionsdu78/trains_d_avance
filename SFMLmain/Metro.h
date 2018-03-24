#ifndef METRO_H_INCLUDED
#define METRO_H_INCLUDED

#include <vector>
#include <string>

class Gare;
class Ligne;

class Metro
{
    private:
        // liste des stations du métro
        std::vector<Gare*> stations;
        // liste des lignes du metro
        std::vector<Ligne*> lignes;
        // lit les gares à partir d'un ifstream. Le curseur doit être sur la première garre
        void lire_gares(std::ifstream& file, int n);
        // lit les lignes à partir d'un ifstream. Le curseur doit être sur la première ligne
        void lire_lignes(std::ifstream& file, int n);
        // créé une gare à partir d'une description via chaine de carractère
        // <nom> <coord_x> <coord_y>
        Gare* new_gare(std::string data);
        // créé une ligne à partir d'une description via chaine de carractère
        // <id> <nb_train> <gare_1> <gare_2> ...
        Ligne* new_ligne(std::string data);

    public:
        // constructeur du métro. Prend un paramètre un chemin vers fichier
        Metro(const char* file);
        ~Metro();
        // lister les lignes et leur garres
        void presentation();
        // lancer la simulation
        void lancer();

        // renvoie la taille du vector de Gare*
        int getStationsSize() const;

};

// Affiche un message d'erreur et quitte
void error_msg(std::string msg);

// convertis un string en int
int nstoi(std::string str);

// sépare une chaine str en plusieurs chaines stockées dans un vecteur de string.
// le séparateur est le char c
std::vector<std::string> split(std::string str, char c);


#endif // METRO_H_INCLUDED
