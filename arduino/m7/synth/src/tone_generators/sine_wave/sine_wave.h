#pragma once

#include "../tone_generator.h"


class SineWave final : public ToneGenerator {
public:
  SineWave() = default;
  ~SineWave() override = default;
  
private:
  double GetWaveAudioSample(double cycles) const noexcept override;
};