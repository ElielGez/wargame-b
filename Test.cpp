#include "doctest.h"
#include <iostream>
#include <stdexcept>

#include "DemoGame.hpp"
#include "FootCommander.hpp"
#include "FootSoldier.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include <cassert>

TEST_CASE("Sniper Game - winner team is 1") {
    WarGame::Board board(8, 8);
    CHECK(!board.has_soldiers(1));
    board[{0, 1}] = new Sniper(1);
    CHECK(board.has_soldiers(1));

    CHECK(!board.has_soldiers(2));
    board[{7, 1}] = new Sniper(2);
    CHECK(board.has_soldiers(2));

    board.move(1, {0, 1}, WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1, {0, 1}, WarGame::Board::MoveDIR::Up));
    board.move(1, {1, 1}, WarGame::Board::MoveDIR::Up);
    CHECK(!board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
}

TEST_CASE("Foot Game - winner team is 2") {
    WarGame::Board board(8, 8);
    CHECK(!board.has_soldiers(1));
    board[{0, 1}] = new FootSoldier(1);
    CHECK(board.has_soldiers(1));

    CHECK(!board.has_soldiers(2));
    board[{7, 1}] = new FootSoldier(2);
    CHECK(board.has_soldiers(2));

    board.move(1, {0, 1}, WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    CHECK_THROWS(board.move(1, {0, 1}, WarGame::Board::MoveDIR::Up));
    board.move(1, {1, 1}, WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    CHECK_THROWS(board.move(1, {7, 1}, WarGame::Board::MoveDIR::Up));
    CHECK_THROWS(board.move(2, {7, 1}, WarGame::Board::MoveDIR::Up));
    board.move(2, {7, 1}, WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2, {6, 1}, WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2, {5, 1}, WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1, {2, 1}, WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    CHECK_THROWS(board.move(1, {3, 1}, WarGame::Board::MoveDIR::Up));
    CHECK_THROWS(board.move(2, {4, 1}, WarGame::Board::MoveDIR::Down));
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1, {3, 1}, WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2, {4, 1}, WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2, {5, 1}, WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2, {4, 1}, WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2, {3, 1}, WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2, {4, 1}, WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2, {3, 1}, WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2, {4, 1}, WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(!board.has_soldiers(1));
}
TEST_CASE("2 vs 2 - Foot , winner team is 1") {
    WarGame::Board board(8, 8);
    CHECK(!board.has_soldiers(1));
    board[{0, 1}] = new FootSoldier(1);
    board[{0, 0}] = new FootCommander(1);
    CHECK(board.has_soldiers(1));

    CHECK(!board.has_soldiers(2));
    board[{7, 0}] = new FootCommander(2);
    board[{7, 1}] = new FootSoldier(2);

    CHECK(board.has_soldiers(2));

    board.move(1, {0, 1}, WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1, {0, 1}, WarGame::Board::MoveDIR::Up));
    board.move(1, {1, 1}, WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    CHECK_THROWS(board.move(2, {7, 0}, WarGame::Board::MoveDIR::Left));
    board.move(2, {7, 0}, WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1, {0, 0}, WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1, {1, 0}, WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(1, {2, 0}, WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1, {1, 0}, WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(1, {2, 0}, WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1, {1, 0}, WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(1, {2, 0}, WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1, {1, 0}, WarGame::Board::MoveDIR::Up);

    CHECK(board.has_soldiers(1));
    board.move(1, {2, 0}, WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));
}

TEST_CASE("Exceptions") {
    WarGame::Board p(6, 6);
    p[{0, 0}] = new FootSoldier(1);
    p[{3, 3}] = new FootSoldier(2);
    p[{5, 0}] = new FootCommander(1);
    p[{3, 5}] = new FootCommander(2);
    p[{0, 1}] = new Sniper(1);
    p[{3, 0}] = new Sniper(2);
    p[{2, 1}] = new SniperCommander(1);
    p[{0, 3}] = new SniperCommander(2);
    p[{5, 1}] = new Paramedic(1);
    p[{1, 3}] = new Paramedic(2);
    p[{4, 5}] = new ParamedicCommander(1);
    p[{4, 0}] = new ParamedicCommander(2);
    //Out of bounds by moving
    CHECK_THROWS(p.move(1, {5, 1}, WarGame::Board::Up));
    CHECK_THROWS(p.move(1, {0, 0}, WarGame::Board::Down));
    CHECK_THROWS(p.move(2, {3, 5}, WarGame::Board::Right));
    CHECK_THROWS(p.move(1, {4, 5}, WarGame::Board::Right));
    CHECK_THROWS(p.move(1, {5, 0}, WarGame::Board::Left));
    //Out of bounds direct
    CHECK_THROWS(p.move(1, {6, 0}, WarGame::Board::Up));
    CHECK_THROWS(p.move(1, {7, 3}, WarGame::Board::Up));
    CHECK_THROWS(p.move(1, {8, 2}, WarGame::Board::Down));
    CHECK_THROWS(p.move(2, {9, 0}, WarGame::Board::Right));
    CHECK_THROWS(p.move(2, {10, 4}, WarGame::Board::Left));
    //Already have soldier
    CHECK_THROWS(p.move(2, {4, 0}, WarGame::Board::Up));
    CHECK_THROWS(p.move(2, {3, 0}, WarGame::Board::Up));
    CHECK_THROWS(p.move(2, {0, 3}, WarGame::Board::Up));
    CHECK_THROWS(p.move(2, {1, 3}, WarGame::Board::Down));
    CHECK_THROWS(p.move(1, {0, 1}, WarGame::Board::Left));
    //No soldier there
    CHECK_THROWS(p.move(1, {2, 0}, WarGame::Board::Up));
    CHECK_THROWS(p.move(1, {4, 3}, WarGame::Board::Up));
    CHECK_THROWS(p.move(1, {2, 2}, WarGame::Board::Down));
    CHECK_THROWS(p.move(2, {1, 0}, WarGame::Board::Right));
    CHECK_THROWS(p.move(2, {5, 4}, WarGame::Board::Left));
}

TEST_CASE("Move and check type test") {
    WarGame::Board p(5, 5);
    p[{0, 0}] = new FootSoldier(1);
    p[{0, 1}] = new FootSoldier(2);
    p[{0, 3}] = new SniperCommander(2);
    p[{0, 4}] = new FootCommander(2);
    p[{2, 0}] = new Paramedic(2);
    p[{2, 1}] = new Paramedic(1);
    p[{2, 2}] = new FootCommander(1);
    p[{2, 3}] = new SniperCommander(1);
    p[{4, 0}] = new Sniper(1);
    p[{4, 1}] = new Sniper(2);
    p[{4, 3}] = new ParamedicCommander(1);
    p[{4, 4}] = new ParamedicCommander(2);

    p.move(1, {2, 2}, WarGame::Board::Up);
    CHECK(p[{2, 2}] == nullptr);
    CHECK(typeid(*p[{3, 2}]) == typeid(FootCommander));

    p.move(1, {2, 3}, WarGame::Board::Down);
    CHECK(p[{2, 3}] == nullptr);
    CHECK(typeid(*p[{1, 3}]) == typeid(SniperCommander));

    p.move(1, {4, 3}, WarGame::Board::Down);
    CHECK(p[{4, 3}] == nullptr);
    CHECK(typeid(*p[{3, 3}]) == typeid(ParamedicCommander));

    p.move(2, {0, 4}, WarGame::Board::Up);
    CHECK(p[{0, 4}] == nullptr);
    CHECK(typeid(*p[{1, 4}]) == typeid(FootCommander));

    p.move(2, {0, 3}, WarGame::Board::Left);
    CHECK(p[{0, 3}] == nullptr);
    CHECK(typeid(*p[{0, 2}]) == typeid(SniperCommander));

    p.move(2, {4, 4}, WarGame::Board::Down);
    CHECK(p[{4, 4}] == nullptr);
}
