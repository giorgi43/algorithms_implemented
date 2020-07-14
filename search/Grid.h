#ifndef GRID_H
#define GRID_H
#include <SFML/Graphics.hpp>
#include <vector>

class Grid {
private:
	std::vector<sf::RectangleShape> grid;
public:
	Grid(int rows, int columns, const int WINDOW_W, const int WINDOW_H);
	void display(sf::RenderWindow& window);
};

#endif