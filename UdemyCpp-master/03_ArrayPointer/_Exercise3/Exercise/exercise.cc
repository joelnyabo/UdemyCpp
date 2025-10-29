#include <cstdint>
#include <iostream>

#include "exercise.h"

// Exercise 1
void push_back(std::int32_t *input_array,
               const std::size_t size,
               const std::int32_t value)
{
    *(input_array + static_cast<std::int32_t>(size)) = value;
}

// Exercise 2
void pop_back(std::int32_t *input_array, const std::size_t size)
{
    auto *z = input_array + static_cast<std::int32_t>(size-1);
   delete(z);
  // z = nullptr;
}
