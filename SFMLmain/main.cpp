#include <iostream>

#include "Gare.h"
#include "Ligne.h"
#include "Metro.h"

using namespace std;

int main()
{
    cout << "Hello train d'avance !" << endl;
    Metro metro("Metro.txt");
    metro.presentation();
    cout << "Bye train d'avance !" << endl;
    return 0;
}
