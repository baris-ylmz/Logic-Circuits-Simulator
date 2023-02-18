

#include <SFML/System/Vector2.hpp>
#include "NotGateButton.h"
#include "../logicelements/NotGate.h"

// create not gate when not gate button is clicked then set simulator state to default
void NotGateButton::onClick(sf::Vector2f mousePos) {
    createNotGate(mousePos);
    simulator->setState(DEFAULT);
}

void NotGateButton::createNotGate(sf::Vector2f mousePos) {
    addNewObject(new NotGate(window, mousePos));
}

NotGateButton::NotGateButton(const sf::Vector2f &pos, sf::RenderWindow *window,
                             Simulator *simulator) : Button(pos, window, simulator) {
    texture.loadFromFile("../resources/Not.PNG");
    shape->setTexture(&texture);
}


