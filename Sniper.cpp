#include "Sniper.hpp"
#include "Board.hpp"

void Sniper::action(Board &board, pair<int, int> location) {
    pair<Soldier *, pair<int, int>> to_attack = board.getStrongestEnemy(location, getEnemyPlayerNum());
    if (to_attack.first == nullptr)
        return;
    to_attack.first->hp -= damage;
    if (to_attack.first->hp <= 0) {
        vector<vector<Soldier *>> &board_game = board.getBoard();
        board_game[to_attack.second.first][to_attack.second.second] = nullptr;
        delete to_attack.first;
    }
}
const uint Sniper::getInitHp() const {
    return INIT_HP;
}