/*****************************************************************************
*                    
*  Author:           Zachary Barrentine
*  Email:            zlbarrentine0427@my.msutexas.edu
*  Label:            Music Class
*  Title:            Background Music Controller
*  Course:           CMPS 2143
*  Semester:         Fall 2024
* 
*  Description:
*        This class manages background music for a game or application using SFML's
*        audio system. It handles loading an MP3 file, setting the volume, and
*        controlling playback with looping capability. The class provides basic
*        functionality to check if the music file loaded successfully and to
*        start playing the music with automatic looping enabled.
*
*  Usage:
*       - Create a Music object
*       - Call check() to load and configure the music file
*       - Call play() to start the music with looping
* 
*  Files:            
*       music.hpp    : header file containing the Music class implementation
*       The Gates of Hell.mp3 : music file that will be played
*****************************************************************************/

#ifndef MUSIC_HPP
#define MUSIC_HPP

#include <SFML/Audio.hpp>
#include <iostream>

/**
 * Music
 * 
 * Description:
 *      This class provides a simple interface for handling background music
 *      in an application. It wraps SFML's Music functionality to provide
 *      easy loading and playback control of a music file.
 * 
 * Public Methods:
 *      void check()    - Loads and configures the music file
 *      void play()     - Starts playing the music with looping
 * 
 * Private Methods:
 *      None
 * 
 * Usage: 
 *      Music bgMusic;          // Create music object
 *      bgMusic.check();        // Load and configure music
 *      bgMusic.play();         // Start playing music
 */
class Music {
    sf::Music music;            // SFML Music object for handling the audio file

public:
    /**
    * Public : check
    * 
    * Description:
    *      Attempts to load the music file and configure initial settings.
    *      If loading is successful, sets the volume to 25%. If loading
    *      fails, outputs an error message to cerr.
    * 
    * Params:
    *      None
    * 
    * Returns:
    *      void
    */
    void check() {
        if (!music.openFromFile("The Gates of Hell.mp3")) {
            std::cerr << "Failed to load music file!" << std::endl;
        } else {
            music.setVolume(25.f);
        }
    }

    /**
    * Public : play
    * 
    * Description:
    *      Starts playing the music if it's not already playing.
    *      Enables looping and begins playback. If the music is
    *      already playing, this method does nothing.
    * 
    * Params:
    *      None
    * 
    * Returns:
    *      void
    */
    void play() {
        if (music.getStatus() != sf::Music::Playing) {
            music.setLoop(true);
            music.play();
        }
    }
};

#endif // MUSIC_HPP