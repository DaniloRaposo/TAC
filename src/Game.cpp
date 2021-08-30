#include "../include/Game.h"

Game * Game::instance;
// Construtor da classe Game, inicializa e instancia o necessário para o jogo começar
Game::Game(const char * title, int width, int height){
    if(instance == NULL){
        this->instance = this;

        SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
        IMG_Init(IMG_INIT_JPG);
        Mix_Init(MIX_INIT_OGG);
        Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);

        this->window = SDL_CreateWindow(title, 0, 0, width, height, 0);
        this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
        this->state = new State();
    }
    else{
        std::cout << "Erro com a lógica do jogo" << std::endl; 
    }
}
// Destrutor da classe Game, desaloca os recursos alocados anteriormente
Game::~Game(){
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
    this->instance = NULL;
}
// Metodo onde é feita a instancia do objeto da classe Game
Game * Game::GetInstance(){
    if(Game::instance == NULL){
        Game::instance = new Game("170031870", 1024, 600);
    }
        return instance;
}

State * Game::GetState(){
    return this->state;
}

SDL_Renderer * Game::GetRenderer(){
    return this->renderer;
}
// loop principal que roda o jogo. Nesse loop o estado do jogo é atualizado e renderizado para o usuário
void Game::Run(){
    while(!(this->state->QuitRequested())){
        GetState()->Update(0);
        GetState()->Render();
        SDL_RenderPresent(GetRenderer());
        SDL_Delay(33);
    }
}