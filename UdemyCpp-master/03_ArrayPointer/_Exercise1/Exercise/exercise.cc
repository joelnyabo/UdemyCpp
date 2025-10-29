#include <array>
#include <cstddef>
#include <cstdint>

#include "exercise.h"

// Exercise 2
double array_sum(const double array[], const std::size_t length)
{
    auto summe = 0.0;
    for(std::uint32_t i = 0U; i < static_cast<std::uint32_t>(length); ++i)
    {
         summe += array[i];
    }
    return summe;
}

// Exercise 3
double array_sum(const std::array<double, 100> array)
{
    auto summe = 0.0;
    for(std::uint32_t i = 0U; i < static_cast<std::uint32_t>(array.size()); ++i)
    {
         summe += array[i];
    }
    return summe;
}
