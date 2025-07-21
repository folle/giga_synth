#pragma once

#include "audio_engines/fm/fm_engine.h"
#include "audio_output/advanced_dac/advanced_dac_output.h"
#include "controls/controls.h"
#include "midi_input/midi_input.h"


class Synth final {
public:
  Synth() = default;
  ~Synth() = default;

  void Process();

private:
  Controls controls_;
  
  MidiInput midi_input_;

  FmEngine fm_engine_;

  AdvancedDacOutput advanced_dac_output_;

  NotesInfo notes_info_;
};