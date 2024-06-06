#pragma once
#include <vector>
#include "mixins/OperationMixin.h"
#include <iostream>

namespace Linal
{
    struct Shape
    {
        int row;
        int col;

        friend bool operator== (const Shape& curr, const Shape& other)
        {
            return (curr.row == other.row) && (curr.col == other.col);
        }
    };

    // Row Vector
    template <typename T, int n>
    struct Vec : OperationMixin<Vec<T, n>>, StdoutMixin<Vec<T,n>>
    {
        std::vector<T> m_data;
        Shape m_shape = {1, n};

        Vec()
        {
            m_data.reserve(n);
            for (int i = 0; i < n; i++)
            {
                m_data.push_back(T());
            }
        }

        Vec(const T& x)
        {
            m_data.reserve(n);
            for (int i = 0; i < n; i++)
            {
                m_data.emplace_back(x);
            }
        }

        Vec(const std::vector<T>& vec)
        {
            m_data.reserve(n);
            for (int i = 0; i < n; i++)
            {
                m_data.emplace_back(vec[i]);
            }
        }

        Vec(const Vec& other)
        {
            m_data.reserve(n);
            for (int i = 0; i < n; i++)
            {
                m_data.emplace_back(other.m_data[i]);
            }
        }

        friend Vec operator* (const Vec& a, T scalar)
        {
            Vec temp;

            for (int i = 0; i < n; i++)
            {
                temp.m_data[i] = a.m_data[i] * scalar;
            }

            return temp;
        }

        friend Vec operator+  (const Vec& a, const Vec& other)
        {
            Vec temp;
            if ( !(other.m_shape == a.m_shape) )
            {
                std::cerr << "Not same shape\n";
                throw std::exception();
            }

            for (int i = 0; i < n; i++)
            {
                temp.m_data[i] = a.m_data[i] + other.m_data[i];
            }

            return temp;
        }


    };
}
