#include<iostream>
#include<cstdint>
#include<vector>
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
    std::vector<std::int32_t>my_vector{3,4,5,6,7};
    aus(my_vector);
    auto &front = my_vector.front();
    front = 8;
    aus(my_vector);
    auto  *my_data = my_vector.data();
    *(my_data+2) = 18;
    aus(my_vector);


}
