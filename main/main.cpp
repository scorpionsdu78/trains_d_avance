#include <iostream>
#include <utility>

#include "Gare.h"
#include "Ligne.h"
#include "Metro.h"

using namespace std;

int main()
{

    pair<int,int> p(11,12);

    Gare gr("bite",p);

    Train tr;

    tr.passage_gare(&gr);



    Metro metro("Metro.txt");

    cout << "Hello world!" << endl;
    return 0;
}
