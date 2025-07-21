#include "advanced_dac_output.h"

#include <stdexcept>

#include "../../settings/settings.h"


AdvancedDacOutput::AdvancedDacOutput() noexcept {
  const auto resolution = Settings::Instance().GetResolution();
  const auto sample_rate = Settings::Instance().GetSampleRate();
  const auto samples_per_buffer = Settings::Instance().GetAdvancedDacOutputSamplesPerBuffer();
  const auto buffers_count = Settings::Instance().GetAdvancedDacOutputBuffersCount();
  if (0 == right_dac_.begin(resolution, sample_rate, samples_per_buffer, buffers_count)) {
    const auto kRightDacStartFailedMessage = "Failed to start right DAC";
    Serial.println(kRightDacStartFailedMessage);
    throw std::runtime_error(kRightDacStartFailedMessage);
  }

  if (0 == left_dac_.begin(resolution, sample_rate, samples_per_buffer, buffers_count)) {
    const auto kLeftDacStartFailedMessage = "Failed to start left DAC";
    Serial.println(kLeftDacStartFailedMessage);
    throw std::runtime_error(kLeftDacStartFailedMessage);
  }
}

bool AdvancedDacOutput::GetBuffers(DMABuffer<Sample>& right_buffer, DMABuffer<Sample>& left_buffer) noexcept {
  if (!right_dac_.available() || !left_dac_.available()) {
    return false;
  }

  right_buffer = right_dac_.dequeue();
  left_buffer = left_dac_.dequeue();

  return true;
}

void AdvancedDacOutput::WriteBuffers(DMABuffer<Sample>& right_buffer, DMABuffer<Sample>& left_buffer) noexcept {
  right_dac_.write(right_buffer);
  left_dac_.write(left_buffer);
}