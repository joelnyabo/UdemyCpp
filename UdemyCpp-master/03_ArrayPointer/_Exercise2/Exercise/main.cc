#include <cstdint>
#include <iostream>


std::int32_t * array_constructor(const std::int32_t value,   const std::size_t length)
{
    static std::int32_t a{};//ohne static wird es nach dem Verlassen der Funktion a und seine Speicher in Stack gelöscht, aber mit Static sagt man a muss nicht nach verlassen der Funktion gelöscht werden.
    std::int32_t *z = &a;
    for(std::size_t i = 0; i<length; i++)
    {
        *(z+i) = value;
    }
   return(z);
}




void ausgabe( std::int32_t *z, std::size_t length)
{
   for(std::size_t i = 0; i<length; i++)
    {
        std::cout<<*(z+i)<<" ";
    }
}



int main()
{
 auto *arr = array_constructor(5, 2);
 ausgabe(arr, 2);//ohne static würde wir sagen, die Funktion ausgabe bekommt eine Adresse die schon gelöscht wurde, aber mit static die bekommt eine existierende Adresse.

}
