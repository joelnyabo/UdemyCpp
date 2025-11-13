#pragma once
#include <cstdint>

struct Coordinates
{
    std::int32_t x;
    std::int32_t y;
};

bool is_finished(const Coordinates &player);

void print_game_state(const Coordinates player);

void execute_move(Coordinates &player, const char move);

void game();
