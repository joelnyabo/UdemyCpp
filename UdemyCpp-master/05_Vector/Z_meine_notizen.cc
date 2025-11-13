#include<iostream>
#include<cstdint>
#include<vector>
//#define MODE

#ifdef MODE //nicht dynamisch
struct DynamicArray
{
    double *m_data;
    std::size_t m_length;
};


double sum(const DynamicArray &dynamic_array)
{
    std::size_t i = 0;
    auto summe = 0.0;
   do
   {
    summe += dynamic_array.m_data[i];
    i++;
   } while (i<dynamic_array.m_length);
   return summe;
}

double mean(const DynamicArray &dynamic_array)
{
  std::size_t counter = 0;
   for(std::size_t i = 0; i<dynamic_array.m_length; i++)
   {
    counter++;
   }
   return (sum(dynamic_array)/static_cast<double>(counter));
}

int main()
{
    constexpr static std::size_t  LENGTH = 5;
    double *z = new double [LENGTH];
    std::cout<<"\n Adresse von z am Anfang = "<<z;
    for(std::size_t i = 0; i<LENGTH; i++)
    {
        z[i] = static_cast<double>(i);
    }

    DynamicArray arr{.m_data = z, .m_length = LENGTH};
    std::cout<<sum(arr)<<"   "<<mean(arr);
    delete [] z;
    std::cout<<"\n Adresse von z bevor man z gelöscht hat = "<<z;
    z = nullptr;
    std::cout<<"\n Adresse von z nachdem man nullptr zugewiesen hat = "<<z;
}
#else // dynamisch
// beim Vector die HEAP ALLOKIERUNG wird automatisch geamcht

double sum(const std::vector<double> &v)
{
    std::size_t i = 0;
    auto summe = 0.0;
   do
   {
    summe += v[i];
    i++;
   } while (i<v.size());
   return summe;
}

int main()
{

  std::size_t i = 0;
  std::vector<double> vek;
  do
  {
    vek.push_back(static_cast<double>(i));
    i++;
  } while(vek.size() < 5);
  std::cout<<sum(vek);
}

#endif
