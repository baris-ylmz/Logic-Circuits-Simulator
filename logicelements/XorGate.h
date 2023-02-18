
#ifndef LOGICPROJECTS_XORGATE_H
#define LOGICPROJECTS_XORGATE_H


#include "LogicElement.h"

class XorGate : public LogicElement {

public:
    XorGate(sf::RenderWindow *window, sf::Vector2f pos);

    bool applyLogicFunction() override;
};


#endif //LOGICPROJECTS_XORGATE_H
