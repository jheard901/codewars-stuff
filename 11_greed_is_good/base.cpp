
#include <iostream> //cin, cout
#include <stdio.h> //printf

/*

Code Wars kata

Greed is a dice game played with five six-sided dice. Your mission, 
should you choose to accept it, is to score a throw according to these 
rules. You will always be given an array with five six-sided dice values.

 Three 1's => 1000 points
 Three 6's =>  600 points
 Three 5's =>  500 points
 Three 4's =>  400 points
 Three 3's =>  300 points
 Three 2's =>  200 points
 One   1   =>  100 points
 One   5   =>   50 point

A single die can only be counted once in each roll. For example, a given
"5" can only count as part of a triplet (contributing to the 500 points) 
or as a single 50 points, but not both in the same roll.

Example scoring

 Throw       Score
 ---------   ------------------
 5 1 3 4 1   250:  50 (for the 5) + 2 * 100 (for the 1s)
 1 1 1 3 1   1100: 1000 (for three 1s) + 100 (for the other 1)
 2 4 4 5 4   450:  400 (for three 4s) + 50 (for the 5)

In some languages, it is possible to mutate the input to the function. This
is something that you should never do. If you mutate the input, you will not
be able to pass all the tests.


NOTE:	The input for dice is a vector of ints which represent the score for
		each individual dice.

*/

#include <vector>

int score(const std::vector<int>& dice) {

	int oneCount = 0, twoCount = 0, threeCount = 0, fourCount = 0, fiveCount = 0, sixCount = 0;
	int sum = 0;

	// count roll occurences
	for (const int& roll : dice)
	{
		switch (roll) 
		{
		case 1:
			oneCount++;
			break;
		case 2:
			twoCount++;
			break;
		case 3:
			threeCount++;
			break;
		case 4:
			fourCount++;
			break;
		case 5:
			fiveCount++;
			break;
		case 6:
			sixCount++;
			break;
		}
	}

	// compute score
	while (oneCount + twoCount + threeCount + fourCount + fiveCount + sixCount > 0)
	{
		// 1
		if (oneCount >= 3)
		{
			sum += 1000;
			oneCount -= 3;
		}
		else if (oneCount > 0)
		{
			sum += oneCount * 100;
			oneCount = 0;
		}
		// 2
		if (twoCount >= 3)
		{
			sum += 200;
			twoCount -= 3;
		}
		else if (twoCount > 0)
		{
			sum += twoCount * 0;
			twoCount = 0;
		}
		// 3
		if (threeCount >= 3)
		{
			sum += 300;
			threeCount -= 3;
		}
		else if (threeCount > 0)
		{
			sum += threeCount * 0;
			threeCount = 0;
		}
		// 4
		if (fourCount >= 3)
		{
			sum += 400;
			fourCount -= 3;
		}
		else if (fourCount > 0)
		{
			sum += fourCount * 0;
			fourCount = 0;
		}
		// 5
		if (fiveCount >= 3)
		{
			sum += 500;
			fiveCount -= 3;
		}
		else if (fiveCount > 0)
		{
			sum += fiveCount * 50;
			fiveCount = 0;
		}
		// 6
		if (sixCount >= 3)
		{
			sum += 600;
			sixCount -= 3;
		}
		else if (sixCount > 0)
		{
			sum += sixCount * 0;
			sixCount = 0;
		}
	}

	return sum;
}

int main()
{

	//begin here
	std::vector<int> sample1 = { 1, 1, 2, 1, 5 };
	std::vector<int> sample2 = { 1, 2, 3, 4, 5 };
	std::vector<int> sample3 = { 5, 5, 5, 5, 5 };
	std::vector<int> sample4 = { 6, 1, 2, 2, 5 };

	std::cout << "Rolls { 1, 1, 2, 1, 5 }\nScore: " << score(sample1) << "\n\n";
	std::cout << "Rolls { 1, 2, 3, 4, 5 }\nScore: " << score(sample2) << "\n\n";
	std::cout << "Rolls { 5, 5, 5, 5, 5 }\nScore: " << score(sample3) << "\n\n";
	std::cout << "Rolls { 6, 1, 2, 2, 5 }\nScore: " << score(sample4) << "\n\n";

	//pause at end of program
	std::cout << "\n\nPress Enter to continue.";
	std::cin.get();
}