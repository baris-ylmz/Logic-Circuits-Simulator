

#ifndef LOGICPROJECTS_LOGICONEBUTTON_H
#define LOGICPROJECTS_LOGICONEBUTTON_H


#include <SFML/System/Vector2.hpp>
#include "Button.h"

class LogicOneButton : public Button {

    void onClick(sf::Vector2f mousePos);

    void createLogicOne(sf::Vector2f mousePos);
public:
    LogicOneButton(const sf::Vector2f &pos, sf::RenderWindow *window, Simulator *simulator);
};

#endif //LOGICPROJECTS_LOGICONEBUTTON_H
