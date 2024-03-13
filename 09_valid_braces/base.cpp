
#include <iostream> //cin, cout
#include <stdio.h> //printf


/*
Code Wars kata

Write a function that takes a string of braces, and determines if the order of the braces is valid. It should return true if the string is valid, and false if it's invalid.

This Kata is similar to the Valid Parentheses Kata, but introduces new characters: brackets [], and curly braces {}. Thanks to @arnedag for the idea!

All input strings will be nonempty, and will only consist of parentheses, brackets and curly braces: ()[]{}.

What is considered Valid?
A string of braces is considered valid if all braces are matched with the correct brace.

Examples
"(){}[]"   =>  True
"([{}])"   =>  True
"(}"       =>  False
"[(])"     =>  False
"[({})](]" =>  False

*/


#include <string>
#include <vector>

bool valid_braces(std::string braces)
{
	//check if size is odd
	if (braces.size() % 2)
	{
		return false;
	}
	else
	{
		//proceed with function
	}

	//method 2, stack open braces into a vector, then pop them once encoutering closed braces
	std::vector<char> cStack;
	bool bValid = true;
	while (braces != "")
	{
		if (braces[0] == '(' || braces[0] == '{' || braces[0] == '[')
		{
			cStack.push_back(braces[0]);
			braces.erase(0, 1);			
		}
		else // braces[0] == ')' || '}' || ']'
		{
			if (cStack.empty()) return false;

			switch (cStack.back())
			{
			case '(':
				if (braces[0] == ')')
				{
					cStack.pop_back();
					braces.erase(0, 1);
				}
				else
				{
					bValid = false;
				}
				break;
			case '{':
				if (braces[0] == '}')
				{
					cStack.pop_back();
					braces.erase(0, 1);
				}
				else
				{
					bValid = false;
				}
				break;
			case '[':
				if (braces[0] == ']')
				{
					cStack.pop_back();
					braces.erase(0, 1);
				}
				else
				{
					bValid = false;
				}
				break;
			}			
		}

		if (!bValid) return false;
	}
	
	/*
	//method 1, did not cover all use cases... start confirming matches
	bool bMatched;
	while (braces != "")
	{
		bMatched = false;

		//check 1st condition if [, (, or { is directly next to it in the given string
		switch (braces[0])
		{
		case '(':
			if (braces[1] == ')')
			{
				braces.erase(0, 2);
				bMatched = true;
			}
			break;
		case '{':
			if (braces[1] == '}')
			{
				braces.erase(0, 2);
				bMatched = true;
			}
			break;
		case '[':
			if (braces[1] == ']')
			{
				braces.erase(0, 2);
				bMatched = true;
			}
			break;
		}

		if (bMatched) continue;

		//check 2nd condition if [, (, or { is on the opposite end of the string
		switch (braces[0])
		{
		case '(':
			if (braces[braces.size()-1] == ')')
			{
				braces.erase(braces.size() - 1, 1);
				braces.erase(0, 1);
				bMatched = true;
			}
			break;
		case '{':
			if (braces[braces.size() - 1] == '}')
			{
				braces.erase(braces.size() - 1, 1);
				braces.erase(0, 1);
				bMatched = true;
			}
			break;
		case '[':
			if (braces[braces.size() - 1] == ']')
			{
				braces.erase(braces.size() - 1, 1);
				braces.erase(0, 1);
				bMatched = true;
			}
			break;
		}

		if (bMatched) continue;
		else return false;
	}
	*/

	return true;
}

int main()
{
	//begin here
	std::cout << "The following strings will return true/false depending on if they are valid.\n\n";

	std::cout << "(()])\n";
	std::cout << valid_braces("(()])") << "\n\n";

	std::cout << "[][{}]\n";
	std::cout << valid_braces("[][{}]") << "\n\n";

	std::cout << "[]][[]\n";
	std::cout << valid_braces("[]][[]") << "\n\n";

	std::cout << "[]{}()\n";
	std::cout << valid_braces("[]{}()") << "\n\n";

	//this should return valid
	std::cout << "({})[({})]\n";
	std::cout << valid_braces("({})[({})]") << "\n\n";

	//pause at end of program
	std::cout << "\n\nPress Enter to continue.";
	std::cin.get();
}