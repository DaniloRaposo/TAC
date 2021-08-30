#include "../include/Game.h"
#include "../include/State.h"
#include "../include/Sprite.h"
#include "../include/Music.h"
#include <iostream>

int main(int argc, char ** argv){
    Game * game = Game::GetInstance();
    game->Run();
    game->~Game();

    return 0;
}