

#include "LogicZero.h"

LogicZero::LogicZero(sf::RenderWindow *window, const sf::Vector2f &pos) : LogicElement(
        window, pos, sf::Vector2f(50, 50), 0, 1) {
    texture.loadFromFile("../resources/LogicZero.png");
    mainShape->setTexture(&texture);
    this->pins.at(0)->setState(Pin::LOW);
}

bool LogicZero::applyLogicFunction() {
    if (!isLogicFunctionApplied) {
        // call this setState method oor the output pit again to set the state of connected input pins
        pins.at(0)->setState(Pin::LOW);
        isLogicFunctionApplied = true;
        return true;
    } else {
        return false;
    }
}
