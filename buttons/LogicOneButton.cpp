

#include "LogicOneButton.h"
#include "../logicelements/LogicOne.h"

void LogicOneButton::onClick(sf::Vector2f mousePos) {
    createLogicOne(mousePos);
    simulator->setState(DEFAULT);
}

void LogicOneButton::createLogicOne(sf::Vector2f mousePos) {
    addNewObject(new LogicOne(window, mousePos));
}

LogicOneButton::LogicOneButton(const sf::Vector2f &pos, sf::RenderWindow *window,
                                 Simulator *simulator) : Button(pos, window, simulator) {
    texture.loadFromFile("../resources/LogicOne.png");
    shape->setTexture(&texture);
}