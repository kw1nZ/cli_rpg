#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "player.h"
#include "warrior.h"
#include "mage.h"
#include "priest.h"


// printers
void printMainMenu();
void printRaceMenu();
void printAll(const std::vector<Player*>& playerLst);


Player* createPlayer(const std::string& name, int typeNum, int raceNum);
void doCleanup(std::vector<Player*> playerLst);
Race getRace(int raceNum);


int main(int argc, char **argv) {
    int choice;
    int raceNum;
    std::string name;

    std::vector<Player*> playerLst;
    printMainMenu();
    std::cin >> choice;
    std::cin.get(); // consume new line

    while(choice != 0) {
    std::cout << "\nWhat would you like to name your character?\n";
    std::getline(std::cin, name);

    printRaceMenu();
    std::cin >> raceNum;
    std::cin.get();

    Player* tempPlayer = createPlayer(name, choice, raceNum);
    playerLst.push_back(tempPlayer);

    printMainMenu();
    std::cin >> choice;
    std::cin.get();
  }

  printAll(playerLst);
  doCleanup(playerLst);

  std::cout << "\nGame Over! :)\n";

  return 0;
}



void printMainMenu() {
    std::cout << "\nWhich of the following would you like?\n";
    std::cout << "\t1 - Create a Warrior\n";
    std::cout << "\t2 - Create a Priest\n";
    std::cout << "\t3 - Create a Mage\n";
    std::cout << "\t0 - Finish creating player characters\n";
}

void printRaceMenu() {
    std::cout << "\nNow, which race do you want?\n";
    std::cout << "\t1 - Human\n";
    std::cout << "\t2 - Elf\n";
    std::cout << "\t3 - Dwarf\n";
    std::cout << "\t4 - Orc\n";
    std::cout << "\t5 - Troll\n";
}

void printAll(const std::vector<Player*>& playerLst) {
    std::cout << "\nPLAYER LIST:\n";
    for (Player* player : playerLst) {
        std::string name = "NAME -> " + player->getName();
        std::string race = "RACE -> " + player->whatRace();
        std::string attack = "ATTACK -> " + player->attack();

        std::cout
            << std::left
            << std::setw(25)
            << name
            << std::setw(18)
            << race
            << attack;

        std::cout << '\n';
    }
}


Player* createPlayer(const std::string& name, int typeNum, int raceNum) {
    Race race = getRace(raceNum);

    Player* tempPlayer;

    switch (typeNum)
    {
    case 1:
        tempPlayer = new Warrior(name, race);
        break;

    case 2:
        tempPlayer = new Priest(name, race);
        break;

    default:
        tempPlayer = new Mage(name, race);
        break;
    }

    return tempPlayer;
}

void doCleanup(std::vector<Player*> playerLst) {
    for (Player* player : playerLst) delete player;
    playerLst.clear();
}

Race getRace(const int raceNum) {
    Race race;

    switch (raceNum)
    {
    case 1:
        race = HUMAN;
        break;
    case 2:
        race = ELF;
        break;
    case 3:
        race = DWARF;
        break;
    case 4:
        race = ORC;
        break;
    case 5:
        race = TROLL;
        break;

    default:
        race = HUMAN;
        break;
    }

    return race;
}