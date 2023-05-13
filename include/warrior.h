#pragma once

#include <utility>

#include "player.h"

class Warrior: public Player {
public:
  Warrior(std::string name, Race race): Player(std::move(name), race, 200, 0) {}

  [[nodiscard]] std::string attack() const override {
    return "I\'ll destroy you with my sword, foul demon!";
  }
};