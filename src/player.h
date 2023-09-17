#pragma once

#include <string>

enum Race { HUMAN, ELF, DWARF, ORC, TROLL };
class Player 
{
public:
  Player(std::string name, Race race, int hp, int mana);
  virtual ~Player() = default;
  
  // getters
  [[nodiscard]] std::string getName() const;
  [[nodiscard]] Race getRace() const;
  [[nodiscard]] std::string whatRace() const;
  [[nodiscard]] int getHp() const;
  [[nodiscard]] int getMana() const;

  // setters
  void setName(std::string name);
  void setRace(Race race);
  void setHp(int hp);
  void setMana(int mana);
  [[nodiscard]] virtual std::string attack() const = 0;

private:
  std::string name;
  Race race;
  int hp;
  int mana;
};