#include<iostream>
#include<cstdint>

int main()
{
    bool check = true;

    std::uint32_t age1 = 0;
    std::cout<<"Enter your age : "<<std::endl;
    std::cin>>age1;
    check = ((age1 >= 30) && (age1 <= 39));
    if(check)
    {
        std::cout<<"Check = " <<std::boolalpha<<check<<std::endl;
    }
    else
    {
         std::cout<<"Check = " <<std::boolalpha<<check<<std::endl;
    }
}
