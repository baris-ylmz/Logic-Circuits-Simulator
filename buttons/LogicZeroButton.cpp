

#include "LogicZeroButton.h"
#include "NotGateButton.h"
#include "../logicelements/LogicZero.h"

void LogicZeroButton::onClick(sf::Vector2f mousePos) {
    createLogicZero(mousePos);
    simulator->setState(DEFAULT);
}

void LogicZeroButton::createLogicZero(sf::Vector2f mousePos) {
    addNewObject(new LogicZero(window, mousePos));
}

LogicZeroButton::LogicZeroButton(const sf::Vector2f &pos, sf::RenderWindow *window,
                             Simulator *simulator) : Button(pos, window, simulator) {
    texture.loadFromFile("../resources/LogicZero.png");
    shape->setTexture(&texture);
}