#pragma once
#include <cstdint>

struct Coordinates
{
    std::int32_t x;
    std::int32_t y;
};

enum class INPUT_DIRECTION
{
    LEFT = 'l',//enum nimmt nur integer aber char ist int unter der Haube (ASCII)
    RIGHT = 'r',
    DOWN = 'd',
    UP = 'u',
};

bool is_finished(const Coordinates &player);

void print_game_state(const Coordinates player);

void execute_move(Coordinates &player, const char move);

void game();
