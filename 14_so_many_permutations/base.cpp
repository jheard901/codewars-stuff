
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

//a working solution
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

//my solution
std::vector<std::string> MyNewShuffle(std::string& input, int lAnchor, int rAnchor)
{
	std::vector<std::string> result;

	//add input to list of results for each combination
	if (lAnchor == rAnchor)
	{				
		result.push_back(input);		
	}	
	//prepare new combinations of the input to test through incrementing
	else
	{
		for (int i = lAnchor; i <= rAnchor; i++)
		{
			//swap letters
			input = QuickSwap(input, lAnchor, i);

			//get permuations incrementally
			std::vector<std::string> nResult = MyNewShuffle(input, lAnchor + 1, rAnchor);

			//verify a value does not already exist in result
			for (int p = 0; p < nResult.size(); p++)
			{
				if (!Exists(result, nResult.at(p)))
				{
					result.push_back(nResult.at(p));
				}
			}

			//swap letters back
			input = QuickSwap(input, lAnchor, i);
		}
	}

	return result;
}

std::vector<std::string> permutations(std::string s) {
	
	std::vector<std::string> result;

	//working solution
	//NewShuffle(s, 0, int(s.size()) - 1, result);

	//my solution || codewars being wierd again with test cases when they say non-empty input strings, but literally have to make code to anticipate a non-empty string...
	if (s == "")
	{
		result.push_back("");
	}
	else
	{
		result = MyNewShuffle(s, 0, int(s.size()) - 1);
	}
	
	return result;
}


int main()
{
	//begin here
	std::vector<std::string> strList1, strList2, strList3, strList4, strList5;

	
	strList1 = permutations("aa");
	std::cout << "aa" << "\n";
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

	//pause at end of program
	std::cout << "\n\nPress Enter to continue.";
	std::cin.get();
}