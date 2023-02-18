

#ifndef LOGICPROJECTS_WIRE_H
#define LOGICPROJECTS_WIRE_H

#include <SFML/Graphics.hpp>

class Wire {
    sf::Color color;
public:
    Wire(sf::Vector2f pos1, sf::Vector2f pos2);

    // End point vertices for the wire
    // 0th idx vertex corresponds to output pin's position
    // 1st idx vertex corresponds to input pin's position
    sf::Vertex line[2];

    void draw(sf::RenderWindow *window);

    void setVertexPosition(int vertexIdx, sf::Vector2f pos);
};

#endif //LOGICPROJECTS_WIRE_H
