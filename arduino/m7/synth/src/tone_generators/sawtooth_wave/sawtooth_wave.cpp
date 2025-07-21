#include "sawtooth_wave.h"

#include <cmath>


double SawtoothWave::GetWaveAudioSample(const double cycles) const noexcept {
  return 2 * (cycles - std::floor(cycles + 0.5));
}