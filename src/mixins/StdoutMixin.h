#pragma once
#include <iostream>

namespace Linal
{
    // T must have m_data, an array which contains all enteries
    template <typename T>
    struct StdoutMixin
    {
        friend std::ostream& operator<<(std::ostream& os, const T& obj)
        {
            int row = obj.m_shape.row;
            int col = obj.m_shape.col;
            for (int  i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    std::cout << obj.m_data[i*row + j] << " ";
                }
                std::cout << std::endl;
            }

            return os;
        }
    };
}
