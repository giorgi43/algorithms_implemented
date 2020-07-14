#include <SFML/Graphics.hpp>
#include "Grid.h"

const int WIDTH = 900;
const int HEIGHT = 900;

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Searching algorithms visualized");

    Grid grid (30, 30, WIDTH, HEIGHT);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        grid.display(window);
        window.display();
    }

    return 0;
}