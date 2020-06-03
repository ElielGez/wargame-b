#include "FootCommander.hpp"
#include "Board.hpp"

void FootCommander::action(Board &board, pair<int, int> location) {
    FootSoldier::action(board, location); // super
    vector<pair<Soldier *, pair<int, int>>> soldiers = board.getCommanderSodliers(FOOT_SOLDIER, player_num);
    for (int i = 0; i < soldiers.size(); i++) {
        Soldier *soldier = soldiers[i].first;
        pair<int, int> location = soldiers[i].second;
        soldier->action(board, {location.first, location.second});
    }
}
const uint FootCommander::getInitHp() const {
    return INIT_HP;
}