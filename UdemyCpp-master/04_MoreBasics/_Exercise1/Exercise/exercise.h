#pragma once
#include<cstdint>
#include<array>

enum class TEAM
{
    ALLIED,
    ENEMY,
};

struct PlayerData
{
   std::uint32_t id;
   float x_pos;
   float y_pos;
   std::uint32_t health;
   std::uint32_t energy;
   TEAM team;
};


std::array<float, 2> ausgabe(const PlayerData &player);
