
#include "LEDButton.h"
#include "../logicelements/LED.h"

void LEDButton::onClick(sf::Vector2f mousePos) {
    createLEDButton(mousePos);
    simulator->setState(DEFAULT);
}

void LEDButton::createLEDButton(sf::Vector2f mousePos) {
    addNewObject(new LED(window, mousePos));
}

LEDButton::LEDButton(const sf::Vector2f &pos, sf::RenderWindow *window, Simulator *simulator)
        : Button(pos, window, simulator) {
    texture.loadFromFile("../resources/LED_off.png");
    shape->setTexture(&texture);
}
