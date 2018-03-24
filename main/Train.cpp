#include "Train.h"

Train::Train()
{
    nb_passager = 80;
}

Train::~Train()
{
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

    deversement = rand()%frequentation;

    don = (nb_passager * deversement)/100;

    nb_passager -= don;

    return don;

}

void Train::passage_gare(Gare* gr)
{
    donner_voyageur(gr);

    recuperer_voyageur(gr);
}


