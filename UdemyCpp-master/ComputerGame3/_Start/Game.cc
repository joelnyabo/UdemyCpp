#include <cstdint>
#include <iostream>
#include "Game.h"



void game()
{
    static auto pos = 0U;
    const char player = 'P';
    const char boundary = '|';
    const char right = 'd';
    const char left  = 'a';
    constexpr auto start = 0U;
    char direction = ' ';
    constexpr auto goal = 9U;

   for(auto i = 0U; i <= goal; i++)
   {
       if( i == pos )
       {
          std::cout<<player;
       }
       else if( i == goal )
             {
                std::cout<<boundary;
             }
             else
             {
                std::cout<<".";
             }
   }

   do{
       std::cin>>direction;
       if( direction == right && pos < goal)
       {
         ++pos;
            for(auto i = 0U; i <= goal; i++)
            {
                  if( i == pos )
                  {
                     std::cout<<player;
                  }
                  else if( i == goal )
                       {
                          std::cout<<boundary;
                       }
                       else
                       {
                          std::cout<<".";
                       }
            }
       }
       else if( direction == left && pos > start )
             {
               --pos;
                    for(auto i = 0U; i <= goal; i++)
                    {
                         if( i == pos )
                         {
                              std::cout<<player;
                         }
                         else if( i == goal )
                              {
                                std::cout<<boundary;
                              }
                              else
                              {
                                std::cout<<".";
                              }
                    }
             }
             else
             {
                for(auto i = 0U; i <= goal; i++)
                    {
                         if( i == pos )
                         {
                              std::cout<<player;
                         }
                         else if( i == goal )
                              {
                                std::cout<<boundary;
                              }
                              else
                              {
                                std::cout<<".";
                              }
                    }
             }
   }while( pos != goal );
}
