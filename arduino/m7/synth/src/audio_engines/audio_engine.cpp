#include "audio_engine.h"


void AudioEngine::GetAudioSamples(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept {
  ProcessSettings();

  GenerateAudioSamples(notes_info, right_buffer, left_buffer, buffers_size);

  volume_filter_.Apply(right_buffer, left_buffer, buffers_size);
}