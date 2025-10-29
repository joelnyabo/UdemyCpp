#include<iostream>
#include<cstdint>

int main()
{
    // wenn wir zb. das Alter[0,200] einer Person eingeben wollen
    std::uint8_t age;//damit wir Speicher vergeudert wird , wird man das Alter nur auf 8 bit begrenzen.
    std::cout<<"Please enter your age : "<<std::endl;
    std::cin>>age;// der Compiler hat age aufgrund seine Anzahl an Bits 8 als Char berücksichtigt, deswegen wird hier nur das erste Zeichnen genommen.
    std::cout<<"Enterred age ist : "<<age<<std::endl;
    // Immer den integer von 32 Bits nehmen, der wird vom Compiler als integer berücksichtigt.

    


}
