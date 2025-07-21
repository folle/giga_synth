#pragma once

#include "../tone_generator.h"


class TriangleWave final : public ToneGenerator {
public:
  TriangleWave() = default;
  ~TriangleWave() override = default;

private:
  double GetWaveAudioSample(double cycles) const noexcept override;
};