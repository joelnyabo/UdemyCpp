#include<iostream>
#include<vector>
#include<random>
#include<cstdint>
#include<chrono>
#include<algorithm>
//#define MODE

#ifdef MODE
int main() // random Zahlen
{
    auto vect = std::vector<std::int32_t>(10, 0U);
    auto gen = std::mt19937{42};
    auto dist = std::uniform_int_distribution<std::int32_t>{-10, 10};
    for(std::size_t i = 0; i<10; i++)
    {
       vect[i] = dist(gen);
    }

    for(std::size_t i = 0; i<10; i++)
    {
      std::cout<<vect[i]<<" ";
    }
}
//#else


std::int32_t gen()
{
    static  auto seed = std::random_device{};// static ist hier wichtig um die Ausführungszeit zu optimisieren, da beim jedem Abruf der Funktion gen() werden ohne "static" die Variablen
    // seed , gen , und dist neu erstellt , das kostet Zeit. Mit Static werden sie einmal erstellt und fertig.
    static auto gen = std::mt19937{seed()};
    static auto dist = std::uniform_int_distribution<std::int32_t>{};
    return(dist(gen));
}


int main() //  Chrono and generate of algorithm
{

  auto vec = std::vector<std::int32_t>(10, 0U);
  auto start_time = std::chrono::steady_clock::now();
  std::generate(vec.begin(), vec.end(), gen);
  auto end_time = std::chrono::steady_clock::now();

  for(auto const  &it : vec )
    std::cout<<it<<" ";

 std::cout<<"\n"<<std::chrono::duration_cast<std::chrono::nanoseconds>(end_time-start_time).count();
}
#else//Transform

std::int32_t gen()
{
    static  auto seed = std::random_device{};// static ist hier wichtig um die Ausführungszeit zu optimisieren, da beim jedem Abruf der Funktion gen() werden ohne "static" die Variablen
    // seed , gen , und dist neu erstellt , das kostet Zeit. Mit Static werden sie einmal erstellt und fertig.
    static auto gen = std::mt19937{seed()};
    static auto dist = std::uniform_int_distribution<std::int32_t>{};
    return(dist(gen));
}

std::int32_t add(std::int32_t val)
{
   return val+2;
}

int main() //  Chrono and generate of algorithm
{

 auto vec = std::vector<std::int32_t>(20, 0U);
 std::generate(vec.begin(), vec.end(), gen );
 for(auto const & it : vec)
     std::cout<<it<<" ";
std::cout<<"\n";
 std::transform(vec.begin(), vec.end(), vec.begin(), add);
 for(auto const & it : vec)
     std::cout<<it<<" ";

}

#endif
