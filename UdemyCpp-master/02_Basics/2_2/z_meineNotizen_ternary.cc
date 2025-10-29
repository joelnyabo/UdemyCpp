#include<iostream>
#include<cstdint>


int main()
{
    std::int32_t age1 , age2;
    std::cout<<"1.age = ";
    std::cin>>age1;
    std::cout<<"\n"<<"2.age = ";
    std::cin>>age2;
    std::int32_t older_age = age1 > age2 ? age1 : age2; // terary Abfrage
    std::cout<<"The older age is = "<<older_age<<std::endl;

}
