

#ifndef LOGICPROJECTS_TOOLBOXGRID_H
#define LOGICPROJECTS_TOOLBOXGRID_H
#define NO_SUBLINES 6

#include <SFML/Graphics/RenderWindow.hpp>

class ToolBoxGrid {
    sf::RenderWindow *window;
    sf::Vertex horizontalLine[2];
    sf::Vertex verticalLine1[2];
    sf::Vertex verticalLine2[2];
    sf::Vertex subHorizontalLines[NO_SUBLINES][2];
    sf::Color color;

public:
    ToolBoxGrid(sf::RenderWindow *window);

    void render();
};

#endif //LOGICPROJECTS_TOOLBOXGRID_H
