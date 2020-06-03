#include "SniperCommander.hpp"
#include "Board.hpp"

void SniperCommander::action(Board &board, pair<int, int> location) {
    Sniper::action(board, location); // super
    vector<pair<Soldier *, pair<int, int>>> soldiers = board.getCommanderSodliers(SNIPER, player_num);
    for (int i = 0; i < soldiers.size(); i++) {
        Soldier *soldier = soldiers[i].first;
        pair<int, int> location = soldiers[i].second;
        soldier->action(board, {location.first, location.second});
    }
}
const uint SniperCommander::getInitHp() const {
    return INIT_HP;
}