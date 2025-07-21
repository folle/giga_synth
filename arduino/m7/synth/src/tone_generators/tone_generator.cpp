#include "tone_generator.h"

#include <AdvancedAnalog.h>

#include "../settings/settings.h"


ToneGenerator::ToneGenerator() noexcept {
  switch (Settings::Instance().GetResolution()) {
  case AN_RESOLUTION_12:
    mininum_amplitude_ = -2048;
    break;
  }
}

double ToneGenerator::GetAudioSample(const double frequency, const uint64_t time_step) const noexcept {
  const auto sample_rate = Settings::Instance().GetSampleRate();
  const auto time = (time_step % sample_rate) / static_cast<double>(sample_rate);
  const auto cycles = time * frequency;
  return mininum_amplitude_ * GetWaveAudioSample(cycles);
}