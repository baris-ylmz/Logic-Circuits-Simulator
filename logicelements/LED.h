

#ifndef LOGICPROJECTS_LED_H
#define LOGICPROJECTS_LED_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "LogicElement.h"

class LED : public LogicElement {
    sf::Texture textureLedOff;
public:
    LED(sf::RenderWindow *window, const sf::Vector2f &pos);

    bool applyLogicFunction() override;

    void cleanup() override;
};

#endif //LOGICPROJECTS_LED_H
