#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdint>
#include<random>
//#define MODE
std::int32_t generator()
{
    auto seed = std::random_device{};
    auto gen = std::mt19937{seed()};
    auto dist = std::uniform_int_distribution<std::int32_t>{-10, 10};
    return dist(gen);
}

template<typename T>
void ausgabe(std::vector<T> v)
{
   for(const auto &it : v)
   {
    std::cout<<it<<"  ";
   }
   std::cout<<" \n";
}

#ifdef MODE
int main()
{
    auto vektor1 = std::vector<std::int32_t>(20, 0U);
    std::generate(vektor1.begin(), vektor1.end(), [](){return generator();});
    auto result_positiv = std::vector<bool>(20, 0);
    std::transform(vektor1.begin(), vektor1.end(), result_positiv.begin(), [&](const auto val){ return val>0;});
    ausgabe(vektor1);
    ausgabe(result_positiv);
    auto result = std::vector<std::int32_t>{};
    std::copy_if(vektor1.begin(), vektor1.end(), std::back_inserter(result), [&](const auto val){ return val>0;});
    ausgabe(result);
}
#else

int main()
{
    auto vektor1 = std::vector<std::int32_t>(20, 0U);
    std::generate(vektor1.begin(), vektor1.end(), [](){return generator();});
    auto result_positiv = std::vector<bool>(20, 0);
    std::transform(vektor1.begin(), vektor1.end(), result_positiv.begin(), [&](const auto val){ return val>0;});
    ausgabe(vektor1);
    ausgabe(result_positiv);
    auto result = std::vector<std::int32_t>{};
    std::copy_if(vektor1.begin(), vektor1.end(), std::back_inserter(result), [&](const auto val){ return val>0;});
    ausgabe(result);
}
#endif
