

#ifndef LOGICPROJECTS_LEDBUTTON_H
#define LOGICPROJECTS_LEDBUTTON_H


#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Simulator.h"
#include "Button.h"

class LEDButton : public Button {
    void onClick(sf::Vector2f mousePos);

    void createLEDButton(sf::Vector2f mousePos);
public:
    LEDButton(const sf::Vector2f &pos, sf::RenderWindow *window, Simulator *simulator);
};


#endif //LOGICPROJECTS_LEDBUTTON_H
