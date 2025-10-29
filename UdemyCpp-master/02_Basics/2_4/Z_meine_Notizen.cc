//Template ist in anderen meinsten Sprachen Generic( wird nur genutzt wenn die Parameter der Funktion sich ändern aber die Logik gleich bleibt)
//die FunktionOverload wird am besten benutzt, wenn funktionen gleichen Name haben, aber die Logik unterschiedlich ist

#include<iostream>
//was unten ist, nennt man docstring
/**
 * @brief Cumputes max of a and b
 *
 * @tparam T should be int or double
 * @param a
 * @param b
 * @return T
 */
template <typename T>
T max(T a, T b)
{
    return a>b ? a:b;
}

int main()
{
    int a = 1, b=2;
    std::cout<<max(a, b)<<std::endl;

    double c = 2.0, d = 3.0;
    std::cout<<max(c, d)<<std::endl;

    //wenn die Maus auf die Funktion drauf legt , wird einem angezeigt dass die Funktion max nur für int und double gedacht wird, wie man es an dem Docstring geschrieben hat

}
