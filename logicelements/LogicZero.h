

#ifndef LOGICPROJECTS_LOGICZERO_H
#define LOGICPROJECTS_LOGICZERO_H


#include "LogicElement.h"

class LogicZero : public LogicElement {

public:
    LogicZero(sf::RenderWindow *window, const sf::Vector2f &pos);

    bool applyLogicFunction() override;
};


#endif //LOGICPROJECTS_LOGICZERO_H
