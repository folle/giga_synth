#pragma once

#include "../tone_generator.h"


class SquareWave final : public ToneGenerator {
public:
  SquareWave() = default;
  ~SquareWave() override = default;
  
private:
  double GetWaveAudioSample(double cycles) const noexcept override;
};