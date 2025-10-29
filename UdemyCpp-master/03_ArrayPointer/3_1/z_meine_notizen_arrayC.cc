#include<iostream>
#include<cstdint>
//#define PROG MODE




#ifdef PROG
int main()
{
    // das ist C
   constexpr auto length = 4U;
   std::int32_t vector1[length]{};
   std::int32_t vector2[length]{};


   for( auto i = 0U; i<length; ++i )
   {
      std::cout<<"vector1["<<i<<"] = ";
      std::cin>>vector1[i];
   }


   for( auto j = 0U; j<length; ++j )
   {
      std::cout<<"vector2["<<j<<"] = ";
      std::cin>>vector2[j];
   }

std::cout<<"Die Summe der Vectoren sind : "<<'\n';

std::cout<<"vector["<<length<<"] = {";
   for( auto j= 0U; j<length; ++j )
   {
    if( j != length -1 )
        std::cout<<vector1[j] + vector2[j]<<",";
    else
        std::cout<<vector1[j] + vector2[j];
   }
std::cout<<"}";

}
#else
// jetzt char array in C (ein String ist eigentlich ein char Array)

int main()
{
  char name[] = "Dannick";
  for(auto i = 0U; i<7; i++)
  {
     std::cout<<name[i];
  }
}




#endif
