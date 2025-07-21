#pragma once

#include "../tone_generator.h"


class SawtoothWave final : public ToneGenerator {
public:
  SawtoothWave() = default;
  ~SawtoothWave() override = default;
    
private:
  double GetWaveAudioSample(double cycles) const noexcept override;
};