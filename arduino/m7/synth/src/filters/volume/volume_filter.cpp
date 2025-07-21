#include "volume_filter.h"

#include "../../settings/settings.h"


void VolumeFilter::Apply(int16_t* const right_buffer, int16_t* const left_buffer, const std::size_t buffers_size) const noexcept {
  const auto volume = Settings::Instance().GetVolume();
  for (auto i = 0L; i < buffers_size; ++i) {
    right_buffer[i] *= volume;
    left_buffer[i] *= volume;
  }
}