


#ifndef LOGICPROJECTS_ANDGATE_H
#define LOGICPROJECTS_ANDGATE_H

#include <SFML/Graphics.hpp>
#include "LogicElement.h"

class AndGate : public LogicElement {

public:
    AndGate(sf::RenderWindow *window, sf::Vector2f pos);

    virtual ~AndGate();



    bool applyLogicFunction() override;
};


#endif //LOGICPROJECTS_ANDGATE_H
