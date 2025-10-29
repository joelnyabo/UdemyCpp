#include<iostream>
#include<cstdint>
#include<array> // nur in C++ vorhanden.

/**
 * @brief um einfach uns ermöglichen Array von verschiedenen Größen auszugeben.
 *
 * @tparam N
 * @param tab
 */
template<std::size_t N>
void ausgabe(std::array<std::int32_t, N> tab)
{
    for(auto i = 0U; i<tab.size(); i++)
    {
        std::cout<<tab[i]<<" ";
    }
}
int main()
{
    constexpr std::size_t length = 4;
    std::array<std::int32_t, length> tabelle{1, 4, 6, 7};
    std::array<std::int32_t, 9> tabel{};
    ausgabe(tabelle);
    ausgabe(tabel);

}
