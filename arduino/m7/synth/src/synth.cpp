#include "synth.h"

#include "settings/settings.h"


void Synth::Process() {
  controls_.ProcessUi();
  
  DMABuffer<Sample> right_buffer;
  DMABuffer<Sample> left_buffer;
  if (!advanced_dac_output_.GetBuffers(right_buffer, left_buffer)) {
    return;
  }
  
  midi_input_.ProcessNotes(notes_info_);

  const auto right_buffer_data = reinterpret_cast<int16_t*>(right_buffer.data());
  const auto left_buffer_data = reinterpret_cast<int16_t*>(left_buffer.data());
  switch (Settings::Instance().GetAudioEngineType()) {
    case Settings::AudioEngineType::kAdditive:
      break;
    case Settings::AudioEngineType::kSubtractive:
      break;
    case Settings::AudioEngineType::kSampler:
      break;
    case Settings::AudioEngineType::kFm:
      fm_engine_.GetAudioSamples(notes_info_, right_buffer_data, left_buffer_data, right_buffer.size());
      break;
  }

  advanced_dac_output_.WriteBuffers(right_buffer, left_buffer);
}