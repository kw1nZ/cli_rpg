#pragma once

#include <utility>

#include "player.h"

class Priest : public Player {
public:
    Priest(std::string name, Race race) : Player(std::move(name), race, 100, 200) {}

    [[nodiscard]] std::string attack() const override {
        return "Attack of Priest";
    }
};
