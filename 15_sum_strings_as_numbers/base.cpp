
#include <iostream> //cin, cout
#include <stdio.h> //printf

/*

Code Wars kata

Given the string representations of two integers, return the string representation of the sum of those integers.

For example:

sumStrings('1','2') // => '3'
A string representation of an integer will contain no characters besides the ten numerals "0" to "9".

I have removed the use of BigInteger and BigDecimal in java

Python: your solution need to work with huge numbers (about a milion digits), converting to int will not work.

*/

#include <string>


bool IsValid(const std::string& val, size_t pos)
{
	if (val.empty() || pos > val.size() - 1 || pos < 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

std::string sum_strings(const std::string& a, const std::string& b) {
	
	size_t duration;
	size_t aLENGTH = a.size(), bLENGTH = b.size();

	std::string resultStr = "";

	//assert cases
	if (a.empty() && !b.empty())
	{
		return b;
	}
	else if (!a.empty() && b.empty())
	{
		return a;
	}
	else if (a.empty() && b.empty())
	{
		return resultStr;
	}

	//use longest string as duration
	if (aLENGTH >= bLENGTH)
	{
		duration = aLENGTH;
	}
	else
	{
		duration = bLENGTH;
	}

	//c is the placeholder for any sums with carryover
	int cNum = 0;

	for (size_t i = 0; i < duration; i++)
	{		
		int aNum, bNum;

		if (IsValid(a, aLENGTH - 1 - i))
		{
			std::string aStr;
			aStr.push_back(a[aLENGTH - 1 - i]);
			aNum = std::stoi(aStr);
		}
		else
		{
			aNum = 0;
		}

		if (IsValid(b, bLENGTH - 1 - i))
		{
			std::string bStr;
			bStr.push_back(b[bLENGTH - 1 - i]);
			bNum = std::stoi(bStr);
		}
		else
		{
			bNum = 0;
		}

		//begin calculations
		int abcSum = aNum + bNum + cNum;
		std::string abcStr = std::to_string(abcSum);

		//now determine the placeholder's value and modify final result
		if (abcSum >= 10)
		{
			cNum = 1;
			resultStr.insert(resultStr.begin(), abcStr[1]);
		}
		else
		{
			cNum = 0;		
			resultStr.insert(resultStr.begin(), abcStr[0]);
		}
	}

	//if there is carryover after loop ends
	if (cNum == 1) { resultStr.insert(resultStr.begin(), '1'); }

	return resultStr;
}


int main()
{
	//begin here
	std::cout << "Adding strings together...\n\n";

	std::cout << "16\n";
	std::cout << "+5\n";
	std::cout << "=" << sum_strings("16", "5") << "\n\n";

	std::cout << "2\n";
	std::cout << "+2\n";
	std::cout << "=" << sum_strings("2", "2") << "\n\n";

	std::string ex1 = "199999999", ex2 = "018263820";
	std::cout << ex1 << "\n";
	std::cout << "+" << ex2 << "\n";
	std::cout << "=" << sum_strings(ex1, ex2) << "\n\n";

	std::cout << "An empty string\n";
	std::cout << "+ An empty string\n";
	std::cout << "=" << sum_strings("", "") << "\n\n";

	std::cout << "99\n";
	std::cout << "+2\n";
	std::cout << "=" << sum_strings("99", "2") << "\n\n";


	//pause at end of program
	std::cout << "\n\nPress Enter to continue.";
	std::cin.get();
}