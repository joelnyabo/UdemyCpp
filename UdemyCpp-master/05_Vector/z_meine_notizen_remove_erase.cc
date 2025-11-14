#include<iostream>
#include<cstdint>
#include<algorithm>
#include<vector>

void aus(std::vector<std::int32_t> &v)
{
  for(auto it = v.begin(); it!=v.end(); it++)
  {
    std::cout<<*it<<" ";
  }
  std::cout<<"\n";
}

bool pos(std::int32_t a)
{
  return a<0 ? true:false;
}

int main()
{
    std::vector<std::int32_t>vec{2,2,-4,-63,1,46,8};
    std::int32_t value = 2;
    auto neu = std::remove(vec.begin(),vec.end(), value);
    vec.erase(neu, vec.end());
    aus(vec);

    auto neu_neg = std::remove_if(vec.begin(), vec.end(), pos);
    vec.erase(neu_neg, vec.end());
    aus(vec);
}
