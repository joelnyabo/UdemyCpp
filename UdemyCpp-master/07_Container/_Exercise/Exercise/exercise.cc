#include <iostream>

#include "exercise.h"

// Exercise 2

std::int32_t oldest(const std::map<std::string, std::pair<std::int32_t, std::int32_t>> &friends)
{
    std::int32_t max = 0;
    for(auto &it : friends)
    {
       max = (max > it.second.first)? max : it.second.first;
    }
    return max;
}

std::int32_t heaviest(const std::map<std::string, std::pair<std::int32_t, std::int32_t>> &friends)
{
    std::int32_t max = 0;
    for(auto &it : friends)
    {
       max = (max > it.second.second)? max : it.second.second;
    }
    return max;
}

std::string_view get_oldest_friend(const std::map<std::string, std::pair<std::int32_t, std::int32_t>> &friends)
{
    for( auto &it : friends )
    {
        if(it.second.first == oldest(friends))
        {
            return ("Die Person = "+it.first +" mit dem Alter = "+ std::to_string(it.second.first) + "ist die älteste!\n");
        }
    }
}

std::string_view get_heaviest_friend(const std::map<std::string, std::pair<std::int32_t, std::int32_t>> &friends)
{
    for( auto &it : friends )
    {
        if(it.second.first == heaviest(friends))
        {
            return ("Die Person = "+it.first +" mit dem Gewicht = "+ std::to_string(it.second.first) + "ist die schwerste!\n");
        }
    }
}
