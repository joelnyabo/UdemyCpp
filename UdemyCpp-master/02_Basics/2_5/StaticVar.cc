#include <cstdint>
#include <iostream>

int func(const int val)
{
    static int counter = 0; // wird in Compilertime angelegt und wird nur einmal erstellt. Dagegen val und temp werden jedesmal wenn die Funktion
// func() aufgerufen wird erstellt und beim Loslassen der Funktion zerstört.(mit Debugger prüfen)
    const int temp = val * 2;

    ++counter;
    std::cout << "Counter: " << counter << "\n";

    return temp / 3;
}

int main()
{
    std::cout << func(1) << '\n';
    std::cout << func(2) << '\n';
    std::cout << func(3) << '\n';

    return 0;
}
