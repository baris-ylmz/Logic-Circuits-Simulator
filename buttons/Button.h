

#ifndef LOGICPROJECTS_BUTTON_H
#define LOGICPROJECTS_BUTTON_H

#include "SFML/Graphics.hpp"
#include "../Object.h"
#include "../Simulator.h"


class Button : public Object {
protected:
    Simulator *simulator;
    sf::RectangleShape *shape;
    sf::Vector2f size;

public:
    Button(sf::Vector2f pos, sf::RenderWindow *window, Simulator *simulator) : Object(window, pos),
                                                                               simulator(simulator) {
        size = sf::Vector2f(120, 90);
        shape = new sf::RectangleShape(size);
        locked = true;
        this->shape->setPosition(pos);
    }

    ~Button() {};

    // creates new gate and adds it to the end of the list when it's clicked on
    virtual void onClick(sf::Vector2f mousePos) {
    }

    void draw() override {
        window->draw(*shape);
    }

    bool isInObject(sf::Vector2f mousePos) override {
        if (this->shape->getGlobalBounds().contains(mousePos)) {
            return true;
        }
        return false;
    }

    void setSize(sf::Vector2f _size) {
        this->shape->setSize(_size);
    }
};

#endif //LOGICPROJECTS_BUTTON_H
