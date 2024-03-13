
//from https://www.kvraudio.com/forum/viewtopic.php?t=281238
//#define _CRT_SECURE_NO_DEPRECATE

#include <iostream> //cin, cout
#include <stdio.h> //printf


//codewars problem of getting sum of all digits for a number recursively
/*
Given n, take the sum of the digits of n. If that value has more than one digit, 
continue reducing in this way until a single-digit number is produced. The input
will be a non-negative integer.

16		-->  1 + 6 = 7
942		-->  9 + 4 + 2 = 15  -->  1 + 5 = 6
132189  -->  1 + 3 + 2 + 1 + 8 + 9 = 24  -->  2 + 4 = 6
493193  -->  4 + 9 + 3 + 1 + 9 + 3 = 29  -->  2 + 9 = 11  -->  1 + 1 = 2

*/
int digital_root(int n)
{
	// e.g. n = 17, 19, 127, 333, or 123456
	int final = n;
	int sum = 0;
	
	while (final >= 10)
	{
		sum += final % 10;
		final = final / 10;
	}

	final += sum;
	
	if (final >= 10)
	{
		final = digital_root(final);
	}
	
	return final;
}


int main()
{
	//begin here
	std::cout << digital_root(9876127);
	
	//pause at end of program
	std::cout << "\n\nPress Enter to continue.";
	std::cin.get();
}

