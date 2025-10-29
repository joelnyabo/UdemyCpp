//wenn man im Terminal "gcc --version" zum Compilieren eingibt "--version" ist Commandeline Argumente, wir können auch unser Programm schreiben, dass wir diese Commandeline beim Compilieren eingeben.
// argc : stehr für Argument count
//argv : -||- für Argument values
//wenn man gcc --version eingibt wird argv = 2 , wenn nur gcc dann 1

#include<iostream>
#include<cstdint>

int main(int argc, char **argv)//wie schon oben erwähnt, argc stht für Argumentcounter, argv für Argumentvalues
{
  //warum char **argv, weil beim Compilieren wie (zb gcc -version) wird erst wie an der Line 9 angefordet argc angegeben(quasi wie viel Argumente erwartet wird)
  //danach muss man eine Array von char Array eingeben(quasi ein Array von String, da ein Array von Char oder ein Pointer auf Char ein String ist)

  //jetzt wollen rausbekommen haben was man beim Compilieren eingegeben hat.

  for(std::size_t i = 0;  i < static_cast<std::size_t>(argc); i++)
  {
      std::cout<<argv[i]<<"\n";//wie oben gesagt, wir wissen, dass argv eine Array von String ist, deswegen um auf String des Array zuzugreifen, geht mit argv[i]
  }
}

//zum Compilieren soll man  "g++ -std=c++17 -Wall -Wextra -O2 z_meine_Notizen_argc.cc -o z_meine_notizen_argc.exe" in Terminal wo man ih haben möchte eingeben und es wird
//"z_meine_notizen_argc.exe" zum Ausführen in Terminal einfach z_meine_notizen_argc.exe eingeben und noch mehr Argumentcd

