#include<iostream>
#include<cstdint>

int main()
{


   std::uint32_t number = 0;
   std::uint32_t win_number = 7;

   //1-Hier hat der Benutzer nur noch 3 Versuche.
   /* std::cout<<"Welcome to our guess play!\n you have to guess a number betwenn 0 and 10, for it you have 3 attemps"<<std::endl;
   std::int32_t max_attempts = 3;
   std::int32_t rest_attemp = max_attempts;

   for(std::int32_t i = 0; i<max_attempts; i++)
   {
        std::cout<<"Give a Number"<<std::endl<<"Number = ";
        std::cin>>number;
        if (number == win_number)
        {
            std::cout<<"you win"<<std::endl;
            break;
        }
        else
        {
            if(rest_attemp == 1 )
            {
              std::cout<<"you lost"<<std::endl;
              std::cout<<"The Game is finish!!!"<<std::endl;
            }
            else
            {
                std::cout<<"you lost"<<std::endl;
                std::cout<<"you only have "<<(rest_attemp-1)<<" attemps"<<std::endl;
            }
        }

    --rest_attemp ;

    }*/

    // 2-Hier darf er undendlich viel ausprobieren bis er gewinnt.

  while(true)
  {

    std::cout<<"Give a Number"<<std::endl<<"Number = ";
    std::cin>>number;
    if (number == win_number)
        break;

  }
    std::cout<<"You win!!!";

    // 3-Hier darf er undendlich viel ausprobieren bis er gewinnt.

}
