#include<iostream>
#include<tuple>
#include<string>
#include<cstdint>
#include<vector>
#include<array>

struct User
{
    std::string name;
    std::string vorname;
    std::int32_t age;
};

int main()
{
    User student{.name = "Dannick", .vorname ="Joel", .age=23};
    auto my_tuple = std::tuple<int, double, User>{01, 0.5F, student};
    std::cout<<std::get<0>(my_tuple)<<" "<<std::get<1>(my_tuple)<<" "<<std::get<2>(my_tuple).age<<" "<<std::get<2>(my_tuple).name<<" "<<std::get<2>(my_tuple).vorname<<"\n";

//Anstatt Tuple oder pair zu nutzen, könnte man am besten Struct oder Class verwendet. aber tuple ider pair könnten gern beutz werden wenn man in einer Funktion mehrere Sachen zurückgeben möchte.


}
