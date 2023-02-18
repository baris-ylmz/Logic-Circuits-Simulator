

#include "NotGate.h"

NotGate::NotGate(sf::RenderWindow *window, sf::Vector2f pos) : LogicElement(window, pos, 1, 1) {
    texture.loadFromFile("../resources/Not.PNG");
    mainShape->setTexture(&texture);
}

bool NotGate::applyLogicFunction() {
    if (isLogicFunctionApplied) {
        // if the output pin's states is already set, return false since we won't have any change below
        return false;
    }

    if (pins.at(0)->getState() == Pin::UNDEFINED) {
        // as input pin is already undefined, we cannot decide on the state of the output pin
        return false;
    } else if (pins.at(0)->getState() == Pin::LOW) {
        pins.at(1)->setState(Pin::HIGH);
    } else {
        pins.at(1)->setState(Pin::LOW);
    }
    isLogicFunctionApplied = true;
    return true;
}
