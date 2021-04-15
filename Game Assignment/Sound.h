#pragma once
#ifndef _CSOUND_H_
#define _CSOUND_H_
#include <fmod.h>
#include <fmod.hpp>
#define SOUND_MAX 1.0f
#define SOUND_MIN 0.0f
#define SOUND_DEFAULT 0.5f
#define SOUND_WEIGHT 0.1f

class Sound {
private:
    static Sound* sInstance;
    
    Sound();
    ~Sound();

    FMOD::System* system;
    FMOD::Sound* mainMenu;
public:
    static Sound* getInstance();
    static void releaseInstance();
    FMOD::Channel* bgChannel;
    int play();
    void Release();

};

#endif
