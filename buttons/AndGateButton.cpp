
#include "AndGateButton.h"
#include "../logicelements/AndGate.h"

void AndGateButton::onClick(sf::Vector2f mousePos) {
    createAndGate(mousePos);
    simulator->setState(DEFAULT);
}

void AndGateButton::createAndGate(sf::Vector2f mousePos) {
    addNewObject(new AndGate(window, mousePos));
}

AndGateButton::AndGateButton(const sf::Vector2f &pos, sf::RenderWindow *window,
                             Simulator *simulator) : Button(pos, window, simulator) {
    texture.loadFromFile("../resources/AND.PNG");
    shape->setTexture(&texture);
}
