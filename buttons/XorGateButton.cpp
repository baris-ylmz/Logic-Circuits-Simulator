//
// Created by brsyl on 4/30/2022.
//

#include <SFML/System/Vector2.hpp>
#include "XorGateButton.h"
#include "../logicelements/XorGate.h"

void XorGateButton::onClick(sf::Vector2f mousePos) {
    createXorGate(mousePos);
    simulator->setState(DEFAULT);
}


void XorGateButton::createXorGate(sf::Vector2f mousePos) {
    addNewObject(new XorGate(window, mousePos));
}

XorGateButton::XorGateButton(const sf::Vector2f &pos, sf::RenderWindow *window,
                             Simulator *simulator) : Button(pos,
                                                            window, simulator) {
    texture.loadFromFile("../resources/Xor.PNG");
    shape->setTexture(&texture);
}
