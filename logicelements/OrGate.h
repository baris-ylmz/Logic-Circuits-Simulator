
#ifndef LOGICPROJECTS_ORGATE_H
#define LOGICPROJECTS_ORGATE_H


#include "LogicElement.h"

class OrGate : public LogicElement {

public:
    OrGate(sf::RenderWindow *pWindow, sf::Vector2f vector2);

    bool applyLogicFunction() override;
};


#endif //LOGICPROJECTS_ORGATE_H
