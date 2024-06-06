#include <linal.h>
#include <iostream>

int main()
{
    Linal::Vec<float, 4> a({1,2,3,4});
    Linal::Vec<float, 4> b({4,3,2,1});
    Linal::Vec<float, 4> c = a - b;
    std::cout << a << "\n" << b  << "\n" << c << "\n\n";

    c += b;
    std::cout << a << "\n" << b  << "\n" << c << "\n\n";

    c -= b;
    std::cout << a << "\n" << b  << "\n" << c << "\n\n";

    c *= 2;
    std::cout << a << "\n" << b  << "\n" << c << "\n\n";

    c = c / 2;
    std::cout << a << "\n" << b  << "\n" << c << "\n\n";

    std::cout << "Vector Operation Mixin Tested" << std::endl;
}

