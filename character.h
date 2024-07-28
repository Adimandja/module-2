/* Program name: RPG Characters
* Author: Adolphe Dimandja
* Date last updated: 7/27/2024
* Purpose: Define the base Character class and derived classes Fighter, Rogue, Magician, and Cleric for an RPG game.
*/

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
protected:
    std::string name;
    double hp;
    double mp;
    int strength;
    int dexterity;
    int intelligence;
    int speed;
    int endurance;
    int faith;

public:
    Character(std::string n, double h, double m, int str, int dex, int intl, int spd, int end, int fth)
        : name(n), hp(h), mp(m), strength(str), dexterity(dex), intelligence(intl), speed(spd), endurance(end), faith(fth) {}

    virtual ~Character() {}

    virtual std::string toString() const = 0;

    void setName(std::string n) { name = n; }
    std::string getName() const { return name; }

    void setHP(double h) { hp = h; }
    double getHP() const { return hp; }

    void setMP(double m) { mp = m; }
    double getMP() const { return mp; }

    void setStrength(int str) { strength = str; }
    int getStrength() const { return strength; }

    void setDexterity(int dex) { dexterity = dex; }
    int getDexterity() const { return dexterity; }

    void setIntelligence(int intl) { intelligence = intl; }
    int getIntelligence() const { return intelligence; }

    void setSpeed(int spd) { speed = spd; }
    int getSpeed() const { return speed; }

    void setEndurance(int end) { endurance = end; }
    int getEndurance() const { return endurance; }

    void setFaith(int fth) { faith = fth; }
    int getFaith() const { return faith; }

    virtual void specialAbility(Character& target) = 0;
};

class Fighter : public Character {
public:
    Fighter(std::string n) : Character(n, 300, 0, 16, 10, 5, 8, 15, 5) {}

    void specialAbility(Character& target) override {
        double damage = strength + endurance;
        target.setHP(target.getHP() - damage);
    }

    std::string toString() const override {
        return name + " stats:\nHP: " + std::to_string(hp) + "\nMP: " + std::to_string(mp) +
               "\nStrength: " + std::to_string(strength) + "\nDexterity: " + std::to_string(dexterity) +
               "\nIntelligence: " + std::to_string(intelligence) + "\nSpeed: " + std::to_string(speed) +
               "\nEndurance: " + std::to_string(endurance) + "\nFaith: " + std::to_string(faith) + "\n";
    }
};

class Rogue : public Character {
public:
    Rogue(std::string n) : Character(n, 200, 0, 10, 16, 16, 15, 8, 5) {}

    void specialAbility(Character& target) override {
        int percentage = rand() % 41 + 10;
        double stealAmount = (dexterity + speed + intelligence) * (percentage / 100.0);
        target.setHP(target.getHP() - stealAmount);
        hp += stealAmount;
    }

    std::string toString() const override {
        return name + " stats:\nHP: " + std::to_string(hp) + "\nMP: " + std::to_string(mp) +
               "\nStrength: " + std::to_string(strength) + "\nDexterity: " + std::to_string(dexterity) +
               "\nIntelligence: " + std::to_string(intelligence) + "\nSpeed: " + std::to_string(speed) +
               "\nEndurance: " + std::to_string(endurance) + "\nFaith: " + std::to_string(faith) + "\n";
    }
};

class Magician : public Character {
public:
    Magician(std::string n) : Character(n, 250, 200, 5, 10, 16, 16, 5, 8) {}

    void specialAbility(Character& target) override {
        double damage = intelligence + speed;
        target.setHP(target.getHP() - damage);
        mp -= 32; // consume some MP
    }

    std::string toString() const override {
        return name + " stats:\nHP: " + std::to_string(hp) + "\nMP: " + std::to_string(mp) +
               "\nStrength: " + std::to_string(strength) + "\nDexterity: " + std::to_string(dexterity) +
               "\nIntelligence: " + std::to_string(intelligence) + "\nSpeed: " + std::to_string(speed) +
               "\nEndurance: " + std::to_string(endurance) + "\nFaith: " + std::to_string(faith) + "\n";
    }
};

class Cleric : public Character {
public:
    Cleric(std::string n) : Character(n, 200, 200, 5, 10, 8, 16, 5, 16) {}

    void specialAbility(Character& target) override {
        double healAmount = faith * 1.0;
        target.setHP(target.getHP() + healAmount);
        mp -= 16; // consume some MP
    }

    std::string toString() const override {
        return name + " stats:\nHP: " + std::to_string(hp) + "\nMP: " + std::to_string(mp) +
               "\nStrength: " + std::to_string(strength) + "\nDexterity: " + std::to_string(dexterity) +
               "\nIntelligence: " + std::to_string(intelligence) + "\nSpeed: " + std::to_string(speed) +
               "\nEndurance: " + std::to_string(endurance) + "\nFaith: " + std::to_string(faith) + "\n";
    }
};

#endif // CHARACTER_H