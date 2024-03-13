
/*
#include <iostream> //cin, cout
#include <stdio.h> //printf




// Code Wars kata
// 
// Write a program that will calculate the number of trailing zeros in a factorial of a given number.
// 
// N! = 1 * 2 * 3 *  ... * N
// 
// Be careful 1000! has 2568 digits...
// 
// For more info, see: http://mathworld.wolfram.com/Factorial.html
// 
// Examples
// zeros(6) = 1
// # 6! = 1 * 2 * 3 * 4 * 5 * 6 = 720 --> 1 trailing zero
// 
// zeros(12) = 2
// # 12! = 479001600 --> 2 trailing zeros
// 
// Hint: You're not meant to calculate the factorial. Find another way to find the number of zeros.
// 
// Better Hints:	https://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/
// 					https://brilliant.org/wiki/trailing-number-of-zeros/




#include <vector>

bool IsPrime(long num)
{
	for (long divisor = 2; divisor < num; divisor++)
	{		
		if (num % divisor == 0)
		{
			//not a prime number
			return false;
		}
	}

	//we checked all numbers in between and all had remainders
	return true;
}

std::vector<long> Factorize(long num)
{
	std::vector<long> factors;
	long newNum; //probably can modify num instead of creating a new var

	// we should make a proper special case for inputs of 2 or less
	if (num <= 2)
	{
		factors.push_back(num);
		return factors;
	}

	for (long divisor = 2; divisor < num; divisor++)
	{
		//we found a factor
		if (num % divisor == 0)
		{
			newNum = num / divisor;
			factors.push_back(divisor);
			if (IsPrime(newNum))
			{
				//if newNum prime then add it and return this vector as result
				factors.push_back(newNum);
				return factors;
			}
			else
			{
				//factorize the new number and then add its factors to the original vector
				std::vector<long> rFactors = Factorize(newNum);
				factors.insert(factors.end(), rFactors.begin(), rFactors.end());
				return factors;
			}
		}
	}

	//if no factors were found then num is a prime number
	factors.push_back(num);
	return factors;
}

//there def is more efficent way to do this kata
long zeros(long n) {

	std::vector<long> vec;
	long result = 0;

	if (n < 3) { return result; } //we'll refactor later

	//factorize every number from 1 to n
	for (int i = n; i > 1; i--)
	{
		std::vector<long> tempV = Factorize(i);
		vec.insert(vec.begin(), tempV.begin(), tempV.end());
	}
	 

	//count how many 5's appear after factoring to get trailing zeroes
	for (const auto n : vec)
	{
		if (n == 5)
		{
			result++;
		}
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

	//current solution works, but the following takes too long due to time complexity of the solution
	//std::cout << "100000! = " << zeros(100000) << "\n";
	//std::cout << "1000000000! = " << zeros(1000000000) << "\n";

	//pause at end of program
	std::cout << "\n\nPress Enter to continue.";
	std::cin.get();
}
*/