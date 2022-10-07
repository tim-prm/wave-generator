#include <aaudio/AAudio.h>
#include "Oscillator.h"

class AudioEngine {
public:
    bool start();
    void stop();
    void restart();
    void setFrequency(double newFreq);

private:
    Oscillator oscillator_;
    AAudioStream *stream_;
};
