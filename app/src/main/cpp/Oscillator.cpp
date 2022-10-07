#include "Oscillator.h"
#include <math.h>
#include <android/log.h>

#define TWO_PI (3.14159 * 2)
#define AMPLITUDE 0.3


// Define the sample rate for the audio data.
void Oscillator::setSampleRate(int32_t sampleRate) {
    phaseIncrement_ = (TWO_PI * frequency) / (double) sampleRate;
    __android_log_print(ANDROID_LOG_ERROR, "AudioEngine", "frequency %f",frequency);

}

// Place the values of the wave in the array audioData at each call.
void Oscillator::render(float *audioData, int32_t numFrames) {


    for (int i = 0; i < numFrames; i++) {
        // Calculates the next sample value for the sine wave.
        audioData[i] = (float) (sin(phase_) * AMPLITUDE);

        // Increments the phase, handling wrap around.
        phase_ += phaseIncrement_;
        if (phase_ > TWO_PI) phase_ -= TWO_PI;
    }
}
