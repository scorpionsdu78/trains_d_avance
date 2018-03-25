#include "Train.h"

#include <iostream>

using namespace std;

Train::Train(Gare* _position, Ligne* _ligne, std::pair<int,int> _coords): position{_position}, ligne{_ligne}, coords{_coords}
{
    nb_passager = 0;
}

Train::~Train()
{
}

void Train::init_tmp(Gare* origine, pair<int,int> _coords)
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
    cout << "j'ai " << nb_passager <<"passager " << endl;
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
