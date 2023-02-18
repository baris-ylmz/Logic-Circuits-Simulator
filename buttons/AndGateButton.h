

#ifndef LOGICPROJECTS_ANDGATEBUTTON_H
#define LOGICPROJECTS_ANDGATEBUTTON_H


#include "Button.h"

class AndGateButton : public Button {

public:
    AndGateButton(const sf::Vector2f &pos, sf::RenderWindow *window, Simulator *simulator);

    void onClick(sf::Vector2f mousePos) override;

    void createAndGate(sf::Vector2f mousePos);
};

#endif //LOGICPROJECTS_ANDGATEBUTTON_H
