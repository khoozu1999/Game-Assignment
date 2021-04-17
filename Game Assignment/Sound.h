#pragma once
#include <fmod.hpp>


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


