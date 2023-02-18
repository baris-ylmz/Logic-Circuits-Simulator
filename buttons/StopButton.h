
#ifndef LOGICPROJECTS_STOPBUTTON_H
#define LOGICPROJECTS_STOPBUTTON_H


#include "Button.h"

class StopButton : public Button {
public:
    void onClick(sf::Vector2f mousePos) override;

    StopButton(const sf::Vector2f &pos, sf::RenderWindow *window, Simulator *simulator);
};


#endif //LOGICPROJECTS_STOPBUTTON_H
