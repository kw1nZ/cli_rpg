#include "player.h"

#include <utility>

Player::Player(std::string name, Race race, int hp, int mana) {
  this->name = std::move(name);
  this->race = race;
  this->hp = hp;
  this->mana = mana;
}


// ---------------------- getters
std::string Player::getName() const {
  return name;
}

Race Player::getRace() const {
  return race;
}

std::string Player::whatRace() const {
  std::string res;
  switch (race) {
    case HUMAN: 
      res = "Human";
      break;
    case ELF:
      res = "Elf";
      break;
    case DWARF: 
      res = "Dwarf";
      break;
    case ORC:
      res = "Orc";
      break;
    case TROLL: 
      res = "Troll";
      break;
  }
  return res;
}

int Player::getHp() const {
  return hp;
}

int Player::getMana() const {
  return mana;
}


// ---------------------- setters
void Player::setName(std::string name) {
  this->name = name;
}

void Player::setRace(Race race) {
  this->race = race;
}

void Player::setHp(int hp) {
  this->hp = hp;
}

void Player::setMana(int mana) {
  this->mana = mana;
}
