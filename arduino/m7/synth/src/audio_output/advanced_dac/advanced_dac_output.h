#pragma once

#include <AdvancedDAC.h>


class AdvancedDacOutput final {
public:
  AdvancedDacOutput() noexcept;
  ~AdvancedDacOutput() = default;
  
  bool GetBuffers(DMABuffer<Sample>& right_buffer, DMABuffer<Sample>& left_buffer) noexcept;
  void WriteBuffers(DMABuffer<Sample>& right_buffer, DMABuffer<Sample>& left_buffer) noexcept;

private:
  AdvancedDAC right_dac_ = AdvancedDAC(DAC_0);
  AdvancedDAC left_dac_ = AdvancedDAC(DAC_1);
};