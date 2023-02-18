

#ifndef LOGICPROJECTS_NOTGATEBUTTON_H
#define LOGICPROJECTS_NOTGATEBUTTON_H


#include "Button.h"

class NotGateButton : public Button {

    void onClick(sf::Vector2f mousePos) override;

    void createNotGate(sf::Vector2f mousePos);
public:
    NotGateButton(const sf::Vector2f &pos, sf::RenderWindow *window, Simulator *simulator);
};


#endif //LOGICPROJECTS_NOTGATEBUTTON_H
