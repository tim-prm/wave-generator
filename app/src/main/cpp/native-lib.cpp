#include <jni.h>
#include <android/input.h>
#include "AudioEngine.h"
#include <android/log.h>

static AudioEngine *audioEngine = new AudioEngine();

extern "C" {



JNIEXPORT void JNICALL
Java_fr_patecarbodev_twowaves_MainActivity_startEngine(JNIEnv *env, jobject thiz) {
    audioEngine->start();
}

JNIEXPORT void JNICALL
Java_fr_patecarbodev_twowaves_MainActivity_updateFrequency(JNIEnv *env, jobject thiz,
                                                           jdouble button_value) {
    if (button_value == 660.0) {
        audioEngine->setFrequency(button_value);
    }
    if (button_value == 440.0) {
        audioEngine->setFrequency(button_value);
    }
}

JNIEXPORT void JNICALL
Java_fr_patecarbodev_twowaves_MainActivity_stopEngine(JNIEnv *env, jobject thiz) {
    audioEngine->stop();
}




}
