#include<iostream>
#include<cstdint>

int main()
{
    char input;
    char links = 'a', rechts = 'd';
    std::cout<<"Which direction would you like to move in? for left tap 'a' for right tap 'd'"<<std::endl<<"Direction = ";
    std::cin>>input;
    if (input == links)
       std::cout<<"The player moved to the left!"<<std::endl;
    else if(input == rechts)
         std::cout<<"The player moved to the right!"<<std::endl;
    else
         std::cout<<"Unavailable direction"<<std::endl;


}
