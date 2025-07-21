#include "fm_engine.h"

#include <algorithm>


FmEngine::FmEngine() noexcept {
  SwitchAlgorithm();
  SwitchToneGenerators();
}

void FmEngine::GenerateAudioSamples(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  algorithm_(notes_info, right_buffer, left_buffer, buffers_size);
}

void FmEngine::ProcessSettings() noexcept {
  const auto settings_algorithm = Settings::Instance().GetFmEngineAlgorithm();
  if (active_algorithm_ != settings_algorithm) {
    active_algorithm_ = settings_algorithm;
    SwitchAlgorithm();
  }
  
  const auto settings_tone_generator_type = Settings::Instance().GetFmEngineToneGeneratorType();
  if (active_tone_generator_type_ != settings_tone_generator_type) {
    active_tone_generator_type_ = settings_tone_generator_type;
    SwitchToneGenerators();
  }

  UpdateOperatorsSettings();
}

void FmEngine::SwitchAlgorithm() noexcept {
  switch (active_algorithm_) {
    case 0:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm1(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 1:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm2(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 2:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm3(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 3:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm4(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 4:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm5(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 5:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm6(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 6:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm7(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 7:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm8(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 8:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm9(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 9:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm10(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 10:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm11(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 11:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm12(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 12:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm13(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 13:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm14(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 14:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm15(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 15:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm16(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 16:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm17(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 17:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm18(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 18:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm19(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 19:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm20(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 20:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm21(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 21:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm22(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 22:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm23(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 23:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm24(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 24:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm25(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 25:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm26(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 26:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm27(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 27:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm28(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 28:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm29(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 29:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm30(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 30:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm31(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
    case 31:
      algorithm_ = [this](NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size){ Algorithm32(notes_info, right_buffer, left_buffer, buffers_size); };
      break;
  }
  
  keys_feedbacks_.clear();
}

void FmEngine::SwitchToneGenerators() noexcept {
  std::for_each(fm_operators_.begin(), fm_operators_.end(), [this](auto& fm_operator) { fm_operator.SetToneGenerator(active_tone_generator_type_); });

  keys_feedbacks_.clear();
}

void FmEngine::UpdateOperatorsSettings() noexcept {
  for (auto i = 0L; i < fm_operators_.size(); ++i) {
    fm_operators_.at(i).SetSettings(Settings::Instance().GetFmEngineOperatorSettings(i));
  }
}

void FmEngine::Algorithm1(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      const auto tone1 = fm_operators_.at(1).GetAudioSample(frequency, time_step);
      note += fm_operators_.at(0).GetAudioSample(frequency + tone1, time_step);
      
      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      const auto tone4 = fm_operators_.at(4).GetAudioSample(frequency + tone5, time_step);
      const auto tone3 = fm_operators_.at(3).GetAudioSample(frequency + tone4, time_step);
      note += fm_operators_.at(2).GetAudioSample(frequency + tone3, time_step);

      keys_feedbacks_.at(key) = tone5;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm2(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();
      
      double note = 0.0;
      const auto tone1 = fm_operators_.at(1).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      note += fm_operators_.at(0).GetAudioSample(frequency + tone1, time_step);
      
      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency, time_step);
      const auto tone4 = fm_operators_.at(4).GetAudioSample(frequency + tone5, time_step);
      const auto tone3 = fm_operators_.at(3).GetAudioSample(frequency + tone4, time_step);
      note += fm_operators_.at(2).GetAudioSample(frequency + tone3, time_step);

      keys_feedbacks_.at(key) = tone1;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm3(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      const auto tone2 = fm_operators_.at(2).GetAudioSample(frequency, time_step);
      const auto tone1 = fm_operators_.at(1).GetAudioSample(frequency + tone2, time_step);
      note += fm_operators_.at(0).GetAudioSample(frequency + tone1, time_step);
      
      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      const auto tone4 = fm_operators_.at(4).GetAudioSample(frequency + tone5, time_step);
      note += fm_operators_.at(3).GetAudioSample(frequency + tone4, time_step);
      
      keys_feedbacks_.at(key) = tone5;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm4(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      const auto tone2 = fm_operators_.at(2).GetAudioSample(frequency, time_step);
      const auto tone1 = fm_operators_.at(1).GetAudioSample(frequency + tone2, time_step);
      note += fm_operators_.at(0).GetAudioSample(frequency + tone1, time_step);
      
      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      const auto tone4 = fm_operators_.at(4).GetAudioSample(frequency + tone5, time_step);
      const auto tone3 = fm_operators_.at(3).GetAudioSample(frequency + tone4, time_step);
      note += tone3;

      keys_feedbacks_.at(key) = tone3;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm5(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      const auto tone1 = fm_operators_.at(1).GetAudioSample(frequency, time_step);
      note += fm_operators_.at(0).GetAudioSample(frequency + tone1, time_step);

      const auto tone3 = fm_operators_.at(3).GetAudioSample(frequency, time_step);
      note += fm_operators_.at(2).GetAudioSample(frequency + tone3, time_step);

      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      note += fm_operators_.at(4).GetAudioSample(frequency + tone5, time_step);

      keys_feedbacks_.at(key) = tone5;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm6(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      const auto tone1 = fm_operators_.at(1).GetAudioSample(frequency, time_step);
      note += fm_operators_.at(0).GetAudioSample(frequency + tone1, time_step);

      const auto tone3 = fm_operators_.at(3).GetAudioSample(frequency, time_step);
      note += fm_operators_.at(2).GetAudioSample(frequency + tone3, time_step);

      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      const auto tone4 = fm_operators_.at(4).GetAudioSample(frequency + tone5, time_step);
      note += tone4;

      keys_feedbacks_.at(key) = tone4;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm7(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      const auto tone1 = fm_operators_.at(1).GetAudioSample(frequency, time_step);
      note += fm_operators_.at(0).GetAudioSample(frequency + tone1, time_step);

      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      const auto tone4 = fm_operators_.at(4).GetAudioSample(frequency + tone5, time_step);
      const auto tone3 = fm_operators_.at(3).GetAudioSample(frequency, time_step);
      note += fm_operators_.at(2).GetAudioSample(frequency + tone3 + tone4, time_step);

      keys_feedbacks_.at(key) = tone5;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm8(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      const auto tone1 = fm_operators_.at(1).GetAudioSample(frequency, time_step);
      note += fm_operators_.at(0).GetAudioSample(frequency + tone1, time_step);

      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency, time_step);
      const auto tone4 = fm_operators_.at(4).GetAudioSample(frequency + tone5, time_step);
      const auto tone3 = fm_operators_.at(3).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      note += fm_operators_.at(2).GetAudioSample(frequency + tone3 + tone4, time_step);

      keys_feedbacks_.at(key) = tone3;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm9(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      const auto tone1 = fm_operators_.at(1).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      note += fm_operators_.at(0).GetAudioSample(frequency + tone1, time_step);

      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency, time_step);
      const auto tone4 = fm_operators_.at(4).GetAudioSample(frequency + tone5, time_step);
      const auto tone3 = fm_operators_.at(3).GetAudioSample(frequency, time_step);
      note += fm_operators_.at(2).GetAudioSample(frequency + tone3 + tone4, time_step);

      keys_feedbacks_.at(key) = tone1;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm10(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      const auto tone4 = fm_operators_.at(4).GetAudioSample(frequency, time_step);
      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency, time_step);
      note += fm_operators_.at(3).GetAudioSample(frequency + tone4 + tone5, time_step);

      const auto tone2 = fm_operators_.at(2).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      const auto tone1 = fm_operators_.at(1).GetAudioSample(frequency + tone2, time_step);
      note += fm_operators_.at(0).GetAudioSample(frequency + tone1, time_step);

      keys_feedbacks_.at(key) = tone2;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm11(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      const auto tone4 = fm_operators_.at(4).GetAudioSample(frequency, time_step);
      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      note += fm_operators_.at(3).GetAudioSample(frequency + tone4 + tone5, time_step);

      const auto tone2 = fm_operators_.at(2).GetAudioSample(frequency, time_step);
      const auto tone1 = fm_operators_.at(1).GetAudioSample(frequency + tone2, time_step);
      note += fm_operators_.at(0).GetAudioSample(frequency + tone1, time_step);

      keys_feedbacks_.at(key) = tone5;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm12(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      const auto tone3 = fm_operators_.at(3).GetAudioSample(frequency, time_step);
      const auto tone4 = fm_operators_.at(4).GetAudioSample(frequency, time_step);
      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency, time_step);
      note += fm_operators_.at(2).GetAudioSample(frequency + tone3 + tone4 + tone5, time_step);

      const auto tone1 = fm_operators_.at(1).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      note += fm_operators_.at(0).GetAudioSample(frequency + tone1, time_step);

      keys_feedbacks_.at(key) = tone1;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm13(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      const auto tone3 = fm_operators_.at(3).GetAudioSample(frequency, time_step);
      const auto tone4 = fm_operators_.at(4).GetAudioSample(frequency, time_step);
      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      note += fm_operators_.at(2).GetAudioSample(frequency + tone3 + tone4 + tone5, time_step);

      const auto tone1 = fm_operators_.at(1).GetAudioSample(frequency, time_step);
      note += fm_operators_.at(0).GetAudioSample(frequency + tone1, time_step);

      keys_feedbacks_.at(key) = tone5;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm14(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      const auto tone1 = fm_operators_.at(1).GetAudioSample(frequency, time_step);
      note += fm_operators_.at(0).GetAudioSample(frequency + tone1, time_step);

      const auto tone4 = fm_operators_.at(4).GetAudioSample(frequency, time_step);
      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      const auto tone3 = fm_operators_.at(3).GetAudioSample(frequency + tone4 + tone5, time_step);
      note += fm_operators_.at(2).GetAudioSample(frequency + tone3, time_step);

      keys_feedbacks_.at(key) = tone5;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm15(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      const auto tone1 = fm_operators_.at(1).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      note += fm_operators_.at(0).GetAudioSample(frequency + tone1, time_step);

      const auto tone4 = fm_operators_.at(4).GetAudioSample(frequency, time_step);
      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency, time_step);
      const auto tone3 = fm_operators_.at(3).GetAudioSample(frequency + tone4 + tone5, time_step);
      note += fm_operators_.at(2).GetAudioSample(frequency + tone3, time_step);

      keys_feedbacks_.at(key) = tone1;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm16(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      const auto tone1 = fm_operators_.at(1).GetAudioSample(frequency, time_step);
      const auto tone3 = fm_operators_.at(3).GetAudioSample(frequency, time_step);
      const auto tone2 = fm_operators_.at(2).GetAudioSample(frequency + tone3, time_step);
      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      const auto tone4 = fm_operators_.at(4).GetAudioSample(frequency + tone5, time_step);
      note += fm_operators_.at(0).GetAudioSample(frequency + tone1 + tone2 + tone4, time_step);

      keys_feedbacks_.at(key) = tone5;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm17(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      const auto tone1 = fm_operators_.at(1).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      const auto tone3 = fm_operators_.at(3).GetAudioSample(frequency, time_step);
      const auto tone2 = fm_operators_.at(2).GetAudioSample(frequency + tone3, time_step);
      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency, time_step);
      const auto tone4 = fm_operators_.at(4).GetAudioSample(frequency + tone5, time_step);
      note += fm_operators_.at(0).GetAudioSample(frequency + tone1 + tone2 + tone4, time_step);

      keys_feedbacks_.at(key) = tone1;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm18(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      const auto tone1 = fm_operators_.at(1).GetAudioSample(frequency, time_step);
      const auto tone2 = fm_operators_.at(2).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency, time_step);
      const auto tone4 = fm_operators_.at(4).GetAudioSample(frequency + tone5, time_step);
      const auto tone3 = fm_operators_.at(3).GetAudioSample(frequency + tone4, time_step);
      note += fm_operators_.at(0).GetAudioSample(frequency + tone1 + tone2 + tone3, time_step);

      keys_feedbacks_.at(key) = tone2;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm19(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      const auto tone2 = fm_operators_.at(2).GetAudioSample(frequency, time_step);
      const auto tone1 = fm_operators_.at(1).GetAudioSample(frequency + tone2, time_step);
      note += fm_operators_.at(0).GetAudioSample(frequency + tone1, time_step);
      
      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      note += fm_operators_.at(3).GetAudioSample(frequency + tone5, time_step);
      
      note += fm_operators_.at(4).GetAudioSample(frequency + tone5, time_step);

      keys_feedbacks_.at(key) = tone5;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm20(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      const auto tone2 = fm_operators_.at(2).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      note += fm_operators_.at(0).GetAudioSample(frequency + tone2, time_step);

      note += fm_operators_.at(1).GetAudioSample(frequency + tone2, time_step);

      const auto tone4 = fm_operators_.at(4).GetAudioSample(frequency, time_step);
      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency, time_step);
      note += fm_operators_.at(3).GetAudioSample(frequency + tone4 + tone5, time_step);

      keys_feedbacks_.at(key) = tone2;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm21(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      const auto tone2 = fm_operators_.at(2).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      note += fm_operators_.at(0).GetAudioSample(frequency + tone2, time_step);

      note += fm_operators_.at(1).GetAudioSample(frequency + tone2, time_step);

      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency, time_step);
      note += fm_operators_.at(3).GetAudioSample(frequency + tone5, time_step);
      
      note += fm_operators_.at(4).GetAudioSample(frequency + tone5, time_step);

      keys_feedbacks_.at(key) = tone2;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm22(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      const auto tone1 = fm_operators_.at(1).GetAudioSample(frequency, time_step);
      note += fm_operators_.at(0).GetAudioSample(frequency + tone1, time_step);
      
      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      note += fm_operators_.at(2).GetAudioSample(frequency + tone5, time_step);

      note += fm_operators_.at(3).GetAudioSample(frequency + tone5, time_step);

      note += fm_operators_.at(4).GetAudioSample(frequency + tone5, time_step);
           
      keys_feedbacks_.at(key) = tone5;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm23(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      note += fm_operators_.at(0).GetAudioSample(frequency, time_step);
      
      const auto tone2 = fm_operators_.at(2).GetAudioSample(frequency, time_step);
      note += fm_operators_.at(1).GetAudioSample(frequency + tone2, time_step);

      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      note += fm_operators_.at(3).GetAudioSample(frequency + tone5, time_step);
      
      note += fm_operators_.at(4).GetAudioSample(frequency + tone5, time_step);
           
      keys_feedbacks_.at(key) = tone5;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm24(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      note += fm_operators_.at(0).GetAudioSample(frequency, time_step);

      note += fm_operators_.at(1).GetAudioSample(frequency, time_step);

      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      note += fm_operators_.at(2).GetAudioSample(frequency + tone5, time_step);
      note += fm_operators_.at(3).GetAudioSample(frequency + tone5, time_step);
      note += fm_operators_.at(4).GetAudioSample(frequency + tone5, time_step);
      
      keys_feedbacks_.at(key) = tone5;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm25(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      note += fm_operators_.at(0).GetAudioSample(frequency, time_step);

      note += fm_operators_.at(1).GetAudioSample(frequency, time_step);

      note += fm_operators_.at(2).GetAudioSample(frequency, time_step);
           
      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      note += fm_operators_.at(3).GetAudioSample(frequency + tone5, time_step);
      note += fm_operators_.at(4).GetAudioSample(frequency + tone5, time_step);
      
      keys_feedbacks_.at(key) = tone5;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm26(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      note += fm_operators_.at(0).GetAudioSample(frequency, time_step);

      const auto tone2 = fm_operators_.at(2).GetAudioSample(frequency, time_step);
      note += fm_operators_.at(1).GetAudioSample(frequency + tone2, time_step);

      const auto tone4 = fm_operators_.at(4).GetAudioSample(frequency, time_step);
      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      note += fm_operators_.at(3).GetAudioSample(frequency + tone4 + tone5, time_step);
      
      keys_feedbacks_.at(key) = tone5;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm27(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      note += fm_operators_.at(0).GetAudioSample(frequency, time_step);

      const auto tone2 = fm_operators_.at(2).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      note += fm_operators_.at(1).GetAudioSample(frequency + tone2, time_step);

      const auto tone4 = fm_operators_.at(4).GetAudioSample(frequency, time_step);
      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency, time_step);
      note += fm_operators_.at(3).GetAudioSample(frequency + tone4 + tone5, time_step);
      
      keys_feedbacks_.at(key) = tone2;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm28(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      const auto tone1 = fm_operators_.at(1).GetAudioSample(frequency, time_step);
      note += fm_operators_.at(0).GetAudioSample(frequency + tone1, time_step);

      const auto tone4 = fm_operators_.at(4).GetAudioSample(frequency, time_step);
      const auto tone3 = fm_operators_.at(3).GetAudioSample(frequency + tone4, time_step);
      note += fm_operators_.at(2).GetAudioSample(frequency + tone3, time_step);

      note += fm_operators_.at(5).GetAudioSample(frequency, time_step);

      keys_feedbacks_.at(key) = tone4;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm29(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      note += fm_operators_.at(0).GetAudioSample(frequency, time_step);

      note += fm_operators_.at(1).GetAudioSample(frequency, time_step);

      const auto tone3 = fm_operators_.at(3).GetAudioSample(frequency, time_step);
      note += fm_operators_.at(2).GetAudioSample(frequency + tone3, time_step);

      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      note += fm_operators_.at(4).GetAudioSample(frequency + tone5, time_step);
      
      keys_feedbacks_.at(key) = tone5;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm30(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      note += fm_operators_.at(0).GetAudioSample(frequency, time_step);

      note += fm_operators_.at(1).GetAudioSample(frequency, time_step);

      const auto tone4 = fm_operators_.at(4).GetAudioSample(frequency, time_step);
      const auto tone3 = fm_operators_.at(3).GetAudioSample(frequency + tone4, time_step);
      note += fm_operators_.at(2).GetAudioSample(frequency + tone3, time_step);

      note += fm_operators_.at(5).GetAudioSample(frequency, time_step);

      keys_feedbacks_.at(key) = tone4;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm31(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      note += fm_operators_.at(0).GetAudioSample(frequency, time_step);

      note += fm_operators_.at(1).GetAudioSample(frequency, time_step);

      note += fm_operators_.at(2).GetAudioSample(frequency, time_step);

      note += fm_operators_.at(3).GetAudioSample(frequency, time_step);
           
      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      note += fm_operators_.at(4).GetAudioSample(frequency + tone5, time_step);
      
      keys_feedbacks_.at(key) = tone5;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}

void FmEngine::Algorithm32(NotesInfo& notes_info, int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) noexcept {
  for (auto i = 0L; i < buffers_size; ++i) {
    double sample = 0.0;

    for (auto& [key, note_info] : notes_info) {
      const auto frequency = note_info.GetFrequency();
      const auto time_step = note_info.GetAndIncrementTimeStep();

      double note = 0.0;
      note += fm_operators_.at(0).GetAudioSample(frequency, time_step);

      note += fm_operators_.at(1).GetAudioSample(frequency, time_step);

      note += fm_operators_.at(2).GetAudioSample(frequency, time_step);

      note += fm_operators_.at(3).GetAudioSample(frequency, time_step);

      note += fm_operators_.at(4).GetAudioSample(frequency, time_step);
           
      const auto tone5 = fm_operators_.at(5).GetAudioSample(frequency + keys_feedbacks_[key], time_step);
      note += tone5;

      keys_feedbacks_.at(key) = tone5;

      sample += note * note_info.GetVelocity();
    }
    
    right_buffer[i] = static_cast<int16_t>(std::round(sample));
    left_buffer[i] = right_buffer[i];
  }
}