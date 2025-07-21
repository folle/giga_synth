#include "fm_operator.h"

#include "../../../tone_generators/sawtooth_wave/sawtooth_wave.h"
#include "../../../tone_generators/sine_wave/sine_wave.h"
#include "../../../tone_generators/square_wave/square_wave.h"
#include "../../../tone_generators/triangle_wave/triangle_wave.h"


FmOperator::FmOperator() noexcept {
  SetToneGenerator(Settings::Instance().GetFmEngineToneGeneratorType());
}

void FmOperator::SetToneGenerator(const Settings::ToneGeneratorType type) noexcept {
  switch (type) {
    case Settings::ToneGeneratorType::kSquareWave:
      tone_generator_ = std::make_unique<SquareWave>();
      break;
    case Settings::ToneGeneratorType::kTriangleWave:
      tone_generator_ = std::make_unique<TriangleWave>();
      break;
    case Settings::ToneGeneratorType::kSawtoothWave:
      tone_generator_ = std::make_unique<SawtoothWave>();
      break;
    case Settings::ToneGeneratorType::kSineWave:
      tone_generator_ = std::make_unique<SineWave>();
      break;
  }
}

void FmOperator::SetSettings(const Settings::FmEngineOperatorSettings settings) noexcept {
  settings_ = settings;
}

double FmOperator::GetAudioSample(const double frequency, const uint64_t time_step) const noexcept {
  return tone_generator_->GetAudioSample(frequency * settings_.ratio, time_step) * settings_.level;
}