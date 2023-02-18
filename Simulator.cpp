

#include "Simulator.h"
#include "buttons/Button.h"
#include "buttons/AndGateButton.h"
#include "buttons/OrGateButton.h"
#include "buttons/XorGateButton.h"
#include "buttons/NotGateButton.h"
#include "buttons/DeleteModeButton.h"
#include "buttons/WireModeButton.h"
#include "buttons/StopButton.h"
#include "buttons/RunButton.h"
#include "logicelements/LogicElement.h"
#include "buttons/DefaultModeButton.h"
#include "buttons/LogicOneButton.h"
#include "buttons/LogicZeroButton.h"
#include "buttons/LEDButton.h"
#include <iostream>

Simulator::Simulator() {
    this->objects = nullptr;
    this->heldObject = nullptr;
    this->clickedOutputPin = nullptr;
    // create window
    this->window = new sf::RenderWindow(sf::VideoMode(1640, 850), "Logic Circuits Simulator");
    this->state = DEFAULT;
    this->backgroundColor = sf::Color(111, 111, 111);
    createToolBox();
}

void Simulator::createToolBox() {
    grid = new ToolBoxGrid(window);
    auto *runButton = new RunButton(sf::Vector2f(15.f, 30.f), window, this);
    runButton->setSize(sf::Vector2f(250, 50));
    addObject(runButton);

    auto *stopButton = new StopButton(sf::Vector2f(365.f, 30.f), window, this);
    stopButton->setSize(sf::Vector2f(250, 50));

    addObject(stopButton);
    addObject(new AndGateButton(sf::Vector2f(15.f, 150.f), window, this));
    addObject(new OrGateButton(sf::Vector2f(15.f, 300.f), window, this));
    addObject(new XorGateButton(sf::Vector2f(15.f, 450.f), window, this));
    addObject(new NotGateButton(sf::Vector2f(15.f, 600.f), window, this));
    addObject(new DeleteModeButton(sf::Vector2f(15.f, 750.f), window, this));
    addObject(new DefaultModeButton(sf::Vector2f(165.f, 150.f), window, this));
    addObject(new WireModeButton(sf::Vector2f(165.f, 300.f), window, this));
    addObject(new LogicOneButton(sf::Vector2f(165.f, 450.f), window, this));
    addObject(new LogicZeroButton(sf::Vector2f(165.f, 600.f), window, this));
    addObject(new LEDButton(sf::Vector2f(165.f, 750.f), window, this));
}
// get object if it is not locked
Object *Simulator::getMovableObject(sf::Vector2<float> mousePos) {
    Object *currObject = objects;
    while (currObject != nullptr) {
        if (currObject->isInObject(mousePos) && !currObject->isLocked()) {
            return currObject;
        }
        currObject = currObject->next;
    }
    return nullptr;
}


Pin *Simulator::getClickedPin(sf::Vector2<float> mousePos) {
    Object *currObject = objects;
    while (currObject != nullptr) {
        auto *logicElement = dynamic_cast<LogicElement *>(currObject);
        if (logicElement != nullptr) {
            Pin *clickedPin = logicElement->getClickedPin(mousePos);
            if (clickedPin != nullptr) {
                return clickedPin;
            }
        }
        currObject = currObject->next;
    }
    return nullptr;
}

// check whether mouse position is in objects boundaries and if it is locked create the selected object
void Simulator::tryClickAnyButton(sf::Vector2<float> mousePos) {
    Object *currObject = objects;
    while (currObject != nullptr) {
        if (currObject->isInObject(mousePos) && currObject->isLocked()) {
            auto *button = dynamic_cast<Button *>(currObject);
            if (button != nullptr) {
                button->onClick(mousePos);
            }
            return;
        }
        currObject = currObject->next;
    }
}

void Simulator::handleEvents() {
    while (window->isOpen()) {
        sf::Event ev{};
        while (window->pollEvent(ev)) {
            switch (ev.type) {
                case sf::Event::MouseButtonPressed:
                    if (ev.mouseButton.button == sf::Mouse::Left) {
                        const sf::Vector2<float> &mousePos = sf::Vector2((float) ev.mouseButton.x,
                                                                         (float) ev.mouseButton.y);
                        Pin *clickedPin = nullptr;
                        switch (state) {
                            case DEFAULT:
                                heldObject = getMovableObject(mousePos);
                                if (heldObject != nullptr) {
                                    state = DRAG_AND_DROP;
                                } else {
                                    tryClickAnyButton(mousePos);
                                }
                                break;
                            case DRAG_AND_DROP:
                                break;
                            case WIRE_MODE:
                                clickedPin = getClickedPin(mousePos);
                                if (clickedPin != nullptr) {
                                    switch (clickedPin->getType()) {
                                        case OUTPUT:
                                            if (clickedOutputPin != nullptr) {
                                                clickedOutputPin->togglePinColor();
                                            }
                                            clickedPin->togglePinColor();
                                            clickedOutputPin = clickedPin;
                                            break;
                                        case INPUT:
                                            if (clickedOutputPin != nullptr) {
                                                // create wire between clickedOutputPin and currently clicked input pin
                                                createWireBetweenPins(clickedOutputPin, clickedPin);
                                                clickedOutputPin->togglePinColor();
                                                clickedOutputPin = nullptr;
                                            }
                                    }
                                } else {
                                    tryClickAnyButton(mousePos);
                                }

                                // cleanup
                                if (state != WIRE_MODE) {
                                    if (clickedOutputPin != nullptr) {
                                        clickedOutputPin->togglePinColor();
                                    }

                                    clickedOutputPin = nullptr;
                                }
                                break;
                            case RUNNING:
                                // only stop button can be clicked here
                                tryClickStopButton(mousePos);
                                break;
                            case DELETE_MODE:
                                Object *clickedMovableObject = getMovableObject(mousePos);

                                if (clickedMovableObject != nullptr) {
                                    deleteObject(clickedMovableObject);
                                } else {
                                    tryClickAnyButton(mousePos);
                                }
                                break;
                        }
                    }
                    break;
                case sf::Event::MouseButtonReleased:
                    if (ev.mouseButton.button == sf::Mouse::Left) {
                        switch (state) {
                            case DRAG_AND_DROP:
                                heldObject = nullptr;
                                state = DEFAULT;
                                break;
                            case DEFAULT:
                                break;
                            case DELETE_MODE:
                                break;
                            case WIRE_MODE:
                                break;
                            case RUNNING:
                                break;
                        }
                    }
                    break;
                case sf::Event::MouseMoved:
                    switch (state) {
                        case DEFAULT:
                            break;
                        case DRAG_AND_DROP:
                            if (heldObject != nullptr) {
                                LogicElement *logicElement = dynamic_cast<LogicElement *>(heldObject);
                                if (logicElement != nullptr) {
                                    logicElement->setPosition(
                                            sf::Vector2f((float) ev.mouseMove.x, (float) ev.mouseMove.y));
                                }
                            }
                            break;
                        case WIRE_MODE:
                            break;
                        case DELETE_MODE:
                            break;
                        case RUNNING:
                            break;
                    }
                    break;
                case sf::Event::Closed:
                    window->close();
                    break;
                default:; // noop
            }
        }
        render();
    }
}

void Simulator::addObject(Object *newObject) {
    if (objects == nullptr) {
        objects = newObject;
    } else {
        objects->addNewObject(newObject);
    }
}

void Simulator::deleteObject(Object *deleted) {
    Object *curr = objects;
    if (objects == nullptr) {
        return;
    } else if (objects == deleted) {
        objects = objects->next;
        delete deleted;
    } else {
        while (curr->next != deleted) {
            curr = curr->next;
        }
        curr->next = deleted->next;
        delete deleted;
    }
}

void Simulator::render() {
    window->clear(backgroundColor);
    // render grid grid
    grid->render();
    // render all objects including buttons, logic elements and their wires
    Object *curr = objects;
    while (curr != nullptr) {
        curr->draw();
        curr = curr->next;
    }
    // display window
    window->display();
}

void Simulator::startSimulation() {
    state = RUNNING;
    bool isAnyStateChanged = true;
    while (isAnyStateChanged) {
        isAnyStateChanged = false;
        Object *curr = objects;
        while (curr != nullptr) {
            auto *logicElement = dynamic_cast<LogicElement *>(curr);
            if (logicElement != nullptr) {
                bool isChanged = logicElement->applyLogicFunction();
                if (isChanged) {
                    isAnyStateChanged = true;
                }
            }
            curr = curr->next;
        }
    }
}

void Simulator::stopSimulation() {
    state = DEFAULT;
    Object *curr = objects;
    while (curr != nullptr) {
        auto *logicElement = dynamic_cast<LogicElement *>(curr);
        if (logicElement != nullptr) {
            logicElement->cleanup();
        }
        curr = curr->next;
    }

}

void Simulator::setState(SimulatorState _state) {
    this->state = _state;
}

void Simulator::createWireBetweenPins(Pin *outputPin, Pin *inputPin) {
    Wire *newWire = new Wire(outputPin->getPosition(), inputPin->getPosition());
    outputPin->connectToPin(inputPin, newWire);
    inputPin->connectToPin(outputPin, newWire);
}

//
void Simulator::tryClickStopButton(sf::Vector2<float> mousePos) {
    Object *currObject = objects;
    while (currObject != nullptr) {
        if (currObject->isInObject(mousePos) && currObject->isLocked()) {
            auto *button = dynamic_cast<StopButton *>(currObject);
            if (button != nullptr) {
                button->onClick(mousePos);
            }
            return;
        }
        currObject = currObject->next;
    }
}