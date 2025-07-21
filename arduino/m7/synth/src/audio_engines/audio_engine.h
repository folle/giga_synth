#pragma once

#include <cstdint>

#include "../filters/volume/volume_filter.h"
#include "../note_info/note_info.h"


class AudioEngine {
public:
  AudioEngine() = default;
  virtual ~AudioEngine() = default;
  
  void GetAudioSamples(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept;
  
private:
  virtual void ProcessSettings() noexcept = 0;
  
  virtual void GenerateAudioSamples(NotesInfo& notes_info, int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) noexcept = 0;


  VolumeFilter volume_filter_;
};