
#ifndef LOGICPROJECTS_DELETEMODEBUTTON_H
#define LOGICPROJECTS_DELETEMODEBUTTON_H


#include "Button.h"
#include "../Simulator.h"

class DeleteModeButton: public Button {
public:

    DeleteModeButton(const sf::Vector2f &pos, sf::RenderWindow *window, Simulator *simulator);

    void onClick(sf::Vector2f mousePos) override;
};


#endif //LOGICPROJECTS_DELETEMODEBUTTON_H
