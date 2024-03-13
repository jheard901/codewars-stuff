
#include <iostream> //cin, cout
#include <stdio.h> //printf


/*

Code Wars kata

Write a program that will calculate the number of trailing zeros in a factorial of a given number.

N! = 1 * 2 * 3 *  ... * N

Be careful 1000! has 2568 digits...

For more info, see: http://mathworld.wolfram.com/Factorial.html

Examples
zeros(6) = 1
# 6! = 1 * 2 * 3 * 4 * 5 * 6 = 720 --> 1 trailing zero

zeros(12) = 2
# 12! = 479001600 --> 2 trailing zeros

Hint: You're not meant to calculate the factorial. Find another way to find the number of zeros.

Better Hints:	https://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/
				https://brilliant.org/wiki/trailing-number-of-zeros/

*/

//still need to make it faster...
long zerosSlower(long n) {

	long result = 0;

	for (int i = n; i > 0; i--)
	{
		int t = i;
		while (t % 5 == 0)
		{
			t /= 5;
			result++;
		}
	}

	return result;
}

long zerosSlow(long n) {

	long result = 0;

	if (n < 5)
	{
		return result;
	}
	else
	{
		while (n % 5 != 0)
		{
			n--;
		}

		for (int i = n; i > 0; i -= 5)
		{
			int t = i;
			while (t % 5 == 0)
			{
				t /= 5;
				result++;
			}
		}

		return result;
	}
}

// the solution
long zeros(long n) {

	long result = 0;

	for (int i = 5; i <= n; i *= 5)
	{
		result += n / i;
	}

	return result;
}

int main()
{
	//begin here
	std::cout << "Trailing Zeroes:\n\n";
	std::cout << "3! = " << zeros(3) << "\n";
	std::cout << "5! = " << zeros(5) << "\n";
	std::cout << "100! = " << zeros(100) << "\n";
	std::cout << "1000! = " << zeros(1000) << "\n";
	std::cout << "100000! = " << zeros(100000) << "\n";
	std::cout << "1000000000! = " << zeros(1000000000) << "\n";

	//pause at end of program
	std::cout << "\n\nPress Enter to continue.";
	std::cin.get();
}