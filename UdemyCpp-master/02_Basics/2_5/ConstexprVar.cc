#include <cstdint>
#include <iostream>

constexpr int VALUE = 2;  // wird eher in Compilertime angelegt so wird Zeit beim ausführen gespart.

int func(const int val)
{
    const int temp = val * 2;

    return temp / 3;
}

int main()
{

    constexpr int b = 9;
     constexpr  int v = 2 * 3 * 5;// wird eher in Compilertime vorgerechnet so wird Zeit beim ausführen gespart, aber nocht nicht im Speicher angelegt, was rechts steht muss zur Compilerzeit schon vorliegen,
    std::cout << func(v) << '\n';//so constexpr int a = b*8, wird zur Compilerfehler führen wenn b nicht als constexper auch deklariert ist. 8 ist hardcodiert(Literal) liegt zur Compilertime
    static constexpr int  a = b*8;// sagt man dem Compiler mit constexpr a muss in Compilertime vorberechnet und mit static auch in Compilertime angelegt.dh. beim Runtine wird diese Zeile gesprungen, man kann es mit dem Debugger prüfen.
    std::cout << func(a) << '\n';
    return 0;

    //NB : Auf dem Stack werden normalen Variablen angelegt, in Heap Speicher wird mit Pointer und Referenz angelegt. hat man auch Static Speicher wird mit static angelegt
}
