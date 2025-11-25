#pragma once

#include <cstdint>
#include <vector>

struct Coordinate
{
    std::uint32_t x;
    std::uint32_t y;
};

enum class ConsoleInput
{
    INVALID,
    LEFT = 'l',
    RIGHT = 'r',
    UP = 'u',
    DOWN = 'd',
};

bool is_finished(const Coordinate &player);

void print_game_state(const Coordinate &player,
                      const std::vector<Coordinate> &obstacles);

void execute_move(Coordinate &player,
                  const ConsoleInput move,
                  const std::vector<Coordinate> &obstacles);

void game();
