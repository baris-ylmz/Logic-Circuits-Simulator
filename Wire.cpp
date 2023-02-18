

#include "Wire.h"

Wire::Wire(sf::Vector2f pos1, sf::Vector2f pos2) {
    color = sf::Color::Red;
    line[0] = sf::Vertex(pos1, color);
    line[1] = sf::Vertex(pos2, color);
};

void Wire::draw(sf::RenderWindow *window) {
    window->draw(line, 2, sf::Lines);
}

void Wire::setVertexPosition(int vertexIdx, sf::Vector2f pos) {
    line[vertexIdx].position = pos;
}
