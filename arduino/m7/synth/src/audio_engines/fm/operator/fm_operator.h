#pragma once

#include <memory>

#include "../../../settings/settings.h"
#include "../../../tone_generators/tone_generator.h"


class FmOperator final {
public:
  FmOperator() noexcept;
  ~FmOperator() = default;

  void SetToneGenerator(Settings::ToneGeneratorType type) noexcept;
  void SetSettings(Settings::FmEngineOperatorSettings settings) noexcept;

  double GetAudioSample(double frequency, uint64_t time_step) const noexcept;

private:
  std::unique_ptr<ToneGenerator> tone_generator_;

  Settings::FmEngineOperatorSettings settings_;
};