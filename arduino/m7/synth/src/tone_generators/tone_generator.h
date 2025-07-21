#pragma once

#include <cstdint>


class ToneGenerator {
public:
  ToneGenerator() noexcept;
  virtual ~ToneGenerator() = default;
  
  double GetAudioSample(double frequency, uint64_t time_step) const noexcept;

private:
  virtual double GetWaveAudioSample(double cycles) const noexcept = 0;


  long long mininum_amplitude_;
};