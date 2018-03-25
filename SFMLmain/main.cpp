#include <iostream>
<<<<<<< HEAD
#include <SFML/Graphics.hpp>
=======
#include <ctime>
>>>>>>> 3d15c44de59d8bbfdaea465ee6d53bf46bda06c7

#include "Gare.h"
#include "Ligne.h"
#include "Metro.h"
#include "Train.h"


using namespace std;

int main()
{
<<<<<<< HEAD
    // Pour activer l'anti-aliasing
    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;

    // Initialise une fenêtre de taille 800x600
    sf::RenderWindow window(sf::VideoMode(700, 700), "Un train d'avance", sf::Style::Default, settings);

    cout << "Hello train d'avance !" << endl << endl;
=======
    srand(time(nullptr));

    cout << "Hello train d'avance !" << endl;
>>>>>>> 3d15c44de59d8bbfdaea465ee6d53bf46bda06c7
    Metro metro("Metro.txt");
    metro.presentation();

//    test1();

    cout << "Bye train d'avance !" << endl;

    // Boucle principale
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Nettoie le contenu de l'écran
        window.clear(sf::Color::White);

        // On dessine sur le buffer


        // On affiche le contenu du buffer sur l'écran
        window.display();
    }

    return 0;
}
