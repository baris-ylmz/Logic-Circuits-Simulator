

#ifndef LOGICPROJECTS_LOGICZEROBUTTON_H
#define LOGICPROJECTS_LOGICZEROBUTTON_H


#include "Button.h"

class LogicZeroButton : public Button {

    void onClick(sf::Vector2f mousePos);

    void createLogicZero(sf::Vector2f mousePos);
public:
    LogicZeroButton(const sf::Vector2f &pos, sf::RenderWindow *window, Simulator *simulator);
};


#endif //LOGICPROJECTS_LOGICZEROBUTTON_H
