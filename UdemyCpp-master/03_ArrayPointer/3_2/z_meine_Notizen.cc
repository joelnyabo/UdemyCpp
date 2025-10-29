#include<iostream>
#include<cstdint>
#include<array>
//#define MODE


#ifdef MODE

int main()
{
    int main()
{
    std::int32_t *z = new std::int32_t{9};
    std::cout<<z<<" "<<*z;
    delete z;//normalerweise wenn man den allokierten Speicher freigibt, sollte der Zeiger z nicht mehr auf die davor reservierte Speicher zeigen, was nicht der Fall ist.
   //deswegen nullptr;
   z = nullptr;
    std::cout<<z<<" "<<*z;//muss es beim ausführen abstürzen

}

}
#else

int main()
{
    std::size_t lenght = 10;
    auto *arr = new std::int32_t [lenght] ;
    for(std::size_t i = 0; i<lenght; i++)
    {
       arr[i] = static_cast<std::int32_t>(i);
    }

    for(std::size_t i = 0; i<lenght; i++)
    {
        std::cout<<arr[i];
    }

    delete []arr;
    arr = nullptr;

}
#endif
