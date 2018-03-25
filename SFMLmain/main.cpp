#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>

#include "Gare.h"
#include "Ligne.h"
#include "Metro.h"
#include "Train.h"


using namespace std;

int main()
{
    // Pour activer l'anti-aliasing
    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;

    // Initialise une fenêtre de taille 800x600
    sf::RenderWindow window(sf::VideoMode(700, 700), "Un train d'avance", sf::Style::Default, settings);

    cout << "Hello train d'avance !" << endl << endl;
    srand(time(nullptr));

    cout << "Hello train d'avance !" << endl;
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
