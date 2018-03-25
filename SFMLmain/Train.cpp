#include "Train.h"

#include <iostream>
#include <cmath>

using namespace std;

pair<float,float>* equation(Gare* garea, Gare* gareb);
float distf(pair<float,float> g_a, pair<float,float> g_b);

Train::Train(Gare* _position, Ligne* _ligne, std::pair<float,float> _coords): position{_position}, ligne{_ligne}, coords{_coords}
{
    nb_passager = 0;
    pos_ligne = 0;

    transition = true;

    a=0;

    b=0;

    dist=0;

    mode = 0;
}

Train::~Train()
{
}

void Train::init_tmp(Gare* origine, pair<float,float> _coords)
{
    nb_passager = 60;

    position = origine;

    coords = _coords;

}

int Train::place_disponible()
{
    return 100 - nb_passager;
}

void Train::recuperer_voyageur(Gare* gr)
{
    int tmp;

    tmp = gr->donner_voyageur(this);

    nb_passager += tmp;

}

int Train::donner_voyageur(Gare* gr)
{
    int frequentation;
    int deversement;
    int don;

    frequentation = gr->ping_freq();

    deversement = rand();

    cout << "deversement1 = " << deversement << endl;

    deversement = deversement % (frequentation - 10) + 10;

    don = (nb_passager * deversement)/100;

    cout << "fréquentation= " << frequentation << " deversement = " << deversement << "don= " << don << endl;

    nb_passager -= don;

    return don;

}

void Train::passage_gare(Gare* gr)
{
    int tmp;

    tmp=donner_voyageur(gr);

    recuperer_voyageur(gr);

    gr->recuperer_voyageur(tmp);
}

void Train::presentation()
{
    cout << "je suis sur la ligne " << endl;
    ligne->nom();
    cout <<"et j'ai" << nb_passager <<"passager " << endl;
}

void Train::actualiser_position()
{
    int signe;
    pair<float,float> old;
    pair<float,float> coor_dest;
    Gare* gare_b = ligne->find_gare(pos_ligne+1);


    coor_dest = gare_b->get_coords();

    cout << "transition = " << transition << endl;


    cout << "depart ( " << coords.first << " ; " << coords.second << " )"<<endl;
    cout << "arriver ( " << coor_dest.first << " ; " << coor_dest.second << " )"<<endl;

    if(transition == true)
    {
        init_transport();
        transition = false;
    }


    if(mode == 1 )
    {

        if(coor_dest.first - coords.first > 0)
            signe = 1;

        else if(coor_dest.first - coords.first < 0)
            signe = 0;


        old.first = coords.first;
        old.second = coords.second;

        if(signe)
        {

            coords.first = coords.first +1;
            coords.second = (coords.first * a) + b;
        }

        else if(!signe)
        {

            coords.first = coords.first - 1;
            coords.second = (coords.first * a)+b;
        }

        dist -= distf(old,coords);

        cout << "dist =" << dist << endl;

        if (dist<0.5)
        {

            transition=true;

            coords = coor_dest;

            //passage_gare(gare_b);

            pos_ligne++;
        }

    }

    else if(mode == 2)
    {
       // dist = distf(coor_dest,coords);

        if(coor_dest.second - coords.second > 0)
            signe = 1;

        else if(coor_dest.second - coords.second < 0)
            signe = 0;

        old.first = coords.first;
        old.second = coords.second;

        if(signe)
        {
            coords.second = (coords.second  + 1);
        }

        else if(!signe)
        {
            coords.second = coords.second - 1;
        }


        dist -= distf(old,coords);

        if (dist<0.5)
        {

            transition=true;

            coords = coor_dest;

            //passage_gare(gare_b);

            pos_ligne++;
        }


    }

}

pair<float,float>* equation(Gare* garea, Gare* gareb)
{
    pair<float,float>* r = new pair<float,float>;

    float xa,xb,ya,yb;

    pair<float,float> g_a = garea->get_coords();
    pair<float,float> g_b = gareb->get_coords();

    xa=g_a.first;
    ya=g_a.second;
    xb=g_b.first;
    yb=g_b.second;

    r->first = (yb-ya)/(xb-xa);

    r->second = distf(g_a,g_b);

    return r;

}

float distf(pair<float,float> g_a, pair<float,float> g_b)
{
    int xa,xb,ya,yb;
    float r;

    xa=g_a.first;
    ya=g_a.second;
    xb=g_b.first;
    yb=g_b.second;

    r = sqrt(pow((xb-xa),2)+pow((yb-ya),2));

    return r;

}

pair<float,float> Train::getCoords() const
{
    return coords;
}

void Train::init_transport()
{
    Gare* gare_a = ligne->find_gare(pos_ligne);
    Gare* gare_b = ligne->find_gare(pos_ligne+1);
    pair<float,float>* tmp;
    pair<float,float> coor_dest;


    coor_dest = gare_b->get_coords();
    coords = gare_a->get_coords();

    if(coords.first != coor_dest.first )
        mode=1;

    else if (coords.first == coor_dest.first )
        mode=2;

    /*gare_a->presentation();
    gare_b->presentation();*/

    tmp = equation(gare_a,gare_b);
    a = tmp->first;
    dist = tmp->second;


    b = coords.second - a * coords.first;

    cout << "a= " << a << endl;
    cout << "b= " << b << endl;
}



