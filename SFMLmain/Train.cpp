#include "Train.h"

#include <iostream>
#include <cmath>

using namespace std;

pair<int,float>* equation(Gare* garea, Gare* gareb);
float distf(pair<float,float> g_a, pair<float,float> g_b);

Train::Train(Gare* _position, Ligne* _ligne, std::pair<float,float> _coords): position{_position}, ligne{_ligne}, coords{_coords}
{
    nb_passager = 0;
    pos_ligne = 0;
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
    int coef;
    float dist;
    pair<int,float>* tmp;
    pair<float,float> old;

    tmp = equation(ligne->find_gare(pos_ligne),ligne->find_gare(pos_ligne+1));

    coef = tmp->first;
    dist = tmp->second;

    while (dist >1)
    {
        old.first = coords.first;
        old.second = coords.second;

        coords.first = coords.first +1;
        coords.second = coords.second * coef;

        dist -= distf(old,coords);

    }


}

pair<int,float>* equation(Gare* garea, Gare* gareb)
{
    pair<int,float>* r = new pair<int,float>;

    float xa,xb,ya,yb;

    pair<float,float> g_a = garea->get_coords();
    pair<float,float> g_b = gareb->get_coords();

    xa=g_a.first;
    ya=g_a.second;
    xb=g_b.first;
    yb=g_b.second;

    r->first = (xb-xa)/(yb-ya);

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


/*
void test1(void)
{
    pair<int,int> coords(0,0);
    Gare gr("test",coords);

    Train tr();

    tr.init_tmp(&gr,coords);

    gr.presentation();

    tr.presentation();

    tr.passage_gare(&gr);


    gr.presentation();

    tr.presentation();


}
*/

