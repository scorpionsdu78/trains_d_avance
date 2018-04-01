#include "fonction.h"

#include <cmath>

using namespace std;

pair<float,float> equation(Gare* garea, Gare* gareb)
{
    pair<float,float> r;

    float xa,xb,ya,yb;

    pair<float,float> g_a = garea->get_coords();
    pair<float,float> g_b = gareb->get_coords();

    xa=g_a.first;
    ya=g_a.second;
    xb=g_b.first;
    yb=g_b.second;

    r.first = (yb-ya)/(xb-xa);

    r.second = distf(g_a,g_b);

    return r;

}

float distf(pair<float,float> g_a, pair<float,float> g_b)
{
    float xa,xb,ya,yb;
    float r;

    xa=g_a.first;
    ya=g_a.second;
    xb=g_b.first;
    yb=g_b.second;

    r = sqrt(pow((xb-xa),2)+pow((yb-ya),2));

    return r;

}

