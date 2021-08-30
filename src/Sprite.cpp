#include "../include/Game.h"
#include "../include/Sprite.h"

Sprite::Sprite(){
    texture = NULL;
}

Sprite::Sprite(const char * file){
    texture = NULL;
    Open(file);
}

Sprite::~Sprite(){
    if(texture != NULL){
        SDL_DestroyTexture(texture);
    }
}
// Metodo que carrega a imagem designada pelo parametro file, descobre as dimensões da imagem e seta essa dimenções no clip
void Sprite::Open(const char * file){
    if(texture != NULL){
        SDL_DestroyTexture(texture);
    }

    texture = IMG_LoadTexture(Game::GetInstance()->GetRenderer(), file);    

    SDL_QueryTexture(texture, NULL, NULL, &width, &height);
    SetClip(0,0,width,height);
}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}
// Metodo que a partir do renderizador do jogo coloca a imagem carregada na tela
void Sprite::Render(int x, int y){
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.h = GetHeight();
    rect.w = GetWidth();
    SDL_RenderCopy(Game::GetInstance()->GetRenderer(),texture, &clipRect, &rect);
}

int Sprite::GetWidth(){
    return width;
}

int Sprite::GetHeight(){
    return height;
}

bool Sprite::IsOpen(){
    return (texture != NULL);
}