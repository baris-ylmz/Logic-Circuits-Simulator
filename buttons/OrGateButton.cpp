

#include <SFML/System/Vector2.hpp>
#include "OrGateButton.h"
#include "../logicelements/OrGate.h"

// create or gate when or gate button is clicked then set simulator state to default
void OrGateButton::onClick(sf::Vector2f mousePos) {
    createOrGate(mousePos);
    simulator->setState(DEFAULT);
}


void OrGateButton::createOrGate(sf::Vector2f mousePos) {
    addNewObject(new OrGate(window, mousePos));
}

OrGateButton::OrGateButton(const sf::Vector2f &pos, sf::RenderWindow *window,
                           Simulator *simulator) : Button(pos, window, simulator) {
    texture.loadFromFile("../resources/Or.PNG");
    shape->setTexture(&texture);
}
