#pragma once

#include <Arduino_GigaDisplayTouch.h>
#include <Arduino_H7_Video.h>


class Controls final {
public:
  Controls() noexcept;
  ~Controls() = default;

  void ProcessUi() const noexcept;

private:
  Arduino_H7_Video giga_display_; 
  Arduino_GigaDisplayTouch giga_display_touch_detector_;
};