#include <iostream>

// 1.) User-Input: side length of a square
// 2.) Compute the perimeter and area of a square.
// 3.) Print out the values to the console.
// The variable a should be a double

int main()
{
    double side = 0.0, perimeter = 0.0 , area = 0.0;// double ist genauer als float.
    std::cout<<"Enter please the Side of square :"<<std::endl;
    std::cin>>side;
    perimeter  = 4*side;
    area = side * side;
    std::cout<<"Perimeter = "<<perimeter<<"\n"<<"Area = "<<area<<std::endl;
    return (0);

}
