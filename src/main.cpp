#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "player.h"
#include "warrior.h"
#include "mage.h"
#include "priest.h"


// printers
void printMainMenu() {
    std::cout << "\nWhich of the following would you like?\n"
                 "\t1 - Create a Warrior\n"
                 "\t2 - Create a Priest\n"
                 "\t3 - Create a Mage\n"
                 "\t0 - Finish creating player characters\n"
                 "-> ";
}

void printRaceMenu() {
    std::cout << "\nNow, which race do you want?\n"
                 "\t1 - Human\n"
                 "\t2 - Elf\n"
                 "\t3 - Dwarf\n"
                 "\t4 - Orc\n"
                 "\t5 - Troll\n"
                 "-> ";
}

void printAllPlayers(const std::vector<Player *> &players) {
    std::cout << "\nPLAYER LIST:\n";
    for (Player *player: players) {
        const std::string name = "NAME: " + player->getName();
        const std::string race = "RACE: " + enumString(player->getRace());
        const std::string attack = "ATTACK: " + player->attack();

        std::cout
                << std::left
                << std::setw(20)
                << name
                << std::setw(18)
                << race
                << attack
                << '\n';
    }
}

Race getRace(const int raceNum) {
    switch (raceNum) {
        case 1:
            return HUMAN;
        case 2:
            return ELF;
        case 3:
            return DWARF;
        case 4:
            return ORC;
        case 5:
            return TROLL;
    }
}

Player *createPlayer(const std::string &name, const int typeNum, const int raceNum) {
    Race race = getRace(raceNum);

    switch (typeNum) {
        case 1:
            return new Warrior(name, race);
        case 2:
            return new Priest(name, race);
        case 3:
            return new Mage(name, race);
    }
}

void doCleanup(std::vector<Player *> playerLst) {
    for (Player *player: playerLst) delete player;
    playerLst.clear();
}


int main() {
    printMainMenu();

    std::vector<Player *> players;
    int typeNum;
    std::cin >> typeNum;
    std::cin.get(); // consume new line

    std::string name;
    int raceNum;
    while (typeNum != 0) {
        std::cout << "\nWhat would you like to name your character?\n-> ";
        std::getline(std::cin, name);

        printRaceMenu();
        std::cin >> raceNum;
        std::cin.get();

        players.push_back(createPlayer(name, typeNum, raceNum));

        printMainMenu();
        std::cin >> typeNum;
        std::cin.get();
    }

    printAllPlayers(players);
    doCleanup(players);

    return 0;
}








