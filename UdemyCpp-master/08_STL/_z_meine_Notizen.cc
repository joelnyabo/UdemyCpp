#include<iostream>
#include<vector>
#include<random>
#include<cstdint>


auto static VALUE = std::size_t{20};
std::int32_t generator()
{
    auto seed = std::random_device{};
    auto gen = std::mt19937{seed()};
    auto dist = std::uniform_int_distribution<std::int32_t>{-10, 10};
    return( dist(gen));
}
int main()
{
   auto vect = std::vector<std::int32_t>(VALUE, 0U);
   for(auto &it : vect)
   {
    it=generator();
   }

   for(auto const &it : vect)
   {
    std::cout<<it<<"  ";
   }
}
