#include <iostream>

#include "exercise.h"

int main()
{
    auto spieler1 = PlayerData{.id=3U, .x_pos=3.3f, .y_pos=6.5f, .health=3U, .energy=4U, .team=TEAM::ALLIED};
   // auto spieler2 = PlayerData{.id=3, .x_pos=3.3, .y_pos=6.5, .health=3, .energy=4, .team=TEAM::ENEMY};
    auto arr = ausgabe(spieler1);

        std::cout<<"x = "<<arr[0]<<" y = "<<arr[1];

    return 0;
}
