#include<iostream>
#include"Game.h"
#include<array>


auto pos = 0U;
char direction = ' ';

bool is_finished(const std::uint32_t player)
{
    return( player == goal ? true : false );
}

void print_game_state(const std::uint32_t player)
{
    std::array<char, goal+1> feld;

    for(auto i = static_cast<std::size_t>(start); i < feld.size(); ++i )
    {
        if( i == player )
        {
            feld[i] = input;
        }
        else if( i == goal )
        {
            if( !is_finished(player) )
            {
               feld[i] = boundary;
            }
            else
            {
               feld[i] = input;
            }
        }
        else
        {
            feld[i] = '_';
        }
    }

    for(auto i = static_cast<std::size_t>(start); i < feld.size(); ++i )
    {
        std::cout<<feld[i];
    }
}

void execute_move(std::uint32_t &player, const char move)
{
  if( move == right && !is_finished(player) )
  {
      ++player;
  }
  else if( move == left && player != start )
  {
    --player;
  }
}

void game()
{
   print_game_state(pos);
   do{
       std::cin>>direction;
       execute_move(pos, direction);
       print_game_state(pos);
   }while(pos != goal);
}
