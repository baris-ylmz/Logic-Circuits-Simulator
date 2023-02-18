

#ifndef LOGICPROJECTS_PIN_H
#define LOGICPROJECTS_PIN_H

#define MAX_CONNECTIONS 20

#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Wire.h"

// enum for pin type (input or output pin)
enum pinType {
    INPUT, OUTPUT
};

class Pin {
    const sf::Color primaryColor = sf::Color::Blue;
    const sf::Color secondaryColor = sf::Color::Green;

    // Index of the pin for an element
    // The first input pin has an index 0, the second input
    // pin has an index 1, output pin has an index 2, so on…
    int index;
    // enum for pin type (input or output pin)
    // whether this pin is input or output
    pinType type;


    // List of other pins this pin is connected to
    Pin *connectTo[MAX_CONNECTIONS];
    // Wires connected to this pin
    Wire *wires[MAX_CONNECTIONS];
    // Screen position of the pin
    sf::Vector2f pos;

    sf::RectangleShape *shape;
    void createPinShape();

public:
    // enum for pin state
    enum pinState {
        HIGHZ, LOW, HIGH, UNDEFINED
    };

    // Logic state of the signal on this pin
    pinState state;

    static const sf::Vector2f size;

    Pin(pinType type);

    void setState(pinState state);

    [[maybe_unused]] pinState getState() const;

    sf::Vector2f getPosition();

    void setPosition(sf::Vector2f pos);

    void draw(sf::RenderWindow *window);

    bool isInPin(sf::Vector2f mousePos);

    void togglePinColor();

    // returns pin type (input or output pin)
    pinType getType() {
        return type;
    }

    void connectToPin(Pin *pin, Wire *wire);
};

#endif //LOGICPROJECTS_PIN_H
