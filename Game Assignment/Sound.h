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
    

    FMOD::System* system;
   
    FMOD::Channel* attackChannel;
    FMOD::Channel* mainChannel;
    FMOD::Channel* hitChannel;
    FMOD::Channel* enemyChannel;
   

    FMOD::Sound* attackSound;
    FMOD::Sound* mainSound;
    FMOD::Sound* hitSound;
    FMOD::Sound* enemySound;




    float m_volume;
public:
    static Sound* getInstance();
    static void releaseInstance();
    void Release();
    
    
   
    void playAttackSound();
    void playMainSound();
    void playHitSound();
    void playEnemySound();

  
    
    Sound();
    ~Sound();
  
};

#endif
