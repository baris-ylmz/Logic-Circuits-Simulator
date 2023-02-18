
#ifndef LOGICPROJECTS_DEFAULTMODEBUTTON_H
#define LOGICPROJECTS_DEFAULTMODEBUTTON_H


#include "Button.h"
#include "../Simulator.h"

class DefaultModeButton: public Button {
public:
    DefaultModeButton(const sf::Vector2f &pos, sf::RenderWindow *window, Simulator *simulator);

    void onClick(sf::Vector2f mousePos) override;

};

#endif //LOGICPROJECTS_DEFAULTMODEBUTTON_H
