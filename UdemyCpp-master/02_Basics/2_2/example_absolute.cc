#include <iostream>
#include<cstdint>


// 1.) User-Input: number
// 2.) Compute the absolute value of the number
// 3.) Print out the absolute value
// The number can be a float/double/int etc. its up to you :)

// x < 0: -x
// x >= 0: x

int main()
{
    std::int32_t number;
    std::cout<<"Please enter a number "<<std::endl;
    std::cin>>number;
    if (number > 0 )
    {
        std::cout<<"Number = "<<number;
    }
    else
    {
        std::cout<<"Number = "<<-1*number;
    }

    return 0;
}
