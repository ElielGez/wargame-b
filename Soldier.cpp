#include "Soldier.hpp"
namespace WarGame {
uint Soldier::getEnemyPlayerNum() {
    if (player_num == 1)
        return 2;
    else
        return 1;
}
} // namespace WarGame