

#ifndef LOGICPROJECTS_SIMULATOR_H
#define LOGICPROJECTS_SIMULATOR_H

#include <SFML/Graphics.hpp>
#include "Object.h"
#include "ToolBoxGrid.h"
#include "Pin.h"

enum SimulatorState{
    DEFAULT, // our default state which we can create new logic elements
    DRAG_AND_DROP, // This is active when moving/dragging the object until the release mouse left button
    DELETE_MODE,   // in this mode/state, we delete when the user click on top of a logic element
    // the state for creating wires between input and output pins.
    // In this mode, to create wire between the pins, users should first click on the output pin of a logic element then click to the input pin of another logic element.
    WIRE_MODE,
    RUNNING // in this state, we only allow to click to the stop button, ignore other events
};

class Simulator {
    sf::RenderWindow* window;
    // this object pointer points to the head of the linked list
    Object* objects;
    SimulatorState state;
    ToolBoxGrid* grid;
    Object* heldObject;
    Pin *clickedOutputPin;
    sf::Color backgroundColor;

public:
    Simulator();
    void handleEvents();
    void render();
    void startSimulation();
    void stopSimulation();

    Object *getMovableObject(sf::Vector2<float> mousePos);

    void addObject(Object *object);

    void deleteObject(Object *deleted);

    void createToolBox();

    void tryClickAnyButton(sf::Vector2<float> mousePos);

    void setState(SimulatorState state);

    Pin *getClickedPin(sf::Vector2<float> mousePos);

    void createWireBetweenPins(Pin *outputPin, Pin *inputPin);

    void tryClickStopButton(sf::Vector2<float> mousePos);
};


#endif //LOGICPROJECTS_SIMULATOR_H
