

#include "AndGate.h"

AndGate::AndGate(sf::RenderWindow *window, sf::Vector2f pos) : LogicElement(window, pos, 2, 1) {
    texture.loadFromFile("../resources/And.png");
    mainShape->setTexture(&texture);
}

bool AndGate::applyLogicFunction() {
    if (isLogicFunctionApplied) {
        // if output pins' states are already set, return false since we won't have any change
        return false;
    }

    if (pins.at(0)->getState() == Pin::UNDEFINED || pins.at(1)->getState() == Pin::UNDEFINED) {
        // as input pins are already undefined, we cannot decide on the state of the output pin
        return false;
    } else if (pins.at(0)->getState() == Pin::LOW && pins.at(1)->getState() == Pin::LOW) {
        pins.at(2)->setState(Pin::LOW);
    } else if (pins.at(0)->getState() == Pin::LOW && pins.at(1)->getState() == Pin::HIGH) {
        pins.at(2)->setState(Pin::LOW);
    } else if (pins.at(0)->getState() == Pin::HIGH && pins.at(1)->getState() == Pin::LOW) {
        pins.at(2)->setState(Pin::LOW);
    } else {
        pins.at(2)->setState(Pin::HIGH);
    }
    isLogicFunctionApplied = true;
    return true;
}

AndGate::~AndGate() {

}
