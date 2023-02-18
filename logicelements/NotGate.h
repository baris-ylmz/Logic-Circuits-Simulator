

#ifndef LOGICPROJECTS_NOTGATE_H
#define LOGICPROJECTS_NOTGATE_H


#include "LogicElement.h"

class NotGate : public LogicElement {

public:
    NotGate(sf::RenderWindow *window, sf::Vector2f pos);

    bool applyLogicFunction() override;

};


#endif //LOGICPROJECTS_NOTGATE_H
