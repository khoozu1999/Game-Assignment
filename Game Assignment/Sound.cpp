#include "Sound.h"
#include "Windows.h"

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

    system->createSound("resource/sound/mainMenu.mp3", FMOD_DEFAULT, 0, &mainMenu);

}

Sound::~Sound() {
    mainMenu->release();
    mainMenu = NULL;
}

int Sound::play() {
    system->playSound(mainMenu, NULL, false, &sfxChannel);
    mainMenu->setMode(FMOD_LOOP_NORMAL);

    return 0;
}

//int Sound::init() {
//    return 0;
//}
//
//int Sound::Release() {
//    return 0;
//}

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
