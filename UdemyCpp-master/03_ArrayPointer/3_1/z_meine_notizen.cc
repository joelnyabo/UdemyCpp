#include<iostream>
#include<cstdint>
//#define MODE


#ifdef MODE
int main()
{
  constexpr auto length = 3U;
  constexpr auto column = 2U;

  std::int32_t matrix[length][column]{};// eine Matrix ist nicht anderes als ein Array von Vector.

  for( auto i = 0U; i<length; i++)
  {
    for(auto j = 0U; j<column; j++)
    {
        std::cout<<"\nMatrix["<<i+1<<"]"<<"["<<j+1<<"] = ";
        std::cin>>matrix[i][j];
    }
  }

  std::cout<<"\n  Matrix["<<length<<"]["<<column<<"] = ";

   std::cout<<"{";
   for( auto i = 0U; i<length; i++)
   {
      std::cout<<"{";
      for(auto j = 0U; j<column; j++)
      {
          if( j != (column - 1) )
          {
            std::cout<<matrix[i][j]<<",";
          }
          else
          {
             std::cout<<matrix[i][j];
          }
      }
      std::cout<<"}";
    }
    std::cout<<"}";

//Heute Abend Summe der Spalten.
}
#else

int main()
{
    char name[] = "Dannick";
    std::int32_t value[]{1, 3, 7, 8};
    std::cout<<name<<"\n";//Hier merkt man dass char Array ausgeben wird, es ist so dass der Operator "<<" ist für Ausgabe des Char Array aus dieser Form "Dannick" emplementiert ist um es auszugeben, es wird es wie String betrachtet
    std::cout<<value;// aber hier nicht, die Adresse des ersten Character wird ausgeben, hier muss man mit einer For schleife interieren.
    // es ist weil beim char Array ist ein Zeichen '\0'am Ende was das Ende signalisiert.
    //wohingegen beim Array von std::int32_t ist kein Zeichen was das Ende signalisiert, deswegen muss man mit For Schleife interieren.(Video 82)
}
#endif
