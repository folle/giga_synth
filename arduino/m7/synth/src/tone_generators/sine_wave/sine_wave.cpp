#include "sine_wave.h"

#include <cmath>

#include <math.h>


double SineWave::GetWaveAudioSample(const double cycles) const noexcept {
  return std::sin(M_TWOPI * cycles);
}