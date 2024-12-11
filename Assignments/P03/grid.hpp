/*****************************************************************************
*                    
*  Author:           Zachary Barrentine
*  Email:            zlbarrentine0427@my.msutexas.edu
*  Label:            Grid Class
*  Title:            Interactive Grid System
*  Course:           CMPS 2143
*  Semester:         Fall 2024
* 
*  Description:
*        This class implements a graphical grid system using SFML. It creates
*        a 3x3 grid of rectangles with customizable spacing and positioning.
*        Each cell in the grid is represented by a RectangleShape with a black
*        fill color and white outline. The grid's position can be dynamically
*        adjusted, and the entire grid will be recreated to reflect any
*        position changes.
*
*  Usage:
*       - Create a Grid object
*       - Optionally set grid position using setGridStartXY()
*       - Draw the grid to an SFML window
* 
*  Files:            
*       grid.hpp    : header file containing the Grid class implementation
*****************************************************************************/

#ifndef GRID_HPP
#define GRID_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

/**
 * Grid
 * 
 * Description:
 *      This class manages a 3x3 grid of rectangular cells using SFML's
 *      graphics system. Each cell is represented as a RectangleShape
 *      with customizable properties including size, spacing, and position.
 * 
 * Public Methods:
 *      Grid()                          - Constructor that creates initial grid
 *      void setGridStartXY()          - Sets the starting position of the grid
 *      void createGrid()              - Creates or recreates the grid
 *      void draw()                    - Draws the grid to the window
 * 
 * Private Methods:
 *      None
 * 
 * Usage: 
 *      Grid gameGrid;                     // Create grid object
 *      gameGrid.setGridStartXY(100, 60);  // Set position
 *      gameGrid.draw(window);             // Draw to SFML window
 */
class Grid {
    std::vector<sf::RectangleShape> grid;      // Vector storing all grid cells
    const int rows = 3;                         // Number of rows in the grid
    const int cols = 3;                         // Number of columns in the grid
    const float cellSize = 60.f;               // Width and height of each cell
    float gridStartX = 100.f;                  // Starting X position of the grid
    float gridStartY = 60.f;                   // Starting Y position of the grid
    const float cellSpacing = 5.f;             // Spacing between cells

public:
    /**
    * Constructor
    * 
    * Description:
    *      Initializes the Grid object and creates the initial grid layout.
    * 
    * Returns:
    *      None
    */
    Grid() {
        createGrid();
    }

    /**
    * Public : setGridStartXY
    * 
    * Description:
    *      Updates the grid's starting position and recreates the grid
    *      to reflect the new position.
    * 
    * Params:
    *      float x : New X coordinate for grid start position
    *      float y : New Y coordinate for grid start position
    * 
    * Returns:
    *      void
    */
    void setGridStartXY(float x, float y) {
        gridStartX = x;
        gridStartY = y;
        createGrid(); // Re-create grid if position is changed
    }

    /**
    * Public : createGrid
    * 
    * Description:
    *      Creates or recreates the entire grid. Clears any existing grid
    *      cells and creates new ones with current position and spacing
    *      settings. Each cell is created as a black rectangle with a
    *      white outline.
    * 
    * Params:
    *      None
    * 
    * Returns:
    *      void
    */
    void createGrid() {
        grid.clear(); // Clear existing grid before re-creating it

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
                cell.setFillColor(sf::Color::Black); // Default cell color
                cell.setOutlineColor(sf::Color::White);
                cell.setOutlineThickness(1.5f);

                // Calculate cell position
                float x = gridStartX + col * (cellSize + cellSpacing);
                float y = gridStartY + row * (cellSize + cellSpacing);
                cell.setPosition(x, y);

                // Add the cell to the grid
                grid.push_back(cell);
            }
        }
    }

    /**
    * Public : draw
    * 
    * Description:
    *      Draws all grid cells to the provided SFML render window.
    * 
    * Params:
    *      sf::RenderWindow& window : Reference to the SFML window to draw to
    * 
    * Returns:
    *      void
    */
    void draw(sf::RenderWindow& window) {
        for (const auto& cell : grid) {
            window.draw(cell);
        }
    }
};

#endif // GRID_HPP