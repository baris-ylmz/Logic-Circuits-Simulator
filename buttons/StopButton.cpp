

#include "StopButton.h"

StopButton::StopButton(const sf::Vector2f &pos, sf::RenderWindow *window, Simulator *simulator)
        : Button(pos, window, simulator) {
    texture.loadFromFile("../resources/Stop.PNG");
    shape->setTexture(&texture);
}

void StopButton::onClick(sf::Vector2f mousePos) {
    simulator->stopSimulation();
}
