#pragma once

#include <vector>

#include <Arduino_USBHostMbed5.h>
#include <USBHostMIDI/USBHostMIDI.h>
#include <mbed.h>

#include "../note_info/note_info.h"


class MidiInput final {
public:
  MidiInput() noexcept;
  ~MidiInput() = default;

  void ProcessNotes(NotesInfo& notes_info) noexcept;

private:
  static void OnMiscellaneousFunctionCodeReceived(uint8_t data_1, uint8_t data_2, uint8_t data_3) noexcept;
  static void OnCableEventReceived(uint8_t data_1, uint8_t data_2, uint8_t data_3) noexcept;
  static void OnSystemCommonTwoBytesReceived(uint8_t data_1, uint8_t data_2) noexcept;
  static void OnSystemCommonThreeBytesReceived(uint8_t data_1, uint8_t data_2, uint8_t data_3) noexcept;
  static void OnSystemExclusiveReceived(const uint8_t* const data, uint16_t length, bool has_next_data) noexcept;
  static void OnNoteMessageReceived(uint8_t channel, uint8_t key, uint8_t velocity, bool pressed) noexcept;
  static void OnPolyKeyPressReceived(uint8_t channel, uint8_t key, uint8_t pressure) noexcept;
  static void OnControlChangeMessageReceived(uint8_t channel, uint8_t controller, uint8_t value) noexcept;
  static void OnProgramChangeReceived(uint8_t channel, uint8_t program) noexcept;
  static void OnChannelPressureReceived(uint8_t channel, uint8_t pressure) noexcept;
  static void OnPitchBendReceived(uint8_t channel, uint16_t value) noexcept;
  static void OnSingleByteReceived(uint8_t value) noexcept;

  void SetNotesStatus(NotesInfo& notes_info) noexcept;
  void SetDamperPedalStatus(NotesInfo& notes_info) const noexcept;
  void EraseFinishedNotes(NotesInfo& notes_info) const noexcept;


  static rtos::Mutex messages_mutex_;

  typedef struct {
    uint8_t key;
    double velocity;
    bool pressed;
  } NoteMessage;
  static std::vector<NoteMessage> notes_messages_;

  static bool damper_pedal_pressed_;

  USBHostMIDI usb_host_midi_;
};