#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>

#include "Gare.h"
#include "Ligne.h"
#include "Metro.h"
#include "Train.h"

#include "sfLine.h"

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

    //metro.testtrain();

    //metro.lancer();

    cout << "Bye train d'avance !" << endl;

    // Un tableau d'hexagones qui représentent les gares, placés grâce aux coords des Gares
    sf::CircleShape affStations[metro.getStationsSize()];
    vector<vector<sf::CircleShape>> affVoyageurs(metro.getStationsSize());

    for (int i(0); i < metro.getStationsSize(); i++)
    {
        affStations[i].setRadius(20);
        affStations[i].setPointCount(6);
        affStations[i].setFillColor(sf::Color::White);
        affStations[i].setOutlineThickness(-6);
        affStations[i].setOutlineColor(sf::Color::Black);
        affStations[i].setPosition(get<0>(metro.getCoordAff(i)) * 40.0, get<1>(metro.getCoordAff(i)) * 40.0);
    }

    vector<vector<sfLine>> affLigne(metro.getLignesSize());
    vector<vector<sf::RectangleShape>> affTrains(metro.getLignesSize());

    sf::Color color;
    for (int i(0); i < metro.getLignesSize(); i++)
    {
        switch (i)
        {
            case 0:
                color = sf::Color::Red;
                break;
            case 1:
                color = sf::Color::Green;
                break;
            case 2:
                color = sf::Color::Yellow;
                break;
            case 4:
                color = sf::Color::Blue;
                break;
        }
        for (int j(0); j < metro.getInterLignesNbr(i); j++)
        {
            affLigne[i].push_back(sfLine(sf::Vector2f(get<0>(metro.getGareLigneCoord(i,j)) * 40.0 + 20.0, get<1>(metro.getGareLigneCoord(i,j)) * 40.0 + 20.0),
                                         sf::Vector2f(get<0>(metro.getGareLigneCoord(i,j+1)) * 40.0 + 20.0, get<1>(metro.getGareLigneCoord(i,j+1)) * 40.0 + 20.0),
                                         color));
        }

        for (int j(0); j < metro.getNombreTrain(i); j++)
        {
            affTrains[i].push_back(sf::RectangleShape(sf::Vector2f(20,10)));
            affTrains[i][j].setFillColor(color);
            affTrains[i][j].setOutlineThickness(3);
            affTrains[i][j].setOutlineColor(sf::Color::Black);
            affTrains[i][j].setOrigin(10.0, 5.0);
        }
    }

    // Boucle principale
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::L)
                {
                    metro.testtrain();
                }
            }
        }

        // Nettoie le contenu de l'écran
        window.clear(sf::Color::White);

        // On dessine sur le buffer
        for (int i(0); i < metro.getLignesSize(); i++)
        {
            for (int j(0); j < metro.getInterLignesNbr(i); j++)
            {
                window.draw(affLigne[i][j]);
            }
        }

        for (int i(0); i < metro.getStationsSize(); i++)
        {
            window.draw(affStations[i]);
            for (int j(0); j < metro.getNombreVoyageursGare(i) / 5; j++)
            {
                affVoyageurs[i].push_back(sf::CircleShape(4.5, 60));
                affVoyageurs[i][j].setFillColor(sf::Color::Black);

                if (j > 11)
                    affVoyageurs[i][j].setPosition(get<0>(metro.getCoordAff(i)) * 40.0 + 75.0, get<1>(metro.getCoordAff(i)) * 40.0 + (j % 4) * 10.0);
                else if (j > 7)
                    affVoyageurs[i][j].setPosition(get<0>(metro.getCoordAff(i)) * 40.0 + 65.0, get<1>(metro.getCoordAff(i)) * 40.0 + (j % 4) * 10.0);
                else if (j > 3)
                    affVoyageurs[i][j].setPosition(get<0>(metro.getCoordAff(i)) * 40.0 + 55.0, get<1>(metro.getCoordAff(i)) * 40.0 + (j % 4) * 10.0);
                else
                    affVoyageurs[i][j].setPosition(get<0>(metro.getCoordAff(i)) * 40.0 + 45.0, get<1>(metro.getCoordAff(i)) * 40.0 + j * 10.0);

                window.draw(affVoyageurs[i][j]);
            }
        }

        for (int i(0); i < metro.getLignesSize(); i++)
        {
            for (int j(0); j < metro.getNombreTrain(i); j++)
            {
                affTrains[i][j].setPosition(get<0>(metro.getCoordTrain(i, j)) * 40.0 + 20.0, get<1>(metro.getCoordTrain(i, j)) * 40.0 + 20.0);
                window.draw(affTrains[i][j]);
            }
        }

        // On affiche le contenu du buffer sur l'écran
        window.display();

        for (int i(0); i < metro.getStationsSize(); i++)
        {
            affVoyageurs[i].clear();
        }
    }

    return 0;
}
