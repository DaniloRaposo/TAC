#include "../include/Music.h"

Music::Music(){
    music = NULL;
}

Music::Music(const char * file){
    music = NULL;
    Open(file);
}

Music::~Music(){
    Stop(1500);
    Mix_FreeMusic(music);
}

void Music::Play(int times){
    Mix_PlayMusic(music, times);
}

void Music::Stop(int msToStop){
    Mix_FadeOutMusic(msToStop);
}
// Metodo que carrega a musica indicada pelo arquivo file
void Music::Open(const char * file){
    music = Mix_LoadMUS(file);
    this->Play(-1);
}

bool Music::IsOpen(){
    return (music != NULL);
}