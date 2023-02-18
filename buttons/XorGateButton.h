

#ifndef LOGICPROJECTS_XORGATEBUTTON_H
#define LOGICPROJECTS_XORGATEBUTTON_H


#include "Button.h"

class XorGateButton : public Button {

public:
    XorGateButton(const sf::Vector2f &pos, sf::RenderWindow *window, Simulator *simulator);

private:
    void onClick(sf::Vector2f mousePos);

    void createXorGate(sf::Vector2f vector2);
};


#endif //LOGICPROJECTS_XORGATEBUTTON_H
