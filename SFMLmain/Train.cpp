#include "Train.h"
#include "fonction.h"

#include <iostream>
#include <cmath>

using namespace std;

Train::Train(Gare* _position, Ligne* _ligne, std::pair<float,float> _coords, int _pos_ligne): position{_position}, ligne{_ligne}, coords{_coords}, pos_ligne(_pos_ligne)
{
    nb_passager = 25;

    transition = true;

    sens_logique =true;

    a=0;

    b=0;

    dist=0;

    mode = 0;
}

Train::~Train()
{
}



int Train::place_disponible() const
{
    return 100 - nb_passager; //on a 100 place par train, on retourne les 100 place moin le nombre de place prise
}

void Train::recuperer_voyageur(Gare* gr)
{
    //(void)gr;
    int tmp;

    tmp = gr->donner_voyageur(this);//on demande a la gare combien de voayageur elle veut donner a ce trains

    nb_passager += tmp; //on incrémente le nombre de passager en fonction de voyageur donné par la gare

}

int Train::donner_voyageur(Gare* gr)
{
    //(void)gr;

    int frequentation;
    int deversement;
    int don;

    frequentation = gr->ping_freq();//on regarde la taux de fréquentation de la gare

    deversement = rand();

    deversement = deversement % (frequentation - 10) + 10;//on calcule le nombre de personne d'éposé celons un pourcentage random comprix entre 10 et fréquentation

    don = (nb_passager * deversement)/100;

    nb_passager -= don;// on décrémente


    return don;//on retourne le nombre de voyageur déposé

}

void Train::passage_gare(Gare* gr)
{

    int tmp(donner_voyageur(gr));//on initialise tmp avec la valeur de voyageur que le train donne a la gare

    recuperer_voyageur(gr);//on récupère les voaygeur de la gare


    gr->recuperer_voyageur(tmp);// puis on les donne a la gare
}

void Train::presentation() const
{
    cout << "je suis sur la ligne " << endl;
    ligne->nom();
    cout <<"et j'ai" << nb_passager <<"passager " << endl;
}

void Train::actualiser_position()
{

    pair<float,float> coor_dest;
    Gare* gare_b =nullptr;

    if(sens_logique == true)//celons le sens de circulation du train
        gare_b = ligne->find_gare(pos_ligne+1);//on choisit la gare de destination du trains

    else if (sens_logique == false)
        gare_b = ligne->find_gare(pos_ligne-1);//de même ici



    coor_dest = gare_b->get_coords();//on prend les coordonner de la gare de destination


    if(transition == true)//si on est sur un nouveau deplacement on reinitialise la deplacement
    {
        init_transport();//on initialise la deplacement du trains
        transition = false;
    }


    if(mode == 1 )//si la trajectoire est affine
    {

        transport_afine(coor_dest,gare_b);//on appelle la fonction deplacement afine


    }

    else if(mode == 2)//sinon
    {
       // dist = distf(coor_dest,coords);

        transport_vertical(coor_dest,gare_b);//on appelle la fonction deplacment verticale

    }

}

pair<float,float> Train::getCoords() const
{
    return coords;
}

void Train::init_transport()
{
    Gare* gare_a = nullptr;
    Gare* gare_b = nullptr;

    pair<float,float> tmp;
    pair<float,float> coor_dest;

    if(sens_logique == true)
    {

        gare_a = ligne->find_gare(pos_ligne);     // vecteur sur une gare a qui représente la gare de départ
        gare_b = ligne->find_gare(pos_ligne+1);   // vecteur sur une gare qui représente la gare d'arrivée
    }

    else if(sens_logique == false)
    {

        gare_a = ligne->find_gare(pos_ligne);     // vecteur sur une gare a qui représente la gare de départ
        gare_b = ligne->find_gare(pos_ligne-1);   // vecteur sur une gare qui représente la gare d'arrivée
    }

    coor_dest = gare_b->get_coords();//on récupère les coordonné de la estination
    coords = gare_a->get_coords();//on récupère les coordonné de la gare de départ

    if(coords.first != coor_dest.first )//on définie si c'est une droite afine
        mode=1;

    else if (coords.first == coor_dest.first )//on définie si c'est une droite verticale
        mode=2;


    tmp = equation(gare_a,gare_b);//on détermine le coef directeur de l'équation et la distance entre les gare
    a = tmp.first;//on récupère le coef de l'équation
    dist = tmp.second;//on récupère la distance


    b = coords.second - a * coords.first;//on établies la valeur de l'ordonné a l'origine

}


void Train::transport_afine(pair<float,float> coor_dest, Gare* gare_b)
{
    int signe;
    pair<float,float> old;

    if(coor_dest.first - coords.first > 0)//on determine si on parcour la droite de manière croissante ou decroissante
        signe = 1;

    else if(coor_dest.first - coords.first < 0)
        signe = 0;


    old.first = coords.first;//on copie les coordonné du départ pour les calcul de distance
    old.second = coords.second;

    if(signe)// si le signe est positif on progresse de manière croissante
    {

        coords.first = coords.first + 0.1;
        coords.second = (coords.first * a) + b;
    }

    else if(!signe)//sinon on décroit
    {

        coords.first = coords.first - 0.1;
        coords.second = (coords.first * a)+b;
    }

    dist = distf(coords,coor_dest);//on reclacule la distance

    //cout << "dist =" << dist << endl;

    if (dist<0.1)//et si on est suffisament proche de la gare
    {

        transition=true;

        coords = coor_dest;

        passage_gare(gare_b);//on effectue le passage en gare


        if(sens_logique == true)//si on avance dans le sens logique
            pos_ligne++;//on incrémente le passage du train

        else if (sens_logique == false)//si on est dans le sens inverse
            pos_ligne--;//on décrémente le passage du train

        //cout << "### DEBUG\n";
        //cout << pos_ligne << endl;
        //cout << ligne->getNombreGare() << endl;
        if ((pos_ligne + 1)>= ligne->getNombreGare())//on regarde pour faire demi tour
        {
            //cout << "### FALSE ###\n";
            sens_logique = false;
        }

        else if ((pos_ligne - 1)< 0)
            sens_logique =true;

    }


}

void Train::transport_vertical(pair<float,float> coor_dest, Gare* gare_b)
{

    //identique a la fonction précédente seul change les equation

    int signe;
    pair<float,float> old;

    if(coor_dest.second - coords.second > 0)
        signe = 1;

    else if(coor_dest.second - coords.second < 0)
        signe = 0;

    old.first = coords.first;
    old.second = coords.second;

    if(signe)
    {
        coords.second = (coords.second  + 0.1);
    }

    else if(!signe)
    {
        coords.second = coords.second - 0.1;
    }


    dist = distf(coords,coor_dest);

    if (dist<0.1)
    {

        transition=true;

        coords = coor_dest;

            //passage_gare(gare_b);

        if(sens_logique == true)
            pos_ligne++;

        else if (sens_logique == false)
            pos_ligne--;

            //cout << "### DEBUG\n";
            //cout << pos_ligne << endl;
            //cout << ligne->getNombreGare() << endl;

        if ((pos_ligne + 1)>= ligne->getNombreGare())
            sens_logique = false;

        else if ((pos_ligne - 1)<= 0)
            sens_logique =true;


    }
}

