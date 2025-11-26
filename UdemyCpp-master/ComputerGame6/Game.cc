#include <cstdint>
#include <iostream>
#include <vector>
#include "Game.h"
const auto obstacles = std::vector<Coordinate>{ Coordinate{.x = 1, .y = 1}, Coordinate{.x = 2, .y = 2}, Coordinate{.x = 3, .y = 3}};
const auto PLAYER= 'P';
std::size_t ROW = 5;
std::size_t COL = 5;

bool lost(const Coordinate& player)
{
   for(auto it : obstacles)
   {
      if((it.x == player.x) && (it.y == player.y))
      {
        return true;
      }
   }
   return false;
}


bool is_finished(const Coordinate &player)
{
  return (player.x == ROW-1 && player.y == COL-1) ? true : false;
}

void print_game_state(const Coordinate &player, const std::vector<Coordinate> &obstacles)
{
  for(auto i = 0; i<ROW; i++)
  {
    for(auto j = 0; j<COL; j++)
    {
        if(i == player.x && j == player.y)
        {
          std::cout<<PLAYER;
        }
        else if( (i == obstacles[0].x && j == obstacles[0].y) || (i == obstacles[1].x && j == obstacles[1].y) || (i == obstacles[2].x && j == obstacles[2].y) )
        {
           std::cout<<"X";
        }
        else if(i == ROW-1 && j == COL-1)
        {
            std::cout<<"|";
        }
        else
        {
            std::cout<<".";
        }
    }
    std::cout<<"\n";
  }
}

void execute_move(Coordinate &player, const ConsoleInput move, const std::vector<Coordinate> &obstacles)
{
   switch (move)
   {
     case ConsoleInput::RIGHT:
        if(!is_finished(player) && !lost(player))
        {
           if(player.y < COL-1)
           {
            player.y++;
           }
           else
           {
            player.x++;
            player.y == 1;
           }
        }
     break;

     case ConsoleInput::LEFT:
        if(!is_finished(player) && !lost(player) && (player.x != 0 && player.y!=0))
        {
           if(player.y > 0)
           {
            player.y--;
           }
           else
           {
            player.x--;
            player.y == 5;
           }
        }
     break;

      case ConsoleInput::UP:
        if(!is_finished(player) && !lost(player) && player.x!=0)
        {
         player.x--;
        }
     break;

      case ConsoleInput::DOWN:
        if(!is_finished(player) && !lost(player) && player.x!=5)
        {
          player.x++;
        }
     break;

    }

}

void game()
{
  Coordinate player{.x=0, .y=0};
  char move;
  while(!is_finished(player))
  {
    print_game_state(player, obstacles);
    std::cin>>move;
    switch (move)
    {
       case 'l':
         execute_move(player, ConsoleInput::LEFT, obstacles);
       break;

       case 'r':
         execute_move(player, ConsoleInput::RIGHT, obstacles);
       break;

       case 'd':
         execute_move(player, ConsoleInput::DOWN, obstacles);
       break;

       case 'u':
         execute_move(player, ConsoleInput::UP, obstacles);
       break;
    }
  }

}
