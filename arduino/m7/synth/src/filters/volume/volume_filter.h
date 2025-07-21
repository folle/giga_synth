#pragma once

#include <cstdint>


class VolumeFilter final {
public:
  VolumeFilter() = default;
  ~VolumeFilter() = default;

  void Apply(int16_t* right_buffer, int16_t* left_buffer, std::size_t buffers_size) const noexcept;
};