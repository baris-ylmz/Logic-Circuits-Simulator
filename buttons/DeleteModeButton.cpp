
#include "DeleteModeButton.h"


void DeleteModeButton::onClick(sf::Vector2f mousePos) {
    simulator->setState(DELETE_MODE);
}

DeleteModeButton::DeleteModeButton(
        const sf::Vector2f &pos,
        sf::RenderWindow *window,
        Simulator *simulator
) : Button(pos, window, simulator) {
    texture.loadFromFile("../resources/Delete.PNG");
    shape->setTexture(&texture);
}
