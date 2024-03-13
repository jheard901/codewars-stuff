
#include <iostream> //cin, cout
#include <stdio.h> //printf


/*

Code Wars kata

In this kata, your task is to create all permutations of a non-empty input string and remove duplicates, if present.

Create as many "shufflings" as you can!

Examples:

With input 'a':
Your function should return: ['a']

With input 'ab':
Your function should return ['ab', 'ba']

With input 'abc':
Your function should return ['abc','acb','bac','bca','cab','cba']

With input 'aabb':
Your function should return ['aabb', 'abab', 'abba', 'baab', 'baba', 'bbaa']
Note: The order of the permutations doesn't matter.

Good luck!

*/

#include <string>
#include <vector>


bool Exists(std::vector<std::string> container, std::string comparison)
{
	if (container.empty()) { return false; }

	for (int i = 0; i < container.size(); i++)
	{
		if (container.at(i) == comparison)
		{
			return true;
		}
	}
	return false;
}

std::string QuickSwap(std::string input, int pos1, int pos2) 
{	
	std::string p1;
	p1.push_back(input[pos1]);

	std::string p2;
	p2.push_back(input[pos2]);

	input.replace(pos1, 1, p2);
	input.replace(pos2, 1, p1);

	return input;
}

//returns all permutations of a string without moving the specified anchor position char
/* partially works...
std::vector<std::string> Shuffle(std::string input, int anchor)
{
	std::vector<std::string> result;

	if (input.size() == 1) { result.push_back(input); return result; }

	//factorial
	int shuffleCount = int(input.size()) - 1;
	for (int i = shuffleCount; i > 1; i--)
	{
		shuffleCount *= (i - 1);
	}

	//size 2-3 strings
	if (input.size() == 2 || input.size() == 3)
	{
		//0, 0 is used initially to pushback the input before swapping begins
		int c1 = 0, c2 = 0;

		for (int i = 0; i < shuffleCount; i++)
		{
			//go back to beg when reaching end of string
			if (c2 == input.size())
			{				
				c2 = 0;
				c1++;
			}
			if (c1 == input.size())
			{
				c1 = 0;
			}
			
			if (c2 == anchor) { c2++; }
			if (c1 == anchor) { c1++; }

			//check if string already exists before adding it to result
			std::string nString = QuickSwap(input, c1, c2);
			if (!Exists(result, nString))
			{
				result.push_back(nString);
			}

			c2++;
		}
	}
	//size 4 or larger strings only
	else if (input.size() > 3)
	{
		//0, 0 is used initially to pushback the input before swapping begins
		int c1 = 0, c2 = 0, nAnchor = anchor + 1;
		
		for (int i = 0; i < shuffleCount; i++)
		{
			//go back to beg when reaching end of string
			if (nAnchor == input.size())
			{
				nAnchor = 0;
			}
			if (c2 == input.size())
			{
				//input = QuickSwap(input, nAnchor, c1);
				//nAnchor = c1;
				//c2 = 0;
				//c1++;

				if (nAnchor + 1 == input.size())
				{
					c1 = 0;
					if (c1 == anchor) { c1++; }
					input = QuickSwap(input, nAnchor, c1);
					nAnchor = c1;
					c1++;
					c2 = 0;
				}
				else
				{
					input = QuickSwap(input, nAnchor, nAnchor + 1);
					nAnchor++;					
					c2 = 0;
				}
			}
			if (c1 == input.size())
			{
				c1 = 0;
			}
			if (nAnchor == anchor) { nAnchor++; } //this should never happen since nAnchor always starts 1 after anchor
			while (c2 == anchor || c2 == nAnchor) 
			{ 
				//my problem occurs here when nAnchor is at the end and c2 is == to it
				//nAnchor needs to move forward at this point to the next position
				c2++; 
				if (c2 == input.size()) { c2 = 0; }
			}
			while (c1 == anchor || c1 == nAnchor) 
			{ 
				c1++;
				if (c1 == input.size()) { c1 = 0; }
			}
			//if (c2 == anchor) { c2++; }
			//if (c1 == anchor) { c1++; }
			//if (c2 == nAnchor) { c2++; }
			//if (c1 == nAnchor) { c1++; }

			//check if string already exists before adding it to result
			std::string nString = QuickSwap(input, c1, c2);
			if (!Exists(result, nString))
			{
				result.push_back(nString);
			}

			c2++;
		}
	}
	
	return result;
}
*/

std::vector<std::string> Shuffle(std::string input, int anchor)
{
	std::vector<std::string> result;

	if (input.size() == 1) { result.push_back(input); return result; }

	//factorial
	int shuffleCount = int(input.size()) - 1;
	for (int i = shuffleCount; i > 1; i--)
	{
		shuffleCount *= (i - 1);
	}

	//size 2-3 strings
	if (input.size() == 2 || input.size() == 3)
	{
		//0, 0 is used initially to pushback the input before swapping begins
		int c1 = 0, c2 = 0;

		for (int i = 0; i < shuffleCount; i++)
		{
			//go back to beg when reaching end of string
			if (c2 == input.size())
			{
				c2 = 0;
				c1++;
			}
			if (c1 == input.size())
			{
				c1 = 0;
			}

			if (c2 == anchor) { c2++; }
			if (c1 == anchor) { c1++; }

			//check if string already exists before adding it to result
			std::string nString = QuickSwap(input, c1, c2);
			if (!Exists(result, nString))
			{
				result.push_back(nString);
			}

			c2++;
		}
	}
	//size 4 or larger strings only
	else if (input.size() > 3)
	{
		//0, 0 is used initially to pushback the input before swapping begins
		int c1 = 0, c2 = 0, nAnchor = anchor + 1;

		for (int i = 0; i < shuffleCount; i++)
		{
			//go back to beg when reaching end of string
			if (nAnchor == input.size())
			{
				nAnchor = 0;
			}
			while (c2 == anchor || c2 == nAnchor)
			{
				//my problem occurs here when nAnchor is at the end and c2 is == to it
				//nAnchor needs to move forward at this point to the next position
				c2++;
				if (c2 == input.size()) { c2 = 0; }
			}
			while (c1 == anchor || c1 == nAnchor)
			{
				c1++;
				if (c1 == input.size()) { c1 = 0; }
			}
			if (c2 == input.size())
			{
				//input = QuickSwap(input, nAnchor, c1);
				//nAnchor = c1;
				//c2 = 0;
				//c1++;

				if (nAnchor + 1 == input.size())
				{
					c1 = 0;
					if (c1 == anchor) { c1++; }
					input = QuickSwap(input, nAnchor, c1);
					nAnchor = c1;
					c1++;
					c2 = 0;
				}
				else
				{
					input = QuickSwap(input, nAnchor, nAnchor + 1);
					nAnchor++;
					c2 = 0;
				}
			}
			if (c1 == input.size())
			{
				c1 = 0;
			}
			if (nAnchor == anchor) { nAnchor++; } //this should never happen since nAnchor always starts 1 after anchor
			
			//if (c2 == anchor) { c2++; }
			//if (c1 == anchor) { c1++; }
			//if (c2 == nAnchor) { c2++; }
			//if (c1 == nAnchor) { c1++; }

			//check if string already exists before adding it to result
			std::string nString = QuickSwap(input, c1, c2);
			if (!Exists(result, nString))
			{
				result.push_back(nString);
			}

			c2++;
		}
	}

	return result;
}

void NewShuffle(std::string &input, int lAnchor, int rAnchor, std::vector<std::string> &result)
{
	//base case
	if (lAnchor == rAnchor)
	{
		if (!Exists(result, input))
		{
			result.push_back(input);
		}		
	}
	else
	{
		for (int i = lAnchor; i <= rAnchor; i++)
		{
			//swap
			input = QuickSwap(input, lAnchor, i);

			//recursive solution
			NewShuffle(input, lAnchor + 1, rAnchor, result);

			//backtrack
			input = QuickSwap(input, lAnchor, i);
		}
	}
}

void NewShuffleDebug(std::string &input, int lAnchor, int rAnchor)
{
	//base case
	if (lAnchor == rAnchor)
	{
		std::cout << input << "\n";
	}
	else
	{
		for (int i = lAnchor; i <= rAnchor; i++)
		{
			//swap
			input = QuickSwap(input, lAnchor, i);

			//recursive solution
			NewShuffleDebug(input, lAnchor + 1, rAnchor);

			//backtrack
			input = QuickSwap(input, lAnchor, i);
		}
	}
}

std::vector<std::string> permutations(std::string s) {
	
	std::vector<std::string> result;

	//just a quick test
	//result = Shuffle(s, 0);

	//this is prior not working code
	/* Gonna try something different
	for (int i = 0; i < s.size(); i++)
	{
		std::vector<std::string> sl = Shuffle(s, i);
		//result.insert(result.end(), sl.begin(), sl.end());

		for (int n = 0; n < sl.size(); n++)
		{
			if (!Exists(result, sl.at(n)))
			{
				result.push_back(sl.at(n));
			}			
		}
		
		if (i + 1 == s.size())
		{
			s = QuickSwap(s, i, 0);
		}
		else
		{
			s = QuickSwap(s, i, i + 1);
		}
		
			
	}
	*/

	NewShuffle(s, 0, int(s.size()) - 1, result);
	//NewShuffleDebug(s, 0, int(s.size()) - 1);

	return result;
}


int main()
{
	//begin here
	std::vector<std::string> strList1, strList2, strList3, strList4, strList5;

	
	strList1 = permutations("a");
	std::cout << "a" << "\n";
	for (int i = 0; i < strList1.size(); i++)
	{
		std::cout << strList1.at(i) << " |";
	}
	std::cout << "\n\n";

	strList2 = permutations("ab");
	std::cout << "ab" << "\n";
	for (int i = 0; i < strList2.size(); i++)
	{
		std::cout << strList2.at(i) << " |";
	}
	std::cout << "\n\n";

	strList3 = permutations("abc");
	std::cout << "abc" << "\n";
	for (int i = 0; i < strList3.size(); i++)
	{
		std::cout << strList3.at(i) << " |";
	}
	std::cout << "\n\n";

	strList4 = permutations("aabb");
	std::cout << "aabb" << "\n";
	for (int i = 0; i < strList4.size(); i++)
	{
		std::cout << strList4.at(i) << " |";
	}
	std::cout << "\n\n";

	strList5 = permutations("NEXT");
	std::cout << "NEXT" << "\n";
	for (int i = 0; i < strList5.size(); i++)
	{
		std::cout << strList5.at(i) << " |";
	}
	std::cout << "\n\n";

	//helper function test
	//std::cout << "NEXT swapping 1st and last letter: " << QuickSwap("NEXT", 0, 3) << "\n";
	//std::cout << "NEXT swapping 2nd and 3rd letter: " << QuickSwap("NEXT", 1, 2) << "\n";
	//std::cout << "NEXT swapping 2nd and 4th letter: " << QuickSwap("NEXT", 1, 3) << "\n";

	//pause at end of program
	std::cout << "\n\nPress Enter to continue.";
	std::cin.get();
}