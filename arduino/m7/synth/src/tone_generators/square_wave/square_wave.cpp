#include "square_wave.h"

#include <cmath>


double SquareWave::GetWaveAudioSample(const double cycles) const noexcept {
  return ((4 * std::floor(cycles)) * (-2 * std::floor(2 * cycles))) + 1;
}