#include<iostream>
#include<cstdint>

int main()
{

    // alle diese Type die wir unten genannt haben, haben je nach Betriebsystem unterschiedliche Größe zb. ein Integer hat auf Arduino 16 bit anstatt 32 bit wie auf PC.

    // Floating Point Number hat 32bit = 1bit(sign), 8 bit (Exponent), 23 bit (Mantisse)
    //..... 2^2, 2^1 , 2^0 | 2^-1, 2^-2, 2^-3,  2^-4,   2^-5     2^6.... ist gleich was unten ist
    //       4 ,  2,   1   | 0.5 , 0.25, 0.125,0.0625, 0.0315    0.015625
//zb: 6.75 = 1    1    0   |  1     1      0     0       0         0 (hier kann 6.75 exakt dargestellt werden da 0.75  = 0.5 +0.25 ist )
//zb: 5.4  = 1    0    1   |  0     1      1     0       0         1 (der Rest wäre 0.009375 und wird weiter gehen wir werden nie eine exakte binäre Darstellung davon haben)
// wir haben oben gesehen dass 5.4 nicht genau als Binaräre Darstellung dargestellt werden kann, 5.4  float ist ungenauer als 5.4 double , weil als double hat man mehr bit für die Mantisse zur Verfügung.
//nehmen wir an, wir wollen das Alter von einer Person in einem Programm nutzen, wir wissen das Alter kann höchsten 200 [0-200] wenn wir es als integer int darstellen, wird es auf 32 Bit dargestellt
// obwohl 200 in 8bit = 2^8  darstellbar ist, wir würden 3 Bytes(24 bit vergeudern/ verschwenden)deswegen wäre die Darstellung in Char sinnvoller ,aber ein unsigned Char da wir keine negative Alter haben.



//1 bit
   bool my_bool1 = true;
   bool my_bool2 = false;

   // 1 Byte = 8 bit = 2^8 = 256 Werte von -128 bis 127
   char my_char = 10;

   // 2 Byte = 16 bit  = 2^16 Werte

   short my_short = 300;

   // 4 Byte = 32 bit = 2^32 Werte

   int my_int = 100000;

   // 8 Byte = 64 bit = 2^64 Werte

   long long my_ll = 500000000;

   // 4 Byte = 32 bit = 2^32

   float my_float = 10.2;


   // 8 Byte = 64 bit = 2 ^ 64

   double my_double = 12.4;


   //wir haben eine Header Datei in C++ der heißt "cstdint" der ist dafür zuständig die Integer zu dem Betreibsystem anzupassen, wir haben schon gesagt, dass integer unterschiedliche Größe je nach Betriebsystem haben.
   // wir müssen die erst oben einbinden mit "#include<cstdint>"
    std::uint8_t a = 2;// wenn wir die Maus drauf legen, wird uns gezeigt dass a von Typ Char ist, der Compiler wird a in als Typ unsigned Char bewertet, da 8 bit .
    std::uint16_t b = 2;
    std::uint32_t c = 3;
    std::uint64_t d =4;
    std::int16_t e = 8;


    //ASCII
    char haube = 'ü';// wir haben ein Charakter und wollenn wir wissen was für einen Zahlenwert unter der Haube hat.

     std::cout<<"Zahl_unter_der_Haube = "<<(int)haube<<std::endl;

   return(0);
}
