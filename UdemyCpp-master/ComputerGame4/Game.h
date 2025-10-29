#pragma once
#include <cstdint>



const char input = 'P';
const char boundary = '|';
const char right = 'd';
const char left  = 'a';
constexpr auto start = 0U;
constexpr auto goal = 9U;

bool is_finished(const std::uint32_t player);

void print_game_state(const std::uint32_t player);

void execute_move(std::uint32_t &player, const char move);

void game();
