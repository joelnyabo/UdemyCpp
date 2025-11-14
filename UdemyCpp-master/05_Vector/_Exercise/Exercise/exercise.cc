#include <algorithm>
#include <iostream>
#include <vector>
#include<algorithm>
#include "exercise.h"

bool aufsteigen(const double a, const double b)
{
   return a<b ? true : false;
}

double max(const VectorT &vec)
{
    double m = 0.0;
    for(auto &it : vec)
    {
        m = m>it ? m:it;
    }
    return m;
}
// Exercise 2
bool max(double a, double b)
{
    return(a<b ? true:false);
}

VectorT max_row_values(MatrixT &matrix)
{
  VectorT aus;
  for(auto &it : matrix)
  {
    aus.push_back(max(it)) ;
  }
  return(aus);
}

// Exercise 3
ValueT sort_and_max(VectorT &vec)
{
  std::sort(vec.begin(), vec.end(), aufsteigen);
  return(vec[vec.size()-1]);
}
