#include <cstdint>
#include <iostream>

void super_duper_example(const std::int32_t input)
{
   static std::int32_t compter = 0;
   if ( input % 2 == 0 )
   {
     ++compter;
   }
}

int main()
{
 for(std::int32_t i = 0; i<=10; i++)
 {

 }

    return 0;
}
