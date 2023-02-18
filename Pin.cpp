

#include "Pin.h"

const sf::Vector2f Pin::size = sf::Vector2f(10, 10);

Pin::Pin(pinType type) {
    state = UNDEFINED;
    this->type = type;
    createPinShape();
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        connectTo[i] = nullptr;
        wires[i] = nullptr;
    }
}

void Pin::setState(Pin::pinState _state) {
    // set state of the pin
    this->state = _state;
    // If this pin is an output pin, also set the state of
    // connected input pins
    if (type == OUTPUT) {
        for (auto &connectedPin: connectTo) {
            if (connectedPin != nullptr) {
                connectedPin->setState(_state);
            }
        }
    }
}

Pin::pinState Pin::getState() const {
    return state;
}

void Pin::createPinShape() {
    shape = new sf::RectangleShape(size);
    shape->setFillColor(primaryColor);
}

sf::Vector2f Pin::getPosition() {
    return pos;
}

// while setting pin positions according to it's types, also set positions of wire connected to
void Pin::setPosition(sf::Vector2f _pos) {
    this->pos = _pos;
    shape->setPosition(_pos);

    int vertexIdx;
    if (type == OUTPUT) {
        vertexIdx = 0;
    } else {
        vertexIdx = 1;
    }
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        if (wires[i] != nullptr) {
            wires[i]->setVertexPosition(vertexIdx, _pos);
        }
    }
}

void Pin::draw(sf::RenderWindow *window) {
    window->draw(*shape);
    // Draw wires if pin type is OUTPUT
    // Do not draw when it's INPUT to avoid duplicate operation
    if (type == OUTPUT) {
        for (auto &wire: wires) {
            if (wire != nullptr) {
                wire->draw(window);
            }
        }
    }
}

bool Pin::isInPin(sf::Vector2f mousePos) {
    if (shape->getGlobalBounds().contains(mousePos)) {
        return true;
    }
    return false;
}

// Toggle the pin color between primary and secondary color
// We call this color changing method after selecting a
// input pin during the wire creation
void Pin::togglePinColor() {
    if (shape->getFillColor() == primaryColor) {
        shape->setFillColor(secondaryColor);
    } else {
        shape->setFillColor(primaryColor);
    }
}

// makes output pin and input pin connected and be aware of each other for transmit output state to the connected
// pin. connects wire corresponding pin.
void Pin::connectToPin(Pin *pin, Wire *wire) {
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        if (connectTo[i] == nullptr) {
            connectTo[i] = pin;
            wires[i] = wire;
            break;
        }
    }
}

