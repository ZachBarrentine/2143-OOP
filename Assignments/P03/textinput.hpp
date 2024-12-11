/*****************************************************************************
*                    
*  Author:           Zachary Barrentine
*  Email:            zlbarrentine0427@my.msutexas.edu
*  Label:            TextInput
*  Title:            Text Input Handler Class
*  Course:           CMPS 2143
*  Semester:         Fall 2024
* 
*  Description:
*        This class handles text input in an SFML window, allowing users to type
*        characters that are displayed on screen. It includes features like
*        backspace handling, enter key detection, and displaying both the current
*        input and a greeting message after input is submitted. The class manages
*        font loading and text rendering using SFML's text rendering capabilities.
*
*  Usage:
*       - Create a TextInput instance
*       - Call handleEvent() with SFML events
*       - Call draw() in your render loop
* 
*  Files:            
*       textinput.hpp    : header file with class definition
*****************************************************************************/

#ifndef TEXTINPUT_HPP
#define TEXTINPUT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

/**
 * TextInput
 * 
 * Description:
 *      This class manages text input in an SFML window. It handles character input,
 *      displays the current input string, and shows a greeting message after the
 *      user submits their input. The class includes functionality for handling
 *      backspace and enter keys, as well as managing the display of text using
 *      SFML's text rendering system.
 * 
 * Public Methods:
 *                          TextInput()
 *      void                handleEvent(const sf::Event& event)
 *      void                draw(sf::RenderWindow& window)
 * 
 * Private Methods:
 *      void                updateText()
 * 
 * Usage:
 *      TextInput input;                    // Create text input handler
 *      input.handleEvent(event);           // Process SFML events
 *      input.draw(window);                 // Draw text to window
 */
class TextInput {
    std::string userInput;           // For storing typed characters
    sf::Font font;                   // Font for displaying text
    sf::Text text;                   // SFML text object
    sf::Text nameText;               // Text object to store and display the name after Enter is pressed

public:
    /**
    * Public : TextInput (Constructor)
    * 
    * Description:
    *      Initializes a TextInput object by loading the required font and
    *      configuring the text display settings for both input and output text.
    * 
    * Params:
    *      none
    * 
    * Returns:
    *      none
    */
    TextInput() {
        // Load a font (make sure to provide the correct path)
        if (!font.loadFromFile("resources/fonts/Roboto-Regular.ttf")) {
            std::cerr << "Error loading font\n";
        } else {
            std::cout << "Font loaded successfully\n";
        }

        // Configure the SFML text object for user input
        text.setFont(font);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::White);
        text.setPosition(10.f, 10.f); // Position of the text in the window

        // Configure the SFML text object for the entered name
        nameText.setFont(font);
        nameText.setCharacterSize(24);
        nameText.setFillColor(sf::Color::White);
    }

    /**
    * Public : handleEvent
    * 
    * Description:
    *      Processes SFML events related to text input. Handles character typing,
    *      backspace for deletion, and enter key for input submission.
    * 
    * Params:
    *      const sf::Event& event : SFML event to process
    * 
    * Returns:
    *      void
    */
    void handleEvent(const sf::Event& event) {
        // Handle **Text Input**: Typed characters
        if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode < 128) {  // Only handle ASCII characters
                char enteredChar = static_cast<char>(event.text.unicode);
                if (enteredChar == '\b') {  // Backspace handling
                    if (!userInput.empty()) {
                        userInput.pop_back();
                    }
                } else if (enteredChar == '\r') {  // Enter handling
                    std::cout << "Enter key detected. Final input: " << userInput << '\n';
                    nameText.setString("Hello, " + userInput + "!");  // Store the name in the nameText object
                    userInput.clear();  // Clear the input after Enter is pressed
                } else {
                    userInput += enteredChar;
                }
                updateText();
            }
        }
    }

    /**
    * Public : draw
    * 
    * Description:
    *      Renders the appropriate text to the SFML window. Shows either the
    *      current input prompt or the greeting message after input submission.
    * 
    * Params:
    *      sf::RenderWindow& window : SFML window to draw to
    * 
    * Returns:
    *      void
    */
    void draw(sf::RenderWindow& window) {
        if (nameText.getString().isEmpty()) {
            // If the name is not entered yet, show the input prompt
            text.setString("Enter your name: " + userInput); // Show prompt and input
            window.draw(text);  // Draw the input text prompt
        } else {
            // Once Enter is pressed, show the entered name
            window.draw(nameText);  // Draw the nameText (Hello, <name> message)
        }
    }

private:
    /**
    * Private : updateText
    * 
    * Description:
    *      Updates the displayed text to reflect the current user input.
    * 
    * Params:
    *      none
    * 
    * Returns:
    *      void
    */
    void updateText() {
        text.setString("Enter your name: " + userInput); // Update the text to reflect the current input
    }
};

#endif // TEXTINPUT_HPP