#include <stdint.h>

class Oscillator {
public:
    void setSampleRate(int32_t sampleRate);
    void render(float *audioData, int32_t numFrames);
    double frequency = 440.0;
    double phase_ = 0.0;

private:
    double phaseIncrement_ = 0.0;
};
