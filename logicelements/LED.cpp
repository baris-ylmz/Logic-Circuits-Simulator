

#include "LED.h"

LED::LED(sf::RenderWindow *window, const sf::Vector2f &pos) : LogicElement(
        window, pos, sf::Vector2f(50, 50), 1, 0) {
    // When we provide different size image for this same rectangle object
    // it was creating a problem in the appearance. We use same sized images
    // in there which are 300x300
    // texture for led on state
    texture.loadFromFile("../resources/LED_on.png");
    // texture for led off state
    textureLedOff.loadFromFile("../resources/LED_off.png");
    // set led off texture as an initial state
    mainShape->setTexture(&textureLedOff);
    mainShape->setSize(sf::Vector2f(100, 100));
}

bool LED::applyLogicFunction() {
    if (isLogicFunctionApplied) {
        // if the output pin's states is already set, return false since we won't have any change below
        return false;
    }

    if (pins.at(0)->getState() == Pin::UNDEFINED) {
        return false;
    } else if (pins.at(0)->getState() == Pin::LOW) {
        isLogicFunctionApplied = true;
        mainShape->setTexture(&textureLedOff);
        return true;
    } else {
        mainShape->setTexture(&texture);
        isLogicFunctionApplied = true;
        return true;
    }
}

void LED::cleanup() {
    pins.at(0)->setState(Pin::UNDEFINED);
    mainShape->setTexture(&textureLedOff);
    isLogicFunctionApplied = false;
}
