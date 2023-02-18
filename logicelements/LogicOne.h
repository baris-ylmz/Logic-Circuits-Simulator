

#ifndef LOGICPROJECTS_LOGICONE_H
#define LOGICPROJECTS_LOGICONE_H


#include "LogicElement.h"

class LogicOne : public LogicElement {
public:
    LogicOne(sf::RenderWindow *window, const sf::Vector2f &pos);

    bool applyLogicFunction() override;
};


#endif //LOGICPROJECTS_LOGICONE_H
