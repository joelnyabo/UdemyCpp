#include<iostream>
#include<cstdint>
#include<vector>


int main()
{
  std::vector<std::int32_t>v(5, 2);//size ist 5 und mit 2 gefüllt.
  std::vector<std::int32_t>v1{5, 2};// aber hier size = 2, mit 5 und 5 gefüllt.
  std::cout<<"Größe="<<v.size()<<"   Kapazität="<<v.capacity()<<std::endl;
  v.push_back(3);
  std::cout<<"Größe="<<v.size()<<"   Kapazität="<<v.capacity()<<std::endl;
}
