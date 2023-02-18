

#include "LogicElement.h"

const sf::Vector2f LogicElement::defaultSize = sf::Vector2f(100.f, 75.f);


LogicElement::LogicElement(sf::RenderWindow *window, sf::Vector2f pos, sf::Vector2f size, int inputSize, int outputSize)
        : Object(window, pos) {

    this->inputSize = inputSize;
    this->outputSize = outputSize;
    // this variable that represents if the output pins are set or not
    this->isLogicFunctionApplied = false;
    mainShape = new sf::RectangleShape(size);
    // create input pin corresponding input pin number of logic element's
    for (int i = 0; i < inputSize; i++) {
        pins.push_back(new Pin(INPUT));
    }
    // create output pin corresponding output pin number of logic element's
    for (int i = 0; i < outputSize; i++) {
        pins.push_back(new Pin(OUTPUT));
    }
    setPosition(pos);
}

LogicElement::LogicElement(sf::RenderWindow *window, sf::Vector2f pos, int inputSize, int outputSize) :
        LogicElement(window, pos, defaultSize, inputSize, outputSize) {
}

// set logic elements positions and relative pin positions on them
void LogicElement::setPosition(sf::Vector2f pos) {
    this->pos = pos;
    mainShape->setPosition(pos);
    for (int i = 0; i < inputSize; i++) {
        pins.at(i)->setPosition(sf::Vector2f(
                pos.x - Pin::size.x,
                pos.y - (Pin::size.y / 2.0f) + (mainShape->getSize().y / (inputSize + 1.0f)) * (i + 1.0f))
        );
    }

    for (int i = 0; i < outputSize; i++) {
        pins.at(inputSize + i)->setPosition(sf::Vector2f(
                pos.x + mainShape->getSize().x,
                pos.y - (Pin::size.y / 2.0f) + (mainShape->getSize().y / (outputSize + 1.0f)) * (i + 1.0f))
        );
    }
}

// while drawing logic elements also draw its pins
void LogicElement::draw() {
    window->draw(*mainShape);
    for (auto *pin: pins) {
        pin->draw(window);
    }
}

bool LogicElement::isInObject(sf::Vector2f mousePos) {
    if (mainShape->getGlobalBounds().contains(mousePos)) {
        return true;
    }
    return false;
}

// check if mouse position is on any of the pins, and returns if there is any
Pin *LogicElement::getClickedPin(sf::Vector2f mousePos) {
    for (auto *pin: pins) {
        if (pin->isInPin(mousePos)) {
            return pin;
        }
    }
    return nullptr;
}
// after cleanup set all pin's state undefined to be able to simulate different or same function again.
void LogicElement::cleanup() {
    for (auto *pin : pins) {
        pin->setState(Pin::UNDEFINED);
    }
    isLogicFunctionApplied = false;
}

