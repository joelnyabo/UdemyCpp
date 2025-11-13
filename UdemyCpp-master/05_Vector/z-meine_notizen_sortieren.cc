#include<iostream>
#include<cstdint>
#include<vector>
#include<algorithm>

bool such(std::int32_t a, std::int32_t b)
{
  return( a<b ? true:false );
}

void aus(std::vector<std::int32_t> &v)
{
  for(auto it = v.begin(); it!=v.end(); it++)
  {
    std::cout<<*it<<" ";
  }
  std::cout<<"\n";
}

int main()
{
  auto my_vector = std::vector<std::int32_t>{7,24,1,78,9,35,1};
  std::sort(my_vector.begin(), my_vector.end(),such);
  aus(my_vector);
}
