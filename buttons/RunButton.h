

#ifndef LOGICPROJECTS_RUNBUTTON_H
#define LOGICPROJECTS_RUNBUTTON_H


#include "Button.h"

class RunButton : public Button {
public:
    RunButton(const sf::Vector2f &pos, sf::RenderWindow *window, Simulator *simulator);

    void onClick(sf::Vector2f mousePos) override;
};

#endif //LOGICPROJECTS_RUNBUTTON_H
