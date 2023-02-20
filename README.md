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

    1. Clone the repository to your local machine
    git clone https://github.com/baris-ylmz/Logic-Circuits-Simulator.git
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
    

