#include "triangle_wave.h"

#include <cmath>


double TriangleWave::GetWaveAudioSample(const double cycles) const noexcept {
  return 4 * std::fabs(cycles - std::floor(cycles + 0.75) + 0.25) + 1;
}