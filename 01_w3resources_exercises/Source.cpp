
#include <iostream> //cin, cout
#include <stdio.h> //printf

int main()
{
	//following exercises from: https://www.w3resource.com/cpp-exercises/basic/index.php

	//ex 1
	std::cout << "Welcome back...\n\n";

	//ex 2, 4
	int num1 = 70, num2 = 129, sum = num1+num2;	
	std::cout << "num1 = " << num1 << " and num2 = " << num2 << std::endl;
	std::cout << "The sum of these two numbers is " << sum << "\n\n";

	//ex 3 https://cplusplus.com/reference/cstdio/printf/
	std::cout << "The size of various data types is shown below:\n";
	printf("char = %zu\n", sizeof(char));
	//short int shortN;
	std::cout << "short = " << sizeof(short int) << std::endl;
	//printf("short = %i\n", sizeof(int));
	printf("int = %zi\n", sizeof(int));
	//printf("long = %l\n", sizeof(long int*));
	std::cout << "long = " << sizeof(long int*) << std::endl;
	printf("long long = %zu\n", sizeof(long long int*));
	printf("float = %zu\n", sizeof(float));
	printf("double = %zu\n", sizeof(double));
	printf("long double = %zu\n", sizeof(long double*));
	printf("bool = %zd\n", sizeof(bool));
	std::cout << std::endl;

	//ex 5 https://www.simplilearn.com/tutorials/cpp-tutorial/cpp-printf
	//%d = signed int, %u = unsigned int, %f = float
	printf("Max limit of int: %d\n", INT_MAX);
	printf("Min limit of int: %d\n", INT_MIN);
	//fix from here
	printf("Max limit of unsigned int: %u\n", UINT_MAX);
	printf("Max limit of long long: %lld\n", LLONG_MAX);
	printf("Min limit of long long: %lld\n", LLONG_MIN);
	printf("Max limit of unsigned long long: %llu\n", ULLONG_MAX);
	printf("Bits contained within char: %d\n", CHAR_BIT);
	printf("Max limit of char: %d\n", CHAR_MAX);
	printf("Min limit of char: %d\n", CHAR_MIN);
	printf("Max limit of signed char: %d\n", SCHAR_MAX);
	printf("Min limit of signed char: %d\n", SCHAR_MIN);
	printf("Max limit of unsigned char: %u\n", UCHAR_MAX);
	printf("Min limit of short: %d\n", SHRT_MIN);
	printf("Max limit of short: %d\n", SHRT_MAX);
	printf("Max limit of unsigned short: %u\n", USHRT_MAX);
	std::cout << std::endl;

	// skipping ex 6

	//ex 7
	printf("Arithmetic time...!\n");
	int n1 = 27, n2 = 13;
	printf("%d + %d = %d\n", n1, n2, n1+n2);
	float f1 = 1.0, f2 = 15.2;
	printf("%f + %f = %f\n", f1, f2, f1+f2);
	printf("%d + %f = %f\n", n1, f2, n1+f2);
	printf("%d - %d = %d\n", n2, n1, n2-n1);
	printf("%d - %f = %f\n", n2, f2, n2-f2);

	// discontinuing... need more thought provoking exercises


	//pause at end of program
	std::cout << "\n\nPress Enter to continue.";
	std::cin.get();
}


