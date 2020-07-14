#include "Grid.h"

Grid::Grid(int rows, int columns, const int WINDOW_W, const int WINDOW_H) {
	const int CW = WINDOW_W / columns;
	const int CH = WINDOW_H / rows;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			sf::RectangleShape cell(sf::Vector2f(CW, CH));
			cell.setFillColor(sf::Color::Black);
			sf::Color color(105,105,105);
			cell.setOutlineColor(color);
			cell.setOutlineThickness(.5);
			cell.setPosition(j*CW, i*CH);
			grid.push_back(cell);
		}
	}
}

void Grid::display(sf::RenderWindow& window) {
	for (auto c : grid) {
		window.draw(c);
	}
}