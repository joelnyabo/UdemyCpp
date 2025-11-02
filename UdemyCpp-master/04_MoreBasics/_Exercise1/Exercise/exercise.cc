#include <iostream>
#include<array>

#include "exercise.h"

std::array<float, 2> ausgabe(const PlayerData &player)
{
    auto array_aus = std::array<float,2>{};
    array_aus[0] = player.x_pos;
    array_aus[1] = player.y_pos;
    return(array_aus);
}
