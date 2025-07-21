#include "controls.h"

#include <stdexcept>

#include <lvgl.h>

#include "ui/ui.h"


Controls::Controls() noexcept {
  // These return values are broken

  giga_display_.begin();
  // if (!giga_display_.begin()) {
  //   const auto kGigaDisplayStartFailedMessage = "Failed to start Giga Display";
  //   Serial.println(kGigaDisplayStartFailedMessage);
  //   throw std::runtime_error(kGigaDisplayStartFailedMessage);
  // }
  giga_display_touch_detector_.begin();
  // if (0 != giga_display_touch_detector_.begin()) {
  //   const auto kGigaDisplayTouchDetectorStartFailedMessage = "Failed to start Giga Display Touch Detector";
  //   Serial.println(kGigaDisplayTouchDetectorStartFailedMessage);
  //   throw std::runtime_error(kGigaDisplayTouchDetectorStartFailedMessage);
  // }

  ui_init();
}

void Controls::ProcessUi() const noexcept {
  lv_timer_handler();
}