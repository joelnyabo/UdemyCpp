#include<iostream>
#include"Game.h"


  constexpr auto static LINE = 5U;
  constexpr auto static COL= 5U;
  const auto static BOUNDARY= '|';
  const auto static LEER = '.';
  const auto static PLAYER = 'P';
  const auto static LEFT = 'l';
  const auto static RIGHT = 'r';
  const auto static UP = 'u';
  const auto static DOWN = 'd';
  char direction;
  static Coordinates position{.x = 0, .y = 0};
  Coordinates spieler{.x = 0, .y = 0};




bool is_finished(const Coordinates &player)
{
   return (player.x == LINE-1 && player.y == COL-1) ? true : false;
}


void print_game_state(const Coordinates player)
{

 for(std::size_t i=0; i<static_cast<std::size_t>(LINE); ++i)
 {
    for(std::size_t j=0; j<static_cast<std::size_t>(COL); ++j)
    {
        if((i == position.x && j == position.y) || is_finished(player))
        {
            std::cout<<PLAYER;
        }
        else if( i == LINE-1 && j == COL-1 && !is_finished(player))
        {
            std::cout<<BOUNDARY;
        }
        else
        {
            std::cout<<LEER;
        }
    }
    std::cout<<"\n";
 }
}


void execute_move(Coordinates &player, const char move)
{

 switch(move)
 {
    case LEFT:
      if( !is_finished(player) && player.y>0 )
      {
        player.y--;
      }
      else if( player.y == 0 && player.x != 0 )
      {
        player.x--;
        player.y = 4;
      }
    break;

    case RIGHT:
      if( !is_finished(player) && player.y<4 )
      {
        player.y++;
      }
      else if( !is_finished(player) && player.y == 4 )
      {
        player.x++;
        player.y = 0;
      }
    break;

    case UP:
      if( !is_finished(player) && player.x>0 )
      {
        player.x--;
      }
    break;

    case DOWN:
      if( !is_finished(player) && player.x<4 )
      {
        player.x++;
      }
    break;
 }

}

void game()
{
    do{
        print_game_state(position);
        std::cin>>direction;
        execute_move(position, direction);

    }while(!is_finished(position));

}
