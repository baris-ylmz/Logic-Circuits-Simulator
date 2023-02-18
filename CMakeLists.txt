cmake_minimum_required(VERSION 3.0)
project(LogicProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(LogicProject main.cpp Object.cpp Object.h Pin.cpp Pin.h logicelements/LogicElement.cpp logicelements/LogicElement.h Simulator.cpp Simulator.h logicelements/AndGate.cpp logicelements/AndGate.h Wire.cpp Wire.h buttons/Button.cpp buttons/Button.h buttons/AndGateButton.cpp buttons/AndGateButton.h buttons/OrGateButton.cpp buttons/OrGateButton.h buttons/XorGateButton.cpp buttons/XorGateButton.h buttons/NotGateButton.cpp buttons/NotGateButton.h logicelements/XorGate.cpp logicelements/XorGate.h logicelements/NotGate.cpp logicelements/NotGate.h logicelements/OrGate.cpp logicelements/OrGate.h buttons/DeleteModeButton.cpp buttons/DeleteModeButton.h ToolBoxGrid.cpp ToolBoxGrid.h buttons/WireModeButton.cpp buttons/WireModeButton.h buttons/StopButton.cpp buttons/StopButton.h buttons/RunButton.cpp buttons/RunButton.h buttons/DefaultModeButton.cpp buttons/DefaultModeButton.h logicelements/LogicOne.cpp logicelements/LogicOne.h logicelements/LogicZero.cpp logicelements/LogicZero.h buttons/LogicOneButton.cpp buttons/LogicOneButton.h buttons/LogicZeroButton.cpp buttons/LogicZeroButton.h buttons/LEDButton.cpp buttons/LEDButton.h logicelements/LED.cpp logicelements/LED.h)


set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/Users/brsyl/OneDrive/Desktop/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio REQUIRED)

include_directories (C:/Users/brsyl/OneDrive/Desktop/SFML-2.5.1/include)
target_link_libraries(LogicProject sfml-system sfml-window sfml-graphics sfml-audio)