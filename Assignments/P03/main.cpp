/*****************************************************************************
*                    
*  Author:           Zachary Barrentine
*  Email:            zlbarrentine0427@my.msutexas.edu
*  Label:            P02
*  Title:            KnuckleBones Game
*  Course:           CMPS 2143
*  Semester:         Fall 2024
* 
*  Description:
*        This program implements a graphical version of "KnuckleBones" using SFML.
*        The main functionality includes rendering grids, processing dice rolls,
*        handling text input, and playing background music. The music plays in a loop,
*        and the dice roll mechanism prevents concurrent rolls while another roll
*        is in progress.
*
*  Usage:
*       - Compile and run the program.
*       - Interact with the graphical interface using the keyboard:
*         - Press [Enter] to begin.
*         - Press [Space] to roll dice.
*         - Music plays automatically upon startup.
* 
*  Files:            
*       main.cpp         : driver program
*       grid.hpp         : header file for the Grid class
*       roll.hpp         : header file for the Roll class
*       textinput.hpp    : header file for the TextInput class
*       music.hpp        : header file for the Music class
*****************************************************************************/

#include <SFML/Graphics.hpp>
#include "grid.hpp"
#include "roll.hpp"
#include "textinput.hpp"
#include "music.hpp"
#include <ctime>
#include <vector>
#include <iostream>
#include <random>

/**
 * Main
 *
 * Description:
 *      Entry point of the program. Initializes the game window, sets up the
 *      game components, and handles user input and rendering in a loop. The
 *      background music is also initialized and played on a loop.
 *
 * Params:
 *      None
 *
 * Returns:
 *      int : Exit code (0 for success)
 */
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "KnuckleBones");

    Grid grid;                                      // Grid for the first player
    Grid grid2;                                     // Grid for the second player
    Roll roll;                                      // Roll class to handle dice rolls
    TextInput textinput;                            // TextInput class for user input
    Music backgroundMusic;                         // Music class for background music

    grid2.setGridStartXY(500.f, 60.f);              // Adjust the second grid's starting position

    // Initialize and play the music
    backgroundMusic.check();                        // Check if the music file loads correctly
    backgroundMusic.play();                         // Play the background music in a loop

    bool enterPressed = false;                      // Flag to track if Enter key is pressed

    // Main game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();                     // Close the window if the event is Closed
            }

            textinput.handleEvent(event);           // Handle text input events

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                enterPressed = true;                // Set flag when Enter key is pressed
            }

            // Handle space bar for dice rolling
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                if (!roll.isRolling()) {            // Start a roll only if no roll is in progress
                    roll.startRoll();
                }
            }
        }

        window.clear(sf::Color::Black);             // Clear the window with a black background

        textinput.draw(window);                     // Draw the text input box

        if (enterPressed) {                         // If Enter has been pressed:
            grid.draw(window);                      // Draw the first grid
            grid2.draw(window);                     // Draw the second grid

            roll.update();                          // Update the rolling mechanism
            window.draw(roll.getSprite());          // Draw the dice sprite
        }

        window.display();                           // Display the updated window contents
    }

    return 0;                                       // Return success
}