#pragma once
#include<cstdlib>
#include <cstdint>
#include<vector>


struct Coordinate
{
    std::uint32_t x;
    std::uint32_t y;
};

enum class ConsoleInput
{
    LEFT = 'l',
    RIGHT = 'r',
    UP = 'u',
    DOWN = 'd',
};

bool is_finished(const Coordinate &player);

void print_game_state(const Coordinate &player);

void execute_move(Coordinate &player, const ConsoleInput move);

void game();
bool search_in_ob(const Coordinate &player,  const std::vector<Coordinate> &ob);
