#include <cstdint>
#include <iostream>
#
#include "exercise.h"

int main()
{

   constexpr std::size_t length = 100;
   double array[length]{};
   for(std::uint32_t i = 0U; i < static_cast<std::int32_t>(length) ; ++i)
   {
      array[i] = static_cast<double>(i);
   }

   std::array<double,length> tabelle{};
   for(std::uint32_t i = 0U; i < static_cast<std::uint32_t>(tabelle.size()) ; ++i)
   {
      tabelle[i] = static_cast<double>(i);
   }
   std::cout<<array_sum(array, length)<<"   "<<array_sum(tabelle);
}
