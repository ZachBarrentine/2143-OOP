/*****************************************************************************
*                    
*  Author:           Zachary Barrentine
*  Email:            zlbarrentine0427@my.msutexas.edu
*  Label:            Roll Class
*  Title:            Dice Rolling Animation
*  Course:           CMPS 2143
*  Semester:         Fall 2024
* 
*  Description:
*        This class implements a graphical dice rolling animation using SFML.
*        It loads a series of frame textures to create a smooth rolling animation
*        and displays a random final face when the roll completes. The animation
*        consists of 24 frames played in sequence, followed by a random die face.
*
*  Usage:
*       - Create a Roll object
*       - Call startRoll() to begin animation
*       - Update the roll in your game loop
*       - Draw the roll to your SFML window
* 
*  Files:            
*       roll.hpp    : header file containing the Roll class implementation
*       images/     : directory containing animation frames and die face images
*****************************************************************************/

#ifndef ROLL_HPP
#define ROLL_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <random>

/**
 * Roll
 * 
 * Description:
 *      This class manages the dice rolling animation and final face display.
 *      It handles loading animation frames, updating the animation state,
 *      and rendering the current frame to the screen.
 * 
 * Public Methods:
 *      Roll()                          - Constructor that loads animation frames
 *      void update()                   - Updates the current animation frame
 *      void startRoll()               - Begins the rolling animation
 *      void stopRoll()                - Stops the rolling animation
 *      void draw()                    - Draws the current frame
 *      bool isRolling()               - Checks if dice is currently rolling
 *      sf::Sprite& getSprite()        - Returns reference to the sprite
 * 
 * Private Methods:
 *      None
 * 
 * Usage: 
 *      Roll dice;                // Create dice object
 *      dice.startRoll();        // Start rolling animation
 *      dice.update();           // Update animation state
 *      dice.draw(window);       // Draw to SFML window
 */
class Roll {
    int currentFace;                    // Stores the current face value of the die
    sf::Texture randFrame;              // Texture for the final random face
    std::vector<sf::Texture> textures;  // Vector storing all animation frame textures
    sf::Sprite sprite;                  // Sprite used to render the current frame
    sf::Clock clock;                    // Clock for timing frame updates
    sf::Time frameDuration;             // Duration to display each frame
    std::string nowFrame;               // Current frame filename
    int currentFrame;                   // Index of current animation frame
    int rollFrameCount;                 // Counter for tracking animation progress
    bool rolling;                       // Flag indicating if die is currently rolling

public:
    /**
    * Constructor
    * 
    * Description:
    *      Initializes the Roll object and loads all animation frames.
    *      Sets up initial position and loads frame textures.
    * 
    * Returns:
    *      None
    */
    Roll() :
        frameDuration(sf::milliseconds(24)),
        currentFrame(0),
        rollFrameCount(0),
        rolling(false) {
        std::srand(std::time(0));
        for (int i = 1; i <= 24; ++i) {
            sf::Texture texture;
            std::string prefix = (i < 10) ? "00" : "0";
            std::string filename = "frame_" + prefix + std::to_string(i) + ".png";
            if (!texture.loadFromFile("../PROG3OOP/images/" + filename)) {
                std::cerr << "Error loading " << filename << std::endl;
                return;
            }
            textures.push_back(texture);
        }

        if (!textures.empty()) {
            sprite.setTexture(textures[currentFrame]);
        }
        sprite.setPosition(300.f, 350.f);
    }

    /**
    * Public : update
    * 
    * Description:
    *      Updates the animation state. If rolling, advances to next frame
    *      after frameDuration has elapsed. When animation completes,
    *      selects and displays random final face.
    * 
    * Returns:
    *      void
    */
    void update() {
        if (rolling) {
            if (clock.getElapsedTime() >= frameDuration) {
                clock.restart();
                currentFrame = (currentFrame + 1) % textures.size();
                sprite.setTexture(textures[currentFrame]);
                rollFrameCount++;

                // Check if we've completed one full animation cycle
                if (rollFrameCount >= 24) {
                    // Generate random final face
                    int finalFace = rand() % 6 + 1;
                    nowFrame = std::to_string(finalFace) + ".png";
                    if (!randFrame.loadFromFile("../PROG3OOP/images/" + nowFrame)) {
                        std::cerr << "Error loading " << nowFrame << std::endl;
                        return;
                    }
                    sprite.setTexture(randFrame);
                    stopRoll();
                }
            }
        }
    }

    /**
    * Public : startRoll
    * 
    * Description:
    *      Initiates the rolling animation by resetting animation
    *      counters and starting the clock.
    * 
    * Returns:
    *      void
    */
    void startRoll() {
        rolling = true;
        rollFrameCount = 0;
        currentFrame = 0;
        clock.restart();
    }

    /**
    * Public : stopRoll
    * 
    * Description:
    *      Stops the rolling animation by resetting the rolling flag
    *      and frame counter.
    * 
    * Returns:
    *      void
    */
    void stopRoll() {
        rolling = false;
        rollFrameCount = 0;
    }

    /**
    * Public : draw
    * 
    * Description:
    *      Draws the current frame to the provided SFML window.
    * 
    * Params:
    *      sf::RenderWindow& window : Reference to the SFML window to draw to
    * 
    * Returns:
    *      void
    */
    void draw(sf::RenderWindow& window) {
        window.draw(sprite);
    }

    /**
    * Public : isRolling
    * 
    * Description:
    *      Checks if the die is currently in rolling animation.
    * 
    * Returns:
    *      bool : True if die is rolling, false otherwise
    */
    bool isRolling() const {
        return rolling;
    }

    /**
    * Public : getSprite
    * 
    * Description:
    *      Returns a reference to the sprite used for rendering.
    * 
    * Returns:
    *      sf::Sprite& : Reference to the sprite object
    */
    sf::Sprite& getSprite() {
        return sprite;
    }
};

#endif // ROLL_HPP