#include "../include/State.h"

// Construtor da classe State, onde os atributos são inicializados e os assets são carregados
State::State(){
    quitRequested = false;
    LoadAssets();
}

void State::LoadAssets(){
    bg = * (new Sprite("../img/ocean.jpg"));
    music = * (new Music("../audio/stageState.ogg"));

}
// Metodo onde é verificado se o jogo foi finalizado. Se sim, chamar o destrutor para as classes Sprite e Music
void State::Update (float dt){
    if(SDL_QuitRequested()){
        quitRequested = true;
        bg.~Sprite();
        music.~Music();
    }
}

void State::Render(){
    bg.Render(0, 0);
}

bool State::QuitRequested(){
    return quitRequested;
}