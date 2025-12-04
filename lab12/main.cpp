#include <SDL2/SDL.h>
#include "picture.h"
#include "point.h"
#include "line.h"
#include "circle.h"
#include "rectangle.h"

int main(int argc, char* argv[]) {

    // initialize SDL
    // ----------------------------------------------------
    // 1. Initialize SDL
    // ----------------------------------------------------
    // SDL_Init starts the SDL library. We need the VIDEO part
    // because we want to create windows and draw graphics.
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return -1; // failed to initialize SDL
    }
    
       // ----------------------------------------------------
    // 2. Create a window
    // ----------------------------------------------------
    // SDL_CreateWindow opens a window on the screen.
    // Parameters:
    // - title ("Shape Drawing Demo")
    // - x and y positions (centered)
    // - width = 800, height = 600
    // - SDL_WINDOW_SHOWN → make it visible
    SDL_Window* window = SDL_CreateWindow(
        "Shape Drawing Demo",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_SHOWN
    );
    
    if (!window) {
        SDL_Quit();
        return -1; // failed to create window
    }
    
     // ----------------------------------------------------
    // 3. Create the renderer
    // ----------------------------------------------------
    // The renderer is the "drawing tool" that draws on the window.
    // It is needed for lines, points, rectangles, circles, etc.
    //
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    if (!renderer) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1; // failed to create renderer
    }
    
    // create picture and add shapes
    Picture pic;
    
    // add some points
    pic.addShape(new Point(100, 100));
    pic.addShape(new Point(200, 100));
    
    // add lines
    pic.addShape(new Line(Point(50, 50), Point(750, 50)));
    pic.addShape(new Line(Point(50, 50), Point(50, 550)));
    
    // add circles
    pic.addShape(new Circle(Point(400, 300), 50));
    pic.addShape(new Circle(Point(600, 300), 80));
    
    // add rectangles
    pic.addShape(new Rectangle(Point(100, 400), 150, 100));
    pic.addShape(new Rectangle(Point(300, 400), 200, 120));
    
    // main loop
    bool running = true;

    // ----------------------------------------------------
// EVENT HANDLING SECTION
// ----------------------------------------------------

// SDL_Event is a struct that stores ANY user input event.
// It can hold: key press, mouse movement, mouse click,
// window close button, joystick, etc.

    SDL_Event event;
    
    while (running) {
        // handle events
        // - Checks if there is a pending event in the queue.
// - If YES → it copies the event into 'event' variable and returns 1.
// - If NO  → returns 0 and stops the loop.

        while (SDL_PollEvent(&event)) {
            // ------------------------------------------------
    // 1. Window close button (the X button)
    // ------------------------------------------------
    // If the user clicks the window's X, SDL sends an SDL_QUIT event.
            if (event.type == SDL_QUIT) {
                running = false; // exit the program
            }
            // press ESC to quit

        // event.key.keysym.sym contains WHICH key was pressed.
        // If the key is ESCAPE → quit the program.
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                running = false;
            }
        }
        
        // clear screen (black background)
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        
        // draw all shapes
        pic.draw(renderer);
        
        // present to screen
        SDL_RenderPresent(renderer);
        
        // small delay
        SDL_Delay(16);  // ~60 FPS
    }
    
    // cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}