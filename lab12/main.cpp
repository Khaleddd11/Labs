#include <SDL2/SDL.h>
#include "picture.h"
#include "point.h"
#include "line.h"
#include "circle.h"
#include "rectangle.h"

int main(int argc, char* argv[]) {
    // initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return -1;
    }
    
    // create window
    SDL_Window* window = SDL_CreateWindow(
        "Shape Drawing Demo",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_SHOWN
    );
    
    if (!window) {
        SDL_Quit();
        return -1;
    }
    
    // create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    if (!renderer) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
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
    SDL_Event event;
    
    while (running) {
        // handle events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            // press ESC to quit
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