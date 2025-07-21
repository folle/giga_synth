#include "midi_input.h"

#include <algorithm>

#include "../settings/settings.h"


rtos::Mutex MidiInput::messages_mutex_;
std::vector<MidiInput::NoteMessage> MidiInput::notes_messages_;
bool MidiInput::damper_pedal_pressed_ = false;

MidiInput::MidiInput() noexcept {
  pinMode(PA_15, OUTPUT);

  usb_host_midi_.attachMiscellaneousFunctionCode([](const uint8_t data_1, const uint8_t data_2, const uint8_t data_3) { OnMiscellaneousFunctionCodeReceived(data_1, data_2, data_3); });
  usb_host_midi_.attachCableEvent([](const uint8_t data_1, const uint8_t data_2, const uint8_t data_3) { OnCableEventReceived(data_1, data_2, data_3); });
  usb_host_midi_.attachSystemCommonTwoBytes([](const uint8_t data_1, const uint8_t data_2) { OnSystemCommonTwoBytesReceived(data_1, data_2); });
  usb_host_midi_.attachSystemCommonThreeBytes([](const uint8_t data_1, const uint8_t data_2, const uint8_t data_3) { OnSystemCommonThreeBytesReceived(data_1, data_2, data_3); });
  usb_host_midi_.attachSystemExclusive([](uint8_t* const data, const uint16_t length, const bool has_next_data) { OnSystemExclusiveReceived(data, length, has_next_data); });
  usb_host_midi_.attachNoteOn([](const uint8_t channel, const uint8_t key, const uint8_t velocity) { OnNoteMessageReceived(channel, key, velocity, true); });
  usb_host_midi_.attachNoteOff([](const uint8_t channel, const uint8_t key, const uint8_t velocity) { OnNoteMessageReceived(channel, key, velocity, false); });
  usb_host_midi_.attachPolyKeyPress([](const uint8_t channel, const uint8_t key, const uint8_t pressure) { OnPolyKeyPressReceived(channel, key, pressure); }); 
  usb_host_midi_.attachControlChange([](const uint8_t channel, const uint8_t controller, const uint8_t value) { OnControlChangeMessageReceived(channel, controller, value); });
  usb_host_midi_.attachProgramChange([](const uint8_t channel, const uint8_t program) { OnProgramChangeReceived(channel, program); }); 
  usb_host_midi_.attachChannelPressure([](const uint8_t channel, const uint8_t pressure) { OnChannelPressureReceived(channel, pressure); }); 
  usb_host_midi_.attachPitchBend([](const uint8_t channel, const uint16_t value) { OnPitchBendReceived(channel, value); }); 
  usb_host_midi_.attachSingleByte([](const uint8_t value) { OnSingleByteReceived(value); }); 
}

void MidiInput::ProcessNotes(NotesInfo& notes_info) noexcept {
  if (!usb_host_midi_.connected() && !usb_host_midi_.connect()) {
    Serial.println("Failed to connect to USB MIDI");
    return;
  }

  const mbed::ScopedLock<rtos::Mutex> mutex_lock(messages_mutex_);
  SetNotesStatus(notes_info);
  SetDamperPedalStatus(notes_info);
  EraseFinishedNotes(notes_info);
}

void MidiInput::OnMiscellaneousFunctionCodeReceived(const uint8_t data_1, const uint8_t data_2, const uint8_t data_3) noexcept {
  // TODO
}

void MidiInput::OnCableEventReceived(const uint8_t data_1, const uint8_t data_2, const uint8_t data_3) noexcept {
  // TODO
}

void MidiInput::OnSystemCommonTwoBytesReceived(const uint8_t data_1, const uint8_t data_2) noexcept {
  // TODO
}

void MidiInput::OnSystemCommonThreeBytesReceived(const uint8_t data_1, const uint8_t data_2, const uint8_t data_3) noexcept {
  // TODO
}

void MidiInput::OnSystemExclusiveReceived(const uint8_t* const data, const uint16_t length, const bool has_next_data) noexcept {
  // TODO
}

void MidiInput::OnNoteMessageReceived(const uint8_t channel, const uint8_t key, const uint8_t velocity, const bool pressed) noexcept {
  const mbed::ScopedLock<rtos::Mutex> mutex_lock(messages_mutex_);
  
  static constexpr uint8_t kVelocityMaxValue = 127;
  notes_messages_.emplace_back(NoteMessage{ key, velocity / static_cast<double>(kVelocityMaxValue), pressed });
}

void MidiInput::OnPolyKeyPressReceived(const uint8_t channel, const uint8_t key, const uint8_t pressure) noexcept {
  // TODO
}

void MidiInput::OnControlChangeMessageReceived(const uint8_t channel, const uint8_t controller, const uint8_t value) noexcept {
  const auto active_channel = Settings::Instance().GetMidiInputChannel();
  if (active_channel && (active_channel != channel)) {
    return;
  }

  static constexpr uint8_t kChannelVolumeController = 7;
  static constexpr uint8_t kDamperPedalController = 64;

  static constexpr uint8_t kPedalsThresholdValue = 63;
  static constexpr uint8_t kControllersMaxValue = 127;

  switch (controller) {
    case kChannelVolumeController:
      Settings::Instance().SetVolume(value / static_cast<double>(kControllersMaxValue));
      break;
    case kDamperPedalController: {
      const mbed::ScopedLock<rtos::Mutex> mutex_lock(messages_mutex_);
      damper_pedal_pressed_ = value > kPedalsThresholdValue;
      break;
    }
  }
}

void MidiInput::OnProgramChangeReceived(const uint8_t channel, const uint8_t program) noexcept {
  // TODO
}

void MidiInput::OnChannelPressureReceived(const uint8_t channel, const uint8_t pressure) noexcept {
  // TODO
}

void MidiInput::OnPitchBendReceived(const uint8_t channel, const uint16_t value) noexcept {
  // TODO
}

void MidiInput::OnSingleByteReceived(const uint8_t value) noexcept {
  // TODO
}

void MidiInput::SetNotesStatus(NotesInfo& notes_info) noexcept {
  for (auto& message : notes_messages_) {
    if (message.pressed) {
      auto it_notes_info = notes_info.find(message.key);
      if (it_notes_info != notes_info.cend()) {
        notes_info.erase(it_notes_info);
      }

      notes_info.insert(std::make_pair(message.key, NoteInfo(message.key, message.velocity)));
    } else {
      auto it_notes_info = notes_info.find(message.key);
      if (it_notes_info == notes_info.cend()) {
        return;
      }

      it_notes_info->second.SetKeyPressed(false);
    }
  }

  notes_messages_.clear();
}

void MidiInput::SetDamperPedalStatus(NotesInfo& notes_info) const noexcept {
  std::for_each(notes_info.begin(), notes_info.end(), [this](auto& note_info_pair){ note_info_pair.second.SetDamperPedalPressed(damper_pedal_pressed_); });
}

void MidiInput::EraseFinishedNotes(NotesInfo& notes_info) const noexcept {
  auto it_notes_info = notes_info.begin();
  while (it_notes_info != notes_info.end()) {
    if (it_notes_info->second.IsFinished()) {
      it_notes_info = notes_info.erase(it_notes_info);
    } else {
      ++it_notes_info;
    }
  }
}