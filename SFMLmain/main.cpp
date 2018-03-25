#include <iostream>
#include <ctime>

#include "Gare.h"
#include "Ligne.h"
#include "Metro.h"
#include "Train.h"


using namespace std;

int main()
{
    srand(time(nullptr));

    cout << "Hello train d'avance !" << endl;
    Metro metro("Metro.txt");
    metro.presentation();

//    test1();

    cout << "Bye train d'avance !" << endl;
    return 0;
}
