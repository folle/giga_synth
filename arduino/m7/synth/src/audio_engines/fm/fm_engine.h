#pragma once

#include <functional>
#include <unordered_map>
#include <vector>

#include "operator/fm_operator.h"
#include "../audio_engine.h"
#include "../../settings/settings.h"


class FmEngine final : public AudioEngine {
public:
  FmEngine() noexcept;
  ~FmEngine() override = default;
  
private:
  void GenerateAudioSamples(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept override;

  void ProcessSettings() noexcept override;


  void SwitchAlgorithm() noexcept;
  void SwitchToneGenerators() noexcept;

  void UpdateOperatorsSettings() noexcept;
  
  void Algorithm1(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm2(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm3(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm4(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm5(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm6(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm7(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm8(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm9(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm10(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm11(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm12(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm13(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm14(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm15(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm16(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm17(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm18(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm19(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm20(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm21(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm22(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm23(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm24(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm25(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm26(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm27(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm28(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm29(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm30(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm31(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  void Algorithm32(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;


  uint8_t active_algorithm_ = Settings::Instance().GetFmEngineAlgorithm();
  std::function<void(NotesInfo&, int16_t*, int16_t*, std::size_t)> algorithm_;

  Settings::ToneGeneratorType active_tone_generator_type_ = Settings::Instance().GetFmEngineToneGeneratorType();
  std::vector<FmOperator> fm_operators_ = std::vector<FmOperator>(Settings::Instance().GetFmEngineOperatorsCount());

  std::unordered_map<int, double> keys_feedbacks_;
};