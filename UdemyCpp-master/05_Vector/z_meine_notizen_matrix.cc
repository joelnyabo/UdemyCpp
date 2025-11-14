#include<iostream>
#include<cstdint>
#include<vector>

using matrix = std::vector<std::vector<std::int32_t>>;

int main()
{
  matrix mat{{12, 3, 5}, {33, 46, 3}, {23, 78, 44}, {24, 78, 9}};
  for(auto &it : mat)
  {
    for(auto &at : it)
    {
      std::cout<<at<<" ";
    }
    std::cout<<std::endl;
  }
}
