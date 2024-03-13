
#include <iostream> //cin, cout
#include <stdio.h> //printf

#include <cinttypes>

/*
Code Wars problem:

Your task is to make a function that can take any non-negative integer 
as an argument and return it with its digits in descending order. 
Essentially, rearrange the digits to create the highest possible number.

*/

#include <vector>
#include <cmath>

uint64_t descendingOrder(uint64_t a)
{
	std::vector<uint64_t> theDigits, sortedDigits;

	//split a into individual digits
	while (a >= 10)
	{
		theDigits.push_back(a % 10);
		a /= 10;
	}
	theDigits.push_back(a);

	//loop through digits vector to sort them into the correct order	
	std::vector<uint64_t>::iterator it;

	//continue until going through every digit
	while (theDigits.size() > 1)
	{
		//start from beginning
		it = theDigits.begin();
		uint64_t highestNum = theDigits[0];

		for (int i = 0; i < theDigits.size(); i++)
		{
			if (highestNum < theDigits[i])
			{
				highestNum = theDigits[i];
				it = theDigits.begin() + i;
			}
		}
		
		//add highest number to new vector and remove it from old vector
		sortedDigits.push_back(highestNum);
		theDigits.erase(it);
	}
	//done this way anticipating the case of having only 1 digit for the given number
	sortedDigits.push_back(theDigits[0]);
	
	//create the solution using the sorted numbers
	uint64_t result = 0;
	int SIZE = int(sortedDigits.size());

	for (int i = 0; i < SIZE; i++)
	{
		//the last number * 10^i should return its respective digit placement
		uint64_t num = sortedDigits.back() * uint64_t(std::pow(10,i));
		result += num;
		sortedDigits.pop_back();
	}
	
	return result;
}

int main()
{
	//begin here
	std::cout << "The number 176299 resorted is " << descendingOrder(176299) << std::endl;
	std::cout << "The number 9 resorted is " << descendingOrder(9) << std::endl;
	std::cout << "The number 987621 resorted is " << descendingOrder(987621) << std::endl;

	//pause at end of program
	std::cout << "\n\nPress Enter to continue.";
	std::cin.get();
}