#include <cstdint>
#include <iostream>

//mit const sagen wir dem Compiler der Wert darf nicht mehr geändert werden, und der Variable wird nur während der Runtime angelegt.

int func(const int val)
{
    const int temp = val * 2;

    return temp / 3;
}

int main()
{
    int v = 2;
    std::cout << func(v) << '\n';

    return 0;
}
