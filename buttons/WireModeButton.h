

#ifndef LOGICPROJECTS_WIREMODEBUTTON_H
#define LOGICPROJECTS_WIREMODEBUTTON_H

#include "SFML/Graphics.hpp"
#include "Button.h"

class WireModeButton : public Button {

public:
    WireModeButton(const sf::Vector2f &pos, sf::RenderWindow *window, Simulator *simulator);

    void onClick(sf::Vector2f mousePos) override;
};


#endif //LOGICPROJECTS_WIREMODEBUTTON_H
