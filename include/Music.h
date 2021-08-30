#ifndef MUSIC
#define MUSIC

#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

class Music{
    private:
        Mix_Music * music;

    public:
        Music();
        Music(const char * file);
        ~Music();

        void Play(int times);
        void Stop(int msToStop);
        void Open(const char * file);
        bool IsOpen();

};

#endif