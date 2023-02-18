

#include "ToolBoxGrid.h"
#include "SFML/Graphics.hpp"

ToolBoxGrid::ToolBoxGrid(sf::RenderWindow *window) {
    this->window = window;
    this->color = sf::Color(0, 43, 54);
    this->horizontalLine[0] = sf::Vertex(sf::Vector2f(0.f, 120.f), color);
    this->horizontalLine[1] = sf::Vertex(sf::Vector2f(1640.f, 120.f), color);

    this->verticalLine1[0] = sf::Vertex(sf::Vector2f(150.f, 120), color);
    this->verticalLine1[1] = sf::Vertex(sf::Vector2f(150.f, 850), color);
    this->verticalLine2[0] = sf::Vertex(sf::Vector2f(300.f, 120), color);
    this->verticalLine2[1] = sf::Vertex(sf::Vector2f(300.f, 850), color);

    for (int i = 0; i < NO_SUBLINES; i++) {
        subHorizontalLines[i][0] = sf::Vertex(sf::Vector2f(0, 120.f + 150.f * (i + 1)), color);
        subHorizontalLines[i][1] = sf::Vertex(sf::Vector2f(300.f, 120.f + 150.f * (i + 1)), color);
    }
}

void ToolBoxGrid::render() {
    window->draw(horizontalLine, 2, sf::Lines);
    window->draw(verticalLine1, 2, sf::Lines);
    window->draw(verticalLine2, 2, sf::Lines);
    for (auto &subHorizontalLine: subHorizontalLines) {
        window->draw(subHorizontalLine, 2, sf::Lines);
    }
}