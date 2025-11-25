#include <cstdint>
#include <iostream>
#include <vector>

#include "Game.h"
const auto obstacles = std::vector<Coordinate>{ Coordinate{.x = 1, .y = 1}, Coordinate{.x = 2, .y = 2}, Coordinate{.x = 3, .y = 3}};
const auto PLAYER= 'P';
std::size_t ROW = 5;
std::size_t COL = 5;

bool lost(const Coordinate& player, const std::vector<Coordinate> &ob)
{
   for(auto it : ob)
   {
      if((it.x == player.x) && (it.y == player.y) )
      {
        return true;
      }
   }
  return false;
}


bool is_finished(const Coordinate &player)
{
  return (player.x == static_cast<std::uint32_t>(ROW)-1 && player.y == static_cast<std::uint32_t>(COL)-1) ? true : false;
}

void print_game_state(const Coordinate &player, const std::vector<Coordinate> &ob)
{
  for(std::size_t i = 0; i<ROW; i++)
  {
    for(std::size_t j = 0; j<COL ; j++)
    {
        if(static_cast<std::uint32_t>(i) == player.x && static_cast<std::uint32_t>(j) == player.y)
        {
          std::cout<<PLAYER;
        }
        else if( (static_cast<std::uint32_t>(i) == ob[0].x && static_cast<std::uint32_t>(j) == ob[0].y) || (static_cast<std::uint32_t>(i) == ob[1].x && static_cast<std::uint32_t>(j) == ob[1].y) || (static_cast<std::uint32_t>(i) == ob[2].x && static_cast<std::uint32_t>(j) == ob[2].y) )
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

void execute_move(Coordinate &player, const ConsoleInput move, const std::vector<Coordinate> &ob)
{
   switch(move)
   {
     case ConsoleInput::RIGHT:
        if(!is_finished(player) && !lost(player, ob))
        {
           if(player.y < COL-1)
           {
             player.y++;
           }
           else
           {
             player.x++;
             player.y = 1;
           }
        }
     break;
     case ConsoleInput::LEFT:
        if(!is_finished(player) && !lost(player, ob) && (player.x != 0 && player.y!=0))
        {
           if(player.y > 0)
           {
             player.y--;
           }
           else
           {
             player.x--;
             player.y = 5;
           }
        }
     break;
      case ConsoleInput::UP:
        if(!is_finished(player) && !lost(player, ob) && player.x!=0)
        {
             player.x--;
        }
     break;
      case ConsoleInput::DOWN:
        if(!is_finished(player) && !lost(player, ob) && player.x!=5)
        {
          player.x++;
        }
     break;
     case ConsoleInput::INVALID :
      break;

    }

}

void game()
{
  Coordinate player{.x=0, .y=0};
  char move =' ';
 while(true)
 {
    print_game_state(player, obstacles);
    std::cin>>move;
    if(!is_finished(player) || !lost(player, obstacles))
    {
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
    else if(!is_finished(player) && lost(player, obstacles))
    {
       std::cout<<"\nYou lost!\n";
       exit(0);
    }
    else
    {
        std::cout<<"\nYou won!\n";
        break;
    }
}

}
