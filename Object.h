

#ifndef LOGICPROJECTS_OBJECT_H
#define LOGICPROJECTS_OBJECT_H

#include <SFML/Graphics.hpp>

class Object {
protected:
    // Whether the object can move on screen or is fixed
    // You can use this flag for toolbar items which cannot move
    bool locked;
    //Pointer to SFML render window
    sf::RenderWindow *window;
    sf::Color activeColor;
    sf::Color idleColor;
    sf::Vector2f pos;
    // SFML texture list for the object (if any). Some objects
    // such as LED element may have multiple textures (for on
    // state and off state), hence this is a list
    sf::Texture texture;
    // State of the logic element (may be used to designate
    // button state, D-flipflop state or whether LED is on or off
    bool state;


    Object(sf::RenderWindow *window, sf::Vector2f pos) {
        this->window = window;
        this->pos = pos;
        this->next = nullptr;
        this->idleColor = sf::Color(108, 113, 196);
        locked = false;
    }

public:
    // Pointer to next object in the list
    Object *next;

    virtual bool isInObject(sf::Vector2f mousePos) = 0;


    virtual void draw() {
    };

    virtual void setPosition(sf::Vector2f pos) {
        this->pos = pos;
    }

    // Add newObject to the end of object list
    void addNewObject(Object *newObject) {
        Object *curr = this;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newObject;
    }

    bool isLocked() const {
        return locked;
    }
};

#endif //LOGICPROJECTS_OBJECT_H
