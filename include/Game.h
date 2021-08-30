#ifndef GAME
#define GAME

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "State.h"
#include <cstddef>
#include <iostream>

class Game {
    private:
        Game(const char* title, int width, int height);

        static Game * instance;
        SDL_Window * window;
        SDL_Renderer * renderer;
        State * state;

    public:
        ~Game();
        void Run();
        SDL_Renderer * GetRenderer();
        static Game * GetInstance();
        State * GetState();

};

#endif