

#ifndef LOGICPROJECTS_ORGATEBUTTON_H
#define LOGICPROJECTS_ORGATEBUTTON_H


#include "Button.h"

class OrGateButton : public Button {

public:
    OrGateButton(const sf::Vector2f &pos, sf::RenderWindow *window, Simulator *simulator);

    void createOrGate(sf::Vector2f mousePos);

    void onClick(sf::Vector2f mousePos);
};


#endif //LOGICPROJECTS_ORGATEBUTTON_H
