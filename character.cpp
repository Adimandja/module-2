/* Program name: RPG Characters
* Author: Adolphe Dimandja
* Date last updated: 7/27/2024
* Purpose: Implement the special abilities for the RPG characters.
*/

#include "character.h"
#include <cstdlib>

// Implement special abilities for derived classes
void Fighter::specialAbility(Character& target) {
    double damage = strength + endurance;
    target.setHP(target.getHP() - damage);
}

void Rogue::specialAbility(Character& target) {
    int percentage = rand() % 41 + 10;
    double stealAmount = (dexterity + speed + intelligence) * (percentage / 100.0);
    target.setHP(target.getHP() - stealAmount);
    hp += stealAmount;
}

void Magician::specialAbility(Character& target) {
    double damage = intelligence + speed;
    target.setHP(target.getHP() - damage);
    mp -= 32; // consume some MP
}

void Cleric::specialAbility(Character& target) {
    double healAmount = faith * 1.0;
    target.setHP(target.getHP() + healAmount);
    mp -= 16; // consume some MP
}

// Implement toString methods for derived classes
std::string Fighter::toString() const {
    return name + " stats:\nHP: " + std::to_string(hp) + "\nMP: " + std::to_string(mp) +
           "\nStrength: " + std::to_string(strength) + "\nDexterity: " + std::to_string(dexterity) +
           "\nIntelligence: " + std::to_string(intelligence) + "\nSpeed: " + std::to_string(speed) +
           "\nEndurance: " + std::to_string(endurance) + "\nFaith: " + std::to_string(faith) + "\n";
}

std::string Rogue::toString() const {
    return name + " stats:\nHP: " + std::to_string(hp) + "\nMP: " + std::to_string(mp) +
           "\nStrength: " + std::to_string(strength) + "\nDexterity: " + std::to_string(dexterity) +
           "\nIntelligence: " + std::to_string(intelligence) + "\nSpeed: " + std::to_string(speed) +
           "\nEndurance: " + std::to_string(endurance) + "\nFaith: " + std::to_string(faith) + "\n";
}

std::string Magician::toString() const {
    return name + " stats:\nHP: " + std::to_string(hp) + "\nMP: " + std::to_string(mp) +
           "\nStrength: " + std::to_string(strength) + "\nDexterity: " + std::to_string(dexterity) +
           "\nIntelligence: " + std::to_string(intelligence) + "\nSpeed: " + std::to_string(speed) +
           "\nEndurance: " + std::to_string(endurance) + "\nFaith: " + std::to_string(faith) + "\n";
}

std::string Cleric::toString() const {
    return name + " stats:\nHP: " + std::to_string(hp) + "\nMP: " + std::to_string(mp) +
           "\nStrength: " + std::to_string(strength) + "\nDexterity: " + std::to_string(dexterity) +
           "\nIntelligence: " + std::to_string(intelligence) + "\nSpeed: " + std::to_string(speed) +
           "\nEndurance: " + std::to_string(endurance) + "\nFaith: " + std::to_string(faith) + "\n";
}
