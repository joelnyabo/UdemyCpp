#include<iostream>
#include<vector>
#include<random>
#include<cstdint>
#include<chrono>
#include<algorithm>

//#define MODE
auto static VALUE = std::size_t{20};
std::int32_t generator()
{
    static auto seed = std::random_device{};// Warum Satic, weil jedes Mal wo man die Funktion aufruf werden die Variablen seed, gen und dist erstellt, was Zeit kostet.
    static auto gen = std::mt19937{seed()};
    static auto dist = std::uniform_int_distribution<std::int32_t>{-10, 10};
    return( dist(gen));
}

#ifdef MODE //Random und Zahlengenerator
int main()
{
   auto vect = std::vector<std::int32_t>(VALUE, 0U);
   for(auto &it : vect)
   {
    it=generator();
   }

   for(auto const &it : vect)
   {
    std::cout<<it<<"  ";
   }
}

//#else //Timimg mit Chrono hier werde ich zeigen dass beim Vector Belegen ist es immer gut im Voraus einen Speicher zu belegen als beim jeder Schleife einen Push_back zu machen.
//das bedeutet nicht unbedingt, dass pushback schneller als normal, da beim Push wird erst ein Kopie gemacht wenn die Kapazität des Vektor erreicht ist, und die Kopie kostet Zeit. das heißt für größe Vektor.

int main()
{
   auto start_time = std::chrono::steady_clock::now();
   auto vect = std::vector<std::int32_t>(VALUE, 0U);
   for(auto &it : vect)
   {
    it=generator();
   }
   auto end_time = std::chrono::steady_clock::now();
   std::cout<<" Time without push_back = "<<std::chrono::duration_cast<std::chrono::microseconds>(end_time-start_time).count()<<"\n";

   auto start_time1 = std::chrono::steady_clock::now();
   auto vect1 = std::vector<std::int32_t>{};
   for(std::size_t i = 0; i<VALUE; i++)
   {
    vect1.push_back(generator());
   }
   auto end_time1 = std::chrono::steady_clock::now();
   std::cout<<"Time with push_back = "<<std::chrono::duration_cast<std::chrono::microseconds>(end_time1-start_time1).count();
//Immer beim Release Mode Kompilieren und am Ende kann man sehen, dass mit Push Back die Compilertime größer als ohne;
}
//#else //  std::generate von Algorithm mit generate kann man einen Vektor mit beliebigen Zahlen belegen ohne for Schleife

int main()
{
 auto vektor = std::vector<std::int32_t>(VALUE, 0);
 std::generate(vektor.begin(), vektor.end(), generator);
 for(auto const &it : vektor)
 {
    std::cout<<it<<" ";
 }
}

//#else //transform einen Container(vector/ Array/ string) modifizieren
std::int32_t add(std::int32_t a)
{
    return a+2;
}
int main()
{
    auto vektor = std::vector<std::int32_t>{2, 7, 14, 27, 45, 06};
    std::transform(vektor.begin(), vektor.end(), vektor.begin(), add);
    for(auto const &it : vektor)
    {
     std::cout<<it<<" ";
    }
}
//#else //replace und replaceif
bool negatif( std::int32_t &val)
{
    return val<=0 ? true:false;
}

int main()
{

    auto vektor = std::vector<std::int32_t>(VALUE, 0U);
    for(auto &it : vektor)//wichtig immer eine Referenz hier benutzen
    {
     it = generator();
    }

    for(auto it = vektor.begin(); it!=vektor.end(); ++it)
    {
        std::cout<<*it<<" ";
    }

    std::cout<<"\n";
    std::replace_if(vektor.begin(), vektor.end(), negatif, 7);
    for(auto it = vektor.begin(); it!=vektor.end(); ++it)
    {
        std::cout<<*it<<" ";
    }
}
#else // shuffle vertauschen

int main()
{
    auto vektor = std::vector<std::int32_t>(VALUE, 0U);
    std::generate(vektor.begin(), vektor.end(), generator);
    for(auto it = vektor.begin(); it!=vektor.end(); ++it)
    {
        std::cout<<*it<<" ";
    }
     std::cout<<"\n";
 auto seed = std::random_device{};
    auto generator = std::mt19937{seed()};
    std::shuffle(vektor.begin(), vektor.end(), generator);
    for(auto it = vektor.begin(); it!=vektor.end(); ++it)
    {
        std::cout<<*it<<" ";
    }
}
#endif
