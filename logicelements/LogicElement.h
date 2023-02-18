

#ifndef LOGICPROJECTS_LOGICELEMENT_H
#define LOGICPROJECTS_LOGICELEMENT_H

#include <SFML/Graphics.hpp>
#include "../Pin.h"

class LogicElement : public Object {

protected:
    const static sf::Vector2f defaultSize;
    int inputSize;
    int outputSize;
    sf::RectangleShape *mainShape;
    bool isLogicFunctionApplied;

    LogicElement(sf::RenderWindow *window, sf::Vector2f pos, int inputSize, int outputSize);
    LogicElement(sf::RenderWindow *window, sf::Vector2f pos, sf::Vector2f size, int inputSize, int outputSize);

    std::vector<Pin *> pins;
public:
    bool isInObject(sf::Vector2f mousePos) override;

    void setPosition(sf::Vector2f pos);

    void draw();

    Pin *getClickedPin(sf::Vector2f mousePos);

    // this function applies the boolean functionality of the logic element
    // it sets the output pins state wrt. the state of the input pins
    // it returns true output pins state has set in this call
    // otherwise, returns false
    virtual bool applyLogicFunction() = 0;

    virtual void cleanup();
};

#endif //LOGICPROJECTS_LOGICELEMENT_H
