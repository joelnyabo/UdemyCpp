#include<iostream>
#include"Game.h"


  constexpr static std::int32_t LINE = 5;
  constexpr static std::int32_t COL= 5U;

  char direction;
  static Coordinates position{.x = 0, .y = 0};

  const static auto BOUNDARY = '|';
  const static auto LEER = '.';
  const static auto PLAYER = 'P';


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
        if((i == static_cast<std::size_t>(position.x) && j == static_cast<std::size_t>(position.y)) || is_finished(player))
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


void execute_move(Coordinates &player, const INPUT_DIRECTION move)
{

 switch(move)
 {
    case INPUT_DIRECTION::LEFT :
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

    case INPUT_DIRECTION::RIGHT :
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

    case INPUT_DIRECTION::UP :
      if( !is_finished(player) && player.x>0 )
      {
        player.x--;
      }
    break;

    case INPUT_DIRECTION::DOWN :
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
        if(direction == 'l')
          execute_move(position, INPUT_DIRECTION::LEFT);
        else
           if(direction == 'r')
              execute_move(position, INPUT_DIRECTION::RIGHT);
           else if(direction == 'u')
                   execute_move(position, INPUT_DIRECTION::UP);
                else
                    execute_move(position, INPUT_DIRECTION::DOWN);
    }while(!is_finished(position));

}
