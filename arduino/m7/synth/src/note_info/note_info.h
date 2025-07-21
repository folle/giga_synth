#pragma once

#include <cstdint>
#include <unordered_map>


class NoteInfo final {
public:
  NoteInfo() = delete;
  ~NoteInfo() = default;

  NoteInfo(uint8_t key, double velocity) noexcept;
  
  void SetKeyPressed(bool key_pressed) noexcept;
  void SetDamperPedalPressed(bool damper_pedal_pressed) noexcept;

  double GetVelocity() const noexcept;
  double GetFrequency() const noexcept;

  bool IsKeyPressed() const noexcept;
  bool IsDamperPedalPressed() const noexcept;
  bool IsFinished() const noexcept;
  
  uint64_t GetAndIncrementTimeStep() noexcept;

private:
  double velocity_;
  double frequency_;

  bool key_pressed_;
  bool damper_pedal_pressed_;

  uint64_t time_step_;
};

typedef std::unordered_map<uint8_t, NoteInfo> NotesInfo;