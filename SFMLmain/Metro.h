#ifndef METRO_H_INCLUDED
#define METRO_H_INCLUDED

#include <vector>
#include <string>

class Gare;
class Ligne;

class Metro
{
    private:
        // liste des stations du m�tro
        std::vector<Gare*> stations;
        // liste des lignes du metro
        std::vector<Ligne*> lignes;
        // lit les gares � partir d'un ifstream. Le curseur doit �tre sur la premi�re garre
        void lire_gares(std::ifstream& file, int n);
        // lit les lignes � partir d'un ifstream. Le curseur doit �tre sur la premi�re ligne
        void lire_lignes(std::ifstream& file, int n);
        // cr�� une gare � partir d'une description via chaine de carract�re
        // <nom> <coord_x> <coord_y>
        Gare* new_gare(std::string data);
        // cr�� une ligne � partir d'une description via chaine de carract�re
        // <id> <nb_train> <gare_1> <gare_2> ...
        Ligne* new_ligne(std::string data);

    public:
        // constructeur du m�tro. Prend un param�tre un chemin vers fichier
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

// s�pare une chaine str en plusieurs chaines stock�es dans un vecteur de string.
// le s�parateur est le char c
std::vector<std::string> split(std::string str, char c);


#endif // METRO_H_INCLUDED
