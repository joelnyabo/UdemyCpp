#include <cstdint>
#include <iostream>

int main()
{
    const char player = 'P';
    const char boundary = '|';
    char move;
    const char right = 'd';
    const char left  = 'a';
    std::int32_t start = 0;
    std::int32_t pos = 0 ;
    std::int32_t goal = 9;

    //player at the first position
    std::cout<<player;
    for(std::int32_t i = 1; i < goal; i++)
    {
        std::cout<<".";
    }
    std::cout<<boundary;

    do{
        std::cin>>move;

        if( move == right && pos != goal )//if man sich rechts bewegt und noch nicht das Ziel erreicht hat.
        {
            ++pos;
            std::cout<<"\n The player moved to the right!"<<std::endl;

            std::cout<<boundary;
            for(std::int32_t i = 1; i < goal; i++)
            {
                if( i == pos)
                {
                  std::cout<<player;
                }
                else
                {
                  std::cout<<".";
                }

            }

            if( pos != goal)
            {
                std::cout<<boundary;
            }
            else
            {
                std::cout<<player;
                std::cout<<"\nYou win!!!"<<std::endl;
                break;
            }
        }
        else
        {
          if( move == left && pos > start )
          {
            --pos;
            std::cout<<"\n The player moved to the left!"<<std::endl;
            std::cout<<boundary;
            for( std::int32_t i = 0; i <= goal; i++ )
            {
                if( i == pos)
                {
                    std::cout<<player;
                }
                else
                {
                    if (i == goal)
                     {
                       std::cout<<boundary;
                     }
                     else
                     {
                         std::cout<<".";
                     }
                }

            }
         }
         else
         {
            std::cout<<player;
              for(std::int32_t i = 1; i < goal; i++)
              {
                  std::cout<<".";
              }
            std::cout<<boundary;
         }
        }

    }while( pos != goal );
}
