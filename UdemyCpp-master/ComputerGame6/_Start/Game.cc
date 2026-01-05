#include"game.h"
#include<iostream>
auto const PLAYER = 'P';
std::size_t ROW = 5;
std::size_t COL = 5;
const auto ZIEL = Coordinate{.x = 4, .y = 4};
auto player_coordinate = Coordinate{.x = 0, .y = 0 };
const auto Obstacles = std::vector<Coordinate>{Coordinate{.x = 1, .y = 1}, Coordinate{.x = 2, .y = 2}, Coordinate{.x = 3, .y = 3}};

bool search_in_ob(const Coordinate &player, const std::vector<Coordinate> &ob)
{
  for(const auto &it : ob)
  {
    if(player.x == it.x && player.y == it.y)
    {
        return true;
    }
  }
  return false;
}

bool is_finished(const Coordinate &player)
{
  if(search_in_ob(player, Obstacles) || (player.x == ZIEL.x && player.y == ZIEL.y))
  {
    return true;
  }
}


void print_game_state(const Coordinate &player)
{
    if(!is_finished(player))
    {
       for(std::size_t i = 0; i<ROW; i++)
       {
          for(std::size_t j = 0; j<COL; j++)
          {
             if(player.x == i && player.y == j)
             {
                std::cout<<PLAYER;
             }
             else
             {
                if( (i == Obstacles[0].x && j == Obstacles[0].y) || (i == Obstacles[1].x && j == Obstacles[1].y) || (i == Obstacles[2].x && j == Obstacles[2].y) )
                {
                  std::cout<<'X';
                }
                else
                {
                    std::cout<<'_';
                }
             }
          }
          std::cout<<"\n";
       }
    }
    else
    {
        if(player.x == ZIEL.x && player.y == ZIEL.y)
        {
          std::cout<<"\nYou won!!!\n";
          exit(0);
        }
        else
        {
          std::cout<<"\nYou lost!!!\nTry again\n";
          exit(1);
        }
    }
}

void execute_move(Coordinate& player, ConsoleInput move)
{
    if (is_finished(player))
        return;

    constexpr std::int32_t MAX = 4;

    switch (move)
    {
        case ConsoleInput::LEFT:
            if (player.y > 0)
                --player.y;
            else
                player.y = MAX;
            break;

        case ConsoleInput::RIGHT:
            if (player.y < MAX)
                ++player.y;
            else
                player.y = 0;
            break;

        case ConsoleInput::UP:
            if (player.x > 0)
                --player.x;
            break;

        case ConsoleInput::DOWN:
            if (player.x < MAX)
                ++player.x;
            break;
    }
}



void game()
{
   char input;
   do
   {
     print_game_state(player_coordinate);
     std::cin>>input;
     switch (input)
     {
       case 'l':
          execute_move(player_coordinate, ConsoleInput::LEFT);
       break;

       case 'r':
         execute_move(player_coordinate, ConsoleInput::RIGHT);
       break;

       case 'u':
         execute_move(player_coordinate ,ConsoleInput::UP);
       break;

       case 'd':
        execute_move(player_coordinate, ConsoleInput::DOWN);
       break;
     }
   } while (true);

}
