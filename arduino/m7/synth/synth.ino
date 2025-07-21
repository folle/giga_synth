#include <memory>

#include "src/synth.h"


std::unique_ptr<Synth> synth;


void setup() {
  const auto kBaudRate = 2000000L;
  Serial.begin(kBaudRate);
  
  synth = std::make_unique<Synth>();
}

void loop() {
  synth->Process();
}