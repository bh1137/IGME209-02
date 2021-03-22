#pragma once
#include "Player.h"
class Fighter :
    public Player
{
public:
    Fighter();
    Fighter(const char* name, int strength, int charisma, int intelligence, const char* weaponSkill);
    void printFighter();
    ~Fighter(); //destructor
    void Attack(Player* player) override;

private:
    const char* weaponSkill;
};

