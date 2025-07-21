#include "settings.h"


Settings& Settings::Instance() noexcept{
  static Settings instance_;
  return instance_;
};

uint32_t Settings::GetResolution() const noexcept {
  return kResolution;
}

uint32_t Settings::GetSampleRate() const noexcept {
  return kSampleRate;
}

double Settings::GetVolume() noexcept {
  const mbed::ScopedLock<rtos::Mutex> mutex_lock(volume_mutex_);
  return volume_;
}

void Settings::SetVolume(const double volume) noexcept {
  const mbed::ScopedLock<rtos::Mutex> mutex_lock(volume_mutex_);
  volume_ = volume;
}

Settings::AudioEngineType Settings::GetAudioEngineType() const noexcept {
  return audio_engine_type_;
}

void Settings::SetAudioEngineType(const AudioEngineType type) noexcept {
  audio_engine_type_ = type;
}

std::size_t Settings::GetFmEngineOperatorsCount() const noexcept {
  return kFmEngineOperatorsCount;
}

uint8_t Settings::GetFmEngineAlgorithm() const noexcept {
  return fm_engine_algorithm_;
}

void Settings::SetFmEngineAlgorithm(const uint8_t algorithm) noexcept {
  fm_engine_algorithm_ = algorithm;
}

void Settings::SetFmEngineToneGeneratorType(const ToneGeneratorType type) noexcept {
  fm_engine_tone_generator_type_ = type;
}

Settings::ToneGeneratorType Settings::GetFmEngineToneGeneratorType() const noexcept {
  return fm_engine_tone_generator_type_;
}

Settings::FmEngineOperatorSettings Settings::GetFmEngineOperatorSettings(const std::size_t operator_index) const noexcept {
  if (operator_index >= fm_engine_operators_settings_.size()) {
    return { 1.0, 1.0 };
  }

  return fm_engine_operators_settings_[operator_index];
}

void Settings::SetFmEngineOperatorRatio(const std::size_t operator_index, const double ratio) noexcept {
  if (operator_index >= fm_engine_operators_settings_.size()) {
    return;
  }

  fm_engine_operators_settings_.at(operator_index).ratio = ratio;
}

void Settings::SetFmEngineOperatorLevel(const std::size_t operator_index, const double level) noexcept {
  if (operator_index >= fm_engine_operators_settings_.size()) {
    return;
  }

  fm_engine_operators_settings_.at(operator_index).level = level;
}

Settings::AdsrEnvelopeSettings Settings::GetAdsrEnvelopeSettings() const noexcept {
  return adsr_envelope_settings_;
}

void Settings::SetAdsrEnvelopeAttack(const uint8_t attack) noexcept {
  adsr_envelope_settings_.attack = attack;
}

void Settings::SetAdsrEnvelopeDecay(const uint8_t decay) noexcept {
  adsr_envelope_settings_.decay = decay;
}

void Settings::SetAdsrEnvelopeSustain(const double sustain) noexcept {
  adsr_envelope_settings_.sustain = sustain;
}

void Settings::SetAdsrEnvelopeRelease(const uint8_t release) noexcept {
  adsr_envelope_settings_.release = release;
}

std::size_t Settings::GetAdvancedDacOutputSamplesPerBuffer() const noexcept {
  return kAdvancedDacOutputSamplesPerBuffer;
}

std::size_t Settings::GetAdvancedDacOutputBuffersCount() const noexcept {
  return kAdvancedDacOutputBuffersCount;
}

uint8_t Settings::GetMidiInputChannel() noexcept {
  const mbed::ScopedLock<rtos::Mutex> mutex_lock(midi_input_channel_mutex_);
  return midi_input_channel_;
}

void Settings::SetMidiInputChannel(const uint8_t channel) noexcept {
  const mbed::ScopedLock<rtos::Mutex> mutex_lock(midi_input_channel_mutex_);
  midi_input_channel_ = channel;
}
