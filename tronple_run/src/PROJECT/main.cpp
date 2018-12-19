#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <cstddef>
#include <math.h>
#include <glimac/Program.hpp> 
#include <glimac/FilePath.hpp> 
#include <glimac/glm.hpp>
#include "project_classes/TrackballCamera.hpp"
#include "project_classes/FreeflyCamera.hpp"
#include "project_classes/Level.hpp"

using namespace glimac;

int main(int argc, char** argv) {

    /*********************************
   * INITIALIZATION OF WINDOW AND 
   *********************************/

  // Initialize SDL and open a window
  const int WINDOW_WIDTH = 800;
  const int WINDOW_HEIGTH = 800;
  SDLWindowManager windowManager(WINDOW_WIDTH, WINDOW_HEIGTH, "GLImac");

  // Initialize glew for OpenGL3+ support
  GLenum glewInitError = glewInit();
  if(GLEW_OK != glewInitError) {
      std::cerr << glewGetErrorString(glewInitError) << std::endl;
      return EXIT_FAILURE;
  }  
    
  /*********************************
   * INITIALIZATION OF PROGRAMS
   *********************************/

  FilePath applicationPath(argv[0]);
  //Programs
  std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
  std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

  /*********************************
   * INITIALIZATION OF LEVEL & GAME
   *********************************/

    Level level("0.ppm");

  /*********************************
   * INITIALIZATION OF CAMERAS
   *********************************/

  /*********************************
   * INITIALIZATION OF RENDERING
   *********************************/

  /*********************************
   * INITIALIZATION OF AUDIO
   *********************************/

  /*********************************
   * MENU 
   *********************************/

  /*********************************
   * MENU APPLICATION LOOP
   *********************************/

  bool done = false;
  bool game = false;
  while(!done) {

    // Event loop:

    SDL_Event e;
    while(windowManager.pollEvent(e)) {
      if(e.type == SDL_QUIT) {
        done = true; // Leave the loop after this iteration
      }
    }

    // Menu display

    /*********************************
     * GAME APPLICATION LOOP
     *********************************/

    while(game) {

      // Event loop:

      SDL_Event e;
      while(windowManager.pollEvent(e)) {
        if(e.type == SDL_QUIT) {
          game = false; // Leave the loop after this iteration
        }
      }

      // Pause menu

      /*********************************
       * CAMERA MANAGEMENT
       *********************************/

      /*********************************
       * GAME MANAGEMENT
       *********************************/

       /*********************************
       * GAME MANAGEMENT
       *********************************/

       // Player movement

       // Collision check

       // Updtate player informations

       /*********************************
       * GAME RENDERING
       *********************************/

       // ViewMatrix / Map / User Interface

       // Pause menu if game is paused

    }

  }

  return EXIT_SUCCESS;
}