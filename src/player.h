#pragma once

#include <string>
#include <utility>

enum Race {
    HUMAN, ELF, DWARF, ORC, TROLL
};

std::string enumString(const Race v) {
    switch (v) {
        case HUMAN:
            return "HUMAN";
        case ELF:
            return "ELF";
        case DWARF:
            return "DWARF";
        case ORC:
            return "ORC";
        case TROLL:
            return "TROLL";
    }
}

class Player {
public:
    Player(std::string name, Race race, int hp, int mana) {
        this->_name = std::move(name);
        this->_race = race;
        this->_hp = hp;
        this->_mana = mana;
    }

    virtual ~Player() = default;


    // getters
    [[nodiscard]] std::string getName() const { return _name; }

    [[nodiscard]] Race getRace() const { return _race; }

    [[nodiscard]] int getHp() const { return _hp; }

    [[nodiscard]] int getMana() const { return _mana; }


    // setters
    void setName(std::string name) { this->_name = std::move(name); }

    void setRace(Race race) { this->_race = race; }

    void setHp(int hp) { this->_hp = hp; }

    void setMana(int mana) { this->_mana = mana; }

    [[nodiscard]] virtual std::string attack() const = 0;


private:
    std::string _name;
    Race _race;
    int _hp;
    int _mana;
};