#include "Sound.h"
#include "Windows.h"
#include "GameStateManager.h"

Sound* Sound::sInstance = NULL;

Sound* Sound::getInstance()
{
    if (Sound::sInstance == NULL)
    {
        sInstance = new Sound;
    }

    return sInstance;
}

void Sound::releaseInstance()
{
    delete sInstance;
    sInstance = NULL;
}


Sound::Sound() {

    system = NULL;

   
    attackChannel = NULL;
    mainChannel = NULL;
   

  
    attackSound = NULL;
    mainSound = NULL;
   

    FMOD::System_Create(&system);
    FMOD_RESULT result = FMOD::System_Create(&system);
    if (result != FMOD_OK) {
        printf("FMOD ERROR! (%d)\n", result);
    }
    result = system->init(512, FMOD_INIT_NORMAL, 0);
    if (result != FMOD_OK) {
        printf("FMOD ERROR! (%d)\n", result);
        exit(-1);
    }

 
    system->createSound("resource/sound/attackSound.mp3", FMOD_DEFAULT, 0, &attackSound);
    system->createSound("resource/sound/mainMenu.mp3", FMOD_DEFAULT, 0, &mainSound);
    
}

Sound::~Sound() {

}




void Sound::playAttackSound() {
    system->playSound(attackSound, NULL, false, &attackChannel);
    attackSound->setMode(FMOD_LOOP_OFF);
}

void Sound::playMainSound() {
    system->playSound(mainSound, NULL, false, &mainChannel);
    mainSound->setMode(FMOD_LOOP_NORMAL);
}





void Sound::Release() {
    system->release();
    system = NULL;

    
  

    attackSound->release();
    attackSound = NULL;

    mainSound->release();
    mainSound = NULL;

}

//int Sound::pause() {
//
//    return 0;
//}
//
//int Sound::resume() {
//
//    return 0;
//}
//
//int Sound::stop() {
//
//    return 0;
//}
//
//int Sound::volumeUp() {
//
//    return 0;
//}
//
//int Sound::volumeDown() {
//
//    return 0;
//}
//
//
//int Sound::Update() {
//
//    return 0;
//}
