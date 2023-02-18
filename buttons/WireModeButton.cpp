

#include "WireModeButton.h"

void WireModeButton::onClick(sf::Vector2f mousePos) {
    simulator->setState(WIRE_MODE);
}

WireModeButton::WireModeButton(
        const sf::Vector2f &pos,
        sf::RenderWindow *window,
        Simulator *simulator
) : Button(pos, window, simulator) {
    texture.loadFromFile("../resources/Wire.PNG");
    shape->setTexture(&texture);
}
