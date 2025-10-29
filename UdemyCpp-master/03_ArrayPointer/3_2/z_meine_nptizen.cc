#include<iostream>
#include<cstdint>
#include<array>
#define LENGHT 4



template<typename T>
void ausgabe(std::array<T, LENGHT> arr)
{
   for(std::size_t i = 0; i<arr.size(); i++)
   {
    std::cout<<arr[i]<<"\n";
   }
}


int main()
{

 std::array<std::int32_t, LENGHT> arr1{2, 7, 9, 29};
  ausgabe(arr1);
 std::array<double, LENGHT> arr2{2.0, 0.9, 7.4, 2.9};
 ausgabe(arr2);

}
