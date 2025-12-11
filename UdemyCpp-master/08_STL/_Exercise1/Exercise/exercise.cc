#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

#include "exercise.h"

// Exercise 2
std::vector<bool> shuffle_till_equal(const std::vector<bool> &target, std::vector<bool> input)
{
    std::size_t iteration = 1;
    bool equal = false;
    while(!equal)
    {
       if(std::equal(input.begin(), input.end(), target.begin()))
       {
           equal = true;
       }
       else
       {
        std::cout<<"\n Iteration : "<<iteration++;
        std::shuffle(input.begin(), input.end(), std::default_random_engine{42});
       }
    }
    return input;
}

// Exercise 3
std::vector<bool> smart_shuffle_till_equal(const std::vector<bool> &target,
                                    std::vector<bool> input)
{
}
