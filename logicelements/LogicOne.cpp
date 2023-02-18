

#include "LogicOne.h"

LogicOne::LogicOne(sf::RenderWindow *window, const sf::Vector2f &pos) : LogicElement(
        window, pos, sf::Vector2f(50, 50), 0, 1) {
    texture.loadFromFile("../resources/LogicOne.png");
    mainShape->setTexture(&texture);
    mainShape->setSize(sf::Vector2f(50, 50));
    this->pins.at(0)->setState(Pin::HIGH);
}

bool LogicOne::applyLogicFunction() {
    if (!isLogicFunctionApplied) {
        // call this setState method oor the output pit again to set the state of connected input pins
        pins.at(0)->setState(Pin::HIGH);
        isLogicFunctionApplied = true;
        return true;
    } else {
        return false;
    }
}
