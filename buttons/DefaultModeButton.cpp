

#include "DefaultModeButton.h"

DefaultModeButton::DefaultModeButton(const sf::Vector2f &pos, sf::RenderWindow *window, Simulator *simulator) :
        Button(pos, window, simulator) {
    texture.loadFromFile("../resources/Default.PNG");
    shape->setTexture(&texture);
}

void DefaultModeButton::onClick(sf::Vector2f mousePos) {
    this->simulator->setState(DEFAULT);
}
