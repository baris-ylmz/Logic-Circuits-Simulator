# Logic-Circuits-Simulator

This project is a logic circuit simulator that allows users to build and simulate digital circuits. It is written in C++ and uses the SFML library for its graphical interface.

## Features

    Building of digital circuits with logic gates (AND, OR, NOT, XOR)
    Simulation of digital circuits
    Display of circuit output

### Getting Started
### Prerequisites

    CLion IDE or Visual Studio 
    CMake
    SFML library

### Installation

    1. Clone the repository to your local machine git clone https://github.com/baris-ylmz/Logic-Circuits-Simulator.git
    2. Navigate to the project directory
    3. Open the project in CLion or Visual Studio
    4. Install SFML graphics library. https://www.sfml-dev.org/download.php
    5. After extracting the contents of the downloaded archive to a directory depending on your choice
    6. Open the CMakeLists.txt file in CLion and add the following lines to the bottom of the file:  
       - set(SFML_STATIC_LIBRARIES TRUE)
       - set(SFML_DIR path/to/SFML-2.x/lib/cmake/SFML)
       - find_package(SFML COMPONENTS system window graphics audio REQUIRED)
       - include_directories (path/to/SFML-2.x/include)
       - target_link_libraries(LogicCircuitsProject sfml-system sfml-window sfml-graphics sfml-audio)
### Usage
    - Use the left mouse button to select a logic gate from the toolbox on the left side of the window
    - Use the left mouse button to place the selected logic gate on the canvas
    - Connect the inputs and outputs of the gates with wires. Use the left mouse button to select Wire mode from the toolbox on the left side of the window
    - Click an output pin of an element to select it, then click an input pin of another element to create a wire between them
    - Provide logic 1 or logic 0 to the circuit by clicking on the "Input" button and clicking on an input pin of an element
    - Calculation of boolean functions can be done by clicking on the "Run" button on the top of the toolbox
    - Observe the circuit output.
    

