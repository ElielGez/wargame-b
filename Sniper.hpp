#pragma once
#include "Soldier.hpp"
using namespace WarGame;
class Sniper : public Soldier {
private:
    static const int INIT_HP = 100;

public:
    Sniper(){};
    Sniper(uint num) {
        player_num = num;
        type = SNIPER;
        hp = INIT_HP;
        damage = 50;
    };
    ~Sniper(){};
    void action(Board &board, pair<int, int> location);
    const uint getInitHp() const;
};