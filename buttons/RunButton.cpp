
#include "RunButton.h"

RunButton::RunButton(const sf::Vector2f &pos, sf::RenderWindow *window, Simulator *simulator)
        : Button(pos, window, simulator) {
    texture.loadFromFile("../resources/RunButton.PNG");
    shape->setTexture(&texture);
}

void RunButton::onClick(sf::Vector2f mousePos) {
    simulator->startSimulation();
}
