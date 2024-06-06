#pragma once
#include <cmath>

namespace Linal
{
	// T needs to have a parameterize constructor of the type T(type x)
	// Where type is a type like int, float or double.
	// T also needs to have a + and scalar multiplcation defined.
	template <typename T>
	struct OperationMixin
	{
		friend T operator- (const T& op1, const T& op2)
		{
			return T(op1 + op2*-1.0f);
		}

		friend T operator/ (const T& op1, float op2)
		{
			if (op2 == 0.0f)
			{
				T a = T(NAN);
			}
			return op1 * (1.0f/op2);
		}

		friend T operator* (float op1, const T& op2)
		{
			return op2 * op1;
		}

		friend void operator+= (T& curr, const T& other)
		{
			curr = curr + other;
		}

		friend void operator-= (T& curr, const T& other)
		{
			curr = curr - other;
		}

		friend void operator*= (T& curr, float scaler)
		{
			curr = curr * scaler;
		}

		friend void operator/= (T& curr, float scaler)
		{
			curr = curr / scaler;
		}
	};
}
