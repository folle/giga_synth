#pragma once

#include <cstdint>
#include <vector>

#include <AdvancedAnalog.h>
#include <mbed.h>


class Settings {
public:
  static Settings& Instance() noexcept;

  ~Settings() = default;

  uint32_t GetResolution() const noexcept;
  uint32_t GetSampleRate() const noexcept;

  double GetVolume() noexcept;
  void SetVolume(double volume) noexcept;

  enum class AudioEngineType {
    kFm,
    kSampler,
    kAdditive,
    kSubtractive,
  };
  AudioEngineType GetAudioEngineType() const noexcept;
  void SetAudioEngineType(AudioEngineType type) noexcept;

  std::size_t GetFmEngineOperatorsCount() const noexcept;

  uint8_t GetFmEngineAlgorithm() const noexcept;
  void SetFmEngineAlgorithm(uint8_t algorithm) noexcept;

  enum class ToneGeneratorType {
    kSineWave,
    kSquareWave,
    kTriangleWave,
    kSawtoothWave
  };
  ToneGeneratorType GetFmEngineToneGeneratorType() const noexcept;
  void SetFmEngineToneGeneratorType(ToneGeneratorType type) noexcept;

  typedef struct {
    double ratio;
    double level;
  } FmEngineOperatorSettings;
  FmEngineOperatorSettings GetFmEngineOperatorSettings(std::size_t operator_index) const noexcept;
  void SetFmEngineOperatorRatio(std::size_t operator_index, double ratio) noexcept;
  void SetFmEngineOperatorLevel(std::size_t operator_index, double level) noexcept;

  typedef struct {
    uint8_t attack;
    uint8_t decay;
    double sustain;
    uint8_t release;
  } AdsrEnvelopeSettings;
  AdsrEnvelopeSettings GetAdsrEnvelopeSettings() const noexcept;
  void SetAdsrEnvelopeAttack(uint8_t attack) noexcept;
  void SetAdsrEnvelopeDecay(uint8_t decay) noexcept;
  void SetAdsrEnvelopeSustain(double sustain) noexcept;
  void SetAdsrEnvelopeRelease(uint8_t release) noexcept;

  std::size_t GetAdvancedDacOutputSamplesPerBuffer() const noexcept;
  std::size_t GetAdvancedDacOutputBuffersCount() const noexcept;

  uint8_t GetMidiInputChannel() noexcept;
  void SetMidiInputChannel(uint8_t channel) noexcept;

private:
  Settings() = default;
  Settings(const Settings&) = delete;
  Settings& operator=(const Settings&) = delete;

  
  static Settings* instance_;
  

  const uint32_t kResolution = AN_RESOLUTION_12;
  const uint32_t kSampleRate = 48000;
  
  rtos::Mutex volume_mutex_;
  double volume_ = 1.0;

  AudioEngineType audio_engine_type_ = AudioEngineType::kFm;

  const std::size_t kFmEngineOperatorsCount = 6L;
  uint8_t fm_engine_algorithm_ = 1;
  ToneGeneratorType fm_engine_tone_generator_type_ = ToneGeneratorType::kSineWave;
  std::vector<FmEngineOperatorSettings> fm_engine_operators_settings_ = std::vector<FmEngineOperatorSettings>(kFmEngineOperatorsCount, { .ratio = 1.0, .level = 1.0 });

  AdsrEnvelopeSettings adsr_envelope_settings_{
    .attack = 80,
    .decay = 80,
    .sustain = 0.8,
    .release = 80
  };

  const std::size_t kAdvancedDacOutputSamplesPerBuffer = 1L;
  const std::size_t kAdvancedDacOutputBuffersCount = 1L;

  rtos::Mutex midi_input_channel_mutex_;
  uint8_t midi_input_channel_ = 0;
};