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

    metro.testtrain();

    cout << "Bye train d'avance !" << endl;

    sf::CircleShape affStations[metro.getStationsSize()];

    for (int i(0); i < metro.getStationsSize(); i++)
    {
        affStations[i].setRadius(20);
        affStations[i].setPointCount(6);
        affStations[i].setFillColor(sf::Color::White);
        affStations[i].setOutlineThickness(-6);
        affStations[i].setOutlineColor(sf::Color::Black);
        affStations[i].setPosition(get<0>(metro.getCoordAff(i)) * 40.0, get<1>(metro.getCoordAff(i)) * 40.0);
    }

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
        for (int i(0); i < metro.getStationsSize(); i++)
        {
            window.draw(affStations[i]);
        }

        // On affiche le contenu du buffer sur l'écran
        window.display();
    }

    return 0;
}
